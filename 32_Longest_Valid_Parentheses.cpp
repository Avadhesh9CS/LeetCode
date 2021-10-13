/*
32. Longest Valid Parentheses
Hard
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:
Input: s = ""
Output: 0

Constraints:
    0 <= s.length <= 3 * 104
    s[i] is '(', or ')'.
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int len=0,n=s.size(),res=0,c=0;
        if(n==0)return 0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') c++;
            else c--;
            if(c<0){
                c=0;
                len=0;
            }else{
                len++;
                if(c==0) res=max(res,len);
            }
        }
        c=0,len=0;
         for(int i=n-1;i>=0;i--){
            if(s[i]==')') c++;
            else c--;
            if(c<0){
                c=0;
                len=0;
            }else{
                len++;
                if(c==0) res=max(res,len);
            }
        }
        return res;
    }
};
