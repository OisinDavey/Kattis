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

const long double E = 2.7182818284590452353602874713527;

long double _sinh(long double x){
    long double a = pow(E, x);
    long double b = -1.0*pow(E, -1.0*x);
    return (a + b)/2.0;
}

long double _cosh(long double x){
    long double a = pow(E, x);
    long double b = pow(E, -1.0*x);
    return (a + b)/2.0;
}

int main(){
    long double d, s;
    cin >> d >> s;
    long double L = 0.0;
    long double R = 400000000.0;
    int cnt = 0;
    while(cnt < 10000){
        ++cnt;
        long double a = L + (R - L)/2.0;
        long double tmp = a*_cosh(d/(2.0*a)) - a - s;
        if(abs(tmp) < 0.0000001){
            L = a;
            break;
        }else if(tmp > 0.0){
            L = a;
        }else{
            R = a;
        }
    }
    long double ans = 2.0*L*_sinh(d/(2.0*L));
    cout << fixed << setprecision(10) << ans << endl;
}
