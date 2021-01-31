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

void maxHeap(vector<ll>& mh, int i)
{
    ll largest;
    bool left = false;
    if(i <= (mh.size()-1) / 2)
    {
        if(i*2+1 < mh.size() && mh[i*2+1] > mh[i])
        {
            left = true;
            largest = mh[i*2+1];
        }else
        {
            largest = mh[i];
        }
        if(i*2+2 < mh.size() && mh[i*2+2] > largest)
        {
            left = false;
            largest = mh[i*2+2];
        }
        if(largest != mh[i])
        {
            if(left)
            {
                mh[i*2+1] = mh[i];
                mh[i] = largest;
                maxHeap(mh, i*2+1);
            }
            else
            {
                mh[i*2+2] = mh[i];
                mh[i] = largest;
                maxHeap(mh, i*2+2);
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
    vector<ll> mh;
    vector<ll> out;
    string op="";
    while(op!="end")
    {
        cin >> op;
        if(op=="insert")
        {
            ll num;
            cin >> num;
            mh.push_back(num);
            ll i = mh.size()-1;
            while(i > 0 && mh[(i-1)/2]<mh[i])
            {
                mh[i]=mh[(i-1)/2];
                mh[(i-1)/2]=num;
                i = (i-1)/2;
            }
        }else if(op=="extract")
        {
            cout << mh[0] << endl;
            out.push_back(mh[0]);
            mh[0] = mh[mh.size()-1];
            mh.pop_back();
            //mh.erase(mh.begin());
            maxHeap(mh, 0);
        }
    }
    for(size_t i=0;i<out.size(); i++)
    {
        //cout << out[i] << endl;
    }
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}