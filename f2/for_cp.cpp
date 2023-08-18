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
ll dx[4] = {0,1,-1,0};
ll dy[4] = {1,0,0,-1};
string dir = "RDUL";
 
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
 
ll ceil_div(ll a, ll b)
{
  return (a+b-1)/b;
}
 
void add_edge(v_ll adj[],ll u,ll v)
{
  adj[u].pb(v);
  // adj[v].pb(u);
}
struct node{
  int parent;
  int rank;
};
vector<node> dsuf;
ll Find(ll p)
{
  if(dsuf[p].parent == p)
  return p;
  return dsuf[p].parent = Find(dsuf[p].parent);
}
void Union(ll x,ll y)
{
  if(dsuf[x].rank == dsuf[y].rank)
  {
    dsuf[x].parent = y;
    dsuf[y].rank++;
  }
  else if(dsuf[x].rank > dsuf[y].rank)
  dsuf[y].parent = x;
  else 
  dsuf[x].parent = y;
 
}
void merge(v_lp &v,ll &cnt,ll l,ll mid,ll r)
{
  ll n1 = mid-l+1;
  ll n2 = r-mid;
 
  v_lp L(n1),R(n2);
  forn(i,n1)
  L[i] = v[l+i];
  
  forn(j,n2)
  R[j] = v[mid+1+j];
 
  ll i = 0;
  ll j = 0;
  ll k = l;
  while(i<n1 && j<n2)
  {
    if(L[i].ff <= R[j].ff)
    {
      v[k] = R[j];
      j++;
      k++;
    }
    else 
    {
      cnt += n2-j;
      v[k] = L[i];
      i++;
      k++;
 
    }
  }
  while(i<n1)
  {
    v[k] = L[i];
    i++;
    k++;
  }
  while(j<n2)
  {
    v[k] = R[j];
    j++;
    k++;
  }
 
}
 
 
void mergesort(v_lp &v,ll l,ll r,ll &cnt)
{
  if(l>=r)
  return;
  ll mid = (r-l)/2 + l;
  mergesort(v,l,mid,cnt);
  mergesort(v,mid+1,r,cnt);
  merge(v,cnt,l,mid,r);
}
void Update(ll idx,ll val,v_ll &BIT)
{
  idx++;
  while(idx <= BIT.size())
  {
    BIT[idx] += val;
    idx += idx & (-idx);
  }
}

ll Sum_range(ll idx,v_ll &BIT)
{
  ll sum = 0;
  idx++;
  while(idx > 0)
  {
    sum += BIT[idx];
    idx -= idx & (-idx);
  } 
  return sum;
}
 
ll Fenwick_tree(v_ll arr)
{
  ll n = arr.size();
  v_ll BIT(n+1,0);
 
  forn(i,n)
  Update(i,arr[i],BIT);
 
  // for queries
  // if l == 0 :
  // return Sum_range(r,BIT);
  // else 
  // return Sum_range(r,BIT) - Sum_range(l-1,BIT);
  return 0;
}

vector<ll> segment_tree;
ll Construct_segment_tree(v_ll arr,ll n,ll cur,ll st,ll se)
{
  if(st == se)
  {
    segment_tree[cur] = arr[st];
    return arr[st];
  }
  ll mid = (se-st)/2 + st;
 
  segment_tree[cur] = max(Construct_segment_tree(arr,n,2*cur+1,st,mid),Construct_segment_tree(arr,n,2*cur+2,mid+1,se));
  return segment_tree[cur];
 
}
ll Query(ll st,ll se,ll qs,ll qe,ll cur)
{
  if(qs <= st && qe >= se)
  return segment_tree[cur];
  if(st > qe || se < qs)
  return 0;
  ll mid = (se-st)/2 + st;
  ll left = Query(st,mid,qs,qe,2*cur+1);
  ll right = Query(mid+1,se,qs,qe,2*cur+2);
 
  return max(left,right);
}
void Update_val(ll cur,ll st,ll se,ll val,ll idx)
{
  if(st == se){
  segment_tree[cur] = val;
  return;
  }
  ll mid = (se-st)/2 + st;
 
  if(idx > mid)
  Update_val(2*cur+2,mid+1,se,val,idx);
  else 
  Update_val(2*cur+1,st,mid,val,idx);
  
  segment_tree[cur] = segment_tree[2*cur+1] + segment_tree[2*cur+2];
}
void Segment_tree(v_ll arr,ll n)
{
  // ll x = ceil(log2(n));
  // ll sz = 2*(ll(pow(2,x)))- 1;
  ll sz = 4*n;
  segment_tree.resize(sz);
  Construct_segment_tree(arr,n,0,0,n-1);
  // ll qs = 0,qe = 2;
  // cout<<Get_sum(0,n-1,qs,qe,0)<<ln;
  // For update values
 
  // ll new_val = 2;
  // ll idx = 1;
  // Update_val(0,0,n-1,new_val,idx);
 
  // For querying sum
 
  // cout<<Get_sum(0,n-1,qs,qe,0)<<ln;
 
}



