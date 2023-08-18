#include<bits/stdc++.h>
using namespace std;

// void add_edge(vector<int> adj[], int u, int v)
// {
//     adj[u].push_back(v);
//     //adj[v].push_back(u);
// }
// void printGraph(vector<int> adj[],int V)
// {
//     for(int i = 0;i<V;i++)
//     {
//         cout<<i<<"-->";
//         for(auto x:adj[i])
//         cout<<x<<" ";
//         cout<<endl;
//     }
// }
// // //
// // void add_edge(vector<vector<int>> &adj_mat,int u,int v)
// // {
// //     adj_mat[u][v] = 1;
// //     adj_mat[v][u] = 1;
// // }
// // void printGraph(vector<vector<int>> &adj_mat,int V)
// // {
// //      for(int i = 0;i<V;i++)
// //     {
// //         for(int j = 0;j<V;j++)
// //         cout<<adj_mat[i][j]<<" ";
// //         cout<<endl;
// //     }
// // }
// // void BFS(vector<int> adj[],int V,int s)
// // {
// //     bool visited[V+1];
// //     for(int i = 1;i<=V;i++)
// //     visited[i] = false;
// //     queue<int> q;
// //     q.push(s);
// //     visited[s] = true;
/////
// //     while(!q.empty())
// //     {
// //         int t = q.front();
// //         q.pop();
// //         cout<<t<<"-->";
// //         for(auto i:adj[t])
// //         {
// //             if(!visited[i]){
// //             q.push(i);
// //             visited[i] = true;
// //             }
// //         }
// //     }
/////
// // }

// void DFS(vector<int> adj[],vector<bool> &visited,int s)
// {
//     visited[s] = true;
//     cout<<s<<"-->";

//     for(auto i : adj[s])
//     {
//         if(!visited[i])
//         DFS(adj,visited,i);
//     }
    
// }
// void connected_components(vector<int> adj[],vector<bool> &visited,int V)
// {
//     for(int i = 0;i<V;i++)
//     {
//         if(!visited[i]){
//         DFS(adj,visited,i);
//         cout<<endl;
//         }
//     }
// }


# define INF 0x3f3f3f3f
typedef pair<int,int> ipair;
void add_edge(vector<ipair> adj[],int u,int v,int wt)
{
    adj[u].push_back(make_pair(v,wt));
    adj[v].push_back(make_pair(u,wt));
}
void print_path(vector<int> parent,int j)
{
    if(parent[j] == -1)
    return;
    print_path(parent,parent[j]);
    cout<<j<<"-->";
}
void Dijkstra(vector<ipair> adj[],int V,int src,int dest)
{
    // priority queue (a,b) where a = current distance of node b from source node in form of min_heap
    // dist vector (V,dis) where first element represents it's current distance from source node
    // map is used for storing (node,its parent) for retracing shortest path between source to destination node
    // adj is adjacency list adj[u] has two parameters first is node v, second is weight of edge uv 
    priority_queue<ipair,vector<ipair>,greater<ipair>> pq;
    vector<int> parent(V);
    parent[src] = -1;
    vector<int> dist(V,INF);
    vector<bool> vis(V,false);
    pq.push(make_pair(0,0));
    dist[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(vis[u])
        continue;
        else 
        vis[u] = true;
        for(auto x:adj[u])
        {
            int v = x.first;
            int weight = x.second;
            if(dist[v]>dist[u] + weight){
            dist[v] = dist[u] + weight;
            pq.push(make_pair(dist[v],v));
            parent[v] = u;
            }
        }
    }
    for(int i = 0;i<V;i++)
    cout<<i<<" "<<dist[i]<<endl;

    cout<<endl;
    cout<<"The shortest path from src node "<<src<<" to destination node "<<dest<<endl;
    cout<<src<<"-->";
    print_path(parent,dest);
    // for(auto i = mp.begin();i!=mp.end();i++)
    // cout<<i->first<<" "<<i->second<<endl;

    
}


// int path(int src,int dest,vector<int> adj[],vector<bool> &visited,vector<int> &_path)
// {
//     visited[src] = true;
//     if(src == dest)
//     {
//         return src;
//     }
//     for(auto v:adj[src])
//     {
//         if(!visited[v])
//         {
            
