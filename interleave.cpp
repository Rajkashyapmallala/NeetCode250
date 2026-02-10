#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkIl(string s1, string s2, string s3,int i,int j,int k, vector<vector<vector<int>>> &memo){
        if(i>=s1.size() && j>=s2.size())
            return true;
        if(i<s1.size() && s1[i] == s3[k]){
            if(memo[0][i][k] == 1)
                return true;
            if(memo[0][i][k] == -1){
                if(checkIl(s1,s2,s3,i+1,j,k+1,memo)){
                    memo[0][i][k] = 1;
                    return true;
                }
                memo[0][i][k] = 0;
            }
        }
        if(j<s2.size() && s2[j] == s3[k]){
            if(memo[1][j][k] == 1)
                return true;
            if(memo[1][j][k] == -1){
                if(checkIl(s1,s2,s3,i,j+1,k+1,memo)){
                    memo[1][j][k] = 1;
                    return true;
                }
                memo[1][j][k] = 1;
            }
        }
        return false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())
            return false;
        int l = max(s1.size(),s2.size());
        vector<vector<vector<int>>> memo(2,vector<vector<int>>(l,vector<int>(s3.size(),-1)));
        return checkIl(s1,s2,s3,0,0,0,memo);
    }
};

int main() {
    class Solution sol;
    cout << sol.isInterleave("aabcc","dbbca","aadbbbaccc");
}