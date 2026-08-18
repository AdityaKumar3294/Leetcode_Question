class Solution {
   public:
    void dfsCheck(int r, int c, vector<vector<char>>& board, vector<vector<int>>& vis, int delRow[4], int delCol[4]){
        
        int n = board.size(), m = board[0].size();
        vis[r][c] = 1;
        
        for(int i=0;i<4;i++){
            int nRow = delRow[i] + r;
            int nCol = delCol[i] + c;

            if(nRow >= 0 && nRow<n && nCol >= 0 && nCol < m && board[nRow][nCol] == 'X' && !vis[nRow][nCol]){
                vis[nRow][nCol] = 1;
                dfsCheck(nRow,nCol,board,vis,delRow,delCol);
            }
        }
    }

    // t.c: O(n*m) + O(n*m * 4)...
    // s.c: O(n+m*2)...
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int delRow[4] = {-1,0,0,1};
        int delCol[4] = {0,-1,1,0};
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'X' && !vis[i][j]){
                    cnt ++;
                    dfsCheck(i,j,board,vis,delRow,delCol);
                }
            }
        }

        return cnt;
    }
};