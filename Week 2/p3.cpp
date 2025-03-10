#include<iostream>
#include<vector>

using namespace std;

//151. Reverse Words in a String
//Use a vector of string to store the words. All the characters except space are considered as a part of one word.

class Solution {
    public:
        string reverseWords(string s) {
            vector<string> vec;
            bool str = false;
            int cur = 0;
            for(int i = 0;i < s.length();i++){
                if(!str && s[i] == ' ') continue;
                if(s[i] != ' ') {
                    if(!str) cur = i, str = true;
                }
                if(str && (s[i] == ' ')){
                    str = false;
                    int len = i - cur;
                    string t = s.substr(cur, len);
                    vec.push_back(t);
                }
            }
            if(str){
                int len = s.length() + 1 - cur;
                string t = s.substr(cur, len);
                vec.push_back(t);
            }
            string ans = "";
            for(int i = vec.size() - 1; i >= 0; i--){
                ans = ans + vec[i];
                if(i > 0) ans = ans + " ";
            }
            return ans;
        }
    };