class Solution {
     int rows, cols;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0},
                                         {0, 1}, {0, -1}};
public:
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        capture(board);

        for(int r =0;r<rows;r++){
            for(int c =0;c<cols;c++){
                if(board[r][c] == 'O'){
                    board[r][c] = 'X';
                }else if(board[r][c] == 'T'){
                    board[r][c] = 'O';
                }
            }
        }
    }
private:
    void capture(vector<vector<char>>& board){
        queue<pair<int,int>> q;
        for(int r=0;r<rows;r++){
            for(int c =0;c<cols;c++){
                if((r==0 || r == rows -1 || c == 0 || c == cols -1) && board[r][c] == 'O'){
                    q.push({r,c});
                }
            }
        }
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            if(board[r][c] == 'O'){
                board[r][c] = 'T';
                for(auto& direction : directions){
                    int nr = r + direction.first;
                    int nc = c + direction.second;
                    if (nr >= 0 && nr < rows &&
                        nc >= 0 && nc < cols) {
                        q.push({nr, nc});
                    }
                }
            }
        }
    }
};
