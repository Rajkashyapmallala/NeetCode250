#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cnt1 = 0;

    bool checkPalin(int l, int r, string s){
                                    // cout << l << " " << r << endl;

        while(l>=0 && r<s.size()){
            if(s[l]!=s[r])
                return false;
                                                cout << l << " " << r << endl;

            l--;
            r++;
            cnt1++;
                                                // cout << l << " " << r << endl;

        }
        l++;
        r--;
                                    // cout << l << " " << r << endl;

        return true;
    }

int main(){
        string s = "aaaa";
        int cnt = 0;
        if(s.size() == 1)
            return 1;
        for(int i=0;i<s.length();i++){
            if(i-1>=0 && i+1<s.length() && checkPalin(i-1,i+1,s))
                cnt++;
            if(i+1<s.length() &&checkPalin(i,i+1,s))
                cnt++;
        }
        cout << cnt1;
        cnt += s.size();
}