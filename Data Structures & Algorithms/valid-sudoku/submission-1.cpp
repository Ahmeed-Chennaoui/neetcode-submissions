class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_set<char> col,row;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.' && col.contains(board[i][j]))return false;
                if(board[j][i]!='.' &&row.contains(board[j][i]))return false;
                row.insert(board[j][i]);
                col.insert(board[i][j]);
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                unordered_set<char> square;
                for(int k=0;k<9;k++){
                    int x=i*3+k%3,y=j*3+k/3;
                    if(board[x][y]!='.' && square.contains(board[x][y]))return false;
                    square.insert(board[x][y]);
                }
            }
        }
        return true;
    }
};
