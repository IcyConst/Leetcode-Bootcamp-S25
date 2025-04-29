#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 53.Maximum Subarray
// The core idea is, for each element, we can start the subarray at here, or connect it to the previous subarray.
// So just calculate the maximum sum for each element is OK.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums);
        int ans = nums[0];
        for(int i = 1;i < size(nums);i++) {
            dp[i] = max(nums[i], nums[i] + dp[i-1]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// Or Kadane's Algorithm like this to optimize the Space Complexity.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0, nmax = INT_MIN;
        for(auto c : nums)
            cur = max(c, cur + c),
            nmax = max(nmax, cur);
        return nmax;
    }
};