    #include <iostream>
#include <vector>
#include <algorithm>
#include<string>
#include <unordered_set>
using namespace std;

    vector<int> countBits(int n) {
        int curr;
        int next = 2;
        vector<int> res;
        for(int i=0;i<=n;i++){
            if(i==0){
                res.push_back(0);
                continue;
            }
            if(i==1){
                res.push_back(1);
                continue;
            }
            if(i == next){
                curr = next;
                next = next << 1;
            }
            int x = i ^ curr;
            cout << x;
            // res.push_back(1+res[x]);
        }

        // for(int x:res){
        //     cout << x << " ";
        // }
    }


int main(){
    countBits(4);
}