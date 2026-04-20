#include <iostream>
#include <vector>
#include <map>
using namespace std;
string solve(int n, vector<int> &arr) {
    map<int, int, greater<int>> freq;

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    vector<int> picks;

    for (auto it = freq.begin(); it != freq.end(); it++) {
        int val = it->first;
        int f = it->second;

        int times = (f >= 2) ? 2 : 1;

        for (int i = 0; i < times; i++) {
            picks.push_back(val);
        }
    }

    long long alex = 0, bob = 0;

    for (int i = 0; i < picks.size(); i++) {
        if (i % 2 == 0)
            alex += picks[i];
        else
            bob += picks[i];
    }

    if (alex > bob)
        return "Alex";
    else
        return "Bob";
}

int main() {

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << solve(n, arr) << endl;
    }

    return 0;
}