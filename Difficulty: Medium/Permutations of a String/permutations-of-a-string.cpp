//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void permute(int idx, string &s, set<string> &st) {
        if(idx == s.length()) {
            st.insert(s);
            return;
        }
        for(int i = idx; i < s.length(); i++) {
            swap(s[idx], s[i]);
            permute(idx + 1, s, st);
            swap(s[idx], s[i]);
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        set<string> st;
        permute(0, s, st);
        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends