// 238.Product of array except self
#include<vector>
#include<iostream>

using namespace std;

// O(n) algorithm. Count how many 0s are in the nums vector. 
// If > 2, all answers are 0. If = 1, only 1 is the rest product, other are 0. If  = 0, just use the element to divide the product.
class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int sum = 1, cnt = 0;
            vector<int> vec;
            for(size_t i = 0;i < nums.size();i++) {
                if(nums[i] == 0) cnt++;
                else sum *= nums[i];
            }
            if(cnt >= 2){
                for(size_t i = 0;i < nums.size();i++) vec.push_back(0);
            }
            else if(cnt == 1){
                for(size_t i = 0;i < nums.size();i++) {
                    if(nums[i] == 0) vec.push_back(sum);
                    else vec.push_back(0);
                }
            }
            else if(cnt == 0){
                for(size_t i = 0;i < nums.size();i++) vec.push_back(sum / nums[i]);
            }
            return vec;
        }
    };