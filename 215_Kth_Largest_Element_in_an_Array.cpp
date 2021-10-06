/*
215. Kth Largest Element in an Array
Medium

Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

Constraints:
    1 <= k <= nums.length <= 104
    -104 <= nums[i] <= 104
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int i=0,n=nums.size();
        priority_queue<int> pq;
        for(;i<k;i++){
            pq.push(-1*nums[i]);
        }
        for(;i<n;i++){
            if(-1*pq.top()<nums[i]){
                pq.push(-1*nums[i]);
                pq.pop();
            }
        }
        return -1*pq.top();
    }
};
