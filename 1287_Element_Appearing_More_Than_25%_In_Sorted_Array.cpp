/*
1287. Element Appearing More Than 25% In Sorted Array
Easy

Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

Example 1:
Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6

Example 2:
Input: arr = [1,1]
Output: 1

Constraints:
    1 <= arr.length <= 104
    0 <= arr[i] <= 105
*/
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int sz=arr.size();
        vector<int> candidate={arr[sz/4],arr[sz/2],arr[sz*3/4]};
        for(auto c:candidate){
            auto l=lower_bound(arr.begin(),arr.end(),c);
            auto u=upper_bound(arr.begin(),arr.end(),c);
            if(4*(u-l)>sz)
                return c;
        }
        return -1;
    }
};
