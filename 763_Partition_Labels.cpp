/*
763. Partition Labels
Medium

You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.
Return a list of integers representing the size of these parts.

Example 1:
Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.

Example 2:
Input: s = "eccbbbbdec"
Output: [10]

Constraints:
    1 <= s.length <= 500
    s consists of lowercase English letters.
*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res, pos(26,0);
        for(int i=0;i<s.size();i++) pos[s[i]-'a']=i;
        for(int i=0,idx=INT_MIN,last_i=0;i<s.size();i++){
            idx=max(idx,pos[s[i]-'a']); 
            if(idx==i)res.push_back(i-exchange(last_i,i+1)+1);
        }
        return res;
    }
};
