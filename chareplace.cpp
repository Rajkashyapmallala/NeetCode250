#include <unordered_map>
#include <string>
#include<iostream>
using namespace std;

int characterReplacement(string s, int k) {
    int l,maxf,res;
    unordered_map<char,int> count;
    l=0;
    maxf=0;
    res=0;
    for(int r=0;r<s.length();r++){
        count[s[r]]++;
        maxf = max(maxf,count[s[r]]);
        cout << l << " " << r << endl;
        if(r-l+1 - maxf > k){
            l++;
            count[s[l]]--;
        }
        cout << l << " " << r << endl;
        res = max(res,r-l+1);
    }
    return res;
}

int main(){
    characterReplacement("ABAA",0);
}