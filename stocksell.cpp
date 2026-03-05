#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMax(vector<int>& prices,int i, bool canBuy, int bp, vector<int> profitArr){
        if(i>=prices.size())
            return 0;
        if(canBuy){
            if(profitArr[i]!=-1)
                return profitArr[i];
            profitArr[i] = max(findMax(prices,i+1,false,prices[i],profitArr),
            findMax(prices,i+1,true,0,profitArr));
            return profitArr[i];
        }
        if(prices[i]<=bp){
            return findMax(prices,i+1,false,bp,profitArr);
        }
        return max(prices[i] - bp + findMax(prices,i+2,true,0,profitArr),
        findMax(prices,i+1,false,bp,profitArr));
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> profitArr(n,-1);
        return findMax(prices,0,true,0,profitArr);
    }
};

int main() {
    return 0;
}