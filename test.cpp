#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 998244353;
const int inf = 1e18;

void solve() {
    int n, m;
    cin>>n>>m;
    int ans;
    if(m>n){
        swap(n, m);
    }
    if(n%2==1){
        if(m%2==1){
             ans=((min(m, n-m+1)%MOD)*(((m+1)/2)%MOD)*(((n+1)/2)%MOD)%MOD);
        }
        else{
             ans=((min(m/2, (n/2)-(m/2)+1)%MOD)*((m+1)%MOD)*(((n+1)/2)%MOD)%MOD);
        }
    }
    else{
        if(m%2==1){
             ans=(((min(m, n-2*(m/2)+1))%MOD)*(((m+1)/2)%MOD)*((n+1)%MOD)%MOD);
        }
        else{
            ans=((min(m/2, (n-m+2)/2 )%MOD)*((m+1)%MOD)*((n+1)%MOD)%MOD);
        }
    }
    cout<<ans%MOD<<endl;
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



