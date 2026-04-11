#include <iostream>
using namespace std;
bool can(string s, int n, int k, int l) {
    int ops = 0;

    for (int i = 0; i < n; ) {
        if (s[i] == '1') {
            ops++;
            i += l;
        } else {
            i++;
        }
    }

    return ops <= k;
}

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int left = 1, right = n, ans = n;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (can(s, n, k, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}