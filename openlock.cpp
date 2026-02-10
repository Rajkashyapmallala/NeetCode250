#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static int openLock(vector<string>& deadends, string target) {
        int res = 0;
        queue<string> q;
        unordered_set<string> vis;
        unordered_set<string> deadstates(deadends.begin(),deadends.end());
        string initial = "0000";
        q.push(initial);
        while(!q.empty()){
            int siz = q.size();
            cout << res << " ";
            while(siz--){
                string state = q.front();
                q.pop();
                if(state == target)
                    return res;
                if(vis.find(state)==vis.end() && deadstates.find(state)==deadstates.end()){
                    for(int i=0;i<4;i++){
                        string next = state;
                        next[i] = (state[i] - '0' + 1)%10 + '0';
                        q.push(next);
                        next[i] = (state[i] - '0' - 1)%10 + '0';
                        q.push(next);
                    }
                    vis.insert(state);
                }
                cout << state << " ";
            }
            res++;
            cout << endl;
        }
        return -1; 
    }
};
int main() {
    vector<string> deadends = {"1111","0120","2020","3333"};

    Solution::openLock(deadends,"5555");

    return 0;
}