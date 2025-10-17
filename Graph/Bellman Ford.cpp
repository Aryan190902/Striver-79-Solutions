#include<vector>

using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    // Creating distance vector
    // Bellman ford algo is used to check for negative cycles, or when weights are negative
    vector<int>dist(V, 1e8);
    dist[src] = 0;
    // Looping for N-1 times, to get shortest distance
    for(int i = 0 ; i < V-1 ; i++){
        for(int j = 0 ; j < edges.size() ; j++){
            int x = edges[j][0], y = edges[j][1], w = edges[j][2];
            if(dist[x] == 1e8)    continue;
            if(dist[x] + w < dist[y]){
                dist[y] = dist[x] + w;
            }
        }
    }
    // Nth loop to check if negative cycle exists
    for(int j = 0 ; j < edges.size() ; j++){
        int x = edges[j][0], y = edges[j][1], w = edges[j][2];
        if(dist[x] == 1e8)    continue;
        if(dist[x] + w < dist[y]){
            return {-1};
        }
    }
    
    return dist;
}