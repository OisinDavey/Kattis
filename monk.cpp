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

int main(){
    int n, m;
    cin >> n >> m;
    int ta[n+1];
    int tb[m+1];
    int ha[n+1];
    int hb[m+1];
    ta[0] = 0;
    ha[0] = 0;
    for(int i=1;i<=n;++i){
        int dt, dh;
        cin >> dh >> dt;
        ta[i] = ta[i-1] + dt;
        ha[i] = ha[i-1] + dh;
    }
    tb[0] = 0;
    hb[0] = ha[n];
    for(int i=1;i<=m;++i){
        int dt, dh;
        cin >> dh >> dt;
        tb[i] = tb[i-1] + dt;
        hb[i] = hb[i-1] - dh;
    }
    double L = 0.0;
    double R = (double)ta[n];
    double eps = 0.0000001;
    while((R - L) > eps){
        double M = L + (R - L)/2.0;
        int i, _l, _r;
        double u, h_a, h_b;

        _l = 0;
        _r = n;
        while(_l < _r){
            int _m = _l + (_r - _l)/2;
            if(ta[_m] >= floor(M)){
                _r = _m;
            }else{
                _l = _m+1;
            }
        }
        if(ta[_l] != floor(M)){
            --_l;
        }

        i = _l;
        u = (double)(ha[i+1] - ha[i])/(double)(ta[i+1] - ta[i]);
        h_a = (double)(ha[i]) + u*(M-(double)ta[i]);
        
//        cout << "A:\n";
//        cout << "i = " << i << endl;
//        cout << "ha[i] = " << ha[i] << endl;
//        cout << "Delta h = " << ha[i+1]-ha[i] << endl;

        _l = 0;
        _r = m;
        while(_l < _r){
            int _m = _l + (_r - _l)/2;
            if(tb[_m] >= floor(M)){
                _r = _m;
            }else{
                _l = _m+1;
            }
        }
        if(tb[_l] != floor(M)){
            --_l;
        }

        i = _l;
        u = (double)(hb[i+1] - hb[i])/(double)(tb[i+1] - tb[i]);
        h_b = (double)(hb[i]) + u*(M-(double)tb[i]);

//        cout << "B:\n";
//        cout << "i = " << i << endl;
//        cout << "hb[i] = " << hb[i] << endl;
//        cout << "Delta h = " << hb[i+1]-hb[i] << endl;

        if(h_a >= h_b){
            R = M;
        }else{
            L = M;
        }
    }
    cout << fixed << setprecision(10) << L << endl;
}
