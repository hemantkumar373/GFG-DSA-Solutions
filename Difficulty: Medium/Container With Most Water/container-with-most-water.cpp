//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int i = 0, j = arr.size() - 1;
        int maxWater = 0;
        
        while (i < j) {
            int water = (j - i) * min(arr[i], arr[j]);
            maxWater = max(maxWater, water);
            
            if (arr[i] < arr[j]) {
                i++;
            }
            else {
                j--;
            }
        }
        
        return maxWater;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends