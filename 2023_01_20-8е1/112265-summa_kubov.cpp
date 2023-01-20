/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

bool calc(int n, int s, int d){
    if (s == n)
        return true;
    if (d==7)
        return false;
    for (int x = 1; s+x*x*x<=n; x += 1)
        if (calc(n, s + x*x*x, d+1)) {
            cout << x*x*x << " ";
            return true;
        }
    return false;
}

int main()
{
    int n;
    cin >> n;
    if (!calc(n, 0, 0))
        cout << 0;

    return 0;
}