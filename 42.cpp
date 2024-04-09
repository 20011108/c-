#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
vector<pair<int,int>> e[maxn];
ll fa[maxn],dep[maxn],son[maxn],siz[maxn],top[maxn];
ll c[maxn],suf[maxn];
ll sum[maxn];
void dfs1(ll u,ll f,ll val){
	fa[u] = f;
	dep[u] = dep[f] + 1;
	siz[u] = 1;
	sum[u] = val;
	for (auto x:e[u]){
		ll v = x.first;
		if (v == f) continue;
		dfs1(v,u,val+x.second);
		siz[u] += siz[v];
		if (siz[v]>siz[son[u]]) son[u] = v;
	}
} 
void dfs2(ll u,ll t){
	top[u] = t;
	if(!son[u]) return;
	dfs2(son[u],t);
	for (auto x:e[u]){
		ll v = x.first;
		if(v != son[u] && v != fa[u]) dfs2(v,v);
	}
}
ll lca(ll x,ll y){
	while(top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x,y);
		x = fa[top[x]];
	}
	return dep[x] > dep[y]? y:x;
}
ll get(ll x, ll y){
	if(x==0||y == 0) return 0;
	return sum[x] + sum[y] - 2 * sum[lca(x,y)];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,k;
	cin>> n >> k;
	for(int i = 1; i < n; i++){
		int u,v,z;
		cin >> u >> v >> z;
		e[u].emplace_back(v,z);
		e[v].emplace_back(u,z);
	}
	dfs1(1,1,0);
	dfs2(1,1);
	for (int i = 1; i <= k; i++) cin >> c[i];
	for(int i = k; i >= 1; i--) suf[i] = suf[i-1] + get(c[i],c[i+1]);
	ll pre = 0;
	for (int i = 1; i <= k; i++){
		cout << pre + get(c[i-1],c[i+1]) + suf[i+1] << " ";
		pre += get(c[i-1],c[i]); 
	}
	return 0;
}
