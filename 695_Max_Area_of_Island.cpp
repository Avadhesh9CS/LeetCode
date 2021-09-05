/*
695. Max Area of Island
Medium

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 

Example 1:

Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 50
    grid[i][j] is either 0 or 1.

*/
class Solution {
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<int,int>> q;
        int max_area=0,area=0,x,y,x1,y1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!visited[i][j] && grid[i][j]){
                    q.push({i,j});
                    visited[i][j]=1;
                    area=0;
                    while(!q.empty()){
                        x=q.front().first;
                        y=q.front().second;
                        q.pop();
                        area++;
                        for(int k=0;k<4;k++){
                            x1=x+dx[k];
                            y1=y+dy[k];
                            if(x1>=0 && y1>=0 && x1<grid.size() && y1<grid[0].size() && grid[x1][y1] && !visited[x1][y1]){
                                visited[x1][y1]=1;
                                q.push({x1,y1});
                            }
                        }
                    }
                }
                if(area>max_area){
                        max_area=area;
                }
            }
        }
        return max_area;
    }
};
