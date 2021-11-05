/*
287. Find the Duplicate Number
Medium

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.

Example 1:
Input: nums = [1,3,4,2,2]
Output: 2

Example 2:
Input: nums = [3,1,3,4,2]
Output: 3

Example 3:
Input: nums = [1,1]
Output: 1

Example 4:
Input: nums = [1,1,2]
Output: 1

Constraints:
    1 <= n <= 105
    nums.length == n + 1
    1 <= nums[i] <= n
    All the integers in nums appear only once except for precisely one integer which appears two or more times.

Follow up:
    How can we prove that at least one duplicate number must exist in nums?
    Can you solve the problem in linear runtime complexity?
*/
//Method 1
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int p = 0; p < 32; ++ p) {
            int bit = (1 << p), a = 0, b = 0;
            for (int i = 0; i < n; i++) {
                if (i & bit) ++a;
                if (nums[i] & bit) ++b;
            }
            if (b > a) res += bit;
        }
        return res;
    }
};
//Method 2
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    
       int slow=nums[0],fast=nums[nums[0]];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        fast=0;
        while(fast!=slow){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};
