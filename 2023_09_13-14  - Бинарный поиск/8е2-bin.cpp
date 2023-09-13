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

void vvod(vector<int> &v){
    for (int i = 0; i < long(v.size()); i++)
        cin >> v[i];
}

void vivod(const vector<int> &v){
    for (int i = 0; i < long(v.size()); i++)
        cout << v[i] << " ";
    cout << endl;
}
// 1 1 3 3 5 7 9 18 18 57
int lower_bound(const vector<int> &data, int el){
    int l = 0;
    int r = int(data.size());
    while (l < r){
        int m = (l + r) / 2;
        if (el <= data[m])
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int upper_bound(const vector<int> &data, int el){
    int l = 0;
    int r = int(data.size());
    while (l < r){
        int m = (l + r) / 2;
        if (el < data[m])
            r = m;
        else
            l = m + 1;
    }
    return l;
}

void search(const vector<int> &data, int el){
    int lb = lower_bound(data, el);
    int ub = upper_bound(data, el);
    if (debug) cout << lb << ' ' << ub << '\n';
    if (data[lb] == el)
        cout << lb + 1 << ' ' << ub << '\n';
    else
        cout << "0\n";
}

void solve(const vector<int> &data, const vector<int> &els){
    for (int i = 0; i < long(els.size()); i++)
        search(data, els[i]);
}

int main()
{
    int n_data, n_els;
    cin >> n_data >> n_els;


    vector<int> data(n_data), els(n_els);
    vvod(data);
    vvod(els);
    if (debug) vivod(data);
    if (debug) vivod(els);
    
    solve(data, els);

    return 0;
}