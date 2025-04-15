#include<iostream>
#include<vector>
using namespace std;

//DP. Set dp[i] as if the first i-th substring can be segmented to the words in the dictionary.
//Then check all the strings in the dictionary, if it can match, edit the value of dp[i] = dp[i] || dp[i-len] to transfrom the condition.
//Remember to use OR operation. Otherwise, if dp[i] matches dp[i-len] with 0 but it is 1 in original, the answer will be wrong.

class Solution {
    public:
        bool wordBreak(string s, vector<string>& wordDict) {
            vector<int> dp(s.length() + 1, 0);
            int minlength = 25;
            dp[0] = 1;
            for (int i = 1; i <= s.length(); i++) {
            for (auto& str : wordDict) {
                int len = str.length();
                if (i >= len && s.substr(i - len, len) == str) {
                    dp[i] = dp[i] || dp[i - len];
                }
            }
        }
        return dp[s.length()];
        }
    };