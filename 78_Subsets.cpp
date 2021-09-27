/*
78. Subsets
Medium
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order. 

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

Constraints:
    1 <= nums.length <= 10
    -10 <= nums[i] <= 10
    All the numbers of nums are unique.
*/
class Solution {
    void find(vector<vector<int>> &ans,vector<int> sub,vector<int> &nums,int index){
        ans.push_back(sub);
        for(int i=index;i<nums.size();i++){
            sub.push_back(nums[i]);
            find(ans,sub,nums,i+1);
            sub.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        find(ans,sub,nums,0);
        return ans;
    }
};
//Method 2 -Bit Manupulation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size(),p=1<<n;
        vector<vector<int>> ans(p);
        for(int i=0;i<p;i++){
            for(int j=0;j<n;j++){
                if((i>>j)&1){
                    ans[i].push_back(nums[j]);
                }
            }
        }
        return ans;
    }
};
