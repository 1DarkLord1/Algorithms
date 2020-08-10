#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int MAXN = 211111;

vector <int> a;
int tree[4 * MAXN];

void build(int tl, int tr, int v){
    if(tl == tr){
        tree[v] = a[tl];
        return;
    }

    int mid = (tl + tr) >> 1;
    build(tl, mid, v << 1);
    build(mid + 1, tr, v << 1 | 1);
    tree[v] = min(tree[v << 1], tree[v << 1 | 1]);
}

void update(int tl, int tr, int v, int idx, int x){
    if(idx < tl || idx > tr){
        return;
    }

    if(tl == tr){
        tree[v] = x;
        return;
    }

    int mid = (tl + tr) >> 1;
    update(tl, mid, v << 1, idx, x);
    update(mid + 1, tr, v << 1 | 1, idx, x);
    tree[v] = min(tree[v << 1], tree[v << 1 | 1]);
}

int query(int tl, int tr, int v, int l, int r){
    if(l > tr || r < tl){
        return INT_MAX;
    }

    if(l <= tl && tr <= r){
        return tree[v];
    }
    int mid = (tl + tr) >> 1;
    return min(query(tl, mid, v << 1, l, r), query(mid + 1, tr, v << 1 | 1, l, r));
}

int main()
{

    return 0;
}
