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
    int q;
    cin >> q;
    for(size_t i=0;i<q; i++)
    {
        string X, Y;
        cin >> X;
        cin >> Y;
        std::vector<std::vector<int>> mat(X.length()+1, vector<int>(Y.length()+1, 0));
        for(size_t ii=1;ii<X.length()+1; ii++)
        {
            for(size_t jj=1;jj<Y.length()+1; jj++)
            {
                if(X[ii-1]==Y[jj-1]) mat[ii][jj] = mat[ii-1][jj-1]+1;
                else if(mat[ii][jj-1] >= mat[ii-1][jj]) mat[ii][jj] = mat[ii][jj-1];
                else mat[ii][jj] = mat[ii-1][jj];
            }
        }
        cout << mat[X.length()][Y.length()] << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}