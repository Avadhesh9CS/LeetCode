/*
583. Delete Operation for Two Strings
Medium

Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
In one step, you can delete exactly one character in either string.

Example 1:
Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

Example 2:
Input: word1 = "leetcode", word2 = "etco"
Output: 4

Constraints:
    1 <= word1.length, word2.length <= 500
    word1 and word2 consist of only lowercase English letters.
*/
class Solution {
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size(),pre,temp;
        if(m>n) {
            swap(text1,text2);
            swap(m,n);
        }
        vector<int> dp(m,0);
        for(int i=0;i<n;i++){
            pre=0;
            for(int j=0;j<m;j++){
                temp=dp[j];                
                if(text2[i]==text1[j]){
                    dp[j]=1+pre;
                }else{
                    dp[j]=max(dp[j],j==0?pre:dp[j-1]);
                }
                pre=temp;
            }
        }
        return dp[m-1];
    }
public:
    int minDistance(string word1, string word2) {
        return word1.size()+word2.size()-2*longestCommonSubsequence(word1,word2);
    }
};
