#include<vector>
#include<queue>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>>adj(numCourses);
    vector<int>indegree(numCourses, 0);
    queue<int>q;
    
    // Creating Adjacency array, and storing indegree
    for(vector<int>i : prerequisites){
        adj[i[1]].push_back(i[0]);
        indegree[i[0]]++;
    }

    // Pushing numbers with indegree = 0
    for(int i = 0 ; i < numCourses ; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    // Using Kahn's Algorithm (Topological sort)
    vector<int>ans;
    while(!q.empty()){
        int ind = q.front();
        q.pop();
        ans.push_back(ind);
        for(int i : adj[ind]){
            indegree[i]--;
            if(indegree[i] == 0){
                q.push(i);
            }
        }
    }
    if(ans.size() == numCourses)    return ans;
    return {};
}