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
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    for(int i=0;i<n;++i){
        cin >> b[i];
    }
    int L = 0;
    int R = 1000000001;
    while(L < R){
        int M = L + (R - L)/2;
        vector<int> v1, v2;
        for(int i=0;i<n;++i){
            if(a[i] > M){
                v1.pb(a[i]);
            }
            if(b[i] > M){
                v2.pb(b[i]);
            }
        }
        bool good = true;
        for(int i=0;i<v1.size();++i){
            bool bad = true;
            if(i > 0){
                if(v1[i] == v1[i-1]){
                    bad = false;
                }
            }
            if(i < v1.size()-1){
                if(v1[i] == v1[i+1]){
                    bad = false;
                }
            }
            if(bad){
                good = false;
            }
        }
        for(int i=0;i<v2.size();++i){
            bool bad = true;
            if(i > 0){
                if(v2[i] == v2[i-1]){
                    bad = false;
                }
            }
            if(i < v2.size()-1){
                if(v2[i] == v2[i+1]){
                    bad = false;
                }
            }
            if(bad){
                good = false;
            }
        }
        if(good){
            R = M;
        }else{
            L = M+1;
        }
    }
    cout << L << endl;
}
