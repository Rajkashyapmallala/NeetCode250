#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static string decodeString(string s) {
        stack<string> stk;
        string res;
        for(char c:s){
            if(c != ']')
                stk.push(string(1,c));
            else{
                string str;
                while(stk.top()!="["){
                    str = stk.top() + str;
                    stk.pop();
                }
                stk.pop();
                int k = stoi(stk.top());
                string temp = str;
                while(--k){
                    str += temp;
                }
                stk.pop();
                stk.push(str);
            }
        }
        while(!stk.empty()){
            res = stk.top() + res;
            stk.pop();
        }   
        return res;
    }
};
int main() {
    cout << Solution::decodeString("ab2[c]3[d]1[x]");
    return 0;
}