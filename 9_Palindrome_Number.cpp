//9. Palindrome Number
/*
Given an integer x, return true if x is palindrome integer.
An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.

Example 1:

Input: x = 121
Output: true

Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Example 4:

Input: x = -101
Output: false

Constraints:

    -2^31 <= x <= 2^31 - 1
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
      if(x<0){
         return false;
      }
      int rev=0,temp=x;
      while(x){
         if (rev > (INT_MAX / 10) || rev < (INT_MIN / 10)){
                return false;
            }
         rev=rev*10+x%10;
         x/=10;
      }
      if(rev==temp)
         return true;
      return false;
    }
};
int main(){
   int x;
   cin>>x;
   Solution s;
   cout<<s.isPalindrome(x);
}