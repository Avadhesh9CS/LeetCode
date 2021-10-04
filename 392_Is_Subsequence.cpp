/*
392. Is Subsequence
Easy

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false

Constraints:
    0 <= s.length <= 100
    0 <= t.length <= 104
    s and t consist only of lowercase English letters.
    
Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sl=s.size(),tl=t.size();
        if(sl==0)return true;
        if(sl!=0 && tl==0) return false;
        vector<bool> dp(tl,true);
        bool pre,temp;
        for(int i=0;i<sl;i++){
            pre=i==0?true:false;
            for(int j=0;j<tl;j++){
                temp=dp[j];
                if(s[i]==t[j]){
                    dp[j]=pre;
                }else{
                    dp[j]=j==0?false:dp[j-1];
                }
                pre=temp;
            }
        }
        return dp[tl-1];
    }
};
//Two pointer approch
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == m ? 1 : 0;
    }
};
