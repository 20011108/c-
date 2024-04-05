#include <bits/stdc++.h>
using namespace std;

const int maxn = 2021;

vector<int> u[maxn + 52];
vector<int> v[maxn + 52];
int disDijk[maxn + 52];
int disFloyd[maxn + 52][maxn + 52];
bool vis[maxn + 52];

// 初始化建图，u[i][j]表示i的第j条出边编号，v[i][j]表示i的第j条边的长度，也就是i和u[i][j]的距离
void InitGroup() {
  for (int i = 1; i <= maxn; i++) {
    for (int j = i + 1; j <= maxn; j++) {
      if (j - i <= 21) {
        u[i].push_back(j);
        v[i].push_back(i * j / __gcd(i, j));
        u[j].push_back(i);
        v[j].push_back(i * j / __gcd(i, j));
      }
    }
  }
}

// floyd算法计算最短路，disFloyd[i][j] 表示i到j的最短距离
void Floyd() {
  // 初始化disFloyd为一个较大值
  memset(disFloyd, 0x3f, sizeof(disFloyd));
  for (unsigned int i = 1; i <= maxn; i++) {
    for (unsigned int j = 0; j < v[i].size(); j++) {
      disFloyd[i][u[i][j]] = v[i][j];
      disFloyd[u[i][j]][i] = v[i][j];
    }
  }

  // 执行floyd算法
  for (int k = 1; k <= maxn; k++) {
    for (int i = 1; i <= maxn; i++) {
      for (int j = 1; j <= maxn; j++) {
        disFloyd[i][j] = disFloyd[j][i] = min(disFloyd[i][j], disFloyd[i][k] + disFloyd[k][j]);
      }
    }
  }
  printf("floyd ans = %d\n", disFloyd[1][maxn]);
}

// Dijkstra算法计算最短路，disDijk[i]表示i距离结点1的最短距离
void Dijkstra() {
  memset(disDijk, 0x3f, sizeof(disDijk));
  memset(vis, 0, sizeof(vis));

  disDijk[1] = 0;

  for (int i = 1; i <= maxn; i++) {
    int curMin = 0x3f3f3f3f;
    int curIndex = -1;
    for (int j = 1; j <= maxn; j++) {
      if (vis[j]) {
        continue;
      }
      if (curMin > disDijk[j] || curIndex == -1) {
        curMin = disDijk[j];
        curIndex = j;
      }
    }
    vis[curIndex] = true;

    for (unsigned int j = 0; j < u[curIndex].size(); j++) {
      int t = u[curIndex][j], val = v[curIndex][j];
      disDijk[t] = min(disDijk[t], disDijk[curIndex] + val);
    }
  }
  printf("Dijkstra ans = %d  vis = %d\n", disDijk[2021], vis[2021]);
}

int main() {
  InitGroup();
  Floyd();
  Dijkstra();

  return 0;
}

