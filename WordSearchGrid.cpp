#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int r[4]={1,-1,0,0};
    int c[4]={0,0,1,-1};
    bool helper(vector<vector<char>>& board, string word, int index, int row, int col ){
        if(index==word.size())
        return true;
        int m=board.size();
        int n=board[0].size();
        char ch=board[row][col];
        board[row][col]='$';
        for(int i=0; i<4; i++){
            int nr=row+r[i];
            int nc=col+c[i];
            if(nr<m && nr>=0 && nc>=0 && nc<n){
                if(board[nr][nc]==word[index]){
                    if(helper(board, word, index+1, nr, nc)){
                        return true;
                    }
                }
            }
        }
        board[row][col]=ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]==word[0]){
                    if(helper(board, word, 1, i, j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};