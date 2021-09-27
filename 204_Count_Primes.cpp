/*
204. Count Primes
Medium

Given an integer n, return the number of prime numbers that are strictly less than n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:

Input: n = 0
Output: 0

Example 3:

Input: n = 1
Output: 0

Constraints:
    0 <= n <= 5 * 106
*/
class Solution {
public:
    int countPrimes(int n) {
        if(n==0||n==1) return 0;
        vector<bool> Primes(n,true);
        Primes[0]=Primes[1]=false;
        for(int i=0;i<sqrt(n);i++){
            if(Primes[i]){
                for(int j=i*i;j<n;j+=i){
                    Primes[j]=false;
                }
            }
        }
        return count(Primes.begin(), Primes.end(), true);;
    }
};
