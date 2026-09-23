#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N= 2e5+5,MOD=1e9+7,INF=1e18+5;

int gcd(int a,int b){// O(log(min(a,b)))
    if(b==0) return a;
    return gcd(b,a%b);
}

int lcm(int a,int b){
    return a*b/gcd(a,b);
}

vector<int> find_divisors(int n){// sqrt(n)
    vector<int> divisors;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            divisors.push_back(i);
            if(i!=n/i)divisors.push_back(n/i);
        }
    }
    sort(divisors.begin(),divisors.end());
    return divisors;
}

vector<int> factorize(int n){// sqrt(n)
    vector<int> factors;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            n/=i;
            factors.push_back(i);
        }
    }
    if(n>1) factors.push_back(n);
    return factors;
}

vector<int> factorizeU(int n){// sqrt(n) unique
    vector<int> factors;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            factors.push_back(i);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) factors.push_back(n);
    return factors;
}

bool isprime(int n){// sqrt(n)
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}

// N is the maximum value not the count of elements applicaple if N is at most 1e6
vector<int> divisors[N];
int number_divisors[N];

void find_all_divisors(){// nlogn
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            divisors[j].push_back(i);
        }
    }
}

void find_all_number_divisors(){// nlogn
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            number_divisors[j]++;
        }
    }
}

vector<bool> is_prime(N, true);
int spf[N];

void sieve(){//n loglogn up to 1e7
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) {
            spf[i]=i;
            for (int j = i * i; j < N; j += i){
                is_prime[j] = false;
                if(!spf[j]) spf[j]=i;
            }
        }
    }
}

vector<int> factorizeF(int x){// logn fast
    vector<int> factors;
    while(x!=1){
        factors.push_back(spf[x]);
        x/=spf[x];
    }
    return factors;
}

vector<int> factorizeFU(int x){// logn fast and unique
    vector<int> factors;
    while(x!=1){
        int p=spf[x];
        factors.push_back(p);
        while(x%p==0) x/=p;
    }
    return factors;
}

void solve(){
gcd(12,15);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t=1; 
    // cin>>t;
    while(t--) solve();
    return 0;
}