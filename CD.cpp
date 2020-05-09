#include<bits/stdc++.h> 
#define MX_N 1000000
#define INF 100000000

#define mod7 1000000007

typedef long long int ll;
typedef unsigned long long int ull;

ll gcd(ull a, ull b){return (a==0)?b:gcd(b%a,a);}
ll lcm(ull a, ull b){return a*(b/gcd(a,b));}

int kx[8] = {+2,+2,-2,-2,+1,+1,-1,-1};
int ky[8] = {+1,-1,+1,-1,+2,-2,+2,-2};
int d9x[9] = {+1,+1,+1,+0,+0,+0,-1,-1,-1};
int d9y[9] = {+1,+0,-1,+1,+0,-1,+1,+0,-1};
int dx4[4] = {0, 0, +1, -1};
int dy4[4] = {+1, -1, 0, 0};

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p1=0, p2=0;
    int sum=0;
    int n, m;
    static ll a[MX_N], b[MX_N];
    while(1){
        scanf("%d %d", &n, &m);

        if(n==0 && m==0)
            return 0;

        for(int i=0;i<n;++i)
            scanf("%lld", &a[i]);
        for(int i=0;i<m;++i)
            scanf("%lld", &b[i]);

        p1=0, p2=0;
        sum=0;

        while(p1 < n && p2 < m){
            sum += (a[p1] == b[p2]);
            (a[p1] > b[p2])?++p2:++p1;
        }cout << sum << endl;
    }
}

