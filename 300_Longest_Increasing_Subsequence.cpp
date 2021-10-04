/*
300. Longest Increasing Subsequence
Medium

Given an integer array nums, return the length of the longest strictly increasing subsequence.
A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1

Constraints:
    1 <= nums.length <= 2500
    -104 <= nums[i] <= 104
Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/
//Method 1 dp- O(n^2):
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),mx=1;
        if(n<2)return n;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[j]>=dp[i]){
                    dp[i]=1+dp[j];
                    mx=max(dp[i],mx);
                }
            }
        }
        return mx;
    }
};
//Method 2 greedy approch- O(N*LOGN)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            auto it= lower_bound(res.begin(),res.end(),nums[i]);
            if(it==res.end()) res.push_back(nums[i]);
            else *it=nums[i];
        }
        return res.size();
    }
};
