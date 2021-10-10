/*
212. Word Search II
Hard

Given an m x n board of characters and a list of strings words, return all words on the board.
Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

Example 1:
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]

Example 2:
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []

Constraints:
    m == board.length
    n == board[i].length
    1 <= m, n <= 12
    board[i][j] is a lowercase English letter.
    1 <= words.length <= 3 * 104
    1 <= words[i].length <= 10
    words[i] consists of lowercase English letters.
    All the strings of words are unique.
*/
class TrieNode{
    public:
    bool isEnd;
    vector<TrieNode*> child;
    TrieNode(){
        isEnd=false;
        child=vector<TrieNode*>(26,NULL);
    }
};
class Trie{
    private:
        TrieNode* root;
    public:
        TrieNode* getRoot(){return root;}
        Trie(vector<string> &words){
            root=new TrieNode();
            for(auto w:words){
                addWord(w);
            }
        }
        void addWord(const string& word){
            TrieNode* curr=root;
            for(int i=0;i<word.size();i++){
                if(curr->child[word[i]-'a']==NULL){
                    curr->child[word[i]-'a']=new TrieNode();
                }
                curr=curr->child[word[i]-'a'];
            }
            curr->isEnd=true;
        }
};
class Solution {
    int m,n;
    set<string> resultset;
    public:
    void search(vector<vector<char>>& board, TrieNode* root,string w,int i,int j){
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]=='\0')
            return;
        if(root->child[board[i][j]-'a']!=NULL){
            w+=board[i][j];
            root=root->child[board[i][j]-'a'];
            if(root->isEnd) resultset.insert(w);
            char t=board[i][j];
            board[i][j]='\0';
            search(board,root,w,i-1,j);
            search(board,root,w,i,j+1); 
            search(board,root,w,i+1,j);
            search(board,root,w,i,j-1);
            board[i][j]=t;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie=new Trie(words);
        TrieNode* root=trie->getRoot();
        m=board.size(),n=board[0].size();
        vector<string> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                search(board,root,"",i,j);
                }
            }
        for(auto it:resultset){
            ans.push_back(it);
        }
        return ans;
    }
};
