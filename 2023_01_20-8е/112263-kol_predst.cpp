#include <iostream>

using namespace std;

long SearchFor(long Curnum, long N, int st) {
    if (Curnum == N) {
        return 1;
    }
    long f;
    f = 0;
    for (int i = st; i <= N - Curnum; i++) {
        f += SearchFor(Curnum + i, N, i);
    }
    return f;
}

int main()
{
    long N;
    cin >> N;
    cout << SearchFor(0, N, 1)-1;
}