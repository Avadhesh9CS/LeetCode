//733. Flood Fill
/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].
To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.
Return the modified image after performing the flood fill.

Example 1:
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

Example 2:
Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
Output: [[2,2,2],[2,2,2]]

Constraints:
    m == image.length
    n == image[i].length
    1 <= m, n <= 50
    0 <= image[i][j], newColor < 216
    0 <= sr < m
    0 <= sc < n
*/
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> visited(image.size(),vector<int>(image[0].size(),0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc]=1;
        int i,j;
        while(!q.empty()){
            i=q.front().first;
            j=q.front().second;
            q.pop();
            //top
            if(i-1>=0 && visited[i-1][j]==0 && image[i][j]==image[i-1][j]){
                visited[i-1][j]=1;
                q.push({i-1,j});
            }
            //bottom
            if(i+1<image.size() && visited[i+1][j]==0 && image[i][j]==image[i+1][j]){
                visited[i+1][j]=1;
                q.push({i+1,j});
            }
            //left
            if(j-1>=0 && visited[i][j-1]==0 && image[i][j]==image[i][j-1]){
                visited[i][j-1]=1;
                q.push({i,j-1});
            }
            //right
            if(j+1<image[0].size() && visited[i][j+1]==0 && image[i][j]==image[i][j+1]){
                visited[i][j+1]=1;
                q.push({i,j+1});
            }
            image[i][j]=newColor;
        }
        return image;
    }
};
