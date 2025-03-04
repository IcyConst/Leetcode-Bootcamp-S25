// 75. Sort Colors
#include<vector>
#include<iostream>

using namespace std;

// O(n) algorithm. Count how many 0,1,2s are in the nums vector. And push_back them in order.
class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int red = 0, white = 0, blue = 0;
            for(size_t i = 0;i < nums.size();i++){
                if(nums[i] == 0) red++;
                if(nums[i] == 1) white++;
                if(nums[i] == 2) blue++;
            }
            nums.clear();
            for(size_t i = 0;i < red; i++) nums.push_back(0);
            for(size_t i = 0;i < white; i++) nums.push_back(1);
            for(size_t i = 0;i < blue; i++) nums.push_back(2);
        }
    };