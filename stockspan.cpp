#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> idx;

int findSpan(int k) {
    v.push_back(k);
    int n = v.size();

    if (n == 1) {
        idx.push_back(-1);
        return 1;
    }

    int i = n - 2;
    while (i >= 0 && v[i] <= k) {
        i = idx[i];
    }

    idx.push_back(i);
    return n - i - 1;
}

int main() {
    int x;
    while(cin >> x){
        cout << findSpan(x);
    }
    return 0;
}