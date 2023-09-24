#include <string>
#include <bits/stdc++.h>
#include <algorithm>
#include <stack>

using namespace std;


int main(){
    int t,n,q,a[10005],tot = 1;
    map<int,int> nums;
    cin >> t;
    while(t--){
        
        
        cin >> n >> q;
        for (int i=0;i<n;++i){
            cin >> a[i];
        }
        
        int l,r;
        while(q--){
            cin >> l >> r;
            nums.clear();
            tot = 1;
            int flag = 1;
            for (int i=l-1;i<r;++i){
                
                if (!nums[a[i]]){
                    nums[a[i]] = 1;
                }
                else{
                    // cout << "dfsds" << endl;
                    nums[a[i]] = (nums[a[i]] * (nums[a[i]]+1))%int(1e9 + 7);
                }
                if (flag){
                    flag = 0;
                    continue;
                }
                tot = (tot * (tot+1))%int(1e9 + 7);

            }
            int res = 1;
            for (auto [key,val] : nums){
                // cout << "val" << val << endl;
                res *= val;
                // cout << res << endl;
            }
            // cout << "total fact : " << tot << endl;
            cout << tot/res << endl;
        }


    }
    
    return 0;
}