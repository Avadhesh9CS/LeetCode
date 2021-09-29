/*
79. Word Search
Medium

Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

Constraints:
    m == board.length
    n = board[i].length
    1 <= m, n <= 6
    1 <= word.length <= 15
    board and word consists of only lowercase and uppercase English letters.

Follow up: Could you use search pruning to make your solution faster with a larger board?
*/
class Solution {
    int m;
    int n;
    bool search(vector<vector<char>>& board,const char* w,int i,int j){
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]=='\0' || *w!=board[i][j])
            return false;
        if(*(w+1)=='\0')
            return true;
        char t=board[i][j];
        board[i][j]='\0';
        if(search(board,w+1,i-1,j) || search(board,w+1,i,j+1) || search(board,w+1,i+1,j) || search(board,w+1,i,j-1))
            return true;
        board[i][j]=t;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(search(board,word.c_str(),i,j))
                    return true;
            }
        }
        return false;
    }
};
