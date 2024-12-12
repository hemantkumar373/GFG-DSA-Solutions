//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findMatching(string text, string pat) {
        int m = text.length();
        int n = pat.length();
        
        for(int i=0; i<=m-n; i++){
            for(int j=0; j<n; j++){
                if(text[i+j] != pat[j]){
                    break;
                }
                if(j == n-1) return i;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string text, pat;
        cin >> text >> pat;
        Solution obj;
        cout << obj.findMatching(text, pat) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends