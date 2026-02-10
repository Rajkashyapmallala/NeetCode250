#include <bits/stdc++.h>
using namespace std;
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mArr) {
        int l,r,m;
        l = 0;
        r = mArr.length()-1;
        while(l<=r){
            m = l + (r-l)/2;
            if(mArr.get(m-1)<mArr.get(m)){
                if(mArr.get(m)>mArr.get(m+1))
                    break;
                else
                    l = m + 1;
            }
            else
                r = m - 1;
        }
        int peak = m;
        if(mArr.get(peak) == target)
            return peak;
        if(mArr.get(0)<= target && target<mArr.get(peak)){
            l = 0;
            r = peak;
            while(l<=r){
                m = l + (r-l)/2;
                if(mArr.get(m) == target)
                    return m;
                if(mArr.get(m)<target)
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        else{
            l = peak;
            r = mArr.length()-1;
            while(l<=r){
                m = l + (r-l)/2;
                if(mArr.get(m) == target)
                    return m;
                if(mArr.get(m)<target)
                    r = m - 1;
                else
                    l = m + 1;                
            }
        }
        return -1;
    }
};
int main() {
    
    return 0;
}