#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
#include <unordered_set>
using namespace std;


void insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // int idx = lower_bound(intervals.begin(),intervals.end(),newInterval) - intervals.begin();
        // intervals.insert(intervals.begin() + idx, newInterval);
        // for(int i=0;i<intervals.size()-1;i++){
        //     int l1 = intervals[i][0];
        //     int r1 = intervals[i][1];
        //     int l2 = intervals[i+1][0];
        //     int r2 = intervals[i+1][1];
        //     if(l2<=r1 && r2>r1){
        //         intervals.erase(intervals.begin()+i);
        //         intervals.erase(intervals.begin()+i);
        //         intervals.insert(intervals.begin()+i,{l1,r2});
        //         i--;
        //     }
        //     if(l2<r1 && r1>=r2){
        //         intervals.erase(intervals.begin()+i+1);
        //         i--;
        //     }
        // }

        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        for(auto intr:intervals){
            if(res.empty()|| (res.back()[0] < intr[0] && res.back()[1] < intr[0]))
                res.push_back(intr);
            else
                res.back()[1] = max(res.back()[1],intr[1]);
      }
        //return res;
                for(auto x: res){
            cout << x[0] << x[1] << " ";
        }
        cout << endl;

}

int main(){
    vector<vector<int>> inter = {{1,3},{1,5},{6,7}};
    vector<int> newInt = {0,5};
    insert(inter,newInt);
}