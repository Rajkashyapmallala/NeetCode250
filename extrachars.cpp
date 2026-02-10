#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            dp[i] = 1 + dp[i-1];
            for(string str: dictionary){
                int len = str.size();
                if(len<=i && s.substr(i-len,len) == str){
                    dp[i] = min(dp[i],dp[i-len]);
                }
            }
        }
        return dp[n];
    }
};

int main() {
    return 0;
}