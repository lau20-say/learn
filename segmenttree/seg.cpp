class NumArray
{
private:
    vector<int> seg;
    int n;

    void build(int v, int l, int r, vector<int> &nums)
    {
        if (l == r)
        {
            seg[v] = nums[l];
        }
        else
        {
            int m = (l + r) / 2;
            build(2 * v, l, m, nums);
            build(2 * v + 1, m + 1, r, nums);
            seg[v] = seg[2 * v] + seg[2 * v + 1];
        }
    }

        void update(int v, int l, int r, int pos, int val)
        {
            if (l == r)
            {
                seg[v] = val;
            }
            else
            {
                int m = (l + r) / 2;
                if (pos <= m)
                {
                    update(2 * v, l, m, pos, val);
                }
                else
                {
                    update(2 * v + 1, m + 1, r, pos, val);
                }
                seg[v] = seg[2 * v] + seg[2 * v + 1];
            }
        }

    int query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
        {
            return 0;
        }
        if (l == tl && r == tr)
        {
            return seg[v];
        }
        int m = (tl + tr) / 2;
        int left = query(2 * v, tl, m, l, min(r, m));
        int right = query(2 * v + 1, m + 1, tr, max(l, m + 1), r);
        return left + right;
    }

public:
    NumArray(vector<int> &nums)
    {
        n = nums.size();
        seg.resize(4 * n);
        build(1, 0, n - 1, nums);
    }

    void update(int index, int val)
    {
        update(1, 0, n - 1, index, val);
    }

    int sumRange(int left, int right)
    {
        return query(1, 0, n - 1, left, right);
    }
};