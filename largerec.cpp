#include <bits/stdc++.h>
using namespace std;

    int largestRectangleArea(vector<int>& heights) {
        int res = INT_MIN;
        stack<int> stk;
        int n = heights.size();
        vector<int> l(n,-1);
        vector<int> r(n,n);

        for(int i=0;i<heights.size();i++){
            if(stk.empty()){
                stk.push(i);
                continue;
            }
            while(!stk.empty() && heights[stk.top()]>heights[i]){
                r[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        for(int i=heights.size()-1;i>=0;i--){
            if(stk.empty()){
                stk.push(i);
                continue;
            }
            while(!stk.empty() && heights[stk.top()]>heights[i]){
                l[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        for(int i=0;i<n;i++){
            cout << (r[i]-l[i]-1) * heights[i]<< endl;
        }
    }

int main() {
    vector<int> ht = {7,1,7,2,2,4};

    cout << largestRectangleArea(ht);

    return 0;
}