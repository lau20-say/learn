#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
vector<int> segTree[4 * maxn];
int a[maxn];
int n, q;

void build(int v, int l, int r)
{
    if (l == r)
    {
        segTree[v] = {a[l]};
    }
    else
    {
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);

        // Merge sorted arrays from left and right children
        merge(segTree[2 * v].begin(), segTree[2 * v].end(),
              segTree[2 * v + 1].begin(), segTree[2 * v + 1].end(),
              back_inserter(segTree[v]));
    }
}

int query(int v, int tl, int tr, int l, int r, int k)
{
    if (l > r)
        return 0; // No overlap
    if (tl == l && tr == r)
    {
        // Use binary search to count elements >= k
        return segTree[v].end() - lower_bound(segTree[v].begin(), segTree[v].end(), k);
    }
    int mid = (tl + tr) / 2;
    return query(2 * v, tl, mid, l, min(r, mid), k) +
           query(2 * v + 1, mid + 1, tr, max(l, mid + 1), r, k);
}

void update(int v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
    {
        segTree[v] = {new_val};
    }
    else
    {
        int mid = (tl + tr) / 2;
        if (pos <= mid)
        {
            update(2 * v, tl, mid, pos, new_val);
        }
        else
        {
            update(2 * v + 1, mid + 1, tr, pos, new_val);
        }

        // Rebuild the merged sorted list
        segTree[v].clear();
        merge(segTree[2 * v].begin(), segTree[2 * v].end(),
              segTree[2 * v + 1].begin(), segTree[2 * v + 1].end(),
              back_inserter(segTree[v]));
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    build(1, 0, n - 1);

    cin >> q;
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        cout << query(1, 0, n - 1, l, r, k) << '\n';
    }

    return 0;
}
