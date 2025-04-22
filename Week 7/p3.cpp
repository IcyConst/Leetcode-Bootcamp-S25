#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// 210. Course Schedule II
// Build a topo graph. Do BFS on it.
// Maybe in C++ using unordered_map<int, list<int>> to store the adjList is better.

class Solution {
    public:
        struct edge{
            int to;
            int nxt;
        }e[4000005];
    
        int head[2005] = {0}, ecnt = 0;
    
        void add(int x,int y)
        {
            e[++ecnt].to = y;
            e[ecnt].nxt = head[x];
            head[x] = ecnt;
        }
    
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            int cnt = numCourses, ind[2005] = {0};
            queue<int> q;
            vector<int> ans;
            for(auto pre : prerequisites){
                add(pre[1], pre[0]);
                ind[pre[0]]++;
            }
            for(int i = 0;i < numCourses; i++){
                if(ind[i] == 0) q.push(i);
            }
            while(!q.empty()){
                int k = q.front();
                q.pop();
                ans.push_back(k);
                cnt--;
                for(int i = head[k];i;i = e[i].nxt){
                    ind[e[i].to]--;
                    if(ind[e[i].to] == 0) q.push(e[i].to);
                }
            }
            if(cnt > 0) ans.clear();
            return ans;
        }
    };