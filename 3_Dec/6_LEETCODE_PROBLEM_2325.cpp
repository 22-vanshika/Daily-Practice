class Solution {
public:
  string decodeMessage(string key, string message) {
    unordered_map<char, int> code;
    int cnt = 0 + 'a';
    for (int i = 0; i < key.length(); i++) {
      if (key[i] != ' ' && code.find(key[i]) == code.end())
        code[key[i]] = cnt++;
    }
    string st = "";
    for (auto i : message) {
      if (i == ' ')
        st += ' ';
      else
        st += char(code[i]);
    }
    return st;
  }
};
___________ optimized-- - not performing the find function

                          class Solution {
public:
  string decodeMessage(string key, string message) {
    vector<int> table(26, -1);
    for (int i = 0, k = 0; i < key.size(); i++) {
      if (key[i] != ' ' && table[key[i] - 'a'] == -1) {
        table[key[i] - 'a'] = k++;
      }
    }
    for (int i = 0; i < message.size(); i++) {
      if (message[i] != ' ') {
        message[i] = table[message[i] - 'a'] + 'a';
      }
    }
    return message;
  }
};

// 2325. Decode the Message
// You are given the strings key and message, which represent a cipher key and a
// secret message, respectively. The steps to decode message are as follows:

// Use the first appearance of all 26 lowercase English letters in key as the
// order of the substitution table. Align the substitution table with the
// regular English alphabet. Each letter in message is then substituted using
// the table. Spaces ' ' are transformed to themselves. For example, given key =
// "happy boy" (actual key would have at least one instance of each letter in
// the alphabet), we have the partial substitution table of ('h' -> 'a', 'a' ->
// 'b', 'p' -> 'c', 'y' -> 'd', 'b' -> 'e', 'o' -> 'f'). Return the decoded
// message.

// Example 1:

// Input: key = "the quick brown fox jumps over the lazy dog", message = "vkbs
// bs t suepuv" Output: "this is a secret" Explanation: The diagram above shows
// the substitution table. It is obtained by taking the first appearance of each
// letter in "the quick brown fox jumps over the lazy dog".