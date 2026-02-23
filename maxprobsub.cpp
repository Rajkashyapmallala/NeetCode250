#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int minV = 1;
        int maxV = 1;
        for(int i=0;i<n;i++){
            int temp = minV;
            minV = min({minV*nums[i],maxV*nums[i],nums[i]});
            maxV = max({temp*nums[i],maxV*nums[i],nums[i]});
            res = max(maxV,res);
        }
        return res;
    }
};

int main() {
    return 0;
}