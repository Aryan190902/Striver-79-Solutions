#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

vector<vector<int>> solve(vector<vector<int>>&g, vector<vector<int>>&vis, int i, int j){
    int n = g.size(), m = g[0].size();
    vis[i][j] = 1;
    
    queue<pair<int, int>>q;
    q.push({i, j});
    vector<vector<int>>ans;
    
    // using BFS
    while(!q.empty()){
        pair<int, int>p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        ans.push_back({x, y});
        // checking possible 1 in each direction
        if(x+1 < n && !vis[x+1][y] && g[x+1][y] == 1){
            vis[x+1][y] = 1;
            q.push({x+1, y});
        }
        if(y+1 < m && !vis[x][y+1] && g[x][y+1] == 1){
            vis[x][y+1] = 1;
            q.push({x, y+1});
        }
        if(x-1 >= 0 && !vis[x-1][y] && g[x-1][y] == 1){
            vis[x-1][y] = 1;
            q.push({x-1, y});
        }
        if(y-1 >= 0 && !vis[x][y-1] && g[x][y-1] == 1){
            vis[x][y-1] = 1;
            q.push({x, y-1});
        }
    }
    // substracting base value from each element
    // and reinitializing base value to 0,0
    for(int a = 1 ; a < ans.size() ; a++){
        ans[a][0] -= ans[0][0];
        ans[a][1] -= ans[0][1];
    }
    ans[0][0] = 0, ans[0][1] = 0;
    return ans;
}

int countDistinctIslands(vector<vector<int>>& grid) {
    set<vector<vector<int>>>st;
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>>vis(n, vector<int>(m, 0)); // visited array
    // traversing each element in case of multiple islands
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(!vis[i][j] && grid[i][j] == 1){
                st.insert(solve(grid, vis, i, j));
            }
        }
    }
    
    return (int)st.size();
}