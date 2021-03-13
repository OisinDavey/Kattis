//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            5001
#define mp              make_pair
#define mod7            1000000007
#define modpi           314159
#define PI              3.141592653589793238
#define pb              push_back
#define FastIO          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define All(a)          a.begin(),a.end()
#define fi              first
#define se              second
#define ll              long long int
#define ull             unsigned long long int

int kx[8]  =            {+2, +2, -2, -2, +1, +1, -1, -1};
int ky[8]  =            {+1, -1, +1, -1, +2, -2, +2, -2};
int d9x[9] =            {+1, +1, +1, +0, +0, +0, -1, -1, -1};
int d9y[9] =            {+1, +0, -1, +1, +0, -1, +1, +0, -1};
int dx4[4] =            {+0, +0, +1, -1};
int dy4[4] =            {+1, -1, +0, +0};

ll gcd(ull a, ull b){
    return (a==0)?b:gcd(b%a,a);
}

ll lcm(ull a, ull b){
    return a*(b/gcd(a,b));
}

const long long INF = 1e18;

using namespace std;

ll n, q;
ll tree[5000005];

void update(ll at, ll val){
    ++at;
    while(at < n+5LL){
        tree[at] += val;
        at += (at&(-at));
    }
    return;
}

ll query(ll at){
    ll res = tree[0];
    while(at > 0ll){
        res += tree[at];
        at -= (at&(-at));
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(tree, 0, sizeof(tree));
    cin >> n >> q;
    ll at, val;
    while(q--){
        char c;
        cin >> c;
        if(c == '?'){
            cin >> at;
            ll tmp = query(at);
            printf("%lld\n", tmp);
        }else{
            cin >> at >> val;
            update(at, val);
        }
    }
}
