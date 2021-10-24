/*
84. Largest Rectangle in Histogram
Hard

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:
Input: heights = [2,4]
Output: 4

Constraints:
    1 <= heights.length <= 105
    0 <= heights[i] <= 104
*/
class Solution {
public:
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
};
