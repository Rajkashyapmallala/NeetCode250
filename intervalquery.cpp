#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<pair<int,int>> qr;
        int n = queries.size();
        int m = intervals.size();
        vector<int> res(n);
        for(int i=0;i<n;i++)
            qr.push_back({queries[i],i});
        sort(qr.begin(),qr.end());
        sort(intervals.begin(),intervals.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheap;
        int j = 0;
        for(int i=0;i<n;i++){
            while(j<m && intervals[j][0]<=qr[i].first){
                minheap.push({intervals[j][1]-intervals[j][0]+1,intervals[j][1]});
                // cout << j << " " << i << " ";
                j++;
            }
            while(!minheap.empty() && minheap.top().second<qr[i].first){
                                // cout << j << " " << i << " ";

                minheap.pop();
            }
            if(!minheap.empty())
                res[qr[i].second] = minheap.top().first;
            else
                res[qr[i].second] = -1;
        }
        for(int r:res)
            cout<< r << " ";
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> itr = {{1,3},{2,3},{3,7},{6,6}};
    vector<int> qr = {2,3,1,7,6,8};
    sol.minInterval(itr,qr);
    return 0;
}