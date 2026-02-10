#include <unordered_map>
#include <string>
#include<iostream>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> mp;
    int l = 0, res = 0;
    for (int r = 0; r < s.size(); r++) {
        if (mp.find(s[r]) != mp.end()) {
            l = mp[s[r]] + 1;
        }
        mp[s[r]] = r;
        cout << l << " " << r << endl;

        res = max(res, r - l + 1);
    }
    return res;
}

int main(){
    lengthOfLongestSubstring("abba");
}