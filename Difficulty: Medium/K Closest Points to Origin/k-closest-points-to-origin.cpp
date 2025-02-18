//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; i++) {
            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.push({dist, {points[i][0], points[i][1]}});
            
            if(pq.size() > k)
                pq.pop();
        }
        
        while(!pq.empty()) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends