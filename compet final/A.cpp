#include <bits/stdc++.h>
#define sor3a ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int main() {


    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;

//     int idx = 0;
//     bool found = false;
//     int ans = 0;
//     while(idx <= n-1){
//         if (idx == n-1){
//             if (s[idx] == 'B' && t[idx] == 'A'){
//                 cout << -1;
//                 return 0;
//             }
//         }
//         if (s[idx] == 'A' && t[idx] == 'B'){
//             if (found)  {
//                 ans++;
//                 idx++;
//                 continue;
//             }else{
//                 cout << -1;
//                 return 0;
//             }
//         }
//         if (s[idx] == 'A') {
//                         // cout << " dkhl hna ?" << endl;
// found = true;
//         } 
//         if (s[idx] == 'B' && t[idx] == 'A'){
//             while(idx+1<=n-1 && s[idx+1] == t[idx+1]){
//                 idx++;
//             }
//             idx++;
//             ans++;
//             s[idx] = 'B';
//             continue;
//         }
//         idx++;

//         // cout << s << endl;
//         // cout << idx << endl;
//     }

//     cout << ans;


























    if (s == t){
        cout << 0 ;
        return 0;
    }

    if (n == 2){
        if (t=="AB") {
            if (s=="AA" || s=="BA" || s=="BB") {
                cout << 1;
                return 0;
            }
        }
        cout << -1;
        return 0;
    }

   int a=0,b=0;
   int cnta = 0, cntb = 0;
    int founda=0, foundb=0,a0,b0;
    for (int i=0;i<n;++i){
        if (s[i] == 'B' && t[i] == 'A'){
            if(!founda){
                a = i;
                cnta++;
                a0 = i;
                founda = 1;
            }else{
                a = i;
                cnta++;
            }
            
        }

        if (s[i] == 'A' && t[i] == 'B'){
            if(!foundb){
                b = i;
                cntb++;
                b0 = i;
                foundb = 1;
            }else{
                b = i;
                cntb++;
            }
        }

        
    }

    // cout << a.size()+b.size() << endl;
    // cout << a[a.size()-1] << " " << b[0] << endl;
    
    if ( a0 > b0 || a > b || cnta == 0 || cntb == 0){
            cout << -1 << endl;
        }   
        else{
            cout << max(cnta,cntb) << endl;
        }




    return 0;
}