/*
977. Squares of a Sorted Array
Easy

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]


Constraints:

    1 <= nums.length <= 104
    -104 <= nums[i] <= 104
    nums is sorted in non-decreasing order.

 
Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int index2=lower_bound(nums.begin(),nums.end(),0)-nums.begin();
        int index1=index2-1;
        vector<int> ans;
        while(index1>=0 && index2<nums.size()){
            if(abs(nums[index1])<abs(nums[index2])){
                ans.push_back(nums[index1]*nums[index1]);
                index1--;
            }else{
                ans.push_back(nums[index2]*nums[index2]);
                index2++;
            }
        }
        while(index1>=0){
            ans.push_back(nums[index1]*nums[index1]);
            index1--;
        }
        while(index2<nums.size()){
            ans.push_back(nums[index2]*nums[index2]);
            index2++;
        }
        return ans;
    }
};

//Method 2
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int l=0,h=nums.size()-1;
        for(int k=nums.size()-1;k>=0;k--){
            if(abs(nums[l])>abs(nums[h])){ans[k]=nums[l]*nums[l++];}
            else{ans[k]=nums[h]*nums[h--]; }
        }
        return ans;
    }
};
