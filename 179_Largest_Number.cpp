/*
179. Largest Number
Medium

Given a list of non-negative integers nums, arrange them such that they form the largest number.
Note: The result may be very large, so you need to return a string instead of an integer.

Example 1:
Input: nums = [10,2]
Output: "210"

Example 2:
Input: nums = [3,30,34,5,9]
Output: "9534330"

Example 3:
Input: nums = [1]
Output: "1"

Example 4:
Input: nums = [10]
Output: "10"

Constraints:
    1 <= nums.length <= 100
    0 <= nums[i] <= 109
*/
class Solution {
    struct compare{
        bool operator()(string a,string b){
            return a+b>b+a;
        }
    };
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(int n: nums){
            arr.push_back(to_string(n));
        }
        sort(arr.begin(),arr.end(),compare());
        string ans="";
        for(auto n: arr){
            ans+=n;
        }
        while(ans[0]=='0' && ans.size()>1){
            ans.erase(0,1);
        }
        return ans;
    }
};
