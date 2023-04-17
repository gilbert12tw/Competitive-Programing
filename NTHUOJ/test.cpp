#include<bits/stdc++.h>
using namespace std;

int n, m;
char color;
list<char> beads;

/*
void eliminate() {
    auto lit = it, rit = it;
    char c = *it;
    while (lit != beads.begin() && *prev(lit) == c) lit--;
    while (next(rit) != beads.end() && *next(rit) == c) rit++;
}
*/

int main() {
    cin >> n >> m >> color;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        beads.push_back(c);
    }
    
    auto it = beads.insert(next(beads.begin(), m), 1, color);

    while (1) {
        int cnt = 1;
        auto lit = it;
        auto rit = it;
        char c = *it;
        while (lit != beads.begin() && *prev(lit) == c) {
            lit--;
            cnt++;
        }
        while (next(rit) != beads.end() && *next(rit) == c) { 
            rit++;
            cnt++;
        }
        if (cnt < 3) break;

        
        if (c == 'R') {
            // do nothing
        } else if (c == 'G') {
            //beads.insert(beads.begin(), cnt * 2, 'G');
        } else {
            //beads.insert(prev(beads.end()), cnt, 'B');
            //beads.reverse();
        }

        it = beads.erase(lit, next(rit));
        for (char c : beads) cout << c;
        cout << '\n';
    }

    for (char c : beads) cout << c;
}
