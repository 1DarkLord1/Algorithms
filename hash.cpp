#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

struct Hash{
    int n, mod = 1e9 + 7, P1 = 81, P2;
    vector <ull> h1, h2;
    vector <ull> deg1, deg2;
    Hash(string & s){
        n = s.size() + 1;
        P2 = rand();
        h1.resize(n), h2.resize(n);
        deg1.resize(n), deg2.resize(n);
        deg1[0] = deg2[0] = 1;
        for(int i = 0; i < n - 1; i++){
            deg1[i + 1] = deg1[i] * P1;
            deg2[i + 1] = (deg2[i] * P2) % mod;
        }
        for(int i = 0; i < n - 1; i++){
            h1[i + 1] = h1[i] * P1 + s[i];
            h2[i + 1] = (h2[i] * P2 + s[i]) % mod;
        }
    }

    ull get_hash1(int i, int j){
        return h1[j + 1] - h1[i] * deg1[j - i + 1];
    }

    ull get_hash2(int i, int j){
        return (h2[j + 1] - h2[i] * deg2[j - i + 1] + 3ll * mod) % mod;
    }

    bool cmp(Hash & a, int i, int j){
        return (get_hash1(i, j) == a.get_hash1(i, j) && get_hash2(i, j) == a.get_hash2(i, j));
    }

};

bool cmp(Hash & a, string & A, Hash & b, string & B){
    if(A.size() > B.size() && a.cmp(b, 0, B.size() - 1)){
        return 1;
    }
    else if(A.size() <= B.size() && b.cmp(a, 0, A.size() - 1)){
        return 0;
    }
    int ln = 1;
    while((1 << ln) <= min(A.size(), B.size())){
        ln++;
    }

    int l = -1;
    for(int i = ln; i >= 0; i--){
        int j = (l + (1 << i));
        if(j >= min(A.size(), B.size())){
            continue;
        }
        if(a.cmp(b, 0, j)){
            l = j;
        }
    }
    return (A[l + 1] > B[l + 1]);
}

int main()
{
    
    return 0;
}
