#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1000003;
ll s;
ll f[N] = {0};
int main(){
    int n;
    cin >> n;
    cin >> s;
    for (int i = 1; i <= n; i++){
        cin >> f[i];
        f[i] = f[i - 1] + f[i];
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        for (int j = i ; j <= n; j++){
            ll t = f[j] - f[i];
            if (2*j-i < n) {
                ll q = f[2*j - i] - f[i];
                if (t <= s && q <= 2*s){
                    ans = (2*(j-i) > ans) ? 2*(j-i) : ans;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