//             int ans = path(v,dest,adj,visited,_path);
//             visited[v] = true;
//             if(ans != -1)
//             _path.push_back(v);
//             return ans;

//         }
//     }
//     return -1;

// }
// struct Edge{
//     int src;
//     int dest;
//     int weight;
// };
// struct Graph{
//     int E,V;
//     struct Edge* edge;
// };
// struct Graph* createGraph(int V,int E)
// {
//     struct Graph* graph = new Graph;
//     graph->E = E;
//     graph->V = V;
//     graph->edge = new Edge[E];
//     return graph;

// }
void BellmanFord(struct Graph * graph,int src)
{
    int V = graph->V;
    int E = graph->E;
    vector<int> dist(V,INF);
    dist[src] = 0;

    for(int i = 1;i<=V-1;i++)
    {
        for(int j = 0;j<E;j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int w = graph->edge[j].weight;
            if(dist[v]>dist[u]+w && dist[u] != INT_MAX)
            dist[v] = dist[u] + w;
        }
    }
    for(int i = 0;i<E;i++)
    {

        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int w = graph->edge[i].weight;
        if(dist[u] != INT_MAX && dist[v]>dist[u] + w){
        cout<<"Negative weight cycle is detected"<<endl;
        }
    }
    for(int i = 0;i<V;i++)
    cout<<dist[i]<<" ";
    return;
}
// int find_min_index(int V,map<int,int> mp)
// {
//     int min_index = 0;
//     for(int i = 1;i<V;i++)
//     {
//         if(mp[i]<mp[min_index])
//         min_index = i;
//     }
//     return min_index;
// }
// int min_value_of_array(int V,int dist[])
// {
//     int min_value = INF;
//     for(int i = 0;i<V;i++)
//     {
//         if(min_value > dist[i])
//         min_value = dist[i];
//     }
//     return min_value;
// }
// void MinimumSpanningTree(int V,int graph_matrix[][V])
// {
//     map<int,int> mp;
//     mp[0] = 0;
//     for(int i = 1;i<V;i++)
//     mp[i] = INF;
//     vector<bool> mst(V,false);
//     for(int i = 0;i<V;i++)
//     {
//         int min_index = find_min_index(V,mp);
//         while(!mst[min_index])
//         {
//             min_index = find_min_index(V,mp);
//         }
//         mst[min_index] = true;
//         for(int j = 0;j<V;j++)
//         {
//             mp[j] = min_value_of_array(V,graph_matrix[j]);
//         }

