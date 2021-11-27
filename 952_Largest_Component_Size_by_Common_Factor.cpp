/*
952. Largest Component Size by Common Factor
Hard

You are given an integer array of unique positive integers nums. Consider the following graph:
    There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
    There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.
Return the size of the largest connected component in the graph.

Example 1:
Input: nums = [4,6,15,35]
Output: 4

Example 2:
Input: nums = [20,50,9,63]
Output: 2

Example 3:
Input: nums = [2,3,6,7,4,12,21,39]
Output: 8

Constraints:
    1 <= nums.length <= 2 * 104
    1 <= nums[i] <= 105
    All the values of nums are unique.
*/
class UnionFind{
    private:
        vector<int> parent;
    public:    
        UnionFind(int n){
            for(int i=0;i<n;i++){
                parent.push_back(i);
            }
        }
    void Union(int x,int y){
        parent[find(x)]=parent[find(y)];
    }
    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
};

class Solution {
  
public:
    int largestComponentSize(vector<int>& nums) {
        int n=*max_element(nums.begin(),nums.end());
        UnionFind ufs(n+1);
        for(int a: nums){
            for(int k=2;k<=sqrt(a);k++){
                if(a%k==0){
                    ufs.Union(a,k);
                    ufs.Union(a,a/k);
                }
            }
        }
        unordered_map<int,int> umap;
        int ans=1;
        for(int a:nums){
            ans=max(ans,++umap[ufs.find(a)]);
        }
        return ans;
    }
};
