#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

struct ST{
    int n;
    vector <int> lg;
    vector < vector <int> > sparse;
    ST(vector <int> & a){
        n = a.size();
        lg.resize(n + 1);
        lg[1] = 0;
        for(int i = 2; i <= n; i++){
            lg[i] = lg[i >> 1] + 1;
        }
        sparse.resize(n, vector <int> (lg[n] + 1));
        for(int i = 0; i < n; i++){
            sparse[i][0] = a[i];
        }

        for(int j = 1; j <= lg[n]; j++){
            for(int i = 0; i <= n - (1 << j); i++){
                sparse[i][j] = min(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int i, int j){
        int ln = lg[j - i + 1];
        return min(sparse[i][ln], sparse[j - (1 << ln) + 1][ln]);
    }
};

int main()
{
    
    return 0;
}
