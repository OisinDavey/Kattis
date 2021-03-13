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

int n, q;
ll v[6];
ll BITS[200002][6];
int type[200002];

void update_point(int tree_id, int pos, ll val){
    while(pos < 200002){
        BITS[pos][tree_id] += val;
        pos += ((pos)&(-pos));
    }
    return;
}

ll query_pref(int tree_id, int pos){
    ll res = 0ll;
    while(pos > 0){
        res += BITS[pos][tree_id];
        pos -= ((pos)&(-pos));
    }
    return res;
}

ll range_query(int tree_id, int L, int R){
    return query_pref(tree_id, R) - query_pref(tree_id, L-1);
}

int main(){
    cin >> n >> q;
    for(int i=0;i<6;++i){
        cin >> v[i];
    }
    for(int i=1;i<=n;++i){
        char c;
        cin >> c;
        type[i] = (int)(c - '0') - 1;
        update_point(type[i], i, +1LL);
    }
    while(q--){
        int x;
        ll a, b;
        cin >> x >> a >> b;
        switch(x){
            case 1:
                update_point(type[a], a, -1LL);
                type[a] = b-1;
                update_point(type[a], a, +1LL);
                break;
            case 2:
                v[a-1] = b;
                break;
            case 3:
                ll ans = 0LL;
                for(int i=0;i<6;++i){
                    ans += v[i]*range_query(i, a, b);
                }
                cout << ans << endl;
                break;
        }
    }
}
