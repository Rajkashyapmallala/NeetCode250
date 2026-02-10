#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    static vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> deg(n,0);
        queue<int> leaves;
        vector<int> res;

        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[0]].push_back(edge[1]);
            deg[edge[0]]++;
            deg[edge[1]]++;
        }

        for(int i=0;i<n;i++){
            if(deg[i] == 1)
                leaves.push(i);
        }

        while(leaves.size()>2){
            int size = leaves.size();
            while(size--){
                int p = leaves.front();
                leaves.pop();
                for(int ne:adj[p]){
                    deg[ne]--;
                    if(deg[ne] == 1)
                        leaves.push(ne);
                }
            }
        }
        
        while(!leaves.empty()){
            res.push_back(leaves.front());
            leaves.pop();
        }

        for(int x: res)
            cout << x << " ";

        return res;
    }
};
int main() {

    vector<vector<int>> e = {{0,1},{3,1},{2,3},{4,1}};
    vector<vector<int>> e1 = {{0,1},{3,0},{2,0}};
    Solution::findMinHeightTrees(5,e);
    cout << endl;
    Solution::findMinHeightTrees(4,e1);

    return 0;
}

