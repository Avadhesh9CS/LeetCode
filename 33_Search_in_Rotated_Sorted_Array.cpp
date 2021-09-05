/*
33. Search in Rotated Sorted Array
Medium

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:

Input: nums = [1], target = 0
Output: -1

 

Constraints:

    1 <= nums.length <= 5000
    -104 <= nums[i] <= 104
    All values of nums are unique.
    nums is guaranteed to be rotated at some pivot.
    -104 <= target <= 104

*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,mid;
        while(l<r){
            mid=l+((r-l)>>1);
            if((nums[0]>target) ^ (nums[0]>nums[mid]) ^ (target>nums[mid])){
                l=mid+1;   
            }else{
                r=mid;
            }
        }
        return (l==r && nums[l]==target)?l:-1;
    }
};

class Solution {
public:
    int search(vector<int>& a, int target) {
        int s = 0;
        int e = a.size() - 1;
        while(s <= e) {
            int mid = (s+e) / 2;
            if(a[mid] == target)
                return mid;
            
            if(a[s] <= a[mid]) {
                if(target >= a[s] && target <= a[mid])
                    e = mid - 1;
                else 
                    s = mid + 1;
            }
            else {
                if(target <= a[e] && target >= a[mid])
                    s = mid + 1;
                else 
                    e = mid - 1;
            }
        }
        return -1;
    }
};
