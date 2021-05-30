//58. Length of Last Word
/*
Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.
A word is a maximal substring consisting of non-space characters only.

Example 1:
Input: s = "Hello World"
Output: 5

Example 2:
Input: s = " "
Output: 0

Constraints:
    1 <= s.length <= 104
    s consists of only English letters and spaces ' '.
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
       int i,j=s.length()-1;
        while(j>=0 && s[j]==' '){
          --j;
        }
        for(i=j;i>=0;i--){
          if(s[i]==' '){
            return j-i;
          }
        }
        if(i==-1){
          return ++j;
        }
      return 0; 
    }
};
int main(){
  string str;
  getline(cin,str);
  //cout<<str;
  Solution s;
  cout<<s.lengthOfLastWord(str)<<endl;
}