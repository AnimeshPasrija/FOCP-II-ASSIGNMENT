#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int Q; cin >> Q;
    unordered_map<int, int> acc;

    while (Q--) {
        string cmd; cin >> cmd;

        if (cmd == "CREATE") {
            int x, y; cin >> x >> y;
            if (acc.count(x)) { acc[x] += y; cout << "false\n"; }
            else { acc[x] = y; cout << "true\n"; }
        }
        else if (cmd == "DEBIT") {
            int x, y; cin >> x >> y;
            if (!acc.count(x) || acc[x] < y) cout << "false\n";
            else { acc[x] -= y; cout << "true\n"; }
        }
        else if (cmd == "CREDIT") {
            int x, y; cin >> x >> y;
            if (!acc.count(x)) cout << "false\n";
            else { acc[x] += y; cout << "true\n"; }
        }
        else if (cmd == "BALANCE") {
            int x; cin >> x;
            cout << (acc.count(x) ? acc[x] : -1) << "\n";
        }
    }
}