#include<vector>
using namespace std;

// This algorithm is used when we need to have shortest distance from multiple sources
void floydWarshall(vector<vector<int>> &dist) {
    int n = dist.size();
    for(int a = 0 ; a < n ; a++){
        // Traveling from source to destination via a
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(a == i || a == j)    continue; // since there is no point to calculate that
                if(dist[i][a] == 1e8 || dist[a][j] == 1e8)  continue; // To avoid getting wrong ans, due to negative values
                dist[i][j] = min(dist[i][j], dist[i][a] + dist[a][j]);
            }
        }
    }
    /*
    Checking negative cycle
    The distance from itself will be 0, if it is less that means there is a negative cycle
    for(int i = 0 ; i < n ; i++){
        if(dist[i][i] < 0)  cout << "Negative Cycle detected!";
    }
    */
}