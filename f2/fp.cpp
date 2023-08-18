#include <bits/stdc++.h>
using namespace std;
#define ll long long
void dfs(vector<ll> adj[],ll u,vector<bool> &vis,ll k,vector<ll> dist[])
{
    vis[u] = true;
    for(auto v : adj[u])
    {
        if(vis[v])
        continue;
        dist[v].push_back(1+dist[u][k]);
        dfs(adj,v,vis,k,dist);


    }

}
int main() {
    ll n,m;
    cin>>n>>m;

    vector<ll> adj[n];
    for(ll i = 0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll x,y,z;
    cin>>x>>y>>z;

    vector<ll> dist[n];
    vector<bool> vis(n,false);
    dist[x].push_back(0);
    dfs(adj,x,vis,0,dist);
    vis = vector<bool> (n,false);
    dist[y].push_back(0);
    dfs(adj,y,vis,1,dist);
    vis = vector<bool> (n,false);
    dist[z].push_back(0);
    dfs(adj,z,vis,2,dist);


    ll res = 0;
    for(ll i = 0;i<n;i++)
    {
        if(i != x && i != y && i != z)
        {
            sort(dist[i].begin(),dist[i].end());
            if(dist[i][0]*dist[i][0]+dist[i][1]*dist[i][1] == dist[i][2]*dist[i][2])
            res++;
        }
    }
    cout<<res<<endl;
}