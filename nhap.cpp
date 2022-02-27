#include <iostream>
#include <vector>
using namespace std;
main() {
    vector<int> p = {1, 2};
    p.erase(p.begin());
    for (int i: p)
        cout << i;
}