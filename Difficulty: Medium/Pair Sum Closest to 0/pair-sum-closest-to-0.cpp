//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int closestToZero(int arr[], int n)
    {
        sort(arr, arr + n);
            
        int l = 0, r = n - 1;
        int ans = INT_MAX;
        while(l < r){
            int sum = arr[l] + arr[r];
            if(abs(ans) > abs(sum)){
                ans = sum;
            }
            if(abs(ans) == abs(sum)){
                ans = max(ans, sum);
            }
            if(sum < 0) l++;
            else r--;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}
// } Driver Code Ends