// 960. Delete Columns to Make Sorted III

class Solution {
private:
    // Helper function to check if column j can precede column i for all strings
    bool isSorted(const vector<string>& strs, int j, int i) {
        for (const string& s : strs) {
            // If any string violates the non-decreasing order, return false
            if (s[j] > s[i])
                return false;
        }
        return true;
    }

public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs[0].size();
        // dp[i] stores the max length of an increasing subsequence ending at index i
        vector<int> dp(m, 1);

        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < i; ++j) {
                // If column j can precede column i, try to extend the sequence
                if (isSorted(strs, j, i)) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        // The longest sequence we can keep
        int longest = *max_element(dp.begin(), dp.end());
        
        // Result is total columns minus the ones we keep
        return m - longest;
    }
};


// CHATGPT TAKEAWAY 

// 1 Problem restatement (very important)

// Now comes the DP idea (very important)
// Once you think:
// “I want the longest sequence of columns I can keep in order”
// This becomes a Longest Increasing Subsequence (LIS)–style problem.
// But instead of numbers, we have columns.


// 2 What does dp[i] mean? (THIS is the heart)

// dp[i] = the maximum number of columns we can keep, if column i is the LAST kept column
// Say this sentence slowly.
// This is the entire DP meaning.
// Example intuition
// If:dp[5] = 3
// It means:
// “There exists a valid way to keep 3 columns, and the last one is column 5.”


// 3 How the DP is built (thinking process)

// Imagine scanning columns from left to right.
// For each column i:
// Assume we keep only this column → dp[i] = 1
// Try all earlier columns j < i
// If column j can come before i (safe for all rows)
// Then:
// dp[i] = max(dp[i], dp[j] + 1)
// This is identical in structure to LIS.


// 4 Why LIS thinking appears here

// Classic LIS problem:
// Longest increasing subsequence in an array
// Here:
// “array elements” = columns
// “increasing” = non-decreasing in every row
// So this problem is:
// LIS on columns under a custom comparison rule


// 5 Big mental takeaway (very important)

// When a problem asks:
// “Delete the minimum number of things to make X valid”
// Very often you should think:
// “What is the maximum number of things I can keep valid?”
// That almost always leads to:
// LIS
// DP on subsequences
// DP on ordering


// 6 What this DP is really storing (one line)

// dp[i] stores the maximum number of columns we can keep,ending exactly at column i,such that every row is sorted.
// If you remember just this, the solution will always make sense.


// 7 When to recognize this pattern again

// Think of this solution when you see:
// “delete minimum elements”
// “keep order”
// “valid subsequence”
// “global constraint across all rows”
// Those are strong DP/LIS signals.




// You are given an array of n strings strs, all of the same length.

// We may choose any deletion indices, and we delete all the characters in those indices for each string.

// For example, if we have strs = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef", "vyz"].

// Suppose we chose a set of deletion indices answer such that after deletions, the final array has every string (row) in lexicographic order. (i.e., (strs[0][0] <= strs[0][1] <= ... <= strs[0][strs[0].length - 1]), and (strs[1][0] <= strs[1][1] <= ... <= strs[1][strs[1].length - 1]), and so on). Return the minimum possible value of answer.length.

 

// Example 1:

// Input: strs = ["babca","bbazb"]
// Output: 3
// Explanation: After deleting columns 0, 1, and 4, the final array is strs = ["bc", "az"].
// Both these rows are individually in lexicographic order (ie. strs[0][0] <= strs[0][1] and strs[1][0] <= strs[1][1]).
// Note that strs[0] > strs[1] - the array strs is not necessarily in lexicographic order.