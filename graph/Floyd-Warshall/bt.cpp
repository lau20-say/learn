#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,q;
    cin >> n >> m >>q;
    vector<vector<ll>> dp(503, vector<ll>(503, LLONG_MAX));
    ll a,b,c;
    while(m--){
        cin >> a >> b >> c;
         dp[a][b] = min(dp[a][b], c);
        dp[b][a] = min(dp[b][a], c);
    }
    for(ll i = 1; i <= n; ++i){
        dp[i][i] = 0;
    }
    for(ll k = 1; k <= n; ++k){
        for(ll i = 1; i <= n; ++i){
            for(ll j = 1; j <= n; ++j){
                if(dp[i][k] != LLONG_MAX && dp[k][j] != LLONG_MAX && dp[i][j] > dp[i][k] + dp[k][j]){
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }   
    }
    ll x, y;
    while(q--){
        cin >> x >> y;
        if(dp[x][y] == LLONG_MAX){
            cout << -1 << '\n';
        }else{
            cout << dp[x][y] << '\n';
        }
    }

    return 0;
}