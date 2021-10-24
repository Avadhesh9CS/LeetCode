/*
1081. Smallest Subsequence of Distinct Characters
Medium

Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

Example 1:
Input: s = "bcabc"
Output: "abc"

Example 2:
Input: s = "cbacdcbc"
Output: "acdb"

Constraints:
    1 <= s.length <= 1000
    s consists of lowercase English letters.
Note: This question is the same as 316: https://leetcode.com/problems/remove-duplicate-letters/
*/
class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26,0);
        vector<bool> visited(26,false);
        string ans="";
        int n=s.size();
        for(char c:s){
            freq[c-'a']++;
        }
        for(char c:s){
            freq[c-'a']--;
            if(s.empty()){
                ans.push_back(c);
                visited[c-'a']=true;
                continue;
            }
            if(visited[c-'a']) continue;
            while(!ans.empty() && c<ans.back() && freq[ans.back()-'a']>0){
                visited[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(c);
            visited[c-'a']=true;
        }
        return ans;
    }   
};
