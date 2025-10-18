#include<vector>
#include<string>
#include<map>
#include<queue>

using namespace std;

bool check(string &a, string &b){
    int cnt = 0;
    for(int i = 0 ; i < a.size() ; i++){
        if(a[i] != b[i]){
            cnt++;
        }
        if(cnt > 1) return false;
    }
    return cnt == 1;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    map<int, vector<int>>mp;
    int bInd = -1; // beginWord index
    int n = wordList.size();
    for(int i = 0 ; i < n ; i++){
        if(wordList[i] == beginWord){
            bInd = i;
        }
        for(int j = i+1 ; j < n ; j++){
            if(check(wordList[i], wordList[j])){
                mp[i].push_back(j);
                mp[j].push_back(i);
            }
        }
    }
    if(bInd == -1){
        for(int j = 0 ; j < n ; j++){
            if(check(beginWord, wordList[j])){
                mp[-1].push_back(j);
                mp[j].push_back(-1);
            }
        }
    }
    queue<pair<int, int>>q;
    q.push({bInd, 1});
    vector<int>vis(n+1, 0);
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        int ind = x.first;
        int dist = x.second;
        vector<int>v = mp[ind];
        vis[ind+1] = 1;
        if(ind != -1 && wordList[ind] == endWord){
            return dist;
        }
        for(int i = 0 ; i < (int)v.size() ; i++){
            if(!vis[v[i]+1]){
                q.push({v[i], dist+1});
            }
        }
    }
    return 0;
    
}