#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <stdlib.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
#include<valarray>
 
using namespace std;
typedef long long int ll;
typedef unsigned long long int ulli;
typedef long double ld;
typedef pair<int, int> p_int;
typedef pair<ll, ll> p_ll;
typedef pair<double, double> p_dd;
typedef map<ll, ll> o_map;
typedef map<string, ll> os_map;
typedef unordered_map<ll, ll> u_map;
typedef unordered_map<string, ll> us_map;
typedef set<ll> o_set;
typedef unordered_set<ll> u_set;
typedef unordered_map<char, ll> uc_map;
typedef map<char, ll> oc_map;
typedef set<char> oc_set;
typedef unordered_set<char> uc_set;
 
typedef vector<int> v_int;
typedef vector<ll> v_ll;
typedef vector<bool> v_b;
typedef vector<char> v_c;
typedef vector<p_ll> v_lp;
typedef vector<string> v_ss;
typedef vector<vector<char>> v_cc;
typedef vector<vector<bool>> v_bb;
typedef vector<vector<int>> vv_int;
typedef vector<vector<ll>> vv_ll;
typedef pair<ll,ll> ipair;
ll MOD = 998244353;
ll dx[4] = {-1,1,0,0};
ll dy[4] = {0,0,1,-1};
string dir = "UDRL";
 
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define hfind(c, e) ((c).find(e) != (c).end())
#define mp make_pair
#define pb push_back
#define py cout << "YES" << ln;
#define pn cout << "NO" << ln;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ff first
#define ss second
#define INF 2e18
#define fast_cin()                  \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)

v_ll dp1,dp2,val,sum;
void dfs1(ll u,v_ll adj[])
{
    sum[u] += val[u];

    for(auto v : adj[u])
    {
        dfs1(v,adj);
        dp1[u] = dp1[v] + sum[v];
        sum[u] += sum[v];
    }
}
void dfs2(ll u,v_ll adj[])
{
    for(auto v : adj)
    {
        dp1[u] -= (dp1[v]+sum[v]);
        sum[u] -= sum[v];
        sum[v] += sum[u];
        dp1[v] += (dp1[u]+sum[u]);
        dp2[u] = dp1[u];
        dfs2(v,adj);
        dp1[v] -= (dp1[u]+sum[u]);
        sum[v] -= sum[u];
        sum[u] += sum[v];
        dp1[u] += (dp1[v]+sum[v]);
    }
}
void solve()
{
    ll n;
    cin>>n;

    v_ll adj[n+1];

    forn(i,n-1)
    {
        ll x,y;
        cin>>x>>y;

        adj[x].pb(y);
    }
    dp1.resize(n+1,0);
    dp2.resize(n+1,0);
    val.resize(n+1,0);
    sum.resize(n+1,0);
    forn(i,n)
    cin>>val[i];

    dfs1(1,adj);
}

int main()
{
    fast_cin();
    
    
    
    ll t;
    t = 1;
    // cin>>t;
    
    
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}