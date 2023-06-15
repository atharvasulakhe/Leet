//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool bfs(int node, vector<int> adj[], int vis[]) {
    queue<int> q;
    q.push(node);
    vis[node] = 1;

    while (!q.empty()) {
        int n = q.front();
        q.pop();

        for (int i = 0; i < adj[n].size(); i++) {
            int adjacentNode = adj[n][i];

            if (vis[adjacentNode] == -1) {
                vis[adjacentNode] = 1 - vis[n];
                q.push(adjacentNode);
            } else if (vis[adjacentNode] == vis[n]) {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[]) {
    int vis[V];
    memset(vis, -1, sizeof(vis));

    for (int i = 0; i < V; i++) {
        if (vis[i] == -1) {
            if (bfs(i, adj, vis) == false) {
                return false;
            }
        }
    }
    return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends