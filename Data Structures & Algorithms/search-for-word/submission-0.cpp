class Solution {
public:
    int rows , cols;
    bool dfs(vector<vector<char>>& board,string& word,int row,int col,int index){
        if(index == word.size()){
            return true;
        }

        if(row < 0 || row >= rows || col < 0 || col >= cols){
            return false;
        }

        if(board[row][col] != word[index]){
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '#';

        bool found = 
            dfs(board,word,row + 1,col,index + 1)||
            dfs(board,word,row - 1,col,index+ 1)||
            dfs(board,word,row,col + 1,index + 1)||
            dfs(board,word,row,col - 1,index + 1);

        board[row][col] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for(int i=0;i<rows;i++){
            for(int j =0;j<cols;j++){
                if(board[i][j] == word[0]){
                    if(dfs(board,word,i,j,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
