/*
187. Repeated DNA Sequences
Medium

The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
    For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.
Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

Example 1:
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]

Example 2:
Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]

Constraints:
    1 <= s.length <= 105
    s[i] is either 'A', 'C', 'G', or 'T'.
*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {     
        unordered_map<string,int> m;
        int i=0,j=9;
        vector<string> ans;
        string str;
        if(s.size()<=10) return ans;
        while(j<s.size()){
            str=s.substr(i,10);
            if(m[str]>0){
                ans.push_back(str);
                m[str]=INT_MIN;
            }
            m[str]++;
            i++;
            j++;
        }
        return ans;
    }
};