//     }
//     for(int i = 0;i<V;i++)
//     cout<<i<<" "<<mp[i]<<endl;
// }
void dfs1(vector<int> adj[],int V,int src,vector<bool> &vis,stack<int> &s)
{
    if(!vis[src])
    {
        vis[src] = true;
        for(auto v: adj[src])
        dfs1(adj,V,v,vis,s);
        s.push(src);
    }
}
void reverse(vector<int> adj[],int V,vector<int> rev[])
{
    for(int i = 0;i<V;i++)
    {
        for(auto v : adj[i])
        rev[v].push_back(i);
    }

}
void dfs2(vector<int> rev[],int V,int src,vector<bool> &vis)
{
    
    if(!vis[src])
    {
        cout<<src<<"-->";
        vis[src] = true;
        for(auto v:rev[src])
        dfs2(rev,V,v,vis);

    }
}
void fcc(vector<int> adj[],int V)
{
    vector<bool> vis(V,false);
    stack<int> s;
    int src = 0;

    dfs1(adj,V,src,vis,s);

    vector<int> rev[V];
    reverse(adj,V,rev);
    for(int i = 0;i<V;i++)
    vis[i] = false;

    while(!s.empty())
    {
        if(!vis[s.top()]){
            int curr = s.top();
            s.pop();
            dfs2(rev,V,curr,vis);
            cout<<endl;
        }
        else 
        s.pop();

    }

    
}
bool ford_fulkerson_bfs(vector<vector<int>>& res_graph,int s,int t,int n,vector<int> &parent)
{
    vector<bool> vis(n,false);
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while(!q.empty())
    {
        int st = q.size();
        while(st--)
        {
            int u = q.front();
            q.pop();
            for(int v = 0;v<n;v++)
            {
                if(!vis[v] && res_graph[u][v] > 0)
                {
                    if(v == t)
                    {
                        parent[v] = u;
                        return true;
                    }
                    parent[v] = u;
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    return false;
}
int ford_fulkerson(vector<vector<int>> graph,int s,int t,int n)
{
    vector<vector<int>> res_graph = graph;
    int max_flow = 0;
    vector<int> parent(n);
    while(ford_fulkerson_bfs(res_graph,s,t,n,parent))
    {
        int curr_flow = INT8_MAX;
        int v = t;
        while(v != s)
        {
            int u = parent[v];
            curr_flow = min(curr_flow,res_graph[u][v]);
            v = u;
        }
        v = t;
        while(v != s)
        {
            int u = parent[v];
            res_graph[u][v] -= curr_flow;
            res_graph[v][u] += curr_flow;
            v = u;
        }
        max_flow += curr_flow;

    }
    return max_flow;
}
// Disjoint Set Union
struct node{
        int parent;
        int rank;
    };
vector<node> dsuf;
int Find(int v)
{
    if(dsuf[v].parent == -1)
        return v;
    return dsuf[v].parent = Find(dsuf[v].parent);
}
void Union(int x,int y)
{
    if(dsuf[x].rank == dsuf[y].rank)
    {
        dsuf[x].parent = y;
        dsuf[y].rank++;
    }
    else if(dsuf[x].rank < dsuf[y].rank)
        dsuf[x].parent = y;
    else 
        dsuf[y].parent = x;
}

// Minimum Spanning Tree
bool sortby_mst(vector<int> &a,vector<int> &b)
{
    return a[2] < b[2];
}
void kruskal_mst(vector<vector<int>> &edge_list,int V)
{
    sort(edge_list.begin(),edge_list.end(),sortby_mst);
    dsuf.resize(V);
    for(int i = 0;i<V;i++)
    {
        dsuf[i].rank = 0;
        dsuf[i].parent = -1;
    }
    int i = 0;
    int j = 0;
    vector<vector<int>> mst;
    while(i < V-1 && j < edge_list.size())
    {
        int xp = Find(edge_list[i][0]);
        int yp = Find(edge_list[i][1]);
        if(xp == yp)
        {
            j++;
            continue;
        }
        Union(xp,yp);
        mst.push_back(edge_list[i]);
        i++;
    }

    for(int i = 0;i<mst.size();i++)
    cout<<mst[i][0]<<" "<<mst[i][1]<<" "<<mst[i][2]<<endl;
}
int min_weight_vertex(vector<int> weight,vector<bool> vis)
{
    int vertex,value = 1e9+12;
    for(int i = 0;i<weight.size();i++)
    {
        if(value > weight[i] && !vis[i])
        {
            value = weight[i];
            vertex = i;
        }
    }
    return vertex;
}
void prime_mst(vector<vector<int>> &edge_list,int V)
{
    vector<int> weight(V+1,1e9);
    vector<bool> vis(V+1,false);
    vector<int> parent(V+1,-1);
    for(int i = 0;i<V-1;i++)
    {
        int u = min_weight_vertex(weight,vis);
        cout<<u<<endl;
        vis[u] = true;
        for(int j = 0;j<edge_list.size();j++)
        {
            if(edge_list[j][0] == u && !vis[edge_list[j][1]] && weight[edge_list[j][1]] > edge_list[j][2])
            {
                weight[edge_list[j][1]] = edge_list[j][2];
                parent[edge_list[j][1]] = u;
            }
            else if(edge_list[j][1] == u && !vis[edge_list[j][0]] && weight[edge_list[j][0]] > edge_list[j][2])
            {
                weight[edge_list[j][0]] = edge_list[j][2];
                parent[edge_list[j][0]] = u;
            }
        }
    }
    for(int i = 0;i<V;i++)
    cout<<i<<" -> "<<parent[i]<<endl;
}
// Implementation of Trie

struct trie_node{
    trie_node *links[26];
    bool isEnd = false;
};

trie_node *root; 
bool isEmpty(trie_node *root)
{
    for(int i = 0;i<26;i++)
    {
        if(root->links[i])
        return false;
    }
    return true;
}
trie_node* delete_node(trie_node *root,string word,int i)
{
    if(!root)
    return root;
    if(i == word.length())
    {
        root->isEnd = false;
        if(isEmpty(root))
        {
            delete root;
            root = NULL;
        }
        return root;
    }
    root->links[word[i]-'a'] = delete_node(root->links[word[i]-'a'],word,i+1);
    if(root->isEnd == false && isEmpty(root))
    {
        delete root;
        root = NULL;

    }
    return root;
}
void trie_node_insert(string word)
{
    trie_node *node = root;
    for(auto c : word)
    {
        if(!node->links[c-'a'])
            node->links[c-'a'] = new trie_node();
        node = node->links[c-'a'];
    }
    node->isEnd = true;

}
bool trie_node_search(string word)
{
    trie_node *node = root;
    for(auto c : word)
    {
        if(!node->links[c-'a'])
            return false;
        node = node->links[c-'a'];
    }
    return node->isEnd;

}
bool trie_node_is_startswith(string word)
{
    trie_node *node = root;
    for(auto c : word)
    {
        if(!node->links[c-'a'])
            return false;
        node = node->links[c-'a'];
    }
    return true;

}
void Trie()
{
    root = new trie_node();
    trie_node_insert("hello");
    trie_node_insert("hellboy");
    trie_node_insert("helsinky");
    cout<<trie_node_search("helsi")<<endl;
    cout<<trie_node_search("helsinky")<<endl;
    cout<<trie_node_is_startswith("hels")<<endl;
}
void floyd_warshall(vector<vector<int>> graph)
{
    int n = graph.size();
    // graph[i][j] = min(graph[i][j],w)

    // graph[i][i] = 0
    for(int k = 0;k<n;k++)
    {
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++){
            if(graph[i][j] == INF)
            cout<<"INF"<<" ";
            else
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

}
void dfs_arti(vector<vector<int>> adj,vector<int> &low,vector<int> &parent,vector<int> &dist,int u,vector<bool> &art)
{
    static int time = 0;
    dist[u] = low[u] = time;
    time++;
    int child = 0;
    for(auto v : adj[u])
    {
        if(dist[v] == -1)
        {
        child++;
        parent[v] = u;
        dfs_arti(adj,low,parent,dist,v,art);
        low[u] = min(low[u],low[v]); // checking if there is a back edge

        if(parent[u] == -1 && child > 1) // case 1 : checking for root to be AP 
        art[u] = true;
        
        if(parent[u] != -1 && low[v] >= dist[u]) // case 2 : checking for non root to be AP
        art[u] = true;
        }
        else if(v != parent[u])
        low[u] = min(low[u],dist[v]); // updating the low value
    }
}
void Articulation_points(vector<vector<int>> adj,int v)
{
    vector<int> low(v,-1),parent(v,-1),dist(v,-1);
    vector<bool> art(v,false);
    for(int i = 0;i<v;i++)
    {
        if(dist[i] == -1)
        dfs_arti(adj,low,parent,dist,i,art);
    }

    cout<<"Articulation Points : ";
    for(int i = 0;i<v;i++)
    {
        if(art[i])
        cout<<i<<" ";
    }
    cout<<endl;
}

class LRUCache {
public:
    int cap;
    list<int> recent; // list of keys
    map<int,list<int> ::iterator> pos; // {key,iterator of the key in the list}
    map<int,int> cache; // {key,value}
    void use(int key)
    {
        if(pos.find(key) != pos.end()) // If present 
            recent.erase(pos[key]);
        else if(cap <= recent.size()) // If size exceeds 
        {
            int old = recent.back(); // Take the old one and erase from everywhere
            recent.pop_back();
            cache.erase(old);
            pos.erase(old);
        }
        recent.push_front(key);
        pos[key] = recent.begin();

    }
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end())
        {
            use(key);
            return cache[key];
        }
        else
        return -1;
    }
    
    void put(int key, int value) {
        use(key);
        cache[key] = value;
    }
};
class LFUCache {
public:
    int cap,size,lfu = 0;
    unordered_map<int,pair<int,int>> values; // {key,{value,frequency}}
    unordered_map<int,list<int>> keys; // {freq_no.,its corresponding list}
    unordered_map<int,list<int> ::iterator> iters; // {key,iterators to it in the list}
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    void update(int key) 
    {
        auto iter = iters[key];
        int freq = values[key].second;
        values[key].second++;
        keys[freq].erase(iter);
        keys[freq+1].push_back(key);
        iters[key] = --keys[freq+1].end();
        if(keys[lfu].empty())
        lfu++;
    }
    int get(int key) {
        if(values.find(key) != values.end())
        {
            update(key);
            return values[key].first;
        }
        else 
        return -1;
    }
    
    void put(int key, int value) {
        if(!cap)
        return;

        if(values.find(key) != values.end())
        {
            update(key);
            values[key].first = value; 
        }
        else 
        {
            if(cap == size)
            {
                int rem_key = keys[lfu].front();
                keys[lfu].pop_front();
                values.erase(rem_key);
                iters.erase(rem_key);

            }
            else 
            size++;

            values[key] = {value,1};
            keys[1].push_back(key);
            iters[key] = --keys[1].end();
            lfu = 1;

        }
    }
};
int main()
{
    // int V = 8;
    // vector<int> adj[V];
    // //vector<vector<int>> adj_mat(V,vector<int>(V));
    // add_edge(adj, 0, 1);
    // add_edge(adj, 0, 4);
    // add_edge(adj, 1, 2);
    // add_edge(adj, 1, 3);
    // add_edge(adj, 6, 2);
    // add_edge(adj, 2, 3);
    // add_edge(adj, 3, 4);
    // add_edge(adj, 5, 6);
    // add_edge(adj, 5, 7);
    // add_edge(adj, 7, 4);
    // add_edge(adj, 7, 1);
    // //printGraph(adj,V);
    // // // // cout<<"Breadth First Traversal"<<endl;
    // // // // BFS(adj,V,0);
    // bool visited[V];
    // for(int i = 0;i<V;i++)
    // visited[i] = false;
    //  cout<<"Depth First Traversal"<<endl;
    //  DFS(adj,visited,0);
    //  cout<<endl;
    //  vector<bool> visit(V,false);
    //  vector<int> _path ; 
    //  path(4,0,adj,visit,_path);
    //  for(int i = 0;i<_path.size();i++)
    //  cout<<_path[i]<<"-->";
    // int V = 9; 
    // vector<ipair> adj[V]; 
  
    // // making above shown graph 
    // add_edge(adj, 0, 1, 4); 
    // add_edge(adj, 0, 7, 8); 
    // add_edge(adj, 1, 2, 8); 
    // add_edge(adj, 1, 7, 11); 
    // add_edge(adj, 2, 3, 7); 
    // add_edge(adj, 2, 8, 2); 
    // add_edge(adj, 2, 5, 4); 
    // add_edge(adj, 3, 4, 9); 
    // add_edge(adj, 3, 5, 14); 
    // add_edge(adj, 4, 5, 10); 
    // add_edge(adj, 5, 6, 2); 
    // add_edge(adj, 6, 7, 1); 
    // add_edge(adj, 6, 8, 6); 
    // add_edge(adj, 7, 8, 7); 
  
    // Dijkstra(adj, V, 0, 4); 
    // int V = 5;
    // vector<bool> visited(V,false);
    // vector<int> adj[V];
    // add_edge(adj,0,0);
    // add_edge(adj,1,1);
    // add_edge(adj,4,4);
    // add_edge(adj,0,1);
    // add_edge(adj,0,2);
    // add_edge(adj,0,4);
    // add_edge(adj,1,4);
    // add_edge(adj,2,4);
    // add_edge(adj,2,3);
    // add_edge(adj,2,0);
    // connected_components(adj,visited,V);
    // int V = 5;
    // int E = 8;
    // struct Graph *graph = createGraph(V,E);
    // graph->edge[0].src = 0;
    // graph->edge[0].dest = 1;
    // graph->edge[0].weight = -1;
    // graph->edge[1].src = 1;
    // graph->edge[1].dest = 2;
    // graph->edge[1].weight = 3;
    // graph->edge[2].src = 1;
    // graph->edge[2].dest = 3;
    // graph->edge[2].weight = 2;
    // graph->edge[3].src = 1;
    // graph->edge[3].dest = 4;
    // graph->edge[3].weight = 2;
    // graph->edge[4].src = 0;
    // graph->edge[4].dest = 2;
    // graph->edge[4].weight = 4;
    // graph->edge[5].src = 3;
    // graph->edge[5].dest = 1;
    // graph->edge[5].weight = 1;
    // graph->edge[6].src = 4;
    // graph->edge[6].dest = 3;
    // graph->edge[6].weight = -3;
    // graph->edge[7].src = 3;
    // graph->edge[7].dest = 2;
    // graph->edge[7].weight = 5;
    // BellmanFord(graph,0);
    // cout<<endl;
    // int V = 5;
    // int graph_matrix[V][V] = {{0, 2, 0, 6, 0},
    //                    {2, 0, 3, 8, 5},
    //                    {0, 3, 0, 0, 7},
    //                    {6, 8, 0, 0, 9},
    //                    {0, 5, 7, 9, 0}};
    // MinimumSpanningTree(V,graph_matrix);

    // int V = 8;
    // vector<int> adj[V];
    // add_edge(adj,0,1);
    // add_edge(adj,1,2);
    // add_edge(adj,2,0);
    // add_edge(adj,2,3);
    // add_edge(adj,3,4);
    // add_edge(adj,4,5);
    // add_edge(adj,4,7);
    // add_edge(adj,5,6);
    // add_edge(adj,6,4);
    // add_edge(adj,6,7);
    // fcc(adj,V);

    // vector<vector<int>> graph{
    //     {0,1,1,1,0,0,0},
    //     {0,0,0,0,1,0,0},
    //     {0,0,0,0,0,1,0},
    //     {0,0,0,0,0,0,0},
    //     {0,0,0,0,0,0,1},
    //     {0,0,0,0,0,0,1},
    //     {0,0,0,0,0,0,0}
        
        
    // };
    // int s = 0,t = 6;
    // int n = 7;

    // cout<<ford_fulkerson(graph,s,t,n)<<endl;
    // int v = 3;
    // dsuf.resize(v+1);
    // for(int i = 0;i<v+1;i++)
    // {
    //     dsuf[i].parent = -1;
    //     dsuf[i].rank = 0;
    // }
    // vector<pair<int,int>> edge_list{{1,2},{2,3},{1,3}};
    // // Iterate over edge_list
    // for(int i = 0;i<v;i++)
    // {
    //     int xp = Find(edge_list[i].first);
    //     int yp = Find(edge_list[i].second);
    //     if(xp == yp)
    //     {
    //         cout<<"Cycle detected between "<<edge_list[i].first<<" and "<<edge_list[i].second<<endl;
    //     }
    //     else 
    //     Union(xp,yp);
    // }

    // int V = 6;
    // vector<vector<int>> edge_list{
    //     {0,1,4},
    //     {1,4,4},
    //     {1,2,6},
    //     {1,3,3},
    //     {0,2,6},
    //     {2,3,1},
    //     {4,5,7},
    //     {4,3,2},
    //     {3,5,3},
    // };
    // kruskal_mst(edge_list,V);
    // prime_mst(edge_list,V);

    // Trie();

    // vector<vector<int>> graph{
    //     {0,5,INF,10},
    //     {INF,0,3,INF},
    //     {INF,INF,0,1},
    //     {INF,INF,INF,0}
    // };

    // floyd_warshall(graph);

    int v = 5;
    vector<vector<int>> adj(v);
    adj[0].push_back(2);
	adj[2].push_back(0);
	adj[0].push_back(3);
	adj[3].push_back(0);
	adj[1].push_back(0);
	adj[0].push_back(1);
	adj[2].push_back(1);
	adj[1].push_back(2);
	adj[3].push_back(4);
	adj[4].push_back(3);

    Articulation_points(adj,v);






    return 0;
}