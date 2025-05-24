#include<bits/stdc++.h>
#include <chrono>
using namespace std;
typedef long long int ll;
ll mod=1e9+7;
ll check=0;
// stack<ll> st;
vector<ll> visited(1,0);
void toposort(stack<ll>& st,vector<vector<ll>>& adj,ll n){
    visited[n]=1;
    for(auto k:adj[n]){
        if(visited[k]==1){continue;}
        toposort(st,adj,k);
    }
    st.push(n);
}
void ps(stack<ll> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<" gg\n";
}
void solve() {
    ll n,m;
    cin>>n>>m;
    visited.clear();
    visited.resize(n+1,0);
    stack<ll> st;
    vector<vector<ll>> v(n,vector<ll>(4,0));
    vector<vector<ll>> adj(n+1);
    vector<vector<ll>> rev(n+1);
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        rev[y].push_back(x);
    }
    for(int i=0;i<n;i++){
        char s,c;
        int x,y;
        cin>>s>>x>>c>>y;
        v[i][1]=x;
        v[i][3]=y;
        if(s=='+'){
            v[i][0]=1;
        }
        else{
            v[i][0]=2;
        }
        if(c=='+'){
            v[i][2]=1;
        }
        else{
            v[i][2]=2;
        }
    }
    for(int i=1;i<=n;i++){
        if(visited[i]==1){continue;}
        toposort(st,adj,i);
    }
    // ps(st);
    vector<ll> ans(n+1,0);
    for(int i=1;i<=n;i++){
        if(rev[i].size()==0){
            adj[0].push_back(i);
            rev[i].push_back(0);
        }
    }
    st.push(0);
    while(!st.empty()){
        ll idx=st.top();
        st.pop();
        for(auto k:adj[idx]){
            ll y=0;
            for(auto l:rev[k]){
                if(v[k-1][0]==1){
                    y=max(y,ans[l]+v[k-1][1]);
                }
                else{
                    y=max(y,ans[l]*v[k-1][1]);
                }
                if(v[k-1][2]==1){
                    y=max(y,ans[l]+v[k-1][3]);
                }
                else{
                    y=max(y,ans[l]*v[k-1][3]);
                }
                ans[k]=max(ans[k],y);
            }
        }
    }
    ll maxx=0;
    for(int i=1;i<=n;i++){
        // cout<<ans[i]<<" ";
        maxx=max(maxx,ans[i]);
    }
    cout<<maxx<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("testcases.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Your generator code here
    
    ll t=1;
    cin>>t;
    auto start = std::chrono::high_resolution_clock::now();
    while(t--){
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cerr << "Time taken: " << diff.count() << " seconds\n";
}