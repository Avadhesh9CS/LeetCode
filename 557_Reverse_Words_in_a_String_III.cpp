/*
557. Reverse Words in a String III
Easy

Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Example 2:

Input: s = "God Ding"
Output: "doG gniD"

Constraints:
    1 <= s.length <= 5 * 104
    s contains printable ASCII characters.
    s does not contain any leading or trailing spaces.
    There is at least one word in s.
    All the words in s are separated by a single space.
*/
class Solution {
    void reverseString(string &s,int l,int r) {
        while(l<r){
            s[l]=s[l]^s[r];
            s[r]=s[l]^s[r];
            s[l]=s[l]^s[r];
            l++;
            r--;
        }
    }
public:
    string reverseWords(string s) {
        int l=0,r=0;
        while(r<s.length()){
            if(s[r]==' '){
                reverseString(s,l,r-1);
                l=r+1;
            }
            r++;
        }
       reverseString(s,l,r-1); 
       return s;
    }
};
