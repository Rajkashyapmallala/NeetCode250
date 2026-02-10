#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> w;
    int k;
    sort(w.begin(),w.end());
    int i,j;
    i=0;j=w.size()-1;
    int res = 0;
    while(i<j){
        if(w[i]+w[j]<=k)
            i++;
        res++;
        j--;
    }
    if(i==j)
        res++;
    cout << res;
    return 0;
}