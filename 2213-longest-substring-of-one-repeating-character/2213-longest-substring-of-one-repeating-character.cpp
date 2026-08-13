class Solution {
public:
    struct Node {
        int len, pref, suff, best;
        char lc, rc;
    };

    vector<Node> tree;
    string s;

    Node merge(Node a, Node b)
    {
        Node c;
        c.len = a.len + b.len;
        c.lc = a.lc;
        c.rc = b.rc;
        c.pref = a.pref;
        c.suff = b.suff;
        c.best = max(a.best, b.best);

        if(a.rc == b.lc)
        {
            c.best = max(c.best, a.suff + b.pref);

            if(a.pref == a.len)
                c.pref = a.len + b.pref;

            if(b.suff == b.len)
                c.suff = b.len + a.suff;
        }

        return c;
    }

    void build(int node, int l, int r)
    {
        if(l == r)
        {
            tree[node] = {1, 1, 1, 1, s[l], s[l]};
            return;
        }

        int mid = l + (r - l) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c)
    {
        if(l == r)
        {
            tree[node] = {1, 1, 1, 1, c, c};
            return;
        }

        int mid = l + (r - l) / 2;

        if(idx <= mid)
            update(node * 2, l, mid, idx, c);
        else
            update(node * 2 + 1, mid + 1, r, idx, c);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices)
    {
        this->s = s;

        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for(int i = 0; i < queryIndices.size(); i++)
        {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans.push_back(tree[1].best);
        }

        return ans;
    }
};