#include<vector>
#include<queue>
#include<set>

using namespace std;

vector<int> dijkstra_Priority_Queue_Method(int V, vector<vector<int>> &edges, int src) {
    // Using Priority Queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap
    vector<vector<pair<int, int>>>adj(V);
    // Creating Adjacency Matrix
    for(int i = 0 ; i < edges.size() ; i++){
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }
    // Starting at src, with distance 0
    pq.push({0, src});
    vector<int>dist(V, INT_MAX);
    dist[src] = 0;
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        int distance = x.first, ind = x.second;
        for(auto i : adj[ind]){
            int weight = i.second, node = i.first;
            // Checking if new distance is smaller than previous one
            if(weight+distance < dist[node]){
                dist[node] = weight + distance;
                pq.push({dist[node], node});
            }
        }
    }
    return dist;
}

vector<int> dijkstra_Set_Method(int V, vector<vector<int>> &edges, int src) {
    set<pair<int, int>>st; // Using a set
    vector<vector<pair<int, int>>>adj(V);
    for(int i = 0 ; i < edges.size() ; i++){
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }
    st.insert({0, src});
    vector<int>dist(V, INT_MAX);
    dist[src] = 0;
    while(!st.empty()){
        auto x = *(st.begin()); // First element of set, since set is ordered
        int distance = x.first, ind = x.second;
        st.erase(x);
        for(auto i : adj[ind]){
            int weight = i.second, node = i.first;
            if(weight+distance < dist[node]){
                if(dist[node] != INT_MAX){
                    st.erase({dist[node], node}); 
                    // If there is already a path to reach node, we don't need that path
                    // since we discovered a new shorter path
                    // So we remove it
                }
                dist[node] = weight + distance;
                st.insert({dist[node], node});
            }
        }
    }
    return dist;
}