class Solution {
public:
  int maxTwoEvents(vector<vector<int>> &events) {
    int n = events.size();

    // 1️⃣ Sort by start time
    sort(events.begin(), events.end());

    // 2️⃣ Build suffix max array
    vector<int> suffix(n);
    suffix[n - 1] = events[n - 1][2];
    for (int i = n - 2; i >= 0; i--) {
      suffix[i] = max(suffix[i + 1], events[i][2]);
    }

    int ans = 0;

    // 3️⃣ Try each event as the first event
    for (int i = 0; i < n; i++) {
      // case 1: take only this event
      ans = max(ans, events[i][2]);

      // binary search for next non-overlapping event
      int st = i + 1, end = n - 1, pos = -1;

      while (st <= end) {
        int mid = st + (end - st) / 2;
        if (events[mid][0] >= events[i][1] + 1) {
          pos = mid;
          end = mid - 1;
        } else {
          st = mid + 1;
        }
      }

      // case 2: take two events
      if (pos != -1) {
        ans = max(ans, events[i][2] + suffix[pos]);
      }
    }

    return ans;
  }
};

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -optimised solution

                                          class Solution {
public:
  int maxTwoEvents(vector<vector<int>> &events) {
    // Sort by start time
    sort(events.begin(), events.end(),
         [](const vector<int> &a, const vector<int> &b) {
           return a[0] < b[0]; // start
         });

    // min-heap: {end, value}
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    int bestEndedVal = 0;
    int ans = 0;

    for (auto &e : events) {
      int s = e[0];
      int en = e[1];
      int v = e[2];

      // all events that ended before s can now be paired
      while (!pq.empty() && pq.top().first < s) {
        bestEndedVal = max(bestEndedVal, pq.top().second);
        pq.pop();
      }

      // take current alone
      ans = max(ans, v);

      // pair with best previous
      if (bestEndedVal > 0) {
        ans = max(ans, v + bestEndedVal);
      }

      pq.push({en, v});
    }

    return ans;
  }
};

// 2054. Two Best Non-Overlapping Events

// You are given a 0-indexed 2D integer array of events where events[i] =
// [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends
// at endTimei, and if you attend this event, you will receive a value of
// valuei. You can choose at most two non-overlapping events to attend such that
// the sum of their values is maximized.

// Return this maximum sum.

// Note that the start time and end time is inclusive: that is, you cannot
// attend two events where one of them starts and the other ends at the same
// time. More specifically, if you attend an event with end time t, the next
// event must start at or after t + 1.

// Example 1:

// Input: events = [[1,3,2],[4,5,2],[2,4,3]]
// Output: 4
// Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.