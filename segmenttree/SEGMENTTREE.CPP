#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxn = 20005;
int n, a[maxn], t[maxn * 4];

void build(int v, int l, int r){
    if(l == r){
        t[v] = a[l];
    }
    else{
        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

void update(int v, int l, int r, int pos, int val){
    if(l == r){
        t[v] = val;
    }else{
        int m = (l + r) / 2;
        if(pos <= m){
            update(2 * v, l, m, pos, val);
        }else{
            update(2 * v + 1, m + 1, r, pos, val);
        }
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

ll query(int v, int tl, int tr, int l, int r){
    if(l > r) return 0;
    if(tl == l && tr == r){
        return t[v];
    }
    else{
        int tm = (tl + tr) / 2;
        ll s1 = query(2 * v, tl, tm, l, min(r, tm));
        ll s2 = query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
        return s1 + s2;
    }
}

int main(){
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    build(1, 0, n - 1);
    
    update(1, 0, 7, 4 , 10);
cout << query(1, 0, 7, 2, 3);
}