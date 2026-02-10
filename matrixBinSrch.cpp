#include <bits/stdc++.h>
using namespace std;

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size()-1;
        while(l<=r){
            int m = l + (r-l)/2;
            if(matrix[m][0] == target)
                return true;
            if(matrix[m][0] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        if(r < 0)
            return false;
        int rs = r;
        // cout << l << r << endl;
        l = 0;
        r = matrix[0].size()-1;
        while(l<=r){
            int m = l + (r-l)/2;
            if(matrix[rs][m] == target)
                return true;
            if(matrix[rs][m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return false;
    }


int main() {
    vector<vector<int>> vs = {{1,2,4,8},{10,11,12,13},{14,20,30,40}};
    cout << searchMatrix(vs,100);
}