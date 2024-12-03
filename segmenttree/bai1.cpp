#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long maxn = 200005;
long long n, q, a[maxn], t[maxn * 4];

void build(ll v, ll l, ll r)
{
    if (l == r)
    {
        t[v] = a[l];
    }
    else
    {
        ll mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

ll query(ll v, ll vl, ll vr, ll l, ll r)
{
    if (l > r)
    {
        return 0;
    }
    if (l == vl && r == vr)
    {
        return t[v];
    }
    else
    {
        ll mid = (vl + vr) / 2;
        ll s1 = query(2 * v, vl, mid, l, min(r, mid));
        ll s2 = query(2 * v + 1, mid + 1, vr, max(l, mid + 1), r);
        return s1 + s2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    ll a, b;
    while (q--)
    {
        cin >> a >> b;
        cout << query(1, 0, n - 1, a - 1, b - 1) << '\n';
    }

    return 0;
}