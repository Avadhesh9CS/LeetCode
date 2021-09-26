/*
547. Number of Provinces
Medium

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.


Example 1:

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:

Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3

Constraints:
    1 <= n <= 200
    n == isConnected.length
    n == isConnected[i].length
    isConnected[i][j] is 1 or 0.
    isConnected[i][i] == 1
    isConnected[i][j] == isConnected[j][i]
*/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(),0);
        queue<int> q;
        int count=0,x;
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
                count++;
                while(!q.empty()){
                    x=q.front();
                    q.pop();
                    for(int y=0;y<isConnected[0].size();y++){
                        if(x!=y && !visited[y] && isConnected[x][y]){
                            visited[y]=1;
                            q.push(y);
                        }   
                    }
                }
            }
        }
        return count;
    }
};
