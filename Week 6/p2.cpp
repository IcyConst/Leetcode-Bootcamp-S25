#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Use a map to record the frequency. Then, use heap for O(nlogk). 
// For O(n), use the frequency as the index. Then check the index from the end and get the most Kth frequent ones.
// There may be several elements with the same frequency. So we need to use a 2D vector.

class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> count;
            for(int n: nums) count[n]++;
    
            vector<vector<int>> freq(nums.size() + 1);
            for(auto &entry : count) freq[entry.second].push_back(entry.first);
    
            vector<int> res;
            for(int i = freq.size() - 1; i >= 0; i--){
                for(int num: freq[i]) {
                    res.push_back(num);
                    if(res.size() == k) return res;
                }
            }
            return {};
        }
    };