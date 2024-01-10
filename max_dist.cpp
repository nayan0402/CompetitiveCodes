//the below code gives you the maximum distance from a node. basically for a node , its maximum distance will be from one of the two nodes that span from the diameter. 
//so using the below code, we can find those two distances.
//then we take their maximum
//MOdify the below code , according to your requirement




#include <bits/stdc++.h>
using namespace std;
 
#define int long long
const int N = 2e5+5;

 
vector<int> g[N], depth(N), dist(N);
vector <bool> vis(N);
 
 
void dfs(int vertex) {

    vis[vertex]=true;
 
 
    for (auto child : g[vertex]) {
        
        if (vis[child]) {
            continue;
        }

        depth[child]=depth[vertex]+1;

        dfs(child);

        
    }
    
}

void dfs_dist(int vertex) {

    vis[vertex]=true;
 
 
    for (auto child : g[vertex]) {
        
        if (vis[child]) {
            continue;
        }

        dist[child]=dist[vertex]+1;

        dfs_dist(child);

        
    }
    
} 

void solve() {
    int n,  i, ans=0, node=0;
    cin>>n;
    for(i=1;i<n;i++){
        int l, r;
        cin>>l>>r;
        g[l].push_back(r);
        g[r].push_back(l);
    }

    dfs(1);
    for(i=1;i<=n;i++){
        if(depth[i]>=ans){
            ans=depth[i];
            node=i;
        }
        depth[i]=0;
        vis[i]=false;
    }
    dfs(node);
    ans=0;
    node=0;
    for(i=1;i<=n;i++){
        if(depth[i]>=ans){
            ans=depth[i];
            node=i;
        }
        vis[i]=false;
    }
    dfs_dist(node);
    for(i=1;i<=n;i++){
        cout<<max(depth[i], dist[i])<<" ";
    }
    cout<<endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int TT = 1;
    // cin >> TT;
 
    while (TT--) {
        solve();
    }
 
    return 0;
}
