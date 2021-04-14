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

typedef pair<ll, ll> p;
enum Color { white = 1, gray, black};


void dijkstra(const ll N, const vector< vector<p> >& adj, vector<ll>& d)
{
    vector<Color> color(N, white);
    priority_queue<p, vector<p>, greater<p>> PQ;

    d[0] = 0;
    color[0] = gray;
    PQ.push(make_pair(0, 0));
    while(!PQ.empty())
    {
        pair<ll, ll> f = PQ.top(); PQ.pop();
        const ll n = f.second;
        color[n] = black;
        if(d[n] < f.first) continue;

        for(size_t i=0;i<adj[n].size(); i++)
        {
            const ll nn = adj[n][i].first;
            if(color[nn]==black) continue;
            if(d[nn] > d[n]+adj[n][i].second)
            {
                d[nn] = d[n]+adj[n][i].second;
                PQ.push(make_pair(d[nn], nn));
                color[nn] = gray;
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
    vector< vector<p> > adj(N); //重み付き有向きグラフの隣接リスト表現
    vector<ll> d(N, INF);
    for(size_t i=0;i<N; i++)
    {
        ll uu, k;
        cin >> uu >> k;
        for(size_t ii=0;ii<k; ii++)
        {
            ll v,c;
            cin >> v >> c;
            adj[uu].push_back(make_pair(v,c));
        }
    }

    dijkstra(N, adj, d);

    for(size_t i=0;i<N; i++)
    {
        cout << i << " " << d[i] << endl;;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}