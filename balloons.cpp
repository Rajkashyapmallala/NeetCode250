#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMax(vector<int>& nums, int l, int r, vector<vector<int>> &memo){
        if(l>r)
            return 0;
        if(memo[l][r]!=-1)
            return memo[l][r];
        int res = INT_MIN;
        for(int i=l;i<=r;i++){
            res = max(res,nums[l-1]*nums[i]*nums[r+1]+findMax(nums,l,i-1,memo)+findMax(nums,i+1,r,memo));
        }
        memo[l][r] = res;
        return res;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> memo(n+1,vector<int>(n+1,-1));
        return findMax(nums,1,n,memo);
    }
};

int main() {
    return 0;
}