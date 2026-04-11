#include <iostream>
using namespace std;

const int MAXN = 10000000;

int primeCount[MAXN + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i <= MAXN; i++) {
        if (primeCount[i] == 0) {
            for (int j = i; j <= MAXN; j += i) {
                primeCount[j]++;
            }
        }
    }

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int k = primeCount[n];

        int ans = 1 << k;

        cout << ans << '\n';
    }

    return 0;
}