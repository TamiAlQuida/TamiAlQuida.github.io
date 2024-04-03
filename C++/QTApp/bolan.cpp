#include <iostream>
using namespace std;

int kontantinsats;

void bolan (int penga) {
    kontantinsats = penga * 0.15;
    cout << kontantinsats;
}

int main() {
    bolan(1000);
}
