#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n, q, a[200000], BIT[200000];

void update(int pos, int val)
{
    for (; pos <= n; pos += pos & (-pos))
    {
        BIT[pos] += val;
    }
}

int query(int pos)
{
    int sum = 0;
    for (; pos >= 1; pos -= pos & (-pos))
    {
        sum += BIT[pos];
    }
    return sum;
}

int main()
{
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(i, a[i]);
    }
    while ((q--))
    {
        int tt, x, y;
        cin >> tt >> x >> y;
        if (tt == 1)
        {
            update(x, y);
        }
        else
        {
            cout << query(y) - query(x - 1) << '\n';
        }
    }
}