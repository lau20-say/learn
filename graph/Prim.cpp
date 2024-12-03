#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // {weight, vertex}

int prim(int n, vector<vector<pii>> &graph)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap
    vector<bool> inMST(n, false);                      // Đánh dấu đỉnh đã thuộc MST
    int mstWeight = 0;

    // Bắt đầu từ đỉnh 0
    pq.push({0, 0}); // {weight, vertex}

    while (!pq.empty())
    {
        auto [weight, u] = pq.top();
        pq.pop();

        if (inMST[u])
            continue; // Bỏ qua nếu đỉnh đã trong MST

        inMST[u] = true; // Đánh dấu đỉnh này đã vào MST
        mstWeight += weight;

        // Thêm các cạnh kề vào hàng đợi ưu tiên
        for (auto [v, w] : graph[u])
        {
            if (!inMST[v])
            {
                pq.push({w, v});
            }
        }
    }

    return mstWeight; // Trả về tổng trọng số MST
}

int main()
{
    int n, m; // Số đỉnh và số cạnh
    cin >> n >> m;

    vector<vector<pii>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // Đồ thị vô hướng
    }

    cout << "Weight of MST: " << prim(n, graph) << endl;

    return 0;
}
