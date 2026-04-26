#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    int Q; cin >> Q;
    unordered_map<int, unordered_set<int>> m;

    while (Q--) {
        string cmd; cin >> cmd;

        if (cmd == "BOOK") {
            int x, y; cin >> x >> y;
            if (m[y].count(x) || m[y].size() >= 100) cout << "false\n";
            else { m[y].insert(x); cout << "true\n"; }
        }
        else if (cmd == "CANCEL") {
            int x, y; cin >> x >> y;
            if (!m[y].count(x)) cout << "false\n";
            else { m[y].erase(x); cout << "true\n"; }
        }
        else if (cmd == "IS_BOOKED") {
            int x, y; cin >> x >> y;
            cout << (m[y].count(x) ? "true\n" : "false\n");
        }
        else if (cmd == "AVAILABLE_TICKETS") {
            int y; cin >> y;
            cout << 100 - m[y].size() << "\n";
        }
    }
}