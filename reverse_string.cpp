//https://cses.fi/paste/78623589fc1aebdb1e7b90/
typedef long long LL;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef struct item * pitem;
struct item {
    int prior, value, cnt;
    LL sum;
    bool rev;
 
    item(int value):prior(rng()), value(value) {
        cnt = 0;
        rev = 0;
        sum = value;
        l = r = nullptr;
    }
 
    pitem l, r;
};
 
namespace Treap {
    int cnt (pitem it) {
        return it != nullptr? it->cnt : 0;
    }
    LL sum(pitem it) {
        return it != nullptr? it->sum : 0;
    }
    void upd_cnt (pitem it) {
        if (it!=nullptr) {
            it->cnt = cnt(it->l) + cnt(it->r) + 1;
            it->sum = sum(it->l) + sum(it->r) + it->value;
        }
    }
    void push (pitem it) {
        if (it != nullptr && it->rev == true) {
            it->rev = false;
            swap (it->l, it->r);
            if (it->l)  it->l->rev ^= true;
            if (it->r)  it->r->rev ^= true;
        }
    }
    void merge (pitem & t, pitem l, pitem r) {
        push (l);
        push (r);
        if (l==nullptr || r==nullptr)
            t = (l!=nullptr) ? l : r;
        else if (l->prior > r->prior)
            merge (l->r, l->r, r),  t = l;
        else
            merge (r->l, l, r->l),  t = r;
        upd_cnt (t);
    }
    void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
        if (t==nullptr) {
            l = r = nullptr;
            return;
        }
        push(t);
        int cur_key = add + cnt(t->l);
 
        if (key <= cur_key)
            split (t->l, l, t->l, key, add),  r = t;
        else
            split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
        upd_cnt (t);
    }
    void reverse (pitem &t, int l, int r) {
        pitem t1, t2, t3;
        split (t, t1, t2, l);
        split (t2, t2, t3, r-l+1);
        assert(t2 != NULL);
        t2->rev ^= true;
        merge (t, t1, t2);
        merge (t, t, t3);
    }
    LL query (pitem &t, int l, int r) {
        pitem t1, t2, t3;
        split (t, t1, t2, l);
        split (t2, t2, t3, r-l+1);
        LL ans = t2->sum;
        merge (t, t1, t2);
        merge (t, t, t3);
        return ans;
    }
    void insert (pitem & t, int key, int value) {
        pitem x = new item(value);
        pitem L, R;
        split(t, L, R, key);
        merge(L, L, x);
        merge(t, L, R);
        upd_cnt(t);
    }
    int erase (pitem & t, int key) {
        assert(cnt(t) > key);
        pitem L, MID, R;
        split(t, L, MID, key);
        split(MID, MID, R, 1);
        merge(t, L, R);
        upd_cnt(t);
        int rt = MID->value;
        delete MID;
        return rt;
    }
    void output (pitem t, string &v) {
        if (t==nullptr)  return;
        push (t);
        output (t->l, v);
        v.push_back(t->value);
        output (t->r, v);
    }
    void output2 (pitem t) {
        if (t==nullptr)  return;
        push (t);
//        cout << "(";
        output2 (t->l);
        cout << (t->value) << " ";
        output2 (t->r);
//        cout << ")";
    }
}

 
// void solve(){
//     // first we take the input and insert the string in the tree using the insert function
//     // to find the x , we simply use a binary search 
//     // then we reverse the string and in the end we output it
//     int n, k, i;
//     cin>>n>>k;
//     pitem tr = nullptr;
//     vector <int> l(k), r(k);
//     string s;
//     cin>>s;
//     for(i=0;i<n;i++){
//         Treap::insert(tr, i, s[i]);// this is the setting of the string
//     }
//     int q;
//     cin>>q;
//     while(q--){
//         int L, R;
//         cin>>L>>R;
//         // we have to reverse the string from L to R index
//         // indexing is 0 based, so we subtract 1 from L and R
//         Treap:: reverse(tr, L-1, R-1);
//     }
//     string ans;
//     Treap:: output(tr, ans);// we are taking the final string as output
//     cout<<ans<<endl;
// }
 
