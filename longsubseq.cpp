    #include <iostream>
#include <vector>
#include <algorithm>
#include<string>
#include <unordered_set>
using namespace std;
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int res = 1;
        vector<int> maxlen(n,1);
        for(int i=1;i<n;i++){
            int currmax = 0;
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i])
                    currmax = max(currmax,1+maxlen[j]);
            }
            if(currmax)
                maxlen[i] = currmax;
            res = max(res,currmax);
        }
        for(int num:maxlen)
            cout << num;
        return res;
    }

    int main(){
        vector<int> arr = {9,1,4,2,3,3,7};
        lengthOfLIS(arr);
    }