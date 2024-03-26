#include <iostream>
#include <vector>
#include <queue>

using namespace std;


void vvod(vector<vector<int>> &mat){
    for (int i = 0; i < int(mat.size()); ++i)
        for (int j = 0; j < int(mat[i].size()); ++j)
            cin >> mat[i][j];
}

void vivod(vector<int> put){
    if (put.size() == 1)
        cout << -1;
    else if (put.size() == 0)
        cout << 0;
    else if (put.size() > 1) {
        cout << put.size() - 1 << endl;
        for (int i = 0; i < int(put.size()); ++i)
            cout << put[i]+1 << " ";
    }
}

void solve(const vector<vector<int>> &mat, int f, int t, vector<int> &put){
    if (f == t)
        return;
    vector<int> mark(mat.size(), -1);
    queue<int> q;
    q.push(f);
    mark[f] = -2;
    put.push_back(f);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < int(mat.size()); ++i) {
            if ((mat[v][i] == 1) && (mark[i] == -1)) {
                mark[i] = v;
                q.push(i);
            }
        }
    }
    if (mark[t] != -1) {
        int v = t;
        while (v != f) {
            put.insert(put.begin()+1, v);
            // cout << "* " << v+1 << endl;
            v = mark[v];
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    vector<int> put;

    vvod(mat);
    int f, t;
    cin >> f >> t;
    --f; --t;
    solve(mat, f, t, put);
    vivod(put);

    return 0;
}
