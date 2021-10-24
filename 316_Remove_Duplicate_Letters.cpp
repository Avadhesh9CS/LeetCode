/*
316. Remove Duplicate Letters
Medium

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example 1:
Input: s = "bcabc"
Output: "abc"

Example 2:
Input: s = "cbacdcbc"
Output: "acdb"

Constraints:
    1 <= s.length <= 104
    s consists of lowercase English letters.

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
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
