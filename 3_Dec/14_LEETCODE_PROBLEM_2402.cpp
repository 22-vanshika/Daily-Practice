class Solution {
public:
  int mostBooked(int n, vector<vector<int>> &meetings) {
    // Step 1: sort meetings by start time
    sort(meetings.begin(), meetings.end());

    // Step 2: free rooms (min room number)
    priority_queue<int, vector<int>, greater<int>> freeRooms;

    // Step 3: busy rooms (min end time)
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        busyRooms;

    // Step 4: count meetings per room
    vector<int> meetingCount(n, 0);

    // Initially, all rooms are free
    for (int room = 0; room < n; room++) {
      freeRooms.push(room);
    }

    // Process each meeting
    for (auto &meeting : meetings) {
      long long start = meeting[0];
      long long end = meeting[1];
      long long duration = end - start;

      // Free rooms that are done before this meeting starts
      while (!busyRooms.empty() && busyRooms.top().first <= start) {
        int freedRoom = busyRooms.top().second;
        busyRooms.pop();
        freeRooms.push(freedRoom);
      }

      // Case 1: a room is free
      if (!freeRooms.empty()) {
        int room = freeRooms.top();
        freeRooms.pop();
        meetingCount[room]++;
        busyRooms.push({end, room});
      }
      // Case 2: no room free → delay
      else {
        auto earliest = busyRooms.top();
        busyRooms.pop();

        long long newEnd = earliest.first + duration;
        int room = earliest.second;

        meetingCount[room]++;
        busyRooms.push({newEnd, room});
      }
    }

    // Find room with maximum meetings
    int answer = 0;
    for (int i = 1; i < n; i++) {
      if (meetingCount[i] > meetingCount[answer]) {
        answer = i;
      }
    }
    return answer;
  }
};

0 Think like this :
“I need to know which room is free and which room finishes earliest.” That
        thought immediately gives :
“free” → min room number → heap
“finishes earliest” → min end time → heap So
    : two different questions → two different priority queues

          Big
          Takeaways(VERY IMPORTANT) 1 Use TWO heaps when
      priorities conflict One heap cannot efficiently handle two different rules

      2 Simulation problems = heaps If you see
    : earliest smallest next available Think priority queue.

      3 This pattern appears everywhere CPU
      scheduling server load balancing calendar systems job queues

      // 2402. Meeting Rooms III

      // You are given an integer n. There are n rooms numbered from 0 to n - 1.

      // You are given a 2D integer array meetings where meetings[i] = [starti,
      // endi] means that a meeting will be held during the half-closed time
      // interval [starti, endi). All the values of starti are unique.

      // Meetings are allocated to rooms in the following manner:

      // Each meeting will take place in the unused room with the lowest number.
      // If there are no available rooms, the meeting will be delayed until a
      // room becomes free. The delayed meeting should have the same duration as
      // the original meeting. When a room becomes unused, meetings that have an
      // earlier original start time should be given the room. Return the number
      // of the room that held the most meetings. If there are multiple rooms,
      // return the room with the lowest number.

      // A half-closed interval [a, b) is the interval between a and b including
      // a and not including b.

      // Example 1:

      // Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
      // Output: 0
      // Explanation:
      // - At time 0, both rooms are not being used. The first meeting starts in
      // room 0.
      // - At time 1, only room 1 is not being used. The second meeting starts
      // in room 1.
      // - At time 2, both rooms are being used. The third meeting is delayed.
      // - At time 3, both rooms are being used. The fourth meeting is delayed.
      // - At time 5, the meeting in room 1 finishes. The third meeting starts
      // in room 1 for the time period [5,10).
      // - At time 10, the meetings in both rooms finish. The fourth meeting
      // starts in room 0 for the time period [10,11). Both rooms 0 and 1 held 2
      // meetings, so we return 0.