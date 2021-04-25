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

struct Node{
    Node* parent;
    ll key;
    ll group;
    ll depth;
};

class UnionFind
{
private:
    vector<ll> data;
    vector<ll> tree_size;

public:
    UnionFind(ll n)
    {
        data = vector<ll>(n);
        tree_size = vector<ll>(n, 1);
        for (ll i = 0; i < n; ++i)
        {
            data[i] = i;
        }
    }

    ll root(ll a)
    {
        if (data[a] == a) return a;
        else return data[a] = root(data[a]);
    }

    void unite(ll a, ll b)
    {
        ll root_a = root(a);
        ll root_b = root(b);
        if (root_a == root_b)
            return;
        else
        {
            tree_size[root_b] += tree_size[root_a];
            tree_size[root_a] = 0;
            data[root_a] = root_b;
            return;
        }
        return;
    }
    ll get_tree_size(ll a)
    {
        return tree_size[root(a)];
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
    ll n, q;
    cin >> n >> q;
    UnionFind uf = UnionFind(n);
    for(size_t i=0;i<q; i++)
    {
        ll com, t1, t2;
        //com: 0 means unite. 1 means same.
        cin >> com >> t1 >> t2;
        if(com == 0)
        {
            uf.unite(t1, t2);
        }
        if(com == 1)
        {
            if(uf.root(t1) == uf.root(t2)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    /*
    vector< Node* > nodes(n+1);
    for(size_t i=0;i<n; i++)
    {
        nodes[i] = new Node();
        nodes[i]->key = i;
        nodes[i]->group = i;
    }
    for(size_t i=0;i<q; i++)
    {
        ll com, t1, t2;
        //com: 0 means unite. 1 means same.
        cin >> com >> t1 >> t2;
        if(com == 0)
        {
            if(nodes[t1]->depth < nodes[t2]-> depth)
            {
                ll parent_node = t2;
                ll old_parent_node = parent_node;
                while(nodes[parent_node]->parent!=NULL)
                {
                    parent_node = nodes[parent_node]->parent->key;
                    nodes[old_parent_node]->parent = nodes[t1];
                    nodes[old_parent_node]->depth = nodes[t1]->depth + 1;
                }
                nodes[parent_node]->parent = nodes[t1];
                nodes[old_parent_node]->depth = nodes[t1]->depth + 1;
                nodes[t2]->parent = nodes[t1];
                nodes[t2]->depth = nodes[t1]->depth + 1;
            }else
            {
                ll parent_node = t1;
                ll old_parent_node = parent_node;
                while(nodes[parent_node]->parent!=NULL)
                {
                    parent_node = nodes[parent_node]->parent->key;
                    nodes[old_parent_node]->parent = nodes[t2];
                    nodes[old_parent_node]->depth = nodes[t2]->depth + 1;
                }
                nodes[parent_node]->parent = nodes[t2];
                nodes[old_parent_node]->depth = nodes[t2]->depth + 1;
                nodes[t1]->parent = nodes[t2];
                nodes[t1]->depth = nodes[t2]->depth + 1;
            }
        }
        if(com == 1)
        {
            ll parent_node = t1;
            while(nodes[parent_node]->parent!=NULL)
            {
                parent_node = nodes[parent_node]->parent->key;
            }
            ll group1 = nodes[parent_node]->group;

            parent_node = t2;
            while(nodes[parent_node]->parent!=NULL)
            {
                parent_node = nodes[parent_node]->parent->key;
            }
            ll group2 = nodes[parent_node]->group;
            if(group1 == group2) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    */
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}