#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int res[n], ex[n];
        res[0] = nums[0];
        res[1] = max(nums[0],nums[1]);
        ex[0] = 0;
        ex[1] = nums[1];
        for(int i=2;i<n;i++){
            res[i] = max(res[i-1],res[i-2]+nums[i]);
            ex[i] = max(ex[i-1],ex[i-2]+nums[i]);
        }
        return max(ex[n-1],res[n-2]);
    }
};

int main() {
    return 0;
}