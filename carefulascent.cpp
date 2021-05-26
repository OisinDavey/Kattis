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

int n;
double x, y;
vector<pair<double, double> > regions;//{dy, f}

double BTSA(){
    double eps = 0.00000005;
    double L = -10000000000.0;
    double R = +10000000000.0;
    while((R - L) > eps){
        double vx = L + (R - L)/2.0;
        double px = 0.0;
        for(auto& [dy, f] : regions){
            double dx = f*dy*vx;
            px += dx;
        }
        if(px > x){
            R = vx;
        }else{
            L = vx;
        }
    }
    return L;
}

int main(){
    cin >> x >> y >> n;
    pair<double, pair<double, double> > shields[n];
    for(int i=0;i<n;++i){
        cin >> shields[i].fi >> shields[i].se.fi >> shields[i].se.se;
    }
    sort(shields, shields+n);
    double at = 0.0;
    for(int i=0;i<n;++i){
        if(shields[i].fi != at){
            regions.pb({shields[i].fi - at, 1.0});
        }
        at = shields[i].se.fi;
        regions.pb({at - shields[i].fi, shields[i].se.se});
    }
    if(at != y){
        regions.pb({y - at, 1.0});
    }
    cout << fixed << setprecision(10) << BTSA() << endl;
}
