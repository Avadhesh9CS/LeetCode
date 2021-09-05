/*
34. Find First and Last Position of Element in Sorted Array
Medium

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

 

Constraints:

    0 <= nums.length <= 105
    -109 <= nums[i] <= 109
    nums is a non-decreasing array.
    -109 <= target <= 109

*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,mid,s=-1,e=-1;
        while(l<=r){
            mid=l+((r-l)>>1);
            if((mid==0 || nums[mid-1]!=target) && nums[mid]==target){
                s=mid;
                break;
            }else if(nums[mid]<target){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        if(s==-1) return {-1,-1};
        l=s,r=nums.size()-1,mid=0;
        while(l<=r){
            mid=l+((r-l)>>1);
            if((mid==nums.size()-1 || nums[mid+1]!=target) && nums[mid]==target){
                e=mid;
                break;
            }else if(nums[mid]<=target){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return {s,e};
    }
};
