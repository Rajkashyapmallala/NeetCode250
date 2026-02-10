#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    vector<string> res;

    void dfs(string& s,string& p,unordered_map<string,vector<string>>& adj){
        res.push_back(s);
        bool back = false;
        for(int i=0;i<adj[s].size();i++){
            if(adj[s][i] == p){
                back = true;
                continue;
            }
            cout << adj[s][i];
            dfs(adj[s][i],s,adj);
        }
        if(back)
            res.push_back(p);
        return;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> adj;
        for(auto edge: tickets){
            adj[edge[0]].push_back(edge[1]);
        }
        for(auto edg:adj){
            sort(edg.second.begin(),edg.second.end());
        }
        string s = "JFK";
        string p = "000";
        dfs(s,p,adj);
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<string>> itr = {{"HOU","JFK"},{"SEA","JFK"},{"JFK","SEA"},{"JFK","HOU"}};
    sol.findItinerary(itr);
    // for(auto x: sol.res)
    //     cout << x << " ";
    return 0;
}