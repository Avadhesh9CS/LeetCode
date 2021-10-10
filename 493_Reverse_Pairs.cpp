/*
493. Reverse Pairs
Hard

Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

Example 1:
Input: nums = [1,3,2,3,1]
Output: 2

Example 2:
Input: nums = [2,4,3,5,1]
Output: 3

Constraints:
    1 <= nums.length <= 5 * 104
    -231 <= nums[i] <= 231 - 1
*/
class Solution {
    int merge(vector<int>& nums,int l,int m,int h){
        int inv=0,j=m+1;
        for(int i=l;i<=m;i++){
            while(j<=h && nums[i]>2LL*nums[j]) ++j;
            inv+=(j-(m+1));
        }
        vector<int> temp;
        int left=l,right=m+1;
        while(left<=m && right<=h){
            if(nums[left]<=nums[right])temp.push_back(nums[left++]);
            else temp.push_back(nums[right++]);
        }
        while(left<=m)temp.push_back(nums[left++]);
        while(right<=h)temp.push_back(nums[right++]);
        for(int i=l;i<=h;i++){
            nums[i]=temp[i-l];
        }
        return inv;
    }
    int mergesort(vector<int>& nums,int l,int h){
        if(l>=h)return 0;
        int m=l+(h-l)/2;
        int inv=mergesort(nums,l,m);
        inv+=mergesort(nums,m+1,h);
        inv+=merge(nums,l,m,h);
        return inv;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};
