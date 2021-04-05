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


void bfs(const vector<vector<int>>& mat, vector<bool>& search, const int index, vector<int>& group, const int id)
{
    bool reach = false;
    search[index] = true;
    if(group[index] == -1) group[index] = id;
    for(size_t i=0;i<mat[index].size(); i++)
    {
        if(!search[mat[index][i]])
        {
            search[mat[index][i]] = true;
            if(group[index] == -1) group[index] = id;
            bfs(mat, search, mat[index][i], group, id);
        }
    }
}

void assignGroup(const vector<vector<int>>& mat, vector<int>& group)
{
    int id = 0;
    for(size_t i=0;i<group.size(); i++)
    {
        if(group[i] == -1)
        {
            vector<bool> search(group.size());
            bfs(mat, search, i, group, id++);
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
    long N, M;
    cin >> N >> M;
    vector<vector<int>> f(N, vector<int>());
    for(size_t i=0;i<M; i++)
    {
        long s, t;
        cin >> s >> t;
        f[s].push_back(t);
        f[t].push_back(s);
    }

    vector<int> group(N, -1);
    assignGroup(f, group);
    long q;
    cin >> q;
    for(size_t i=0;i<q; i++)
    {
        long s, t;
        cin >> s >> t;
        if(group[s] == group[t]) cout << "yes" << endl;
        else cout << "no" << endl;
    }

#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}