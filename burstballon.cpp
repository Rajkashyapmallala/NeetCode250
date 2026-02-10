#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMax(vector<int>& nums, int l, int r, vector<vector<int>> &memo){
        // cout << l << r<< endl;
        if(l>r)
            return 0;
        if(memo[l][r]!=-1)
            return memo[l][r];
        int res = INT_MIN;
        for(int i=l;i<=r;i++){
            int temp = nums[i];
            int k = nums[i-1]*nums[i]*nums[i+1];
            nums[i]=1;
            res = max(res,k+findMax(nums,l,i-1,memo)+findMax(nums,i+1,r,memo));
            nums[i] = temp;
        }
        memo[l][r] = res;
        cout << l << " " << r << " " << res << endl;
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
    Solution sol;
    vector<int> v = {4,2,3,7};
    cout << sol.maxCoins(v);
    return 0;
}
