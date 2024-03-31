#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 50;
vector<int> e[maxn];
ll fa[maxn],dep[maxn],son[maxn],siz[maxn],top[maxn];
ll diff[maxn];
void dfs1(ll u,ll f) {
	fa[u] = f;
	dep[u] = dep[f] + 1;
	siz[u] = 1;
	for (auto x : e[u]) {
		ll v = x;
		if (v == f) continue;
		dfs1(v,u);
		siz[u] += siz[v];
		if (siz[v] > siz[son[u]]) son[u] = v;
	}
} 
void dfs2(ll u, ll t) {
	top[u] = t;
	if (!son[u]) return;
	dfs2(son[u],t);
	for (auto x : e[u]) {
		ll v = x;
		if (v!=son[u]&&v!=fa[u]) dfs2(v,v);
	}
}
ll lca(ll x,ll y) {
	while(top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap(x,y);
		x = fa[top[x]];
		
	}
	return dep[x] > dep[y] ? y:x; 
}
void dfs(int x,int fx){
	for (auto y : e[x]) {
		if (y == fx) continue;
		diff[x] += diff[y];
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin.tie(nullptr);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int u,v;
		cin >> u >> v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	dfs1(1,1);
	dfs2(1,1);
	for (int i = 1; i <= m; i++) {
		int u,v;
		cin >> u >> v;
		diff[u]++,diff[v]++,diff[lca(u,v)] -= 2;
		
	}
	dfs(1,0);
	ll ans = -1;
	for (int i = 0; i <= n; i++) if (diff[i] >= m) ans = i -1;
	cout << ans << endl;
	return 0;
}
