#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOps(string word1, string word2, int i, int j, vector<int>& memo){
        if(j==word2.size())
            return word1.size()-i;
        if(i==word1.size())
            return (word2.size()-j);
        if(word1[i] == word2[j])
            return minOps(word1,word2,i+1,j+1,memo);
        if(memo[i]!=-1)
            return memo[i];
        memo[i] = 1 + min({minOps(word1,word2,i+1,j+1,memo),minOps(word1,word2,i+1,j,memo),
        minOps(word1,word2,i,j+1,memo)});
        // cout << i << " " << memo[i] << endl;
        return memo[i];
    }
    int minDistance(string word1, string word2) {
        vector<int> memo(word1.size(),-1);
        return minOps(word1,word2,0,0,memo);
    }
};

int main() {
    Solution sol;
    // cout << sol.minDistance("monkeys","money");
    cout << sol.minDistance("neatcdee","neetcode");
    return 0;
}