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

int tree[200002];

int LSOne(int val){
    return (val)&(-val);
}

void update(int at, int val){
    while(at < 200002){
        tree[at] += val;
        at += LSOne(at);
    }
    return;
}

int rq(int at){
    int ans = 0;
    while(at > 0){
        ans += tree[at];
        at -= LSOne(at);
    }
    return ans;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int m, r;
        cin >> m >> r;
        memset(tree, 0, sizeof(tree));
        int pos[m];
        for(int i=0;i<m;++i){
            pos[i] = m-i+1;
            update(pos[i], +1);
        }
        int end = m+1;
        for(int i=0;i<r;++i){
            int q;
            cin >> q;
            --q;
            int res = rq(pos[q]);//The amount below & including
            cout << m-res << ' ';
            update(pos[q], -1);
            update(end+1, +1);
            pos[q] = end+1;
            ++end;
        }
        cout << endl;
    }
}
