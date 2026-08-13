#include <stdlib.h>
#include <string.h>

typedef struct {
    int len;
    int pref;
    int suff;
    int best;
    char left;
    char right;
} Node;

Node tree[400005];

Node merge(Node a, Node b) {
    Node res;

    res.len = a.len + b.len;
    res.left = a.left;
    res.right = b.right;

    res.pref = a.pref;
    res.suff = b.suff;
    res.best = a.best > b.best ? a.best : b.best;

    if (a.left == b.left && a.pref == a.len)
        res.pref = a.len + b.pref;

    if (a.right == b.right && b.suff == b.len)
        res.suff = b.len + a.suff;

    if (a.right == b.left) {
        int x = a.suff + b.pref;
        if (x > res.best)
            res.best = x;
    }

    return res;
}

void build(char *s, int node, int l, int r) {
    if (l == r) {
        tree[node].len = 1;
        tree[node].pref = 1;
        tree[node].suff = 1;
        tree[node].best = 1;
        tree[node].left = s[l];
        tree[node].right = s[l];
        return;
    }

    int mid = (l + r) / 2;

    build(s, node * 2, l, mid);
    build(s, node * 2 + 1, mid + 1, r);

    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

void update(char *s, int node, int l, int r, int pos) {
    if (l == r) {
        tree[node].left = s[pos];
        tree[node].right = s[pos];
        tree[node].len = 1;
        tree[node].pref = 1;
        tree[node].suff = 1;
        tree[node].best = 1;
        return;
    }

    int mid = (l + r) / 2;

    if (pos <= mid)
        update(s, node * 2, l, mid, pos);
    else
        update(s, node * 2 + 1, mid + 1, r, pos);

    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

int* longestRepeating(
    char* s,
    char* queryCharacters,
    int* queryIndices,
    int queryCharactersSize,
    int* returnSize
) {
    int n = strlen(s);

    int *ans = malloc(queryCharactersSize * sizeof(int));

    build(s, 1, 0, n - 1);

    for (int i = 0; i < queryCharactersSize; i++) {
        int pos = queryIndices[i];

        s[pos] = queryCharacters[i];

        update(s, 1, 0, n - 1, pos);

        ans[i] = tree[1].best;
    }

    *returnSize = queryCharactersSize;

    return ans;
}