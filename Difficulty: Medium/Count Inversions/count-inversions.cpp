//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int merge(vector<int>& arr, int l, int mid, int r) {
        vector<int> temp;
        int left = l;
        int right = mid + 1;
        int cnt = 0;
        
        while(left <= mid && right <= r) {
            if(arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                cnt += (mid - left + 1);
                right++;
            }
        }
        
        while(left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right <= r) {
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i = l; i <= r; i++) {
            arr[i] = temp[i - l];
        }
        
        return cnt;
    }
    
    int mergeSort(vector<int>& arr, int l, int r) {
        int cnt = 0;
        if(l >= r) return cnt;
        int mid = (l + r) / 2;
        cnt += mergeSort(arr, l, mid);
        cnt += mergeSort(arr, mid + 1, r);
        cnt += merge(arr, l, mid, r);
        return cnt;
    }
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends