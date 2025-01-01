//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
  public:
    string convertToRoman(int n) {
        static vector<int> val{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        static vector<string> sym{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string result = "";
        for(int i = 0; i < val.size(); i++) {
            if(n == 0) break;
            int times = n / val[i];

            while(times--) {
                result += sym[i];
            }

            n = n % val[i];
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		Solution ob;
    	cout << ob.convertToRoman(N) << endl;
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends