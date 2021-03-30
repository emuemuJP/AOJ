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

int bfs(std::vector<std::vector<int>>& mat, vector<int>& order, int index, int time)
{
    time++;
    //cerr << "   " << index << " " << order[index] << endl;
    vector<bool> search(mat[index].size()); 
    for(size_t i=0;i<mat[index].size(); i++)
    {
        if(order[mat[index][i]]==-1 || order[mat[index][i]] > time )
        {
            order[mat[index][i]] = time;
            search[i] = true;
        }
    }

    for(size_t i=0;i<mat[index].size(); i++)
    {
        if(search[i]) bfs(mat, order, mat[index][i], time);
    }
    return time;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    int N;
    cin >> N;
    std::vector<std::vector<int>> mat(N+1, vector<int>());
    for(size_t i=1;i<=N; i++)
    {
        int edge, k;
        cin >> edge >> k;
        for(size_t j=0;j<k; j++)
        {
            int v;
            cin >> v;
            mat[i].push_back(v);
        }
    }
    vector<int> order(N+1, -1);
    int time = 0;
    /*
    for(size_t i=1;i<=N; i++)
    {
        cerr << i << endl;
        if(order[i]==-1 || order[i] > time) order[i]=time;
        time = bfs(mat, order, i, time);
    }
    */
    order[1] = 0;
    time = bfs(mat, order, 1, time);
    for(size_t i=1;i<=N; i++)
    {
        cout << i << " " << order[i] << endl;
    }

#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}