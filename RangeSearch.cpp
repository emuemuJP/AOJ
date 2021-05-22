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

static const int MAX = 1000000;
static const int NIL = -1;

class Node{
public:
    int location;
    int p=NIL,l=NIL,r=NIL;
    Node(){}
};

class Point{
public:
    int id, x, y;
    Point(){}
    Point(int id, int x, int y):id(id), x(x), y(y){}
    bool operator < (const Point &p) const{
        return id < p.id;
    }
    void print(){
        cout << id << endl;
    }
};


int N;
Point P[MAX];
Node T[MAX];
int np;

bool lessX(const Point &p1, const Point &p2){return p1.x < p2.x;}
bool lessY(const Point &p1, const Point &p2){return p1.y < p2.y;}

int makeKDTree(int l, int r, int depth){
    if(!(l < r)) return NIL;
    int mid = (l+r) / 2;
    int t = np++;
    if(depth%2 == 0){
        sort(P+l, P+r, lessX);
    }else{
        sort(P+l, P+r, lessY);
    }
    T[t].location = mid;
    T[t].l = makeKDTree(l, mid, depth+1);
    T[t].r = makeKDTree(mid+1, r, depth+1);
    return t;
}

void find(int v, const int sx, const int tx, const int sy, const int ty, int depth, vector<Point> & ans){
    int x = P[T[v].location].x;
    int y = P[T[v].location].y;
    if(sx <= x && x <= tx && sy <= y && y <= ty){
        ans.push_back(P[T[v].location]);
    }

    if(depth % 2 == 0){
        if(T[v].l != NIL){
            if(sx <= x) find(T[v].l, sx, tx, sy, ty, depth+1, ans);
        }
        if(T[v].r != NIL){
            if(x <= tx) find(T[v].r, sx, tx, sy, ty, depth+1, ans);
        }
    }else{
        if(T[v].l != NIL){
            if(sy <= y) find(T[v].l, sx, tx, sy, ty, depth+1, ans);
        }
        if(T[v].r != NIL){
            if(y <= ty) find(T[v].r, sx, tx, sy, ty, depth+1, ans);
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
    ll n, x, y;
    cin >> n;
    for(size_t i=0;i<n; i++)
    {
        cin >> x >> y;
        P[i] = Point(i, x, y);
    }
    np = 0;
    int root = makeKDTree(0, n, 0);
    ll q, sx, tx, sy, ty;
    cin >> q;
    vector<Point> ans;
    for(size_t i=0;i<q; i++)
    {
        cin >> sx >> tx >> sy >> ty;
        ans.clear();
        find(root, sx, tx, sy, ty, 0, ans);
        sort(ans.begin(), ans.end());
        for(size_t j=0;j<ans.size(); j++)
        {
            ans[j].print();
        }
        cout << endl;
    }

#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}