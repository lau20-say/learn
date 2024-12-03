#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
int n, q, a[maxn], t[maxn * 4];

void build(int v, int l, int r)
{
    if (l == r)
    {
        t[v] = a[l];
    }
    else
    {
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }
}

int query(int v, int vl, int vr, int l, int r)
{

    if (l > r)
    {
        return INT_MAX;
    }
    if (vr == r && vl == l)
    {
        return t[v];
    }
    int mid = (vl + vr) / 2;
    int cs1 = query(2 * v, vl, mid, l, min(r, mid));
    int cs2 = query(2 * v + 1, mid + 1, vr, max(mid + 1, l), r);
    return min(cs1, cs2);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cin >> q;
    build(1, 0, n - 1);
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << query(1, 0, n - 1, a, b) << '\n';
    }

    return 0;
}