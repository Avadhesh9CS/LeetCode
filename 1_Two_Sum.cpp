/*
1. Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:

    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.

*/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> no;
        int count=0;
        vector<int> output;
        for(auto it=nums.begin();it!=nums.end();it++){
          no[*it]=count;
          count++;
        }
        for(int i=0;i<count;i++){
          if(no.count(target-nums[i])>0){
            int a=no.find(target-nums[i])->second;
            if(i!=a){
            output.push_back(i);
            output.push_back(a);
            break;
            }
          }
        } 
        return output;
    }
};
int main(){
  vector<int> num;
  int n,target;
  cin>>n;
  for(int i=0;i<n;i++){
    int t;
    cin>>t;
    num.push_back(t);
  }
  cin>>target;
  Solution s;
  vector<int> output=s.twoSum(num,target);
  for(int i=0;i<2;i++){
    cout<<output[i]<<endl;
  }
  return 0;
}

