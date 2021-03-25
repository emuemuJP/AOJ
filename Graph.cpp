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
    std::vector<std::vector<int>> mat(N+1, vector<int>(N+1, 0));
    for(size_t i=1;i<=N; i++)
    {
        int edge, k;
        cin >> edge >> k;
        for(size_t j=0;j<k; j++)
        {
            int v;
            cin >> v;
            mat[i][v] = 1;
        }
    }

    for(size_t i=1;i<=N; i++)
    {
        for(size_t j=1;j<N; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << mat[i][N] << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}