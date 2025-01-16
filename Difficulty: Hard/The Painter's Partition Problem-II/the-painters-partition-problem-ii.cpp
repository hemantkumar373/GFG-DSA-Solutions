//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int countPainters(vector<int>& arr, int time) {
        int painters = 1;
        long long boardPainters = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (boardPainters + arr[i] <= time) {
                boardPainters += arr[i];
            } else {
                painters++;
                boardPainters = arr[i];
            }
        }
        return painters;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        while (low <= high) {
            int mid = (low + high) / 2;
            int painters = countPainters(arr, mid);

            if (painters > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        // return minimum time
        return low;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.minTime(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends