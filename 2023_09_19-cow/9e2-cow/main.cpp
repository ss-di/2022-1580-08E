#include <iostream>
#include <vector>

using namespace std;

#define debug 0

void vvod(vector<int> &v){
    for (int i = 0; i < long(v.size()); i++)
        cin >> v[i];
}

void vivod(const vector<int> &v){
    for (int i = 0; i < long(v.size()); i++)
        cout << v[i] << " ";
    cout << endl;
}

bool check(const vector<int> &x, int k, int r){
    int cur_k = 1;
    int last_x = x[0];
    for (int i = 1; i < int(x.size()); i += 1)
        if (x[i] - last_x >= r){
            cur_k += 1;
            last_x = x[i];
        }
    return cur_k >= k;
}

int solve(const vector<int> &x, int k){
    int l = 1;
    int r = x.back() - x.front() + 1;

    while (r - l > 1){
        int m = (l + r) / 2;
        if (check(x, k, m))
            l = m;
        else
            r = m;
    }

    return l;
}


int main()
{
    int n, k;
    cin >> n >> k;


    vector<int> x(n);
    vvod(x);
    if (debug) vivod(x);

    cout << solve(x, k);

    return 0;
}
