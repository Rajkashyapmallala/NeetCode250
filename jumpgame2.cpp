#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int l,r,res;
        l = 0;
        r = 0;
        res = 0;
        while(r<nums.size()-1){
            int temp = r+1;
            for(int i=l;i<=r;i++){
                temp = max(temp,i+nums[i]);
            }
            l = r+1;
            r = temp;
            res++;
        }
        return res;
    }
};

int main() {
    return 0;
}