#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> res;

void checkSum(vector<int> curr,vector<int>& nums, int target, int pos){

    // cout<< endl;
    if(target == 0){
        res.push_back(curr);
            for(int i=0;i<curr.size();i++)
        cout << curr[i] << " ";
        cout << endl;
        return;
    }
    if(pos >= nums.size())
        return;
    if(target < 0)
        return;
    for(int i=0;i<=(target)/nums[pos];i++){
        if(i)
        curr.push_back(nums[pos]);
        checkSum(curr,nums,target-(i*nums[pos]),pos+1);
    }
    for(int i=0;i<(target)/nums[pos];i++){
        curr.pop_back();
    }
    return;
}

vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    vector<int> arr;
    for(int i=0;i<nums.size();i++){
        arr.push_back(nums[i]);
        checkSum(arr,nums,target-nums[i],i);
        arr.pop_back();
    }
    return res;
}

int main(){
    vector<int> nums = {3,4,5};
    int tar = 16;
    combinationSum(nums,tar);
}