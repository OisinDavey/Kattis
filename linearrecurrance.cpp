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

vector<vector<ll> > make_mat(int H, int W){
    vector<vector<ll> > res;
    for(int i=0;i<H;++i){
        vector<ll> tmp;
        for(int j=0;j<W;++j){
            tmp.pb(0LL);
        }
        res.pb(tmp);
    }
    return res;
}

void modulo(ll& x, ll M){
    if(x < 0){
        x = (M + (x%M)) % M;
        return;
    }
    if(x >= M){
        x -= M;
    }if(x >= M){
        x %= M;
    }
    return;
}

vector<vector<ll> > mat_mult(vector<vector<ll> >& A, vector<vector<ll> >& B, ll M){
    int H = A.size();
    int W = B[0].size();
    auto res = make_mat(H, W);
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            for(int k=0;k<A[0].size();++k){
                ll a = A[i][k];
                ll b = B[k][j];
                modulo(a, M);
                modulo(b, M);
                ll tmp = a*b;
                modulo(tmp, M);
                res[i][j] += tmp;
                modulo(res[i][j], M);
            }
        }
    }
    return res;
}

vector<vector<ll> > I;

vector<vector<ll> > mat_modulo(vector<vector<ll> > V, ll M){
    for(auto& v : V){
        for(ll& x : v){
            modulo(x, M);
        }
    }
    return V;
}

vector<vector<ll> > mat_binpow(vector<vector<ll> >& base, ll expo, ll M){
    if(expo == 0LL){
        return I;
    }else if(expo == 1LL){
        return mat_modulo(base, M);
    }else{
        auto tmp = mat_binpow(base, expo/2LL, M);
        tmp = mat_mult(tmp, tmp, M);
        if(expo % 2LL == 1LL){
            tmp = mat_mult(tmp, base, M);
        }
        return tmp;
    }
}

int main(){
    int n;
    cin >> n;
    ll a[n+1];
    for(int i=0;i<=n;++i){
        cin >> a[i];
    }
    ll x[n];
    for(int i=0;i<n;++i){
        cin >> x[i];
    }
    int Q;
    cin >> Q;
    auto Z = make_mat(n+1, n+1);
    Z[0][n] = 1;
    Z[n][n] = 1;
    for(int i=1;i<n;++i){
        Z[i][i-1] = 1;
    }
    for(int i=0;i<n;++i){
        Z[0][i] = a[i+1];
    }
    auto X_initial = make_mat(n+1, 1);
    for(int i=0;i<n;++i){
        X_initial[i][0] = x[n-i-1];
    }
    X_initial[n][0] = a[0];
    I = make_mat(n+1, n+1);
    for(int i=0;i<=n;++i){
        I[i][i] = 1;
    }
    while(Q--){
        ll T;
        cin >> T;
        ll M;
        cin >> M;
        if(T-((ll)n)+1LL >= 0LL){
            auto tmp = mat_binpow(Z, T-((ll)n)+1LL, M);
            tmp = mat_mult(tmp, X_initial, M);
            cout << tmp[0][0] << endl;
        }else{
            cout << x[T]%M << endl;
        }
    }
}
