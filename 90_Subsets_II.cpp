/*
90. Subsets II
Medium
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

Constraints:
    1 <= nums.length <= 10
    -10 <= nums[i] <= 10
*/
class Solution {
        void find(vector<vector<int>> &ans,vector<int> sub,vector<int> &nums,int index){
        ans.push_back(sub);
        for(int i=index;i<nums.size();i++){
            if(i==index || nums[i]!=nums[i-1]){
                sub.push_back(nums[i]);
                find(ans,sub,nums,i+1);
                sub.pop_back();
            }
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> sub;
        find(ans,sub,nums,0);
        return ans;
    }
};
