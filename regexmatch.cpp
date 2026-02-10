#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool match(string s, string p, int i, int j, vector<vector<int>>& memo){
        if(i == s.size()){
            if(j == p.size())
                return true;
            if(j == p.size()-1){ 
                if(p[j] == '*')
                    return true;
                else
                    return false;
            }
            if(j == p.size()-2){
                if(p[j+1] == '*')
                    return true;
            }
            return false;
        }
        if(j == p.size())
            return false;
        if(memo[i][j]!=-1)
            return memo[i][j];
        if(s[i]!=p[j] && p[j]>='a' && p[j]<='z'){
            if(j<p.size()-1 && p[j+1] == '*')
                return match(s,p,i,j+1,memo);
            memo[i][j] = 0;
            return false;
        }
        if(s[i] == p[j] || p[j] == '.'){
            memo[i][j] = match(s,p,i+1,j+1,memo);
            if(!memo[i][j] && j<p.size()-1 && p[j+1] == '*')
                memo[i][j] = match(s,p,i,j+1,memo);
            return memo[i][j];
        }
        memo[i][j] = match(s,p,i,j+1,memo);
        if(!memo[i][j]){
            if(s[i] == p[j-1] || p[j-1] == '.')
                memo[i][j] = match(s,p,i+1,j,memo);
            else
                memo[i][j] = 0;
        }
        return memo[i][j];
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> memo(s.size(),vector<int>(p.size(),-1));
        return match(s,p,0,0,memo);
    }
};

int main() {
    Solution sol;
    cout << sol.isMatch("bbbbba",".*a*a");
    cout << sol.isMatch("nnn","n*");
    cout << sol.isMatch("xyz",".*z");
    cout << sol.isMatch("aab","c*a*b");
    return 0;
}