/*
43. Multiply Strings
Medium

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"

Constraints:
    1 <= num1.length, num2.length <= 200
    num1 and num2 consist of digits only.
    Both num1 and num2 do not contain any leading zero, except the number 0 itself.
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        int m=num1.size(),n=num2.size();
        vector<int> res(m+n,0);
        int pro,carry,p1,p2,sum;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                pro=(num1[i]-'0')*(num2[j]-'0');
                p1=i+j,p2=i+j+1;
                sum=pro+res[p2];
                res[p2]=sum%10;
                res[p1]+=sum/10;
            }
        }
        int i=0;
        while(i<m+n && res[i]==0) i++;
        if(i==m+n) return "0";
        string ans="";
        for(;i<m+n;i++){
            ans+=(res[i]+'0');
        }
        return ans;
    }
};
