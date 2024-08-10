// Link - https://leetcode.com/problems/regions-cut-by-slashes/description/?envType=daily-question&envId=2024-08-10
// Regions Cut By Slashes


class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>&mat, vector<vector<int>>&vis){
        vis[i][j] = 1;
        int n = mat.size(),m=mat[0].size();
        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};
        for(int k=0; k<4; k++){
            int nrow = i+delr[k], ncol=j+delc[k];
            if(nrow<0 || nrow>=n || ncol<0 || ncol>=m || mat[nrow][ncol]!=0 
            || vis[nrow][ncol]) continue;
            dfs(nrow,ncol,mat,vis);
        }
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>>mat(n*3,vector<int>(n*3,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='/'){
                    mat[i*3][j*3+2] = 1;
                    mat[i*3+1][j*3+1] = 1;
                    mat[i*3+2][j*3] = 1;
                }else if(grid[i][j]=='\\'){
                    mat[i*3][j*3] = 1;
                    mat[i*3+1][j*3+1] = 1;
                    mat[i*3+2][j*3+2] = 1;
                }
            }
        }
            
        int count = 0;
        vector<vector<int>>vis(n*3,vector<int>(n*3,0));
        for(int i=0; i<n*3; i++){
            for(int j=0; j<n*3; j++){
                if(mat[i][j]==0 && !vis[i][j]){
                    count++;
                    dfs(i,j,mat,vis);
                }
            }
        }
        return count;
    }
};  