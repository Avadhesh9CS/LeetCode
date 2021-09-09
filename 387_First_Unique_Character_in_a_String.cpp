/*
387. First Unique Character in a String
Easy

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0

Example 2:

Input: s = "loveleetcode"
Output: 2

Example 3:

Input: s = "aabb"
Output: -1

 

Constraints:

    1 <= s.length <= 105
    s consists of only lowercase English letters.

*/
//Method 1
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> m;
        for(int i=0;s[i]!='\0';i++){
            if(m.count(s[i])){
                m[s[i]]=0;
            }else{
                m[s[i]]=i+1;
            }
        }
        int index=INT_MAX;
        for(auto a:m){
            if(a.second>0 && a.second<index){
                index=a.second;
            }
        }
        return index==INT_MAX?-1:index-1;
    }
};

//Method 2
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (auto &c : s) {
            m[c]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] == 1) return i;
        }
        return -1;
    }
};
