#include<bits/stdc++.h>

using cd = complex<double>;
using namespace std;

const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

int main(){
    
    string s;
    cin >> s;
    int n = s.size();
    
    
    vector<int> a(2*n, 0), b(n*2, 0), c(2*n, 0);
    vector<int> aa(2*n, 0), bb(n*2, 0), cc(2*n, 0);
    
    for(int i = 0; i < n; i++){
        if(s[i] == 'a'){
            a[i] = 1;
            aa[n-1-i] = 1;
            continue;
        }
        if(s[i] == 'b'){
            b[i] = 1;
            bb[n-1-i] = 1;
            continue;
        }
        if(s[i] == 'c'){
            c[i] = 1;
            cc[n-1-i] = 1;
            continue;
        }
    }
    
    vector<int> mula = multiply(a, aa);
    vector<int> mulb = multiply(b, bb);
    vector<int> mulc = multiply(c, cc);
    
    int sz = mula.size();
    
    vector<int> res(sz);
    int mx = 0;
    
    for(int i = n; i < sz; i++){
        res[i] = mula[i] + mulb[i] + mulc[i];
        mx = max(mx, res[i]);
    }
    
    for(int i = n; i < sz; i++){
        if(res[i] == mx) cout << i << '\n';
    }
    
    
    return 0;
}