#include<bits/stdc++.h>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vii> vvii;

int n;
vi dep, tin, tout;
vvi g;
vvi par; // par[node][i] = (2^i)th parent of node
int timer=0; 
map<int,vi> mp;

void dfs(int node, int prev, int depth){
    mp[depth].push_back(timer);
    tin[node] = timer++;
    dep[node] = depth;
    par[node][0] = prev;

    for(int i=1;i<20;i++){
        par[node][i] = par[par[node][i-1]][i-1];
    }
    for(auto &v:g[node]){
        if(v!=prev){
            dfs(v,node,depth+1);
        }
    }
    mp[depth].push_back(timer);
    tout[node] = timer++;
}

void solve(){
    cin>>n;
    mp.clear();
    g.clear(); g.resize(n+1);
    dep.clear(); dep.resize(n+1);
    tin.clear(); tin.resize(n+1);
    tout.clear(); tout.resize(n+1);
    par.clear(); par.resize(n+1,vi(20,0));

    vi vec;
    for(int i=1;i<=n;i++){
        int p; cin>>p;
        if(p==0) vec.push_back(i);
        else{
            g[i].push_back(p);
            g[p].push_back(i);
        }
    }
    for(int i=0;i<vec.size();i++){
        dfs(vec[i],vec[i],0);
    }

    int q; cin>>q;
    for(int i=0;i<q;i++){
        int v,p; cin>>v>>p;
        if(dep[v]<p){
            cout<<"0 ";
        }
        else{
            int node = v;
            int ptemp = p;
            for(int i=19;i>=0;i--){
                if(ptemp&(1<<i)){
                    node = par[node][i];
                }
            }
            // find no of children of node at depth = p
            int rd = dep[v];
            int numreqd = lower_bound(mp[rd].begin(), mp[rd].end(), tout[node]) - lower_bound(mp[rd].begin(), mp[rd].end(), tin[node]);
            cout<<(numreqd/2)-1<<" ";
        }
    }cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
    int t=1; //cin>>t;
    while(t--){
        solve();
    }
}