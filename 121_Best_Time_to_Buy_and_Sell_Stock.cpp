/*
121. Best Time to Buy and Sell Stock
Easy

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

 

Constraints:

    1 <= prices.length <= 105
    0 <= prices[i] <= 104

*/
/*class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()){return false;}
        int k=s1.length();
        if(k==0) return true;
        unordered_map<char,int>record,seen;
        for(int i=0;i<k;i++){
            record[s1[i]]++;
            seen[s2[i]]++;
        }
        if(record==seen){
            return true;
        }
        
        for(int i=k;i<s2.length();i++){
            if(seen[s2[i-k]]==1){
                seen.erase(s2[i-k]);
            }else{
                seen[s2[i-k]]--;
            }
            seen[s2[i]]++;
            if(record==seen){
                return true;
            }
        }
        return false;
    }
};*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int map[26] = {0};
        for(char c : s1) map[c - 'a']++;
        int j = 0, i = 0, count_chars = s1.size();
        while(j < s2.size()){
            if(map[s2.at(j++) - 'a']-- > 0)
                count_chars--;
            if(count_chars == 0) return true;
            if(j - i == s1.size() && map[s2.at(i++) - 'a']++ >= 0)
                count_chars++;
        }
        return false;
    }
};
