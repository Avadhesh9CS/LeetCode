//67. Add Binary
/*
Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"

Constraints:
    1 <= a.length, b.length <= 104
    a and b consist only of '0' or '1' characters.
    Each string does not contain leading zeros except for the zero itself.
*/
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string s="";
        bool ad,bd,carry=0,sum=0;
        int i=a.length()-1,j=b.length()-1;
        for(;i>=0 || j>=0;i--,j--){
          ad=i>=0?a[i]-'0':0;
          bd=j>=0?b[j]-'0':0;
          sum=ad^bd^carry;
          carry=ad&bd | bd& carry | carry&ad;
          s=(char)('0'+sum)+s;
        }
        if(carry){
          s=(char)('0'+carry)+s;
        }
      return s;
    }
};
int main(){
  string a,b;
  cin>>a>>b;
  Solution s;
  cout<<s.addBinary(a,b);
  return 0;
}