/*
128. Longest Consecutive Sequence
Medium

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Constraints:
    0 <= nums.length <= 105
    -109 <= nums[i] <= 109
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashset;
        for(auto n:nums){
            hashset.insert(n);
        }
        int ans=0,curr,clen;
        for(auto n:nums){
            if(!hashset.count(n-1)){
                curr=n;
                clen=1;
                while(hashset.count(n+1)){
                    n+=1;
                    clen++;
                }
                ans=max(ans,clen);
            }
        }
        return ans;
    }
};
