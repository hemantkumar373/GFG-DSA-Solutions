//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
    bool isCyclic(int src, int prt, vector<vector<int>> &adjLs, vector<int> &vis) {
        vis[src] = 1;
        for(auto i : adjLs[src]) {
            if(!vis[i]) {
                if(isCyclic(i, src, adjLs, vis)) return true;
            }
            else if(i != prt) return true;
        }
        return false;
    }
    int isTree(int n, int m, vector<vector<int>> &adj) {
        if(m != n - 1) return 0;
        
        vector<vector<int>> adjLs(n);
        for(auto it : adj) {
            adjLs[it[0]].push_back(it[1]);
            adjLs[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n, 0);
        int start = 0;
        if(isCyclic(start, -1, adjLs, vis)) return 0;
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    
cout << "~" << "\n";
}
}

// } Driver Code Ends