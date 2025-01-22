//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    bool static comp(pair<int, int>& a, pair<int, int>& b) {
        double r1 = (double) a.first / (double) a.second;
        double r2 = (double) b.first / (double) b.second;
        return r1 > r2;
    } 
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Your code here
        vector<pair<int, int>> arr;
        for(int i = 0; i < val.size(); i++) {
            arr.push_back({val[i], wt[i]});
        }
        
        sort(arr.begin(), arr.end(), comp);
        
        int currWeight = 0;
        double maxValue = 0.0;
        for(int i = 0; i < val.size(); i++) {
            if(currWeight + arr[i].second <= capacity) {
                currWeight += arr[i].second;
                maxValue += arr[i].first;
            }
            else {
                int remain = capacity - currWeight;
                maxValue += (arr[i].first / (double) arr[i].second) * remain;
                break;
            }
        }
        return maxValue;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends