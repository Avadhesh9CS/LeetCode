/*
200. Number of Islands
Medium

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 300
    grid[i][j] is '0' or '1'.

*/
class Solution {
    int d[5]={0,1,0,-1,0};
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int num=0,x,y,x1,y1;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0 ; j<grid[0].size();j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    q.push({i,j});
                    visited[i][j]=1;
                    num++;
                    while(!q.empty()){
                        x=q.front().first;
                        y=q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++){
                            x1=x+d[k];
                            y1=y+d[k+1];
                            if(x1>=0 && x1<grid.size() && y1>=0 && y1<grid[0].size() && !visited[x1][y1] && grid[x1][y1]=='1'){
                                q.push({x1,y1});
                                visited[x1][y1]=1;
                            }
                        }
                    }
                }
            }
        }
        return num;
    }
};
