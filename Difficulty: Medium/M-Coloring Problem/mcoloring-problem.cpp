//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isSafe(int node, vector<int>& color, vector<vector<int>>& edgeLs, int n, int col) {
        for(int k = 0; k < n; k++) {
            if(k != node && edgeLs[node][k] == 1 && color[k] == col) {
                return false;
            }
        }
        return true;
    }
    bool solve(int node, vector<int>& color, int v, int m, vector<vector<int>>& edgeLs) {
        if(node == v) return true;
        
        for(int i = 1; i <= m; i++) {
            if(isSafe(node, color, edgeLs, v, i)) {
                color[node] = i;
                if(solve(node + 1, color, v, m, edgeLs)) return true;
                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        // code here
        vector<vector<int>> edgeLs(v, vector<int>(v, 0));
        for(auto it : edges) {
            edgeLs[it.first][it.second] = 1;
            edgeLs[it.second][it.first] = 1;
        }
        
        vector<int> color(v, 0);
        return solve(0, color, v, m, edgeLs);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends