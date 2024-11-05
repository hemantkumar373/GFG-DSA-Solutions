//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution
{
  public:
    long long int findsubstr(string& s, int k){
        int l = 0, r = 0;
        int cnt = 0;
        long long int maxCnt = 0;
        int hash[26] = {0};
        
        while(r < s.size()){
            if(hash[s[r] - 'a'] == 0) cnt++;
            hash[s[r] - 'a']++;
            
            while(cnt > k){
                hash[s[l] - 'a']--;
                if(hash[s[l] - 'a'] == 0) cnt--;
                l++;
            }
            
            maxCnt += (r - l + 1);
            r++;
        }
        return maxCnt;
    }
    long long int substrCount (string s, int k) {
        return findsubstr(s, k) - findsubstr(s , k - 1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	
cout << "~" << "\n";
}
}
// } Driver Code Ends