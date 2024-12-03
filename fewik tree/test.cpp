#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, q, a[200000], BIT[200000];

void update(int pos, int val){
    for(; pos <= n; pos += pos & (-pos)){
        BIT[pos] += val;
    }
}

ll query(int pos){
    ll sum = 0;
    for(; pos >= 1; pos -= pos & (-pos)){
        sum += BIT[pos];
    }
    return sum;
}

int main(){
    

    return 0;
}