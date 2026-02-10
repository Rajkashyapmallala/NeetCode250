#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isValid(string s) {
    int len = s.length();
    if(len%2)
        return false;
    for(int i=0;i<len/2;i++){
        if(s[i]!=s[len-i-1])
            return false;
    }
    return true;
}
int main(){
    // vector<int> a = {1,2,3};
    // sort(a.rbegin(),a.rend());
    // for(auto x:a){
    //     cout << x << " ";
    // }
    cout << '(' - ')'; 
}
