#include<vector>
#include<queue>

using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    // Creating Adjacency Matrix
    vector<vector<pair<int, int>>>adj(n);
    for(int i = 0 ; i < flights.size() ; i++){
        adj[flights[i][0]].push_back({flights[i][1], flights[i][2]}); // Storing node & their price
    }

    queue<pair<int, pair<int, int>>>q;
    vector<int>price(n, INT_MAX);
    price[src] = 0;
    q.push({0,{0,src}}); // stop, price and node
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        int stop = x.first, nodePrice = x.second.first, node = x.second.second;
        for(auto i : adj[node]){
            int adjNode = i.first, adjPrice = i.second;
            if(stop > k) continue;

            if(adjPrice + nodePrice < price[adjNode]){
                price[adjNode] = adjPrice + nodePrice;
                q.push({stop+1, {price[adjNode], adjNode}});
            }
        }
    }
    if(price[dst] == INT_MAX)    return -1;
    return price[dst];
}