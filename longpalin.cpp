#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    string checkPalin(int l, int r, string s){
        while(l>=0 && r<s.size()){
            if(s[l]!=s[r])
                break;
            l--;
            r++;
        }
        l++;
        r--;
        return s.substr(l,(r-l+1));        
    }
    string longestPalindrome(string s) {
        string res = s.substr(0,1);
        for(int i=0;i<s.length();i++){
            string odd = checkPalin(i-1,i+1,s);
            if(odd.size()>res.size())
                res = odd;
            string even = checkPalin(i,i+1,s);
            if(even.size()>res.size())
                res = even;
        }
        return res;
    }
};

int main() {
    return 0;
}