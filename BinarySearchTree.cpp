#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <stack>
#include <list>
#include <map>
#include <unordered_map>
#include <chrono>
#include <numeric>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18+1;
const ll DIV = 1000000007;
//#define TEST
struct Node
{
    int key;
    Node* parent = NULL;
    Node* left = NULL;
    Node* right = NULL;
};

class BinarySearchTree
{
private:
    Node* T;
public:
    void insert(ll value)
    {
        if(T==NULL)
        {
            Node* tmp = new Node();
            tmp->key = value;
            T = tmp;
        }else
        {
            Node* tmp = new Node();
            tmp->key = value;
            Node* base = T;
            while(tmp->parent==NULL)
            {
                if(base->key > tmp->key)
                {
                    if(base->left == NULL)
                    {
                        tmp->parent = base;
                        base->left=tmp;
                    }else
                    {
                        base = base->left;
                    }
                }else
                {
                    if(base->right == NULL)
                    {
                        tmp->parent = base;
                        base->right = tmp;
                    }else
                    {
                        base = base->right;
                    }
                }
            }
        }
    }

    void print(void)
    {
        print_intermediate();
        print_preceding();

    }
    void print_intermediate(void)
    {
        stack<Node*> nodes;
        Node* node = T;
        while(node->right!=NULL)
        {
            node=node->right;
        }
        Node* end = node;
        node = T;
        Node* pre_node=NULL;
        bool endNodeSearch = false;//endnodeが左にnodeを持っているか
        if(end->left!= NULL) endNodeSearch = true;//endnodeが左にnodeを持っている
        while(node != end || endNodeSearch != false)
        {
            while(node->left!=NULL && pre_node != node->left)//左のノードがある
            {
                if(node==end) endNodeSearch = false;
                nodes.push(node);
                pre_node = node;
                node = node->left;
            }
            cout << " " << node->key;
            if(node->right!=NULL)//右のノードがある
            {
                pre_node = node;
                node = node->right;
            }else//左右のノードがない
            {
                node = nodes.top();
                pre_node = node->left;
                nodes.pop();
            }
        }
        cout << " " << end->key << endl;
    }

    void print_preceding(void)
    {
        stack<Node*> nodes;
        Node* node = T;
        while(node->right!=NULL)
        {
            node=node->right;
        }
        Node* end = node;
        node = T;
        Node* pre_node=NULL;
        bool endNodeSearch = false;//endnodeが左にnodeを持っているか
        if(end->left!= NULL) endNodeSearch = true;//endnodeが左にnodeを持っている
        while(node != end  || endNodeSearch != false)
        {
            while(pre_node!=node->left && node->left!=NULL)//左のノードがある
            {
                if(node==end) endNodeSearch = false;
                cout  << " " << node->key;
                nodes.push(node);
                pre_node = node;
                node = node->left;
            }
            if(node->right!=NULL)//右のノードがある
            {
                if(node->left==NULL) cout << " " << node->key;
                pre_node = node;
                node = node->right;
            }else//左右のノードがない
            {
                if(node->left==NULL) cout << " " << node->key;
                node = nodes.top();
                pre_node = node->left;
                nodes.pop();
            }
        }
        if(end->left== NULL) cout << " " << end->key << endl;
        else cout << endl;
    }

    void easyprint(void)
    {
        inorder(T);
        cout << endl;
        preorder(T);
        cout << endl;
    }

    void inorder(Node* n)
    {
        if(n==NULL) return;
        inorder(n->left);
        cout << " " << n->key;
        inorder(n->right);
    }

    void preorder(Node* n)
    {
        if(n==NULL) return;
        cout << " " << n->key;
        preorder(n->left);
        preorder(n->right);

    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    BinarySearchTree bst = BinarySearchTree();
    long N;
    cin >> N;
    for(size_t i=0;i<N; i++)
    {
        string order;
        cin >> order;
        if(order == "insert")
        {
            int key;
            cin >> key;
            bst.insert(key);
        }
        if(order == "print")
        {
            //bst.print();
            bst.easyprint();
        }
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}