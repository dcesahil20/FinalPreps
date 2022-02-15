#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsTraversal(int V, vector<int> adj[]){

    vector<int> bfs_res;
    vector<int> vis(V+1, 0);


    for(int i=1; i<=V; i++){
        
        if(vis[i]==0){
                queue<int> q;
                q.push(i);
                vis[i] = 1;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    bfs_res.push_back(node);

                    for(auto it : adj[node]){
                        if(vis[it]==0){
                            q.push(it);
                            vis[it]=1;
                        }
                    }
            }
        }
    }

    return bfs_res;
}


void dfs(int node, vector<int> &res, vector<int> adj[], vector<int> &vis){
    
    res.push_back(node);
    vis[node] = 1;

    for(auto i : adj[node]){
        if(!vis[i]){
            dfs(i, res, adj, vis);
        }
    }
}

vector<int> dfsTraversal(int V, vector<int> adj[]){
    
    vector<int> dfs_res;
    vector<int> vis(V+1,0);

    for(int i=1; i<=V; i++){
        if(!vis[i]){
            dfs(i, dfs_res, adj, vis);
        }
    }

    return dfs_res;
}


bool dfsCycleHelper(int node, int parent, vector<int> adj[], vector<int>&vis){
    vis[node]=1;
    for(auto i : adj[node]){
        if(!vis[i]){
            if(dfsCycleHelper(i, node, adj, vis)){
                return true;
            }
        }
        else if(i!=parent){
            return true;
        }
    }

    return false;
}

bool checkCycle(int V, vector<int> adj[]){
    
    vector<int> vis(V+1, 0);
    for(int i=1; i<=V; i++){
        if(!vis[i]){
            if(dfsCycleHelper(i, -1, adj, vis)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    //n vertices, e edges
    int n, e, u, v;
    cin >> n >> e;

    vector<int> adj[n+1];
    //assuming 1 based indexing of graph nodes

    for(int i=1; i<=e; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); //undirected graph
    }

    //print vertices with edges
    //NOTE: This fails because ye sare nodes par nahi 
    //jarha hai aur visited array ka concepot bhi nahi use kar rahe

    // for(int i=0; i<n+1; i++){
    //     for(int j=0; j<varr[i].size(); j++){
    //         cout << i << ":" << varr[i][j] << endl;
    //         //i->vertex : edges
    //     }
    // }

    cout << "BFS" << endl;

    vector<int> bfs = bfsTraversal(n, adj);
    
    for(auto i: bfs){
        cout << i << " ";
    }

    cout << "DFS" << endl;

    vector<int> dfs = dfsTraversal(n, adj);

    for(auto i: dfs){
        cout << i << " ";
    }

    bool hasCycle = checkCycle(n, adj);
    cout << "cycle? : "<< hasCycle << endl;
}

// 9 9
// 1 3
// 3 4
// 2 5
// 5 6
// 5 6
// 6 7
// 7 8
// 8 9 
// 9 10