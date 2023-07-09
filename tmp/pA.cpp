#include<iostream>
#include<list>
#include<cstring>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    list<int> mylist = {1, 2, 3};
    mylist.push_front(10); // mylist = {10, 1, 2, 3}
    mylist.pop_back();     // mylist = {10, 1, 2}

   for (list<int>::iterator it = mylist.begin(); it != mylist.end(); it++) {
      if (*it == 1) { // delete 1 in the list
        it = mylist.erase(it); 
      }
   }
   // mylist = {10, 2}

   for (list<int>::iterator it = mylist.begin(); it != mylist.end(); it++) {
      if (*it == 10) { // insert -1 before 10
        mylist.insert(it, -1); 
      }
   }
   // mylist {-1, 10, 2}

   for (auto it : mylist) cout << it << ' ';



    return 0;
    int n; cin >> n;
    list<int> li;
    while (n--) {
        string opt; cin >> opt;
        int i;
        if (opt[0] == 'I') {
            cin >> i;
            if (opt[1] == 'H') {   // "IH"
                li.push_front(i);
            } else {               // "IT"
                li.push_back(i);
            }
        } else if (opt[0] == 'R') {
            if (li.empty()) // do nothing
                continue; 
            if (opt[1] == 'H') {   // "RH"
                li.pop_front(); 
            } else {               // "RT"
                li.pop_back(); 
            }
        } else if (opt[0] == 'S') {// "S"
            cin >> i;
            if (li.empty()) { cout << "E\n"; continue;}
            // traverse the linked list
            int ok = 0;
            for (auto it : li) 
                if (it == i) ok = 1;

            cout << (ok ? "Y" : "N") << '\n';
        } else {                   // "O"
            if (li.empty()) { cout << "E\n"; continue;}
            for (auto it : li) cout << it << ' ';
            cout << '\n';
        }
    }
}