/*





// Lazy propagation 
v_ll segment_tree_lazy,lazy;

ll construct_lazy_segment_tree(ll st,ll en,v_ll &arr,ll cur)
{
  if(st == en)
  {
    segment_tree_lazy[cur] = arr[st];
    return segment_tree_lazy[cur];
  }
  ll mid = (en-st)/2 + st;

  ll left = construct_lazy_segment_tree(st,mid,arr,2*cur+1);
  ll right = construct_lazy_segment_tree(mid+1,en,arr,2*cur+2);

  return segment_tree_lazy[cur] = max(left,right);
}

void update_in_range(ll st,ll en,ll qs,ll qe,ll cur,ll val)
{
  if(lazy[cur] != 0)
  {
    segment_tree_lazy[cur] += val;
    if(st != en)
    {
      segment_tree_lazy[2*cur+1] = lazy[cur];
      segment_tree_lazy[2*cur+2] = lazy[cur];
    }
    lazy[cur] = 0;
  }

  // No overlap
  if(st > en || qe < st || en < qs)
  return;

  // Complete overlap
  if(qs <= st && en <= qe)
  {
    segment_tree_lazy[cur] += val;
    if(st != en)
    {
      lazy[2*cur+1] = lazy[cur];
      lazy[2*cur+2] = lazy[cur];
    }
    return;
  }

  // Partial overlap

  ll mid = (en-st)/2 + st;
  update_in_range(st,mid,qs,qe,2*cur+1,val);
  update_in_range(mid+1,en,qs,qe,2*cur+2,val);

  segment_tree_lazy[cur] = max(segment_tree_lazy[2*cur+1],segment_tree_lazy[2*cur+2]);
}

ll Query(ll st,ll en,ll qs,ll qe,ll cur)
{
  if(lazy[cur] != 0)
  {
    segment_tree_lazy[cur] += lazy[cur];
    if(st != en)
    {
      lazy[2*cur+1] = lazy[cur];
      lazy[2*cur+2] = lazy[cur];
    }
    lazy[cur] = 0;
  }
  if(st > en || qe < st || en < qs)
  return INT_MIN;

  if(qs <= st && en <= qe)
  return segment_tree_lazy[cur];

  ll mid = (en-st)/2 + st;
  ll left = Query(st,mid,qs,qe,2*cur+1);
  ll right = Query(mid+1,en,qs,qe,2*cur+2);

  return max(left,right);
}
void Segment_tree_lazy(v_ll arr,ll n)
{
  segment_tree_lazy.resize(4*n);
  lazy.resize(4*n,0);
  construct_lazy_segment_tree(0,n-1,arr,0);
  update_in_range(0,n-1,3,5,0,4);
  cout<<Query(0,n-1,2,5,0)<<ln;
}

*/


// ll dp_cnt[19][201][2];
// ll cnt_num(string s,ll i,ll sum,ll tight)
// {
//   if(i >= s.length() || sum < 0)
//   {
//     if(sum == 0)
//     return 1;
//     else 
//     return 0;
//   }
//   if(dp_cnt[i][sum][tight] != -1)
//   return dp_cnt[i][sum][tight];
 
//   ll up = (tight == 1) ? (s[i]-'0') : 9;
//   ll cnt = 0;
//   forn(j,up+1)
//   cnt += cnt_num(s,i+1,sum-j,(tight > 0 && j == up) ? 1 : 0);
 
//   return dp_cnt[i][sum][tight] = cnt;
// }
 
// ll cnt_num_range(ll l,ll r,ll sum)
// {
//   if(r == 0 && sum == 0)
//   return 1;
//   memset(dp_cnt,-1,sizeof dp_cnt);
//   ll to_l = cnt_num(to_string(l-1),0,sum,1);
//   memset(dp_cnt,-1,sizeof dp_cnt);
//   ll to_r = cnt_num(to_string(r),0,sum,1);
 
//   return to_r - to_l;
// }
ll LPS(string s)
{
  v_ll lps(s.size(),0);
  forsn(i,1,s.length())
  {
    ll j = lps[i-1];
    while(j>0 && s[i] != s[j])
    j = lps[j-1];
 
    if(s[i] == s[j])
    j++;
    lps[i] = j;
  }
  return lps.back();
}



// ll arr[10] = {1,1,2,6,4,2,2,4,2,8};
// // ll helper(ll n)
// {
//   if(n < 10)
//   return arr[n];
//   if(((n/10)%10)%2 == 0)
//   return (6*helper(n/5)*arr[n%10])%10;
//   else 
//   return (4*helper(n/5)*arr[n%10])%10;
// }
ll mod = 1e9 + 7;

void solve()
{
  ll n;
  cin>>n;

  v_ll arr(n);
  forn(i,n)
  cin>>arr[i];

  v_ll a1 = arr;
  v_ll a2 = arr;
  ll res = 0;
  forn(i,n)
  {
    if(a1[i] == 0)
    {
      a1[i] = 1;
      break;
    }
  }

  rforn(i,n-1)
  {
    if(a2[i] == 1)
    {
      a2[i] = 0;
      break;
    }
  }
  v_lp aa;
  v_lp aa1,aa2;
  forn(i,n)
  {
    aa.pb({arr[i],i});
    aa1.pb({a1[i],i});
    aa2.pb({a2[i],i});
  }
  ll cnt = 0;
  mergesort(aa1,0ll,n-1,cnt);
  res = max(res,cnt);
  // cout<<cnt<<ln;
  cnt = 0;
  mergesort(aa2,0ll,n-1,cnt);
  res = max(res,cnt);
  // cout<<cnt<<ln;
  cnt = 0;
  mergesort(aa,0ll,n-1,cnt);
  res = max(res,cnt);
  // cout<<cnt<<ln;

  cout<<res<<ln;


}

int main()
{
  fast_cin();
 
  
 
  ll t;
  // t = 1;
  cin>>t;
  
  
  for (int it = 1; it <= t; it++)
  {
    solve();
  }
  return 0;
}