#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        int num = n;
        while(st.find(num)==st.end()){
            st.insert(num);
            int temp = 0;
            while(num!=0){
                temp += (num%10)*(num%10);
                num = num/10;
            }
            num = temp;
            if(num == 1)
                return true;
        }
        return false;
    }
};

int main() {

    Solution sol;
    cout << sol.isHappy(19);
    return 0;
}