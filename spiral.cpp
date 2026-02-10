    #include <iostream>
#include <vector>
#include <algorithm>
#include<string>
#include <unordered_set>
using namespace std;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int t = m*n;
        vector<int> res(t);
        int i=0;
        int j=0;
        res[0] = matrix[0][0];
        matrix[0][0] = -101;
        int cnt = 1;
        while(cnt<t){
            while(j+1<n && matrix[i][j+1]!=-101){
                res[cnt] = matrix[i][j+1];
                matrix[i][j+1] = -101;
                cnt++;
                j++;
            }
            while(i+1<m && matrix[i+1][j]!=-101){
                res[cnt] = matrix[i+1][j];
                matrix[i+1][j] = -101;
                cnt++;
                i++;
            }
            while(j>0 && matrix[i][j-1]!=-101){
                res[cnt] = matrix[i][j-1];
                matrix[i][j-1] = -101;
                cnt++;
                j--;
            }
            while(i>0 && matrix[i-1][j]!=-101){
                res[cnt] = matrix[i-1][j];
                matrix[i-1][j] = -101;
                cnt++;
                i--;
            }
        }
        for(auto x: res)
            cout << x << " ";
        return res;
    }

    int main(){
        vector<vector<int>> mt = {{1,2,3,4},{5,6,7,8}};
        // vector<vector<int>> mt = {{1,2},{3,4}};
        spiralOrder(mt);
    }
