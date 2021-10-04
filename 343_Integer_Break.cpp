/*
343. Integer Break
Medium

Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
Return the maximum product you can get.

Example 1:
Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.

Example 2:
Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

Constraints:
    2 <= n <= 58
*/
//Method 1
class Solution {
public:
    int integerBreak(int n) {
        if(n<=3) return n-1;
        vector<int> dp(n+1,1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i<=j){
                    if(dp[j]<dp[j-i]*i){
                        dp[j]=dp[j-i]*i;
                        j--;
                    }
                }
            }
        }
        return dp[n];
    }
};
//Method 2
class Solution {
public:
    int integerBreak(int n) {
        if(n<=2) return 1;
        vector<int> dp(n+1,0);
        for(int i=3;i<=n;i++){
            for(int j=1;j<i;j++){
                dp[i]=max(dp[i],max(dp[i-j]*j,j*(i-j)));    
            }
        }
        return dp[n];
    }
};


