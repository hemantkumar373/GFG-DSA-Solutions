//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isValid(vector<vector<int>>& mat, int row, int col, int num) {
        for (int i = 0; i < 9; i++) {
            if (mat[i][col] == num)
                return false;
            if (mat[row][i] == num)
                return false;
            if (mat[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<int>>& mat) {
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {
                    for (int num = 1; num <= 9; num++) {
                        if (isValid(mat, i, j, num)) {
                            mat[i][j] = num;
                            if (solve(mat)) {
                                return true;
                            } else {
                                mat[i][j] = 0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    // Function to find a solved Sudoku.
    void solveSudoku(vector<vector<int>> &mat) {
        solve(mat); 
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends