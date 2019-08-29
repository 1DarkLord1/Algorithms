#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;

struct node{
    node *l, *r;
    int x, pr, g;
    node(){
        pr = (rand() << 15 + rand());
        l = r = 0;
        x = g = 0;
    }
    node(int nw): l(0), r(0), x(nw), pr((rand() << 15) + rand()), g(nw){}
    void print(){
        if(l)l->print();
        cout << x << ' ' << g << '\n';
        if(r)r->print();
    }
};

void upd(node *& t){
    if(!t)return;
    t->g = __gcd(t->x, __gcd((t->l ? t->l->g: 0), (t->r ? t->r->g: 0)));
}

pair <node*, node*> split(node *t, int key){
    if(!t)return {0, 0};
    if(t->x <= key){
        pair <node*, node*> sp = split(t->r, key);
        t->r = sp.f;
        upd(t);
        upd(sp.s);
        return {t, sp.s};
    }
    else{
        pair <node*, node*> sp = split(t->l, key);
        t->l = sp.s;
        upd(t);
        upd(sp.f);
        return {sp.f, t};
    }
}

node *merge(node *a, node *b){
    if(!a)return b;
    if(!b)return a;
    if(a->pr < b->pr){
        a->r = merge(a->r, b);
        upd(a);
        return a;
    }
    else{
        b->l = merge(a, b->l);
        upd(b);
        return b;
    }
}

node *ins(node *& t, int v){
    pair <node*, node*> sp = split(t, v);
    return merge(merge(sp.f, new node(v)), sp.s);
}

void del(node *& t, int v){
    assert(t != 0);
    if(v < t->x)
        del(t->l, v);
    else if(v > t->x)
        del(t->r, v);
    else
        t = merge(t->l, t->r);
    upd(t);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    node *t = 0;
    while(q--){
        char c;
        int a;
        cin >> c >> a;
        if(c == '+'){
            t = ins(t, a);
            //t->print();
            //cout << '\n';
            cout << t->g << '\n';
        }
        else{
            del(t, a);
            //t->print();
            //cout << '\n';
            if(!t)cout << 1 << '\n';
            else cout << t->g << '\n';
        }
    }
    //t->print();
    return 0;
}