#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 998244353;
const int inf = 1e18;
using ll = long long;

//==================================================================

//modular arithmetic for MOD type questions code below:



constexpr int P = 998244353;
// assume -P <= x < 2P
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template<class T>
T power(T a, ll b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    // Z(ll x) : x(norm((int)(x % P))) {} //uncomment this line if there is no #define int long long
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = ll(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    Z &operator%=(const Z &rhs) {
        x = x % rhs.x;
        return *this;
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend Z operator%(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res %= rhs;
        return res;
    }
    friend bool operator==(const Z &lhs, const Z &rhs) {
        if(lhs.x == rhs.x) {
            return true;
        } else {
            return false;
        }
    }
    friend bool operator!=(const Z &lhs, const Z &rhs) {
        if(lhs.x != rhs.x) {
            return true;
        } else {
            return false;
        }
    }
    friend bool operator<(const Z &lhs, const Z &rhs) {
        if(lhs.x < rhs.x) {
            return true;
        } else {
            return false;
        }
    }
    friend bool operator>(const Z &lhs, const Z &rhs) {
        if(lhs.x > rhs.x) {
            return true;
        } else {
            return false;
        }
    }
    friend istream &operator>>(istream &is, Z &a) {
        ll v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend ostream &operator<<(ostream &os, const Z &a) {
        return os << a.val();
    }

};

//Z ans;
// or
//Z fact[100005];
//u get the point ig, Z is a new datatype like int.
//if u do Z%2, be sure to change P to 1000000000.
//===========================================================

void solve() {
    Z n, m, ans;
    cin>>n>>m;
    if(m>n){
        swap(n, m);
    }
    if(n%2==1){
        if(m%2==1){
             ans=min(m, n-m+1)*((m+1)/2)*((n+1)/2);
        }
        else{
             ans=min(m/2, (n/2)-(m/2)+1)*(m+1)*((n+1)/2);
        }
    }
    else{
        if(m%2==1){
             ans=min(m, n-2*(m/2)+1)*((m+1)/2)*(n+1);
        }
        else{
            ans=min(m/2, (n-m+2)/2 )*(m+1)*(n+1);
        }
    }
    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int TT = 1;
    cin >> TT;

    while (TT--) {
        solve();
    }

    return 0;
}

