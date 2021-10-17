/*
188. Best Time to Buy and Sell Stock IV
Hard

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

Constraints:
    0 <= k <= 100
    0 <= prices.length <= 1000
    0 <= prices[i] <= 1000
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(k<=0 || n<=1) return 0;
        vector<int> buy(k,INT_MIN),sell(k,0);
        buy[0]=-prices[0];
        for(int i=1;i<n;i++){
            for(int j=0;j<k;j++){
                if(j==0){
                    buy[j]=max(buy[j],-prices[i]);
                }else{
                    buy[j]=max(buy[j],sell[j-1]-prices[i]);
                }
                sell[j]=max(sell[j],buy[j]+prices[i]);
            }
        }
        return sell[k-1];
    }
};
