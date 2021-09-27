/*
264. Ugly Number II
Medium

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

 

Constraints:

    1 <= n <= 1690

*/
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==0||n==1) return n;
        int t2=0,t3=0,t5=0;
        vector<int> ugly(n);
        ugly[0]=1;
        for(int i=1;i<n;i++){
            ugly[i]=min(ugly[t2]*2,min(ugly[t3]*3,ugly[t5]*5));
            if(ugly[t2]*2==ugly[i]) t2++;
            if(ugly[t3]*3==ugly[i]) t3++;
            if(ugly[t5]*5==ugly[i]) t5++;
        }
        return ugly[n-1];
    }
};
