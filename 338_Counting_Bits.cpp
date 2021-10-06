/*
338. Counting Bits
Easy

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

Example 1:
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

Example 2:
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101

Constraints:
    0 <= n <= 105
    
Follow up:
    It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
    Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?
*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        res.push_back(0);
        if(n==0)return res;
        res.push_back(1);
        if(n==1) return res;
        int i=1;
        while(res.size()<=n){
            res.push_back(res[i]);
            if(res.size()==n+1) break;
            res.push_back(res[i]+1);
            i++;
        }
        return res;
    }
};
