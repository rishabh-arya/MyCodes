#include <iostream>
#include <queue>
#include <math.h>
#include<map>
using namespace std;
struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
void InorderTraversal(struct BinaryTreeNode *root)
{
    if (root == NULL)
        return;
    InorderTraversal(root->left);
    cout << root->data << " ";
    InorderTraversal(root->right);
}
void PreorderTraversal(struct BinaryTreeNode *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}
void PostorderTraversal(struct BinaryTreeNode *root)
{
    if (root == NULL)
        return;
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    cout << root->data << " ";
}
void LevelTraversal(struct BinaryTreeNode *root)
{
    queue<struct BinaryTreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        struct BinaryTreeNode *ptr = q.front();
        q.pop();
        cout << ptr->data << " ";
        q.push(ptr->left);
        q.push(ptr->right);
    }
}
int NumberofNodes(struct BinaryTreeNode *root)
{
    if (root == NULL)
        return 0;

    return 1 + NumberofNodes(root->left) + NumberofNodes(root->right);
}
int SumofNodes(struct BinaryTreeNode *root)
{
    if (root == NULL)
        return 0;

    return root->data + SumofNodes(root->left) + SumofNodes(root->right);
}
int HeightofTree(struct BinaryTreeNode *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(HeightofTree(root->left), HeightofTree(root->right));
}
int TotalLeafNodes(struct BinaryTreeNode *root)
{
    if (root->left == NULL && root->right == NULL)
        return 1;

    return TotalLeafNodes(root->left) + TotalLeafNodes(root->right);
}
void MirrorofTree(struct BinaryTreeNode *root)
{
    if (root == NULL)
        return;

    BinaryTreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    MirrorofTree(root->left);
    MirrorofTree(root->right);
}
void NoSiblings(struct BinaryTreeNode *root)
{
    if (root == NULL)
        return;
    if ((root->left == NULL && root->right != NULL) || (root->right == NULL && root->left != NULL))
        cout << root->data << " ";

    NoSiblings(root->left);
    NoSiblings(root->right);
}
struct BinaryTreeNode *removeleaves(struct BinaryTreeNode *root)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
        return NULL;

    root->left = removeleaves(root->left);
    root->right = removeleaves(root->right);
    return root;
}
bool isbalanced(struct BinaryTreeNode *root)
{
    if (root == NULL)
        return true;
    int l = HeightofTree(root->left);
    int r = HeightofTree(root->right);
    if (abs(l - r) > 1)
        return false;

    return isbalanced(root->left) && isbalanced(root->right);
}
class checkBalanced
{
public:
    bool isbal;
    int height;
    checkBalanced(int height, bool isbal)
    {
        this->height = height;
        this->isbal = isbal;
    }
};
checkBalanced is_balanced(struct BinaryTreeNode *root)
{
    if (root == NULL)
        return checkBalanced(0, true);
    int l = HeightofTree(root->left);
    int r = HeightofTree(root->right);
    int h = max(l, r);
    checkBalanced o(h + 1, true);
    checkBalanced left = is_balanced(root->left);
    checkBalanced right = is_balanced(root->right);
    if (!left.isbal || !right.isbal)
        o.isbal = false;
    if (abs(left.height - right.height) > 1)
        o.isbal = false;

    return o;
}
int diameter(struct BinaryTreeNode *root)
{
    if (root == NULL)
        return 0;
    int l = HeightofTree(root->left);
    int r = HeightofTree(root->right);
    int d = l + r + 1;
    int left = diameter(root->left);
    int right = diameter(root->right);
    return max(max(left, right), d);
}
class Diameter
{
public:
    int height;
    int diam;
    Diameter(int height, int diam)
    {
        this->diam = diam;
        this->height = height;
    }
};
Diameter diameter_of_tree(struct BinaryTreeNode *root)
{
    if (root == NULL)
        return Diameter(0, 0);
    Diameter left = diameter_of_tree(root->left);
    Diameter right = diameter_of_tree(root->right);
    int d = left.height + right.height + 1;
    Diameter o(max(left.height, right.height) + 1, max(d, max(left.diam, right.diam)));
    return o;
}
struct BinaryTreeNode *Array_to_BST(int arr[], int l, int r)
{
    if (l > r)
        return NULL;
    int mid = (l + r) / 2;
    BinaryTreeNode *root = new BinaryTreeNode(arr[mid]);
    root->left = Array_to_BST(arr, l, mid - 1);
    root->right = Array_to_BST(arr, mid + 1, r);

