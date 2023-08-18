#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define INF 0x3f3f3f3f
int find_min_index(int V,map<int,int> mp)
{
    int min_index = 0;
    for(int i = 1;i<V;i++)
    {
        if(mp[i]<mp[min_index])
        min_index = i;
    }
    return min_index;
}
int min_value_of_array(int V,int dist[])
{
    int min_value = INF;
    for(int i = 0;i<V;i++)
    {
        if(min_value > dist[i])
        min_value = dist[i];
    }
    return min_value;
}
void MinimumSpanningTree(int V=5,int matrix[][V])
{
    map<int,int> mp;
    mp[0] = 0;
    for(int i = 1;i<V;i++)
    mp[i] = INF;
    vector<bool> mst(V,false);
    for(int i = 0;i<V;i++)
    {
        int min_index = find_min_index(V,mp);
        while(!mst[min_index])
        {
            min_index = find_min_index(V,mp);
        }
        mst[min_index] = true;
        for(int j = 0;j<V;j++)
        {
            mp[j] = min_value_of_array(V,matrix[j]);
        }

    }
    for(int i = 0;i<V;i++)
    cout<<i<<" "<<mp[i]<<endl;
}
int main()
{
    int V = 5;
    int matrix[][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    MinimumSpanningTree(V,matrix);


    return 0;
}