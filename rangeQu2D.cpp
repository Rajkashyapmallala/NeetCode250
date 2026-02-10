#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> matrix = {{{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}}};
        vector<vector<int>> sum;

            int m = matrix.size();
        int n = matrix[0].size();
        int cum = 0;
        for(int i=0;i<m;i++){
            vector<int> vec;
            for(int j=0;j<n;j++){
                cum += matrix[i][j];
                if(i>0)
                    vec.push_back(cum+sum[i-1][j]);
                else
                    vec.push_back(cum);
            }
            sum.push_back(vec);
            cum = 0;
        }
        for(auto x:sum){
            for(auto y:x)
                cout << y << " ";
            cout << endl;
        }
    return 0;
}