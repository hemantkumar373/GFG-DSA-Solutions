//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sumSubset(int i, int sum, vector<int>& arr, int n, vector<int>& ans){
        if(i == n){
            ans.push_back(sum);
            return;
        }
        
        sumSubset(i + 1, sum + arr[i], arr, n, ans);
        
        sumSubset(i + 1, sum, arr, n, ans);
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> ans;
        sumSubset(0, 0, arr, n, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends