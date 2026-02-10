    #include <iostream>
#include <vector>
#include <algorithm>
#include<string>
#include <unordered_set>
using namespace std;


    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> right(n);
        right[n-1] = 0;
        int res = 0;
        int lmax = 0;
        for(int i=n-2;i>=0;i--)
            right[i] = max(right[i+1],height[i+1]);
        for(int x: right)
            cout << x << " ";
        cout << endl;
        cout << "0 ";
        for(int i=1;i<n;i++){
            lmax = max(lmax,height[i-1]);
            cout << lmax << " ";
            if(min(lmax,right[i])>0 && min(lmax,right[i]) > height[i]){
                res += (min(lmax,right[i]) - height[i]);
            }
        }
        cout << endl;
        cout << res;
        return res;
    }

int main(){
    vector<int> ht = {0,2,0,3,1,0,1,3,2,1};
    trap(ht);
}