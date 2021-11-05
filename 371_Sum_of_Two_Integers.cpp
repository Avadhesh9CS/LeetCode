/*
371. Sum of Two Integers
Medium

Given two integers a and b, return the sum of the two integers without using the operators + and -.

Example 1:
Input: a = 1, b = 2
Output: 3

Example 2:
Input: a = 2, b = 3
Output: 5

Constraints:
    -1000 <= a, b <= 1000
*/
//Method 1
class Solution {
public:
    int getSum(int a, int b) {
        return log2(pow(2,a)*pow(2,b)) ;
    }
};
//Method2
class Solution {
public:
    int getSum(int a, int b) {
        bool sum=0,carry=0,x,y;
        int ans=0;
        for(int i=0;i<32;i++){
            x=a&(1<<i);
            y=b&(1<<i);
            sum=x^y^carry;
            carry=(x&y)|(x&carry)|(y&carry);
            ans|=(sum<<i);
        }
        return ans;
    }
};
