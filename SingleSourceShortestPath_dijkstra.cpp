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

void dijkstra(const ll N, const vector<vector<ll>>& mat, vector<ll>& d)
{
    enum Color { white = 1, gray, black};
    ll minv;
    vector<Color> color(N, white);
    d[0] = 0;
    color[0] = gray;
    while(true)
    {
        minv=INF;
        int u = -1;
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
                if(d[v]>d[u]+mat[u][v])
                {
                    d[v]=d[u]+mat[u][v];
                    color[v]=gray;
                }
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

    vector<ll> u(N, INF);
    vector<vector<ll>> mat(N, vector<ll>(N, INF));
    for(size_t i=0;i<N; i++)
    {
        ll uu, k;
        cin >> uu >> k;
        for(size_t ii=0;ii<k; ii++)
        {
            ll v,c;
            cin >> v >> c;
            mat[uu][v] = c;
        }
        mat[uu][uu] = 0;
    }

    dijkstra(N, mat, u);

    for(size_t i=0;i<N; i++)
    {
        cout << i << " " << u[i] << endl;;
    }

#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}