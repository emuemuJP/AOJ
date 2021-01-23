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
                //cerr << p << "left" << endl;
                cbt[p]->left = n;
                n->parent = cbt[p];
                break;
            }
            if(cbt[p]->right == NULL)
            {
                //cerr << p << "right" << endl;
                cbt[p]->right = n;
                n->parent = cbt[p];
                break;
            }
        }
        cbt.push_back(n);
    }

    for(size_t i=0;i<N; i++)
    {
        cout << "node " << i+1 << ": key = " << cbt[i]->key << ", ";
        if(cbt[i]->parent != NULL) cout << "parent key = " << cbt[i]->parent->key << ", ";
        if(cbt[i]->left != NULL) cout << "left key = " << cbt[i]->left->key << ", ";
        if(cbt[i]->right != NULL) cout << "right key = " << cbt[i]->right->key << ", ";
        cout << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}