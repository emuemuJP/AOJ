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
    vector<int> p(N+1);
    for(size_t i=1;i<=N; i++)
    {
        cin >> p[i-1] >> p[i];
    }
    std::vector<std::vector<ll>> cost(N+1, vector<ll>(N+1, 0));
    for(size_t l=2;l<=N; l++)
    {
        for(size_t i=1;i<=N-l+1; i++)
        {
            int j = i + l -1;
            cost[i][j]=INF;
            for(size_t k=i;k<=j-1; k++)
            {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k+1][j] + p[i-1]*p[k]*p[j]);
            }
        }
    }
    cout << cost[1][N] << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}