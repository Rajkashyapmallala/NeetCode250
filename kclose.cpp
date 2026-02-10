#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       vector<int> res;
       int r = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
       int l = r-1;
       int n = arr.size();
       int cnt = 0;
       while(l>=0 && r<n && cnt<k){
            cout << l << " " << r << endl;
            if(abs(arr[l]-x)<=abs(arr[r]-x)){
                res.push_back(arr[l]);
                l--;
            }
            else{
                res.push_back(arr[r]);
                r++;
            }
            cnt++;
       }
       while(cnt<k){
            if(l>=0){
                res.push_back(arr[l]);
                l--;   
            }
            if(r<n){
               res.push_back(arr[r]);
               r++; 
            }
            cnt++;
       }
       sort(res.begin(),res.end());
       return res; 
    }
};
int main() {
    vector<int> arr = {2,4,5,8};
    int k = 2;
    int x = 6;
    Solution::findClosestElements(arr,k,x);
    return 0;
}