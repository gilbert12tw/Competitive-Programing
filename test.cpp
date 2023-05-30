#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<numeric>
#define loli
using namespace std;
typedef long long ll;
#define int ll
#define pii pair<int, int>
#define X first
#define Y second
#define F first
#define S second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define push emplace
#define lb(x, v) lower_bound(ALL(x), v)
#define ub(x, v) upper_bound(ALL(x), v)
#define re(x) reverse(ALL(x))
#define uni(x) x.resize(unique(ALL(x)) - x.begin())
#define inf 1000000000
#define INF 1000000000000000000
#define get_bit(x, y) ((x>>y)&1)
#define mkp make_pair
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
#ifdef loli
#define test(args...) abc("[" + string(#args) + "]", args)
#else
#define test(args...) void(0)
#endif

const int mxN = 2e6 + 5;

#define ULL unsigned long long
#define LL long long
ULL LLmul(ULL a, ULL b, const ULL &mod) {
	LL ans=0;
	while(b) {
		if(b&1) {
			ans+=a;
			if(ans>=mod) ans-=mod;
		}
		a<<=1, b>>=1;
		if(a>=mod) a-=mod;
	}
	return ans;
}
ULL mod_mul(ULL a,ULL b,ULL m){
    return __int128{a} * b % m;
}
template<typename T>
T pow(T a,T b,T mod){//a^b%mod
	T ans=1;
	for(;b;a=mod_mul(a,a,mod),b>>=1)
		if(b&1)ans=mod_mul(ans,a,mod);
	return ans;
}
int sprp[3]={2,7,61};//int範圍可解
int llsprp[7]={2,325,9375,28178,450775,9780504,1795265022};//至少unsigned long long範圍

bool isprime(LL n,int *sprp,int num){
	if(n==2)return 1;
	if(n<2||n%2==0)return 0;
	int t=0;
	LL u=n-1;
	for(;u%2==0;++t)u>>=1;
	for(int i=0;i<num;++i){
		LL a=sprp[i]%n;
		if(a==0||a==1||a==n-1)continue;
		LL x=pow(a,u,n);
		if(x==1||x==n-1)continue;
		for(int j=1;j<t;++j){
			x=mod_mul(x,x,n);
			if(x==1)return 0;
			if(x==n-1)break;
		}
		if(x==n-1)continue;
		return 0;
	}
	return 1;
}

LL func(const LL n,const LL mod,const int c) {
	return (LLmul(n,n,mod)+c+mod)%mod;
}

LL pollorrho(const LL n, const int c) {//循環節長度 
	LL a=1, b=1;
	a=func(a,n,c)%n;
	b=func(b,n,c)%n; b=func(b,n,c)%n;
	while(gcd(abs(a-b),n)==1) {
		a=func(a,n,c)%n;
		b=func(b,n,c)%n; b=func(b,n,c)%n;
	}
	return gcd(abs(a-b),n);
}

bool Isprime(LL n) {
    return isprime(n, llsprp, 7);
}

void comfactor(const LL &n, vector<LL> &v) {
	if(Isprime(n)) {
		v.push_back(n);
		return;
	}
	LL d = n;
	while (d >= n) d = pollorrho(n, rand() % (n - 1) + 1);
	comfactor(d, v);
	comfactor(n/d, v);
}

void Factor(const LL &x, vector<LL> &v) {
	LL n = x;
	if(n==1) return;
	comfactor(n,v);
	sort(v.begin(),v.end());
}

inline void solve() {
    LL n; cin >> n;
    if (n == 0) {
        cout << "Peace TeTe\n";
    } 
    else if (n == 1) {
        cout << "Aleak\n";
    }
    else {
        vector<LL> fac;
        comfactor(n, fac);

        map<LL, LL> mp;
        for (LL i : fac) mp[i]++;

        LL ans = 0;
        for (auto [x, y] : mp) ans ^= y;

        if (ans) cout << "Eillo\n";
        else cout << "Aleak\n";
    }
}

signed main() {
	IO;	
    int T; cin >> T;
	while (T--) solve();	
}
