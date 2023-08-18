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

using namespace std;
typedef long long int ll;
typedef unsigned long long int ulli;
typedef long double ld;
typedef pair<int, int> p_int;
typedef pair<ll, ll> p_ll;
typedef pair<double, double> p_dd;
typedef map<ll, ll> o_map;
typedef unordered_map<ll, ll> u_map;
typedef set<ll> o_set;
typedef unordered_set<ll> u_set;
typedef unordered_map<char, ll> uc_map;
typedef map<char, ll> oc_map;
typedef set<char> oc_set;
typedef unordered_set<char> uc_set;

typedef vector<int> v_int;
typedef vector<ll> v_ll;
typedef vector<string> v_ss;
typedef vector<vector<int>> vv_int;
typedef vector<vector<ll>> vv_ll;
ll MOD = 998244353;

#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define find(c, e) ((c).find(e) != (c).end())
#define mp make_pair
#define pb push_back
#define py cout << "YES" << ln;
#define pn cout << "NO" << ln;
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define INF 2e18
#define fast_cin()                  \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)



void solve()
{
  ll n,v;
  cin>>n>>v;

  ll max_cost = (n*(n-1))/2;
  ll min_cost = 0;

  ll r = n-1;
  ll p = 0;
  forsn(i,1,n)
  {
    if(r > p)
    {
      min_cost = min_cost + (v-p)*i;
      p = v;
    }
    else 
    break;
    p--;
    r--;
  }

  cout<<max_cost<<" "<<min_cost<<ln;

  
















  
    
  
}

int main()
{
  fast_cin();
  // solve();
  ll t;
  cin >> t;
  for (int it = 1; it <= t; it++)
  {
    solve();
  }
  return 0;
}