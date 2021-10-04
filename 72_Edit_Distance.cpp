/*
72. Edit Distance
Hard

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
    Insert a character
    Delete a character
    Replace a character

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

Constraints:
    0 <= word1.length, word2.length <= 500
    word1 and word2 consist of lowercase English letters.
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size(),temp,pre;
        if(n==0 || m==0){
            return max(m,n);
        }
        if(m>n){
            swap(word1,word2);
            swap(m,n);
        }
        vector<int> dp(m,0);
        for(int i=0;i<m;i++){
            dp[i]=i+1;
        }
        for(int i=0;i<n;i++){
            pre=i;
            for(int j=0;j<m;j++){
                temp=dp[j];
                if(word2[i]!=word1[j]){
                    dp[j]=1+min({pre,j==0?pre+1:dp[j-1],dp[j]});
                }else{
                    dp[j]=pre;
                }
                pre=temp;
            }
        }
        return dp[m-1];
    }
};
