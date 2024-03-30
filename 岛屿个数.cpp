#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int dx[8] = {1,-1,0,0,-1,-1,1,1};
const int dy[8] = {0,0,1,-1,-1,1,-1,1};
int n,m;
char graph[60][60];
bool vis[60][60]; 
char fill(int A,int B){
	for (int i = 0; i <= n+ 1;i++) {
		for (int j = 0; j <= m+1; j++) {
			vis[i][j] = false;
			
		}
	}
	queue<pair<int,int>> q;
	q.emplace(A,B);
	vis[A][B] = true;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first, y = cur.second;
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i],ny = y + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > m) return true;
			if (graph[nx][ny] == '0' && !vis[nx][ny]) {
				vis[nx][ny] = true;
				q.emplace(nx,ny);
			}
		}
	}
	return false;
}
void bfs(int A,int B) {
	queue<pair<int,int>> q;
	q.emplace(A,B);
	while(!q.empty()){
		auto cur = q.front();
		q.pop();
		int x = cur.first,y=cur.second;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i],ny=y+dy[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && graph[nx][ny]=='1'){
				graph[nx][ny] = '0';
				q.emplace(nx,ny);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> n >> m;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				cin >> graph[i][j];
			}
		}
		int ans = 0;
		for (int i = 1; i<=n; i++){
			for (int j = 1; j <= m; j++){
				if (graph[i][j] == '1'){
					if(!fill(i,j))
						graph[i][j] = '0';
				}
			}
		}
		for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (graph[i][j] == '1') {
                    ans++;
                    bfs(i, j);
                }
            }
        }
        cout << ans <<endl;
	}
	return 0;
}


