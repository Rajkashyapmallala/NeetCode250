#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
#include <unordered_set>
using namespace std;

    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(),wordDict.end());
        vector<bool> dp(s.size(),false);
        for(int i=0;i<s.size();i++){
            for(int j=i;j>=0;j--){
                // cout << j << " " << i << endl;
                if(j-1>=0 && dp[j-1]){
                    if(wordSet.find(s.substr(j,(i-j+1)))!=wordSet.end()){
                        dp[i] = true;
                        break;
                    }
                }
                if(j == 0){
                    if(wordSet.find(s.substr(j,(i-j+1)))!=wordSet.end())
                        dp[i] = true;
                }
            }
            cout << dp[i];
        }
        return dp[s.size()-1];
    }

    int main(){
        vector<string> dict = {"neet", "code"};
        wordBreak("neetcode",dict);
    }