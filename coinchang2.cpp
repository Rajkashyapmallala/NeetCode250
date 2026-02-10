#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    int findCount(int amt, int i, vector<int>& coins, vector<vector<int>>& memo){
        if(amt == 0)
            return 1;
        if(i>=coins.size())
            return 0;
        if(coins[i]>amt)
            return 0;
        if(memo[amt][i]!=-1)
            return memo[amt][i];
        int cnt = 0;
        for(int k=0;k<=(amt/coins[i]);k++){
            cnt += findCount(amt-(k*coins[i]),i+1,coins,memo);
        }
        memo[amt][i] = cnt;
        return cnt;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(amount+1,vector<int>(coins.size(),-1));
        return findCount(amount,0,coins,memo);
    }
};

int main() {
    class Solution sol;
    vector<int> coins = {1,2,3};
    cout << sol.change(4,coins);
    return 0;
}