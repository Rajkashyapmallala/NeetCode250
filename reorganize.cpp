#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static string reorganizeString(string s) {
        vector<int> freq(26,0);
        string res = "";
        for(char ch:s)
            freq[ch-'a']++;
        priority_queue<pair<int,int>> pq;

        for(int i=0;i<26;i++){
            if(freq[i]!=0)
                pq.push({freq[i],i});
        }

        while(pq.size()>1){
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();

            res += ('a' + p1.second);
            res += ('a' + p2.second);

            if(p1.first>1)
                pq.push({p1.first-1,p1.second});
            if(p2.first>1)
                pq.push({p2.first-1,p2.second});
            
        }

        if(pq.size() == 1){
            if(pq.top().first > 1)
                return "";
            res += ('a' + pq.top().second);
        }

        return res;
        
    }
};
int main() {
    cout << Solution::reorganizeString("aaabbbccc");
    return 0;
}