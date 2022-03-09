#include "mylib.h"
#include <iostream>
using namespace std;
main() {
    for (int i=0;i<200;i++) {
        textcolor(i);
        cout << i;
    }
}