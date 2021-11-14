/*
324. Wiggle Sort II
Medium

Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
You may assume the input array always has a valid answer.

Example 1:
Input: nums = [1,5,1,1,6,4]
Output: [1,6,1,5,1,4]
Explanation: [1,4,1,5,1,6] is also accepted.

Example 2:
Input: nums = [1,3,2,2,3,1]
Output: [2,3,1,3,1,2]

Constraints:
    1 <= nums.length <= 5 * 104
    0 <= nums[i] <= 5000
    It is guaranteed that there will be an answer for the given input nums.
    
Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        vector<int>::iterator midptr=nums.begin()+n/2;
        nth_element(nums.begin(),midptr,nums.end());
        int mid=*midptr;
        
        int i=(n-1)/2*2,j=i,k=1;
        for(int c=0;c<n;c++){
            if(nums[j]<mid){
                swap(nums[i],nums[j]);
                i-=2;
                j-=2;
            }else if(nums[j]>mid){
                swap(nums[j],nums[k]);
                k+=2;
            }else{
                j-=2;
            }
            if(j<0)j=n/2*2-1;
        }
    }
};
