#include <vector>
#include<iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    for(int i=0;i<nums.size();i++){
        if(i>0&&nums[i]==nums[i-1])
            continue;
        int l,r;
        l = i+1;
        r = nums.size()-1;
        while(l<r){
            cout << i << " " << l << " " << r << endl;
            if(l>i+1&&nums[l]==nums[l-1]){
                l++;
                continue;
            }
            if(r<nums.size()-1&&nums[r]==nums[r+1]){
                r--;
                continue;
            }
            if(nums[l] + nums[r] == -nums[i]){
                vector<int> tri;
                tri.push_back(nums[l]);
                tri.push_back(nums[r]);
                tri.push_back(nums[i]);
                res.push_back(tri);
                l++;
                r--;
            }
            else if(nums[l] + nums[r] < -nums[i]){
                l++;
            }
            else{
                r--;
            }
        }
    }
    return res;
}

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    threeSum(nums);
}