/*
886. Possible Bipartition
Medium

We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.
Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

Example 1:
Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4] and group2 [2,3].

Example 2:
Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false

Example 3:
Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false

Constraints:
    1 <= n <= 2000
    0 <= dislikes.length <= 104
    dislikes[i].length == 2
    1 <= dislikes[i][j] <= n
    ai < bi
    All the pairs of dislikes are unique.
*/
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);
        int u,v;
        for(int i=0;i<dislikes.size();i++){
            u=dislikes[i][0]-1;
            v=dislikes[i][1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> clr(n,-1);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(clr[i]==-1){ 
                clr[i]=0;
                q.push(i);
                while(!q.empty()){
                    u=q.front();
                    q.pop();
                    for(int v:adj[u]){
                        if(clr[u]==clr[v]){
                            return false;
                        }
                        if(clr[v]==-1){
                            clr[v]=!clr[u];
                            q.push(v);
                        }
                    }
                }
            }
        }
        return true;
    }
};
