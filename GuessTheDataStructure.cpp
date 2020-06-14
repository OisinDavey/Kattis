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
    while(cin >> n){
        pair<int, int> a[n];
        for(int i=0;i<n;++i){
            cin >> a[i].fi >> a[i].se;
        }
        queue<int> Q;
        stack<int> S;
        priority_queue<int, vector<int>, less<int> > PQ;
        bool q = true;
        bool s = true;
        bool pq = true;
        for(int i=0;i<n;++i){
            if(q){
                if(a[i].fi == 1){
                    Q.push(a[i].se);
                }else{
                    if(Q.empty()){
                        q = false;
                    }else if(Q.front() != a[i].se){
                        q = false;
                    }else{
                        Q.pop();
                    }
                }
            }
            if(s){
                if(a[i].fi == 1){
                    S.push(a[i].se);
                }else{
                    if(S.empty()){
                        s = false;
                    }else if(S.top() != a[i].se){
                        s = false;
                    }else{
                        S.pop();
                    }
                }
            }
            if(pq){
                if(a[i].fi == 1){
                    PQ.push(a[i].se);
                }else{
                    if(PQ.empty()){
                        pq = false;
                    }else if(PQ.top() != a[i].se){
                        pq = false;
                    }else{
                        PQ.pop();
                    }
                }
            }
        }
        if(q){
            if(s || pq){
                cout << "not sure\n";
            }else{
                cout << "queue\n";
            }
        }else if(s){
            if(pq){
                cout << "not sure\n";
            }else{
                cout << "stack\n";
            }
        }else if(pq){
            cout << "priority queue\n";
        }else{
            cout << "impossible\n";
        }
    }
}
