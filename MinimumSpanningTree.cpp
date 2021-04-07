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

ll prim(const long N, const vector<vector<long>>& mat)
{
    enum Color { white = 1, gray, black};
    ll u, minv;
    vector<ll> d(N, INF);
    vector<ll> p(N, -1);
    vector<Color> color(N, white);
    d[0] = 0;
    while(true)
    {
        minv = INF;
        u = -1;
        for(size_t i=0;i<N; i++)
        {
            if(minv > d[i] && color[i] != black)
            {
                u=i;
                minv=d[i];
            }
        }
        if(u==-1) break;
        color[u] = black;
        for(size_t v=0;v<N; v++)
        {
            if(color[v]!=black && mat[u][v]!=INF)
            {
                if(d[v]>mat[u][v])
                {
                    d[v]=mat[u][v];
                    p[v]=u;
                    color[v]=gray;
                }
            }
        }
    }
    ll total = 0;
    for(size_t i=0;i<N; i++)
    {
        if(p[i]!= -1) total+=mat[i][p[i]];
    }
    return total;
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
    std::vector<std::vector<long>> mat(N, vector<long>(N));
    for(size_t i=0;i<N; i++)
    {
        for(size_t j=0;j<N; j++)
        {
            cin >> mat[i][j];
            if(mat[i][j] == -1) mat[i][j] = INF;
        }
    }

    cout << prim(N, mat) << endl;

#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}