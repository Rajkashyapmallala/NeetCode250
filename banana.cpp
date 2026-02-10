#include <bits/stdc++.h>
using namespace std;

    int timeTaken(vector<int>& piles, int h){
        int t = 0;
        for(int x:piles){
            if(x<=h)
                t++;
            else
                t += (x/h + 1);
            cout << t << endl;
        }
        return t;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxh = 1;
        for(auto x:piles)
            maxh = max(maxh,x);
        int l = 1;
        int r = maxh;
        while(r-l>1){
            int m = l + (r-l)/2;
            int curr = timeTaken(piles,m);
            cout << l << " " << r << " " << m  << " "<< curr  << endl ;
            if(curr > h)
                l = m;
            else
                r = m;
        }
        return r;
    }


int main() {

    vector<int> p = {3,6,7,11};
    cout << minEatingSpeed(p,8);


    return 0;
}