    return root;
}
int Leftmax(struct BinaryTreeNode *root)
{
    if (root == NULL)
        return INT_MIN;
    int left = Leftmax(root->left);
    int right = Leftmax(root->right);
    return (max(max(left, right), root->data));
}
int Rightmin(struct BinaryTreeNode *root)
{
    if (root == NULL)
        return INT_MAX;
    int left = Rightmin(root->left);
    int right = Rightmin(root->right);
    return (min(min(left, right), root->data));
}
bool is_BST(struct BinaryTreeNode *root)
{
    if (root == NULL)
        return true;

    int leftmax = Leftmax(root->left);
    int rightmin = Rightmin(root->right);
    if (root->data <= leftmax || root->data > rightmin)
        return false;
    bool left = is_BST(root->left);
    bool right = is_BST(root->right);
    return left && right;
}
class IsBST
{
public:
    int leftmax;
    int rightmin;
    bool is_bal;

    IsBST(int leftmax, int rightmin, bool is_bal)
    {
        leftmax = this->leftmax;
        rightmin = this->rightmin;
        is_bal = this->is_bal;
    }
};
IsBST check_for_bst(struct BinaryTreeNode *root)
{
    if (root == NULL)
        return IsBST(INT_MIN, INT_MAX, true);
    IsBST left = check_for_bst(root->left);
    IsBST right = check_for_bst(root->right);
    int mi = min(min(left.rightmin, right.rightmin), root->data);
    int mx = max(max(left.leftmax, right.leftmax), root->data);

    IsBST obj(mx, mi, true);
    if (!left.is_bal)
        obj.is_bal = false;

    if (!right.is_bal)
        obj.is_bal = false;

    if (left.leftmax >= root->data || right.rightmin < root->data)
        obj.is_bal = false;

    return obj;
}
void insert(struct BinaryTreeNode *root, int key)
{
    queue<struct BinaryTreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        struct BinaryTreeNode *tmp = q.front();
        q.pop();
        if (tmp->left == NULL)
        {
            tmp->left = new BinaryTreeNode(key);
            break;
        }
        else
            q.push(tmp->left);
        if (tmp->right == NULL)
        {
            tmp->right = new BinaryTreeNode(key);
            break;
        }
        else
            q.push(tmp->right);
    }
}
void del_right_most(struct BinaryTreeNode *root, struct BinaryTreeNode *del_node)
{
    queue<struct BinaryTreeNode *> q;
    q.push(root);
    struct BinaryTreeNode *tmp;
    while (!q.empty())
    {
        tmp = q.front();
        q.pop();
        if (tmp->right)
        {
            if (tmp->right == del_node)
            {
                tmp->right = NULL;
                delete(del_node);
                return;
            }
            else
            q.push(tmp->right);
        }
        if (tmp->left)
        {
            if (tmp->left == del_node)
            {
                tmp->left = NULL;
                delete(del_node);
                return;
            }
            else
            q.push(tmp->left);
        }
        
    }

}
void delete_node(struct BinaryTreeNode *root, int key)
{
    queue<struct BinaryTreeNode *> q;
    q.push(root);
    struct BinaryTreeNode *tmp, *del_node;
    while (!q.empty())
    {
        tmp = q.front();
        q.pop();
        if (tmp->data == key)
            del_node = tmp;
        if(tmp->left)
        q.push(tmp->left);
        if(tmp->right)
        q.push(tmp->right);
    }
    int x = tmp->data;
    del_node->data = x;
    del_right_most(root, tmp);
}
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    int hd;

    Node(int data)
    {
        this->data = data;
        this->hd = 0;
        this-> left = this->right = NULL;
    }
};

