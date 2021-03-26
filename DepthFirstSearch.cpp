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

int depthsearch(vector<vector<int>> & mat, vector<vector<int>> & order, vector<bool> & bool_mat, int index, int time)
{
    if(!bool_mat[index])
    {
        time++;
        order[index].push_back(time);
        bool_mat[index] = true;
        for(size_t i=0;i<mat[index].size(); i++)
        {
            if(!bool_mat[mat[index][i]])
            {
                time = depthsearch(mat, order, bool_mat, mat[index][i], time);
            }
        }
        time++;
        order[index].push_back(time);
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
    std::vector<std::vector<int>> order(N+1, vector<int>());
    std::vector<bool> bool_mat(N+1);
    int time = 0;
    for(size_t i=1;i<=N; i++)
    {
        time = depthsearch(mat, order, bool_mat, i, time);
    }

    for(size_t i=1;i<=N; i++)
    {
        cout << i << " " << order[i][0] << " " << order[i][1] << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}