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

void maxHeap(Node* n, int i)
{
    Node* largest;
    bool left = false;
    if(i <= (cbt.size()-1) / 2)
    {
        if(n->left != NULL && n->left->key > n->key)
        {
            left = true;
            largest = n->left;
        }else
        {
            largest = n;
        }
        if(n->right != NULL && n->right->key > largest->key)
        {
            left = false;
            largest = n->right;
        }
        if(largest != n)
        {
            if(n->parent != NULL)
            {
                if(i%2!=0) n->parent->left = largest;
                else n->parent->right = largest;
            }
            if(left)
            {
                Node* tmp = cbt[i];
                cbt[i] = cbt[i*2+1];
                cbt[i*2+1] = tmp;
                largest->parent = n->parent;
                n->parent = largest;
                //子　左ノードあり
                n->left = largest->left;
                if(largest->left != NULL)
                    largest->left->parent = n;
                largest->left = n;

                tmp = n->right;
                //子　右ノードあり
                if(n->right != NULL)
                    n->right->parent = largest;
                n->right = largest->right;
                if(largest->right != NULL)
                    largest->right->parent = n;
                largest->right = tmp;
                maxHeap(n, i*2+1);
            }
            else
            {
                Node* tmp = cbt[i];
                cbt[i] = cbt[i*2+2];
                cbt[i*2+2] = tmp;
                largest->parent = n->parent;
                n->parent = largest;
                if(n->left != NULL)
                    n->left->parent = largest;
                tmp = n->left;
                n->left = largest->left;
                if(largest->left != NULL)
                    largest->left->parent = n;
                largest->left = tmp;

                n->right = largest->right;
                if(largest->right != NULL)
                    largest->right->parent = n;
                largest->right = n;
                maxHeap(n, i*2+2);
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    long N;
    cin >> N;
    vector<Node*> cbt;
    for(size_t i=0;i<N; i++)
    {
        ll key;
        cin >> key;
        Node* n = new Node();
        n->key = key;

        for(size_t p=0;p<cbt.size(); p++)
        {
            if(cbt[p]->left == NULL)
            {
                cbt[p]->left = n;
                n->parent = cbt[p];
                break;
            }
            if(cbt[p]->right == NULL)
            {
                cbt[p]->right = n;
                n->parent = cbt[p];
                break;
            }
        }
        cbt.push_back(n);
    }

    for(int h=(N-1)/2;h>=0; h--)
    {
        maxHeap(cbt[h], h);
    }
    for(size_t i=0;i<N; i++)
    {
        cout <<  " " << cbt[i]->key;
    }
    cout << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}