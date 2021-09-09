/*
30. Substring with Concatenation of All Words
Hard

You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.

You can return the answer in any order.

 

Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.

Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []

Example 3:

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]

 

Constraints:

    1 <= s.length <= 104
    s consists of lower-case English letters.
    1 <= words.length <= 5000
    1 <= words[i].length <= 30
    words[i] consists of lower-case English letters.

*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int w_len=words[0].length(),s_len=s.length(),w_sz=words.size(),left,count;
        if (w_len * w_sz >s_len) {
            return ans;
        }
        unordered_map<string,int> m,seen;
        for(string word: words){
            m[word]++;
        }

        for(int i=0;i<w_len;i++){
            left=i,count=0;
            seen.clear();
            for(int j=i;j<=s_len-w_len;j+=w_len){
                string word=s.substr(j,w_len);
                if(m.count(word)){
                    seen[word]++;
                    if(seen[word]<=m[word]){
                        count++;
                        
                    }
                    else{
                        while(seen[word]>m[word]){
                            string str=s.substr(left,w_len);
                            seen[str]--;
                            if(seen[str]<m[str]) count--;
                            left+=w_len;
                           // cout<<str<<count<<'\n';
                        }
                    }
                    if(count==w_sz){
                        ans.push_back(left);
                        seen[s.substr(left,w_len)]--;
                        count--;
                        left+=w_len;
                    }
                   
                }
                else{
                    seen.clear();
                    count=0;
                    left=j+w_len;
                }
            }
            
        }
        return ans;
    }
};
