// 167.Two sum II - Input Array is Sorted
#include<vector>
#include<iostream>

using namespace std;

// O(nlogn) algorithm, check the mid element in the rest.
class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            vector<int> vec;
            for(size_t i = 0; i < numbers.size(); i++){
                int l = i + 1, r = numbers.size() - 1;
                int ans = 0;
                bool flag = false;
                while(l <= r){
                    int mid = (l + r) / 2;
                    if(numbers[i] + numbers[mid]  == target){
                        flag = true;
                        ans = mid;
                        break;
                    }
                    if(numbers[i] + numbers[mid] < target) l = mid + 1;
                    else r = mid - 1;
                }
                if(flag == true) {
                    vec.push_back(i+1);
                    vec.push_back(ans+1);
                    break;
                }
            }
            return vec;
        }
    };

// O(n) algorithm. Use the non-decreasing order of the vector, each time only changes one element.
class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            vector<int> vec(2);
            int l = 0, r = numbers.size() - 1;
            while(l < r){
                int ans = numbers[l] + numbers[r];
                if(target == ans) {
                    vec = {l+1, r+1};
                    break;
                }
                else if(ans < target) l++;
                else r--;
            }
            return vec;
        }
    };