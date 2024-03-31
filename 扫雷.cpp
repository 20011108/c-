#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct point {
	int x, y,r;
	point(int xx,int yy,int rr):x(xx),y(yy),r(rr) {
	}
}; 
double get_len(int i,int j,int x,int y){
	return sqrt((i-x)*(i-x) + (j-y)*(j-y));
}
map<pair<int,int>,int>mp;
queue<point> q;
set<pair<int,int>> s;
int m,n;
ll ans = 0;
int main() {
	cin >> n >> m;
	int x ,y ,r;
	for (int i = 0; i< n; i++) {
		cin >> x >> y >> r;
		int tmp = mp[make_pair(x,y)] + 100;
		mp[make_pair(x,y)] = max(tmp,tmp/100 * 100 + r);
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> r;
		q.push(point(x,y,r));
	}
	while(!q.empty()) {
		point po = q.front();
		x = po.x,y=po.y,r=po.r;
		q.pop();
		for (int i = x - r; i <= x + r; i++) {
			for (int j = y - r; j <= y + r; j++) {
				pair<int,int> pir(i,j);
				if (s.count(pir)) continue;
				if (!mp.count(pir)) continue;
				if (get_len(i,j,x,y) > r) continue;
				s.insert(pir);
				q.push(point(i,j,mp[pir] % 100));
				ans += mp[pir] / 100;
			}
		} 
	}
	cout << ans << endl;
} 
