/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

#define debug 0

using namespace std;

void vvod(vector<int> &v) {
    for (int i = 0; i < int(v.size()); i += 1)
        cin >> v[i];
}

void vivod(const vector<int> &v) {
    for (int i = 0; i < int(v.size()); i += 1)
        cout << v[i] << ' ';
    cout << endl;
}

//  1 2 3 3 3 4 4 5

int upper_bound(const vector<int> &data, int el){
    int l = 0;
    int r = int(data.size());
    while (l < r) {
        int m = (l + r) / 2;
        if (el < data[m])
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int lower_bound(const vector<int> &data, int el){
    int l = 0;
    int r = int(data.size());
    while (l < r) {
        int m = (l + r) / 2;
        if (el <= data[m])
            r = m;
        else
            l = m + 1;
    }
    return l;
}

void solve(const vector<int> &data, const vector<int> &els){
    for (int i = 0; i < int(els.size()); i += 1) {
        int ub = upper_bound(data, els[i]);
        int lb = lower_bound(data, els[i]);
        
        if (data[lb] == els[i])
            cout << lb + 1 << " " << ub << '\n';
        else
            cout << 0 << '\n';
    }
}

int main()
{
    int data_n, els_n;
    cin >> data_n >> els_n;
    
    vector<int> data(data_n), els(els_n);
    
    vvod(data);
    vvod(els);
    
    if (debug) vivod(data);
    if (debug) vivod(els);
    
    solve(data, els);

    return 0;
}