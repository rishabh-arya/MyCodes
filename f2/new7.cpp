#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
using namespace std;
void can_we_reach(vector<vector<int>> maze,vector<vector<int>> &path,int n,int x,int y,int &cnt)
{
    if(x < 0 || y< 0 || x>=n || y >= n || maze[x][y] == 0 || path[x][y] == 1)
    return;
    path[x][y] = 1;
    
    if(x == n - 1 && y == n-1)
    {
        cnt++;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            cout<<path[i][j];
            cout<<endl;
        }
        cout<<endl;
        path[x][y] = 0;
    }

    can_we_reach(maze,path,n,x,y+1,cnt);
    can_we_reach(maze,path,n,x+1,y,cnt);
    can_we_reach(maze,path,n,x,y-1,cnt);
    can_we_reach(maze,path,n,x-1,y,cnt);
    path[x][y] = 0;
    

}
int count_sub_arrays_with_average_equals_given(int arr[],int k,int n)
{
    unordered_map<int,int> mp;
    int cur_sum = 0;
    int cnt = 0;
    for(int i = 0;i<n;i++)
    {
        cur_sum += arr[i] - k;
        if(cur_sum == 0)
        cnt++;
        if(mp.find(cur_sum) != mp.end())
        cnt += mp[cur_sum];
        mp[cur_sum]++;
    }
    return cnt;

}

int main()
{
    // // vector<vector<int>> maze = {{1,1,0},{1,1,0},{1,1,1}};

    // // cout<<"The maze representation :"<<endl;
    // // for(int i = 0;i<maze.size();i++)
    // // {
    // //     for(int j = 0;j<maze[i].size();j++)
    // //     cout<<maze[i][j];
    // //     cout<<endl;
    // // }
    // // vector<vector<int>> path(3,vector<int>(3,0));
    // // cout<<"The possible paths: "<<endl;
    // // int cnt = 0;
    // // can_we_reach(maze,path,3,0,0,cnt);
    // // cout<<"The possible path are : "<<cnt<<endl;
    // string s = "heap";
    // cout<<s<<endl;
    // cout<<s.substr(0,1)<<endl;
    // s = s.substr(1,-1);
    // cout<<s<<endl;
    int K = 6;
    int arr[] = {12, 5, 3, 10, 4, 8, 10, 12, -6, -1};
    int n = 10;
    cout<<count_sub_arrays_with_average_equals_given(arr,K,n)<<endl;




    return 0;
}