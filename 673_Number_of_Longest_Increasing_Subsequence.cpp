/*
673. Number of Longest Increasing Subsequence
Medium

Given an integer array nums, return the number of longest increasing subsequences.
Notice that the sequence has to be strictly increasing.

Example 1:
Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

Example 2:
Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.

Constraints:
    1 <= nums.length <= 2000
    -106 <= nums[i] <= 106
*/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(),mx=1,ans=0;
        if(n==0)return ans;
        vector<int> dp(n,1),cnt(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[i]<=dp[j]){
                    dp[i]=dp[j]+1;
                    cnt[i]=cnt[j];
                }else if(dp[j]+1==dp[i]){
                    cnt[i]+=cnt[j];
                }
            }
            mx=max(mx,dp[i]);
        }
        for(int i=0;i<n;i++){
            if(dp[i]==mx) ans+=cnt[i];
        }
        return ans;
    }
};
