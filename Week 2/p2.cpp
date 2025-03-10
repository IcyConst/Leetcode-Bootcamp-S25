#include<iostream>
#include<vector>

using namespace std;

//438. Find All Anagrams in a String
//Use two vectors to store the times that each letter appears.
 
class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            vector<int> pcount(26, 0);
            vector<int> scount(26, 0);
            vector<int> vec;
            if(p.length() > s.length()) return vec;
            for(int i = 0;i < p.length();i++){
                int a = p[i] - 'a';
                int b = s[i] - 'a';
                pcount[a]++;
                scount[b]++;
            }
            for(int i = 0;i < s.length();i++){
                bool same = true;
                for(int j = 0;j < 26; j++) {
                    if(pcount[j] != scount[j]) {
                        same = false;
                        break;
                    }
                }
                if(same) vec.push_back(i);
                int a = s[i] - 'a';
                scount[a]--;
                int cur = i + p.length();
                if(cur >= s.length()) break;
                int b = s[cur] - 'a';
                scount[b]++;
            }
            return vec;
        }
    };