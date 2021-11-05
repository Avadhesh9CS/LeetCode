/*
127. Word Ladder
Hard

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

    Every adjacent pair of words differs by a single letter.
    Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
    sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

Constraints:
    1 <= beginWord.length <= 10
    endWord.length == beginWord.length
    1 <= wordList.length <= 5000
    wordList[i].length == beginWord.length
    beginWord, endWord, and wordList[i] consist of lowercase English letters.
    beginWord != endWord
    All the words in wordList are unique.
*/
//Method 1

class Solution {
    bool check(string a,string b){
        int count=0,i=0;
        while(i<a.size()){
            if(a[i]!=b[i]) count++;
            i++;
        }
        return count==1?true:false;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int endNode=-1,startNode=-1;
        for(int i=0;i<wordList.size();i++){
            if(wordList[i]==endWord){
                endNode=i;
            }
        }
        if(endNode==-1) return 0;
        wordList.push_back(beginWord);
        startNode=wordList.size()-1;
        vector<vector<int>> graph(wordList.size());
         for(int i=0;i<wordList.size();i++){
              for(int j=i+1;j<wordList.size();j++){
                  if(check(wordList[i],wordList[j])){
                      graph[i].push_back(j);
                      graph[j].push_back(i);
                  }
              }
         }
        vector<bool> visited(wordList.size(),false);
        queue<int> q;
        q.push(startNode);
        visited[startNode]=true;
        int curr=1,next=0,step=0,t;
        while(!q.empty()){
            if(curr==0){
                step++;
                curr=next;
                next=0;
            }
            t=q.front();
            q.pop();
            curr--;
            if(t==endNode){
                return step+1;
            }
            for(auto n:graph[t]){
                if(!visited[n]){
                    q.push(n);
                    visited[n]=true;
                    next++;
                }
            }
        }
        return 0;
    }
};

//Method 2
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> uset;
        int endNode=-1;
        for(int i=0;i<wordList.size();i++){
            uset.insert(wordList[i]);
            if(wordList[i]==endWord){
                endNode=i;
            }
        }
        if(endNode==-1) return 0;
        queue<string> q;
        q.push(beginWord);
        string t;
        char c;
        int next=0,curr=1,step=0;
        while(!q.empty()){
            if(curr==0){
                step++;
                curr=next;
                next=0;
            }
            t=q.front();
            q.pop();
            curr--;
            if(t==endWord){
                return step+1;
            }
            for(int i=0;i<t.size();i++){
                c=t[i];
                for(int j=0;j<26;j++){
                    t[i]=j+'a';
                    auto it=uset.find(t);
                    if(it!=uset.end()){
                        q.push(t);
                        uset.erase(it);
                        next++;
                    }
                }
                t[i]=c;
            }
        }
        return 0;
    }
};
