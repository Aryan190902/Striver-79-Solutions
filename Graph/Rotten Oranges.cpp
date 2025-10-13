#include<vector>
#include<queue>

using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>>q; // Queue contains coordinates and time
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0)); // Visited Array

        // Storing already rotten oranges
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        int ans = 0;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int x = p.first.first, y = p.first.second, t = p.second;
            ans = max(ans, t);
            vector<int>l {0,0,1,-1}, r{1,-1,0,0};

            // Checking fresh oranges in all the directions
            for(int i = 0 ; i < 4 ; i++){
                int a = l[i]+x, b = r[i]+y;
                if(a >= 0 && a < n && b >= 0 && b < m && vis[a][b] == 0 && grid[a][b] == 1){
                    vis[a][b] = 1;
                    q.push({{a, b}, t+1});
                }
            }
        }
        
        // To check if all oranges are rotten or not
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    return -1;
                }
            }
        }

        return ans;
    }