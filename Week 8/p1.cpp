#include<iostream>
#include<vector>

using namespace std;

// 416.Partition Equal Subset Sum
// Get the half of the sum, then for each num, transform the condition from num to ans.

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tot = 0;
        for(int num : nums) tot += num;
        if(tot % 2 != 0) return false;

        int ans = tot / 2;
        vector<int> dp(ans+1);
        dp[0] = 1;
        for(int num : nums){
            for(int i = ans; i >= num; i--){
                dp[i] = dp[i] | dp[i - num];
                if(dp[ans]) return true;
            }
        }
        return dp[ans];
    }
};