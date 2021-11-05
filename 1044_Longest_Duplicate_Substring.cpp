/*
1044. Longest Duplicate Substring
Hard

Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.
Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".

Example 1:
Input: s = "banana"
Output: "ana"

Example 2:
Input: s = "abcd"
Output: ""

Constraints:
    2 <= s.length <= 3 * 104
    s consists of lowercase English letters.
*/
class Solution {
    int prime = 10000007;
    vector<int> pow;
public:
    string longestDupSubstring(string s) {
        int l=0,h=s.size(),mid;
        pow=vector<int>(h);
        for(int i=0;i<h;i++)pow[i]=(i==0)?1:(26*pow[i-1])%prime;
        string res;
        while(l<=h){
            mid=l+(h-l)/2;
            string temp=helper(s,mid);
            if((int)temp.size()>(int)res.size()){
                res=temp;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return res;
    }
    
    string helper(string s,int len){
        if(len==0)return "";
        int n=s.size(),curr=0;
        unordered_map<int,vector<int>> hash;
        for(int i=0;i<len;i++){
            curr=(26*curr+(s[i]-'a'))%prime;
        }
        hash[curr]={0};
        for(int i=len;i<n;i++){
            curr=(curr-(pow[len-1]*(s[i-len]-'a'))%prime+prime)%prime;
            curr=(curr*26+(s[i]-'a'))%prime;
            if(hash.find(curr)==hash.end()) hash[curr]={i-len+1};
            else{
                for(int index:hash[curr]){
                    if(s.substr(index,len)==s.substr(i-len+1,len)) return s.substr(i-len+1,len);   
                }
                hash[curr].push_back(i-len+1);
            }
        }
        return "";
    }
};
