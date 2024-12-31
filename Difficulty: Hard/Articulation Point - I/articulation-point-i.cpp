//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    void dfs(int node, int parent, vector<int>& low, vector<int>& disc,
            vector<int>& vis, vector<int>& ap, vector<int>adj[], int& timer) {
        vis[node] = 1;
        low[node] = disc[node] = timer++;
        int child = 0;
        
        for(auto it : adj[node]) {
            if(it == parent) continue;
            if(!vis[it]) {
                dfs(it, node, low, disc, vis, ap, adj, timer);
                low[node] = min(low[node], low[it]);
                
                if(low[it] >= disc[node] && parent != -1) {
                    ap[node] = 1;
                }
                child++;
            }
            else {
                low[node] = min(low[node], disc[it]);
            }
        }
        
        if(child > 1 && parent == -1) {
            ap[node] = 1;
        }
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        int timer = 0;
        vector<int> vis(V, 0), low(V, 0), disc(V, 0);
        vector<int> ap(V, 0);
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, -1, low, disc, vis, ap, adj, timer);
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (ap[i] == 1) {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0) return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends