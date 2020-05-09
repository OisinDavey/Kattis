#include<bits/stdc++.h> 
#define MX_N 5001
#define INF 100000000

#define mod7 1000000007
#define modpi 314159

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

ll D = 257;

unsigned int Hash(vector<int>& s){
    ll ans = 0;
    for(int x : s){
        ans = ans * D + x;
        ans %= mod7;
    }return ans;
}

ll binpow(ll base, ll expo){
    if(expo == 0)
        return 1;
    if(expo == 1)
        return base % mod7;
    ll ans = binpow(base, expo/2);
    ans = ans * ans % mod7;
    if(expo % 2 == 1)
        ans = ans * base % mod7;
    return ans;
}

vector<int> RK(vector<int>& A, vector<int>& B){
    ll P = Hash(A);
    ll S = 0;

    ll n = A.size();
    ll m = B.size();

    ll power = binpow(D, n);

    vector<int> ans;

    for(int i=0;i<m;++i){
        S = S*D + B[i];
        S %= mod7;

        if(i >= n){
            S -= power * B[i-n] % mod7;
            if(S < 0)
                S += mod7;
        }

        if(S == P && i >= n-1)
            ans.push_back(i - (n-1));
    }

    return ans;
}

bool DoesWordHaveFBI(string& s){
    string a = "FBI";
    vector<int> A, B;
    for(char c : a)
        A.push_back((ll)c);
    for(char c : s)
        B.push_back((ll)c);
    vector<int> ans = RK(A, B);
    if(ans.size() == 0)
        return 0;
    for(int i=0;i<ans.size();++i)
        if(s.substr(ans[i], 3) == "FBI")
            return 1;
    return 0;
}

int main(){
    vector<int> ans;
    for(int i=0;i<5;++i){
        string s;
        cin >> s;
        if(DoesWordHaveFBI(s))
            ans.push_back(i);
    }if(ans.size() == 0){
        cout << "HE GOT AWAY!\n";
        return 0;
    }else{
        for(int x : ans)
            cout << x+1 << ' ';
        cout << endl;
    }
}
