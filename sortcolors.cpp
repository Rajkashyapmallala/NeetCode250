#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-1;
        int curr = 0;
        while(curr<=h){
            if(nums[curr] == 0){
                swap(nums[l],nums[curr]);
                l++;
                curr++;
            }
            else if(nums[curr] == 1){
                curr++;
            }
            else{
                swap(nums[h],nums[curr]);
                h--;
            }
        }
    }
};
int main() {
    return 0;
}