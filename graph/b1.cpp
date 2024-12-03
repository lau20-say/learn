#include <bits/stdc++.h>
using namespace std;

vector<unordered_set<int>> notConnected;
vector<bool> visited;
vector<int> componentSizes;

int bfs(int start, int n)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int size = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        size++;

        for (int v = 1; v <= n; ++v)
        {
            if (!visited[v] && notConnected[u].find(v) == notConnected[u].end())
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return size;
}

int main()
{
    int n, m;
    cin >> n >> m;

    notConnected.assign(n + 1, unordered_set<int>());
    visited.assign(n + 1, false);

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        notConnected[x].insert(y);
        notConnected[y].insert(x);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            componentSizes.push_back(bfs(i, n));
        }
    }

    sort(componentSizes.begin(), componentSizes.end());

    cout << componentSizes.size() << "\n";
    for (int size : componentSizes)
    {
        cout << size << " ";
    }

    return 0;
}
