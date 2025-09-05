#include <bits/stdc++.h>
using namespace std;
class SegmentTree
{
private:
    vector<int> arr;
    vector<int> tree;
    int n;
    int build(int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
            return arr[start];
        }
        int mid = (start + end) / 2;
        tree[node] = build(2 * node + 1, start, mid) + build(2 * node + 2, mid + 1, end);
        return tree[node];
    }

public:
    SegmentTree(vector<int> &input)
    {
        arr = input;
        n = arr.size();
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }
    int query(int node, int start, int end, int left, int right)
    {
        if (end < left || right < start)
        {
            return 0;
        }
        if (start >= left && end <= right)
        {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftSum = query(2 * node + 1, start, mid, left, right);
        int rightSum = query(2 * node + 2, mid + 1, end, left, right);
        return leftSum + rightSum;
    }

    int query(int left, int right)
    {
        return query(0, 0, n - 1, left, right);
    }
    void update(int node, int start, int end, int idx, int val)
    {
        if (idx > end || idx < start)
        {
            return;
        }
        if (start == end)
        {
            arr[idx] = val;
            tree[node] = val;
            return;
        }
        tree[node] += val - arr[idx];
        int mid = (start + end) / 2;
        update(2 * node + 1, start, mid, idx, val);
        update(2 * node + 2, mid + 1, end, idx, val);
        // tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
    void update(int idx, int val)
    {
        update(0, 0, n - 1, idx, val);
    }
};

int main()
{
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(9);
    SegmentTree st(arr);
    cout << "Segment Tree built successfully." << endl;
    cout << st.query(0, 3) << endl;
    st.update(2, 10);
    cout << st.query(0, 2) << endl;
    // cout<<st.minimum(0, 2)<<endl;
}
