/*
85. Maximal Rectangle
Hard

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:
Input: matrix = []
Output: 0

Example 3:
Input: matrix = [["0"]]
Output: 0

Example 4:
Input: matrix = [["1"]]
Output: 1

Example 5:
Input: matrix = [["0","0"]]
Output: 0

Constraints:
    rows == matrix.length
    cols == matrix[i].length
    0 <= row, cols <= 200
    matrix[i][j] is '0' or '1'.
*/
class Solution {
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        vector<int> right(heights.size());
        stack<int> st;
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            right[i]=st.empty()? heights.size()-1:st.top()-1;
            st.push(i);
        }
        while(!st.empty()) st.pop(); 
        int left;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            left=st.empty()?0:st.top()+1;
            st.push(i);
            ans=max(ans,(right[i]-left+1)*heights[i]);
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0) return 0;
        vector<int> hist(matrix[0].size(),0);
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(hist[j] && matrix[i][j]=='1'){
                    hist[j]+=1;
                }else if(!hist[j] &&  matrix[i][j]=='1'){
                    hist[j]=1;
                }else{
                    hist[j]=0;
                }
            }
            ans=max(ans,largestRectangleArea(hist));
        }
        return ans;
    }
};
