//20. Valid Parentheses
/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false

Example 4:

Input: s = "([)]"
Output: false

Example 5:

Input: s = "{[]}"
Output: true

Constraints:

    1 <= s.length <= 104
    s consists of parentheses only '()[]{}'.
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isValid(string s) {
      stack<char> st;
      for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
          //cout<<"push "<<s[i]<<'\n';
          st.push(s[i]);
        }else if(st.size()>0 &&(st.top()=='(' && s[i]==')'
                || st.top()=='{' && s[i]=='}'
                || st.top()=='[' && s[i]==']')){
          //cout<<"pop "<<s[i]<<'\n';
          st.pop();
        }else{
          //cout<<"pattern mismatch\n";
          return false;
        }
      }
      //cout<<"Success\n";
      if(st.size()>0){
        return false;
      }
      return true;   
    }
};
int main(){
  string s;
  cin>>s;
  Solution s1;
  cout<<s1.isValid(s);
}
