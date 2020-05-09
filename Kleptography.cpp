#include<bits/stdc++.h> 
#define MX_N 5001
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
    int n, m;
    cin >> n >> m;
    string A, K, B, extra;
    cin >> extra;
    cin >> B;
    A = B;
    K = B;
    for(int i=0;i<n;++i)
        A[m-n+i] = extra[i];
    for(int i=m-1;i>=n;--i){
        if(B[i] > A[i])
            K[i] = (char)(B[i]-A[i]+'a');
        else
            K[i] = (char)((26-A[i]+B[i])%26+'a');
        A[i-n]=K[i];
    }cout << A << endl;
}