void TopView(struct Node *root)
{
    if(root == NULL)
    return;
    queue<struct Node*> q;
    int hd = 0;
    map<int,int> mp;
    root->hd = hd;
    q.push(root);
    while(q.size())
    {
        hd = root->hd;
        if(mp.count(hd) == 0)
        mp[hd] = root->data;
        if(root->left)
        {
            root->left->hd = hd-1;
            q.push(root->left);
        }
        if(root->right)
        {
            root->right->hd = hd+1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();

    }
    for(auto i = mp.begin();i != mp.end();i++)
    cout<<i->second<<" ";
}
void BottomView(struct Node *root)
{
    if(root == NULL)
    return;
    queue<struct Node*> q;
    int hd = 0;
    map<int,int> mp;
    root->hd = hd;
    q.push(root);
    while(q.size())
    {
        hd = root->hd;
        mp[hd] = root->data;
        if(root->left)
        {
            root->left->hd = hd-1;
            q.push(root->left);
        }
        if(root->right)
        {
            root->right->hd = hd+1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
    }
    for(auto i = mp.begin();i!=mp.end();i++)
    cout<<i->second<<" ";

}
bool SumofTree(struct BinaryTreeNode *root)
{
    if(root == NULL)
    return 1;
    if(root->left == NULL && root->right == NULL)
    return 1;
    int left = SumofNodes(root->left);
    int right = SumofNodes(root->right);

    cout<<"The left sum and the right sum for the node "<<root->data<<" is "<<left<<" and "<<right<<endl;
    if(left + right != root->data)
    return 0;
    bool left_node = SumofTree(root->left);
    bool right_node = SumofTree(root->right);
    return left_node && right_node ;
}
void printHeap(vector<int> vec)
{
    for(int i = 0;i<vec.size();i++)
    cout<<vec[i]<<" ";

    cout<<endl;
}
void swap(int &a,int &b)
{
    int t = a;
    a = b; 
    b = t;
}
void heapify(vector<int> &vec,int parent)
{
    //cout<<vec.size();
    int leftchild = 2*parent + 1;
    int rightchild = 2*parent + 2;
    int largest = parent;
    if(leftchild < vec.size() && vec[leftchild] > vec[parent])
    largest = leftchild;
    if(rightchild < vec.size() && vec[rightchild] > vec[parent])
    largest = rightchild;

    if(largest != parent){
    swap(vec[parent],vec[largest]);
    heapify(vec,largest);
    }

}
void upheapify(vector<int> &vec,int i)
{
    int parent = (i-1)/2;
    if(vec[parent]<vec[i] && parent >=0){
    swap(vec[i],vec[parent]);
    upheapify(vec,parent);
    }
    
}
void deletionHeap(vector<int> &vec)
{
    int last = vec[vec.size()-1];
    vec[0] = last;
    vec.pop_back();
    heapify(vec,0);
}
void insertionHeap(vector<int> &vec,int x)
{
    vec.push_back(x);
    upheapify(vec,vec.size()-1);
}
void Heap(vector<int> &vec)
{
    int non_leaf = (vec.size()-2)/2;
    for(int i = non_leaf;i>=0;i--)
    heapify(vec,i);
}
int main()
{
//     struct BinaryTreeNode *root = new BinaryTreeNode(10);
//     root->left = new BinaryTreeNode(20);
//     root->right = new BinaryTreeNode(30);
//     root->left->left = new BinaryTreeNode(10);
//     root->left->right = new BinaryTreeNode(10);
//     // root->right->left = new BinaryTreeNode(6);
//     // root->right->right = new BinaryTreeNode(9);
//     //root->right->right->left = new BinaryTreeNode();
//     //PreorderTraversal(root);
//     //cout<<endl;
//     //InorderTraversal(root);
//     //cout<<endl;
//     //PostorderTraversal(root);
//     //LevelTraversal(root);
//     //cout<<endl;
//     //cout<<NumberofNodes(root)<<endl;
//     //cout<<SumofNodes(root)<<endl;
//     //cout<<HeightofTree(root)<<endl;
//     //cout<<TotalLeafNodes(root)<<endl;
//     //MirrorofTree(root);
//     //PreorderTraversal(root);
//     //NoSiblings(root);
//     //struct BinaryTreeNode *ptr = removeleaves(root);
//     //PreorderTraversal(ptr);
//     //if(isbalanced(root))
//     //cout<<"Balanced"<<endl;
//     //else
//     //cout<<"Not Balanced"<<endl;
//     //if(is_balanced(root).isbal)
//     //cout<<"Balanced"<<endl;
//     //else
//     //cout<<"Not Balanced"<<endl;
//     //cout<<diameter(root)<<endl;
//     //cout<<diameter_of_tree(root).diam<<endl;
//     //int arr[8] = {1,2,3,4,5,6,7,8};
//     //struct BinaryTreeNode *r = new BinaryTreeNode(0);
//     //struct BinaryTreeNode *ptr = Array_to_BST(arr,0,7);
//     //PreorderTraversal(ptr);
//     //if(check_for_bst(root).is_bal)
//     //cout<<"True"<<endl;
//     // struct BinaryTreeNode *root = new BinaryTreeNode(10);
//     // root->left = new BinaryTreeNode(11);
//     // root->left->left = new BinaryTreeNode(7);
//     // root->left->right = new BinaryTreeNode(12);
//     // root->right = new BinaryTreeNode(9);
//     // root->right->left = new BinaryTreeNode(15);
//     // root->right->right = new BinaryTreeNode(8);
// // InorderTraversal(root);
//     // cout << endl;
//     // int key = 11;
//     // insert(root,key);
//     // InorderTraversal(root);
//     // cout<<endl;
//     //delete_node(root, key);
//     // struct Node *root = new Node(10);
//     // root->left = new Node(11);
//     // root->left->left = new Node(7);
//     // root->left->right = new Node(12);
//     // root->right = new Node(9);
//     // root->right->left = new Node(15);
//     // root->right->right = new Node(8);
//     // //InorderTraversal(root);
//     // cout<<endl;
//     // //TopView(root);
//     // cout<<endl;
//     // BottomView(root);
//     cout<<SumofTree(root);

       vector<int> vec;
       //int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
       vec.push_back(1);
       vec.push_back(3);
       vec.push_back(5);
       vec.push_back(4);
       vec.push_back(6);
       vec.push_back(13);
       vec.push_back(10);
       vec.push_back(9);
       vec.push_back(8);
       vec.push_back(15);
       vec.push_back(17);
       printHeap(vec);
       //deletionHeap(vec);
    //    insertionHeap(vec,34);
       Heap(vec);
       printHeap(vec);





    return 0;
}