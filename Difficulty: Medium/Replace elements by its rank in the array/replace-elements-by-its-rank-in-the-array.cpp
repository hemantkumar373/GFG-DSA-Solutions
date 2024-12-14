//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> replaceWithRank(vector<int> &arr, int N) {
        vector<int> sortedArr = arr;
        vector<int> ans;
        unordered_map<int, int> mpp;
        int rank = 1;
        
        sort(sortedArr.begin(), sortedArr.end());
        
        for(auto num : sortedArr) {
            if(mpp.find(num) == mpp.end()) {
                mpp[num] = rank;
                rank++;
            }
        }
        
        for(int i = 0; i < N; i++) {
            ans.push_back(mpp[arr[i]]);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends