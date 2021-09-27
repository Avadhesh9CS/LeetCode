/*
1091. Shortest Path in Binary Matrix
Medium

Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

    All the visited cells of the path are 0.
    All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).

The length of a clear path is the number of visited cells of this path.

 

Example 1:

Input: grid = [[0,1],[1,0]]
Output: 2

Example 2:

Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1

 

Constraints:

    n == grid.length
    n == grid[i].length
    1 <= n <= 100
    grid[i][j] is 0 or 1

*/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[n-1][n-1] || grid[0][0]) return -1;
        vector<pair<int,int>> d={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0]=1;
        int count=0,x,y,x1,y1,curr=1,next=0;
        while(!q.empty()){
            if(curr==0){
                curr=next;
                next=0;
                count++;
            }
            x=q.front().first;
            y=q.front().second;
            q.pop();
            curr--;
            if(x==n-1 && y==n-1) return count+1;   
            for(auto k:d){
                x1=x+k.first;
                y1=y+k.second;
                if(x1>=0 && x1<n && y1>=0 &&y1<n && !grid[x1][y1] && !visited[x1][y1]){
                    q.push({x1,y1});
                    visited[x1][y1]=1;
                    next++;
                }                
            }
            if(q.empty()) return -1;  
        }
        return count+1;
    }
};
