#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
#include <unordered_set>
using namespace std;    
    
    
    int minMeetingRooms(vector<int>& intervals) {
        // int n = intervals.size();
        // vector<int> start(n);
        // vector<int> end(n);
        // // for(auto intr: intervals){
        // //     start.push_back(intr.start);
        // //     end.push_back(intr.end);
        // // }

        vector<int> start = {4};
        vector<int> end = {9};
        int n = 1;
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int i = 0;
        int j = 0;
        int cnt = 0;
        int res = 1;
        while(i<n && j<n){
            if(start[i] < end[j]){
                cnt++;
                i++;
            }
            else if(start[i] > end[j]){
                cnt--;
                j++;
            }
            else{
                i++;
                j++;
            }
            cout << i << " " << j << " " << cnt << endl;
            res = max(res,cnt);
        }
        cout << res;
        return res;
    }

    int main(){
        vector<int> arr = {1};
        minMeetingRooms(arr);
    }