#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static void markElem(vector<int>& nums, int num){
        if(num<=0||num>nums.size()||nums[num-1]==num)
            return;
        int t = nums[num-1];
        nums[num-1] = num;
        markElem(nums,t);
    }
    static int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            markElem(nums,nums[i]);
        }
        for(int i=0;i<nums.size();i++)
            if(nums[i]!=i+1)
                return i+1;
        return nums.size()+1;
    }
};
int main() {
    vector<int> nums = {1,2,4,5,6,3,1};
    cout << Solution::firstMissingPositive(nums);
    return 0;
}