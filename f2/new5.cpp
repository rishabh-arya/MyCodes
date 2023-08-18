#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;

    node(int data)
    {
        this->data = data;
        left = right = NULL;
    }

};
void find_element(vector<int> &vec,struct node *root,int s,int sum)
{
    if(sum > s)
    return;
    if(sum == s)
    {
        vec.push_back(root->data);
        return;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int s;
        cin>>s;
        struct node *root;
        node* ptr = new node(1);
        root = ptr;
        queue<struct node*> q;
        q.push(root); 
        while(!q.empty())
        {
            struct node *top = q.front();
            q.pop();
            if(top->data > s/2)
            break;
            node* left_node = new node(top->data+1);
            mode* right_node = new node(top->data+2);
            q.push(left_node);
            top->left = left_node;
            top->right = right_node;
            q.push(right_node);


        }
        

    }

    return 0;

}