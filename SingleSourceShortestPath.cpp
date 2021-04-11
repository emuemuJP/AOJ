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
ll search(const vector<vector<ll>>& mat, vector<bool> isSearch, vector<ll>& u, const ll idx, ll cost)
{
    isSearch[idx] = true;
    if(u[idx] > cost) u[idx] = cost;
    for(size_t i=0;i<mat[idx].size(); i++)
    {
        if(mat[idx][i]!= -1 && !isSearch[i] && u[i] > cost)
        {
            search(mat, isSearch, u, i, cost+mat[idx][i]);
        }
    }
    return 0;
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
    vector<vector<ll>> mat(N, vector<ll>(N, -1));
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

    vector<bool> isSearch(N, false);
    isSearch[0] = true;
    search(mat, isSearch, u, 0, 0);

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