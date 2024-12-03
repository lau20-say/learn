#include <bits/stdc++.h>
using namespace std;

const int maxn = 30005;  // Giới hạn kích thước mảng
int a[maxn];             // Mảng ban đầu
vector<int> t[maxn * 4]; // Segment Tree lưu các vector đã sắp xếp

// Build Segment Tree
void build(int v, int l, int r)
{
    if (l == r)
    {
        t[v] = {a[l]}; // Node lá chứa một phần tử
    }
    else
    {
        int mid = (l + r) / 2;
        build(2 * v, l, mid);         // Xây cây con trái
        build(2 * v + 1, mid + 1, r); // Xây cây con phải
        // Merge hai vector của con trái và con phải
        merge(t[2 * v].begin(), t[2 * v].end(),
              t[2 * v + 1].begin(), t[2 * v + 1].end(),
              back_inserter(t[v]));
    }
}

// Update Segment Tree (thay đổi giá trị tại một vị trí)
void update(int v, int l, int r, int pos, int val)
{
    if (l == r)
    {
        t[v] = {val}; // Node lá cập nhật giá trị mới
    }
    else
    {
        int mid = (l + r) / 2;
        if (pos <= mid)
        {
            update(2 * v, l, mid, pos, val); // Cập nhật cây con trái
        }
        else
        {
            update(2 * v + 1, mid + 1, r, pos, val); // Cập nhật cây con phải
        }
        // Merge lại các vector từ con trái và con phải
        t[v].clear();
        merge(t[2 * v].begin(), t[2 * v].end(),
              t[2 * v + 1].begin(), t[2 * v + 1].end(),
              back_inserter(t[v]));
    }
}

// Query đếm số lượng phần tử >= k trong đoạn [l, r]
int query(int v, int vl, int vr, int l, int r, int k)
{
    if (l > r)
        return 0; // Đoạn truy vấn không hợp lệ
    if (l == vl && r == vr)
    {
        // Đếm số phần tử >= k trong vector t[v]
        return t[v].end() - lower_bound(t[v].begin(), t[v].end(), k);
    }
    int mid = (vl + vr) / 2;
    // Gọi đệ quy trên các cây con
    return query(2 * v, vl, mid, l, min(r, mid), k) +
           query(2 * v + 1, mid + 1, vr, max(l, mid + 1), r, k);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n; // Đọc số lượng phần tử và số truy vấn

    // Đọc mảng đầu vào
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // Xây dựng Segment Tree
    build(1, 1, n);

    // Thực hiện các truy vấn
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        { // Truy vấn dạng: Đếm số phần tử >= k trong đoạn [l, r]
            int l, r, k;
            cin >> l >> r >> k;
            cout << query(1, 1, n, l, r, k) << "\n";
        }
        else if (type == 2)
        { // Cập nhật giá trị tại vị trí pos
            int pos, val;
            cin >> pos >> val;
            update(1, 1, n, pos, val);
        }
    }

    return 0;
}
