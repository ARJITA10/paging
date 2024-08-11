#include <iostream>
#include <vector>

using namespace std;

int main() {
    int ms, ps, nop, np, rempages, i, j, x, y, pa, offset;
    vector<int> s(10);           // Stores the number of pages required for each process
    vector<vector<int>> fno(10); // Page tables for each process

    cout << "\nEnter the memory size: ";
    cin >> ms;

    cout << "\nEnter the page size: ";
    cin >> ps;

    nop = ms / ps;
    cout << "\nThe number of pages available in memory are: " << nop;

    cout << "\nEnter the number of processes: ";
    cin >> np;

    rempages = nop;

    for (i = 1; i <= np; i++) {
        cout << "\nEnter number of pages required for process [" << i << "]: ";
        cin >> s[i];

        if (s[i] > rempages) {
            cout << "\nMemory is Full";
            return 0;
        }

        rempages -= s[i];
        cout << "\nEnter page table for process [" << i << "]: ";
        
        fno[i].resize(s[i]);  // Resize the inner vector to the number of pages for this process

        for (j = 0; j < s[i]; j++) {
            cin >> fno[i][j];
        }
    }

    cout << "\nEnter Logical Address to find Physical Address";
    cout << "\nEnter process number, page number, and offset: ";
    cin >> x >> y >> offset;

    if (x > np || y >= s[x] || offset >= ps) {
        cout << "\nInvalid Process, Page Number, or Offset";
    } else {
        pa = fno[x][y] * ps + offset;
        cout << "\nThe Physical Address is: " << pa;
    }

    return 0;
}
