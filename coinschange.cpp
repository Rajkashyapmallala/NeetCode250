#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int coinChange(vector<int>& coins, int amount) {
        vector<int> arr(amount+1,-1);
        arr[0] = 0;
        for(int i=1;i<=amount;i++){
            int numCoins = INT_MAX;
            for(int coin:coins){
                if(coin<=i){
                    if(arr[i%coin] == -1)
                        continue;
                    numCoins = min(numCoins,i/coin + arr[i%coin]);
                }
            }
            if(numCoins!=INT_MAX)
                arr[i] = numCoins;
        }
        
        for(int i =0;i<=amount;i++)
            cout << arr[i] << " ";
        return arr[amount];
    }

    int main(){
        vector<int> coins = {2};
        coinChange(coins,3);
    }