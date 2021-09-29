/*
40. Combination Sum II
Medium

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

Constraints:
    1 <= candidates.length <= 100
    1 <= candidates[i] <= 50
    1 <= target <= 30
*/
class Solution {
        vector<vector<int>> res;
    void find(vector<int>& candidates,vector<int>& cand,int target,int begin){
        if(!target){
            res.push_back(cand);
            return;
        }
        for(int i=begin;i<candidates.size() && target>=candidates[i];i++){
            if(i==begin || candidates[i]!=candidates[i-1]){
                cand.push_back(candidates[i]);
                find(candidates,cand,target-candidates[i],i+1);
                cand.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {       res.clear();
        sort(candidates.begin(),candidates.end());
        vector<int> cand;
        find(candidates,cand,target,0);
        return res;
        
    }
};
