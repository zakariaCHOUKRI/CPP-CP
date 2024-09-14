#include <bits/stdc++.h>
using namespace std;
/* #pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
typedef long long ll;
const ll MAXN = 1e6 + 5;
const ll MAXD = 1e3 + 5;
const ll MOD = 1e9 + 7;
const ll MODH = 1e9 + 9;
const ll p = 41;
const long double EPS = 1e-4;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll rand(ll a, ll b) {ll c = rng(); return a+((ll)abs(c))%(b-a+1);}
ll inv[MAXN] , pp[MAXN] , hp[MAXN];
string s,pat;
ll hpat;
int n;
ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
void pinv()
{
  inv[MAXN - 1] = binpow(pp[MAXN - 1] , MODH - 2 , MODH);
  for(int i = MAXN - 2; i >= 0 ; i--)
       inv[i] = (inv[i + 1] * p) % MODH;
}
 
void phash()
{
   s = '0' + s;
   for(int i = 1 ; i < (int)s.size() ; i++)
       hp[i] = (hp[i - 1] + (s[i] - 'a' + 1) * pp[i]) % MODH;
    

}
 
void phash_pat()
{
   hpat = 0;
   for(int i = 0 ; i < (int)pat.size() ; i++)
   {
     hpat = (hpat + (pat[i] - 'a' + 1) * pp[i])%MODH;
   }
}
 
 
ll get_hash(int l,int r)
{
ll left = hp[l - 1];
ll right = hp[r];
ll invh = inv[l];
ll ret = (right - left + MODH) % MODH;
ret = (ret * invh)%MODH;
return ret;
}
 
void prep()
{
   pp[0] = 1;
   for(int i = 1 ; i < MAXN ; i++)
      pp[i] = (pp[i - 1] * p) % MODH;
}
 
 

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
prep();
pinv();
cin >> s;
n = (int)s.size();
phash();


int p1, p2;
p1 = 1;
p2 = s.size()-1;

while (p1 < s.size()-1 && p2 > 0) {
    if (get_hash(1, p1) == get_hash(p2, s.size()-1)) {
        cout << p1 << " ";
    }
    p1++;
    p2--;
}


}



 
