    #include <iostream>
#include <vector>
#include <algorithm>
#include<string>
#include <unordered_set>
using namespace std;
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        vector<int> freq(26,INT_MIN);
        int cnt = 0;
        int curr = 0;
        for(auto ch:s1){
            int idx = ch-'a';
            if(freq[idx] == INT_MIN){
                freq[idx] = 0;
                cnt++;
            }
            freq[idx]++;
        }

        for(int i=0;i<s2.size();i++){
            int idx = s2[i]-'a';
            if(i>=s1.size()){
                int out = s2[i-s1.size()] - 'a';
                if(freq[out]!=INT_MIN){
                    if(freq[out] == 0)
                        curr--;
                    freq[out]++;
                }
            }
            if(freq[idx]!=INT_MIN){
                freq[idx]--;
                if(freq[idx] == 0)
                    curr++;
            }
            // cout << curr << " ";
            if(curr == cnt)
                return true;
        }
        return false;
    }


int main(){
    string s1 = "abc";
    string s2 = "lecaabee";
    cout << checkInclusion(s1,s2);
}