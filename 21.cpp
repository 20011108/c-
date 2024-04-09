#include <bits/stdc++.h>
using namespace std;

vector<long long int> primeNum, primeVal;
// 将x质因数分解
void CalaPrime(long long int x) {
  printf("%lld = ", x);
  for (long long int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      int num = 0;
      while (x % i == 0) {
        x /= i;
        num++;
      }
      primeNum.push_back(num);
      primeVal.push_back(i);
    }
  }
  if (x > 1) {
    primeNum.push_back(1);
    primeVal.push_back(x);
  }

  for (unsigned int i = 0; i < primeNum.size(); i++) {
    if (i != 0) {
      printf("  *  ");
    }
    printf("\n(%lld ^ %lld)", primeVal[i], primeNum[i]);
  }
  printf("\n");
}

int main() {
  CalaPrime(2021041820210418);

  long long int ans = 0;
  ans = 3 * 3 * 3 * 3 * 3;
  ans *= 10;

  printf("ans = %lld\n", ans);
  return 0;
}

