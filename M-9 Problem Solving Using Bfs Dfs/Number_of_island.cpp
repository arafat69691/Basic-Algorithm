/*
 Author : YEASIN ARAFAT
 DATE : 9-30-2024
 SOURCE : https://leetcode.com/problems/number-of-islands/
*/
class Solution {
public:
    bool vis[300][300];
    vector<pair<int,int>> d={{0,1},{0,-1},{-1,0},{1,0}};
    int n,m;
    int ans = 0 ;
    bool valid(int si ,int sj ){
        if(si>=0 && si<n && sj>=0 && sj<m) return true;
        else return false;
    }
    void dfs(int si , int sj ,vector<vector<char>>& grid)
    {
        vis[si][sj]=true;
        for(int i =0 ; i<4 ; i++)
        {
            int ci = si+d[i].first;
            int cj=sj+d[i].second;
            if(valid(ci,cj) && vis[ci][cj]==false && grid[ci][cj]=='1')
            {
                dfs(ci,cj,grid);
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        memset(vis,false,sizeof(vis));
        n=grid.size();
        m=grid[0].size();
        for(int i = 0 ; i<n; i++)
        {
            for(int j =0 ; j<m; j++)
            {
                if(vis[i][j]==false &&grid[i][j]=='1')
                {
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
    return ans;
    }
};