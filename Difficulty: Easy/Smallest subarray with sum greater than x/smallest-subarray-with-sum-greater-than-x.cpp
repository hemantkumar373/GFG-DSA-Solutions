//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = 0;
        int minlen = INT_MAX;
        int sum = 0;

        while(r < n) {
            sum += arr[r];

            while(sum > x) {
                minlen = min(minlen, r - l + 1);
                sum -= arr[l];
                l++;
            }

            r++;
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        vector<int> arr;
        int x;

        cin >> x;
        cin.ignore(); // Ignore the newline character after x

        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        cout << obj.smallestSubWithSum(x, arr) << "\n~\n";
    }

    return 0;
}
// } Driver Code Ends