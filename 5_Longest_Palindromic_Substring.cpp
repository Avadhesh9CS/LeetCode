/*
5. Longest Palindromic Substring
Medium

Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Example 3:
Input: s = "a"
Output: "a"

Example 4:
Input: s = "ac"
Output: "a"

Constraints:
    1 <= s.length <= 1000
    s consist of only digits and English letters.
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(),maxlen=INT_MIN,istat;
        if (n <= 1)
            return s;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        string ans="";
        ans+=s[0];
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    if(j - i == 1 || dp[i + 1][j - 1]){
                        dp[i][j] = true;

                        //Check for Longest Palindrome substring
                        if (ans.size() < j - i + 1)
                            ans = s.substr(i, j - i + 1);
                    }   
                }
            }
        }
        return ans;
    }
};
