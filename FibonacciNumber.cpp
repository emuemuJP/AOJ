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

vector<int> F(100, -1);

int fibonacci(int E)
{
    if(E == 0  || E == 1) return 1;
    else
    {
        return fibonacci(E-2) + fibonacci(E-1);
    }
}

int fibonacci_memo(int E)
{
    if(E == 0  || E == 1){
        return F[E] = 1;
    }
    if(F[E] != -1) return F[E];
    return F[E] = fibonacci_memo(E-2) + fibonacci_memo(E-1);
}

void make_fibonacci(int E)
{
    F[0] = 1;F[1] = 1;
    for(size_t i=2;i<=E; i++)
    {
        F[i] = F[i-2] + F[i-1];
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
    long n;
    cin >> n;
    make_fibonacci(n);
    cout << F[n] << endl;;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}