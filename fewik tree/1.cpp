#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, q, a[1000004], BIT[1000004];

void update(int pos, ll val)
{
    for (; pos <= n; pos += pos & (-pos))
    {
        BIT[pos] += val;
    }
}

ll query(int pos)
{
    ll sum = 0;
    for (; pos >= 1; pos -= pos & (-pos))
    {
        sum += BIT[pos];
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fill(a, a + 1000004, 0);
    fill(BIT, BIT + 1000004, 0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        update(i, a[i]);
    }
    cin >> q;
    while ((q--))
    {
        char f;
        ll r, t;
        cin >> f >> r >> t;
        if (f == 'u')
        {
            update(r, t);
        }
        else
        {
            cout << query(t) - query(r - 1) << '\n';
        }
    }
    return 0;
}