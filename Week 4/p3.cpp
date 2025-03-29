#include<algorithm>
#include<vector>

using namespace std;

//2327. Number of People Aware of a Secret
//Using sliding window is the best way. We set dp[i] as the current number of people who will share the secret.
//Then change the dp[i] by sliding window.

class Solution {

public:
    int mod = 1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int cur = 0, ans = 0;
        vector<long> dp(n+1);
        dp[1] = 1;
        for(int i = 2;i <= n;i++){
            dp[i] = (cur + dp[max(i - delay, 0)] - dp[max(i - forget, 0)] + mod) % mod;
            cur = dp[i];
        }
        for(int i = n - forget + 1;i <= n;i++) ans = (ans + dp[i]) % mod;
        return (int)ans;
    }
};