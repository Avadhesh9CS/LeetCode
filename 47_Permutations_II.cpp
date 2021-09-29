/*
47. Permutations II
Medium

Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Example 1:
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

Example 2:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Constraints:
    1 <= nums.length <= 8
    -10 <= nums[i] <= 10
*/
class Solution {
    vector<vector<int>> ans;
    void helper(vector<int> nums,int begin){
        if(begin==nums.size()-1){
            ans.push_back(nums);
            return;
        }
        for(int i=begin;i<nums.size();i++){
            if((i==begin) || (nums[begin]!=nums[i])){
                swap(nums[i],nums[begin]);
                helper(nums,begin+1);
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ans.clear();
        sort(nums.begin(),nums.end());
        helper(nums,0);
        return ans;
    }
};
