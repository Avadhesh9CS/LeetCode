/*
1239. Maximum Length of a Concatenated String with Unique Characters
Medium

You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.
Return the maximum possible length of s.
A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.

Example 2:
Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").

Example 3:
Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.

Example 4:
Input: arr = ["aa","bb"]
Output: 0
Explanation: Both strings in arr do not have unique characters, thus there are no valid concatenations.

Constraints:
    1 <= arr.length <= 16
    1 <= arr[i].length <= 26
    arr[i] contains only lowercase English letters.
*/
class Solution {
    int hash(string s){
        int val=0,d;
        for(char a:s){
            d=a-'a';
            if(val & 1<<d){
                return -1;
            }else{
                val|=1<<d;
            }
        }
        return val;
    }
    int helper(int x,vector<int> &h_val){
        int i=0,val=0;
        while(x){
            if(x&1){
                if(h_val[i]!=-1 && ((val & h_val[i])==0))   {
                   val|=h_val[i];
                }else{
                    return 0;
                }
            }
            x>>=1;
            i++;
        }
        return count(val);
    }
    int count(int val){
        int c=0;
        while(val){
            val&=(val-1);
            c++;
        }
        return c;
    }
public:
    int maxLength(vector<string>& arr) {
        vector<int> h_val;
        for(auto s:arr){
            h_val.push_back(hash(s));
        }
        int mx=0;
        for(int i=0;i<(1<<arr.size());i++){
            int y=helper(i,h_val);
            mx=max(mx,y);
        }
        return mx;
    }
};
