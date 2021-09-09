/*
383. Ransom Note
Easy

Given two stings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true

 

Constraints:

    1 <= ransomNote.length, magazine.length <= 105
    ransomNote and magazine consist of lowercase English letters.

*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int i=0;
        unordered_map<char,int> m;
        for(i=0;i<magazine.length();i++){
            m[magazine[i]]++;
        }
        for(i=0;i<ransomNote.length();i++){
            if(m[ransomNote[i]]==0) return false;
            m[ransomNote[i]]--;
        }
        return true;
    }
};
