/*
994. Rotting Oranges
Medium

You are given an m x n grid where each cell can have one of three values:

    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.


Example 1:

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.


Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 10
    grid[i][j] is 0, 1, or 2
 */
 class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),one=0,x,y,x1,y1,day=0,curr=0,next=0;
        queue<pair<int,int>> two;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) one++;
                else if(grid[i][j]==2) two.push({i,j});
            }
        }
        if(one==0) return 0;
        if(two.empty()) return -1;
        curr=two.size();
        int d[5]={0,1,0,-1,0};
        while(!two.empty()){
            if(curr==0){
                curr=next;
                next=0;
                day++;
            }
            x=two.front().first;
            y=two.front().second;
            curr--;
            two.pop();
            for(int k=0;k<4;k++){
                x1=x+d[k];
                y1=y+d[k+1];
                if(x1>=0 && y1>=0 && x1<m && y1<n && grid[x1][y1]==1){
                    next++;
                    two.push({x1,y1});
                    grid[x1][y1]=2;
                    one--;
                }
            }
        }
        return one==0?day:-1;
    }
};
