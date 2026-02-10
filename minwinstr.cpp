#include <unordered_map>
#include <string>
#include<iostream>
#include <unordered_set>
using namespace std;


string minWindow(string s, string t) {
    if(t.length()>s.length())
        return "";
    int cnt,l,resl,resr,res;
    cnt=0;
    l=0;
    cnt=0;
    res=0;
    resl = -1;
    resr = -1;
    unordered_map<char,int> mp;
    unordered_set<char> uniqchars;
    for(int i=0;i<t.length();i++){
        uniqchars.insert(t[i]);
        mp[t[i]]++;
    }
    for(int r=0;r<s.length();r++){
        mp[s[r]]--;
        if(mp[s[r]]==0 && uniqchars.find(s[r])!=uniqchars.end())
            cnt++;
        if(cnt == uniqchars.size()){
            if(r-l+1 > res){
                res = r-l+1;
                resl = l;
                resr = r;
            }
        }
        while(l<r && cnt==uniqchars.size()){
            mp[s[l]]++;
            if(r-l+1 > res){
                res = r-l+1;
                resl = l;
                resr = r;
            }
            if(mp[s[l]]>0&&uniqchars.find(s[l])!=uniqchars.end()){
                mp[s[l]]--;
                break;
            }
            l++;    
        }
    }
    if(resl==-1 && resr==-1)
        return "";
    return s.substr(resl,res);
}

int main(){
    minWindow("ADOBECODEBANC","ABC");
}