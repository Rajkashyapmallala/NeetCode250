#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

    long int res = 0;

    void numWays(string &s, int pos){
        if(pos == s.size())
            res++;
        if(s[pos]-'0'){
            numWays(s,pos+1);
            if(pos+1<s.size()){
                int a = s[pos] - '0';
                int b = s[pos+1] - '0';
                int n = a*10 + b;
                if(n>=10 && n<=26)
                    numWays(s,pos+2);
            }
        }
    }
    int dfs(int i, string& s) {
        if (i == s.size()) return 1;
        if (s[i] == '0') return 0;

        int res = dfs(i + 1, s);
        if (i < s.size() - 1) {
            if (s[i] == '1' ||
               (s[i] == '2' && s[i + 1] < '7')) {
                res += dfs(i + 2, s);
            }
        }
        return res;
    }
    int numDecodings(string s) {
        numWays(s,0);
        return 0;
    }

    int main(){
        // numDecodings("2611055971756562");
        string s = "2611055971756562";
        cout << dfs(0,s) ;
    }
