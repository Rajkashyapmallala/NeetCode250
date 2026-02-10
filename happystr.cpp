#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static string longestDiverseString(int a, int b, int c) {
        vector<pair<int,char>> freq(3);
        freq[0] = {a,'a'};
        freq[1] = {b,'b'};
        freq[2] = {c,'c'};
        int cnt = 0;
        string res = "";
        if(!a)  
            cnt++;
        if(!b)
            cnt++;
        if(!c)
            cnt++;
        sort(freq.rbegin(),freq.rend());
        while(cnt<3){
            for(int i=0;i<3;i++){
                if(!res.empty() && freq[i].first > 0 && res.back() == freq[i].second){
                    cnt = 3;
                    break;
                }
                if(freq[i].first>=2){
                    res += string(2,freq[i].second);
                    freq[i].first -= 2;
                    if(freq[i].first == 0)
                        cnt++;
                }
                else if(freq[i].first == 1){
                    res += string(1,freq[i].second);
                    freq[i].first = 0;
                    cnt++;
                }
            }
        }
        return res;
    }
};
int main() {
    cout << Solution::longestDiverseString(0,1,5);
    return 0;
}