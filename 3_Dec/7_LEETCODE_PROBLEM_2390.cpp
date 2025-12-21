class Solution {
public:
  string removeStars(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '*')
        st.pop();
      else
        st.push(s[i]);
    }
    string ans = "";
    while (!st.empty()) {
      char ch = st.top();
      st.pop();
      ans += ch;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

-- -- -- --optimized two pointer approach by overwriting the string

         class Solution {
public:
  string removeStars(string s) {
    int i = 0, j = 0;
    for (i = 0; i < s.size(); i++) {
      if (s[i] == '*') {
        j--;
      } else {
        s[j++] = s[i];
      }
    }
    return s.substr(0, j);
  }
};

// You are given a string s, which contains stars *.

// In one operation, you can:

// Choose a star in s.
// Remove the closest non-star character to its left, as well as remove the star
// itself. Return the string after all stars have been removed.

// Note:

// The input will be generated such that the operation is always possible.
// It can be shown that the resulting string will always be unique.

// Example 1:

// Input: s = "leet**cod*e"
// Output: "lecoe"
// Explanation: Performing the removals from left to right:
// - The closest character to the 1st star is 't' in "leet**cod*e". s becomes
// "lee*cod*e".
// - The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes
// "lecod*e".
// - The closest character to the 3rd star is 'd' in "lecod*e". s becomes
// "lecoe". There are no more stars, so we return "lecoe".
