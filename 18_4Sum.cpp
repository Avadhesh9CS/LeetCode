/*
18. 4Sum
Medium

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

    0 <= a, b, c, d < n
    a, b, c, and d are distinct.
    nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

 

Constraints:

    1 <= nums.length <= 200
    -109 <= nums[i] <= 109
    -109 <= target <= 109
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n=nums.size();
        if(n<3) return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            int target1=target-nums[i];
            if(i>0 && nums[i]==nums[i-1]){continue;}
            if(nums[i+2]+nums[i+3]>target1-nums[i+1])break;
            if(nums[n-2]+nums[n-3]<target1-nums[n-1]) continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && nums[j]==nums[j-1])continue;
                int target2=target1-nums[j];
                if(nums[j+1]+nums[j+2]>target2)break;
                if(nums[n-2]+nums[n-1]<target2)continue;
                int low=j+1,high=n-1;
                while(low<high){
                    int num=nums[low]+nums[high];
                    if(num<target2) low++;
                    else if(num>target2) high--;
                    else{   
                     ans.push_back({nums[i],nums[j],nums[low],nums[high]});
                     while(low<high && nums[low]==nums[low+1])low++;
                     while(low<high && nums[high]==nums[high-1])high--;
                     low++;    
                     high--;   
                    }
                }
            }
        }
        return ans;
    }
};
