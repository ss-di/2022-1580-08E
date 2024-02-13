#include <iostream>
#include <vector>

using namespace std;


void vvod(vector<vector<int>> &mat){
    for (int i = 0; i < int(mat.size()); ++i)
        for (int j = 0; j < int(mat[i].size()); ++j)
            cin >> mat[i][j];
}

bool no_ways(vector<vector<int>> mat){
    for (int i = 0; i < int(mat.size()); ++i)
        for (int j = 0; j < int(mat[i].size()); ++j)
             if (mat[i][j] != 0)
                return false;
    return true;
}

bool all_vertex(vector<bool> p){
    for (int i = 0; i < int(p.size()); ++i)
         if (!p[i])
            return false;
    return true;
}


vector<int> dfs(vector<vector<int>> mat, vector<bool> p, int t, int f, vector<int> put){
    vector<int> current_put;
    if (f != -1) {
        mat[f][t] = 0;
        mat[t][f] = 0;
    }
    put.push_back(t);
    p[t] = true;
    if (t == 0 && no_ways(mat) && all_vertex(p))
        return put;
    for (int i = 0; i < int(mat.size()); ++i)
        if (mat[t][i] != 0) {
            current_put = dfs(mat, p, i, t, put);
            if (current_put.size() != 0)
                return current_put;
        }
    return current_put;
}

bool no_odd_vertex(vector<vector<int>> mat){
    for (int i = 0; i < int(mat.size()); ++i) {
        int s = 0;
        for (int j = 0; j < int(mat[i].size()); ++j)
             s += mat[i][j];
        if (s % 2 != 0)
            return false;
    }

    for (int i = 0; i < int(mat.size()); ++i) {
        int s = 0;
        for (int j = 0; j < int(mat[i].size()); ++j)
             s += mat[j][i];
        if (s % 2 != 0)
            return false;
    }

    return true;
}

void solve(vector<vector<int>> mat, vector<int> &put){
    if (no_odd_vertex(mat)){
        vector<bool> p(mat.size(), false);
        put = dfs(mat, p, 0, -1, put);
    }
}

void vivod(vector<int> put){
    if (put.size() == 0)
        cout << 0;
    else
        for (int i = 0; i < int(put.size()); ++i)
            cout << put[i]+1 << " ";
}


int main()
{
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    vector<int> put;

    vvod(mat);
    solve(mat, put);
    vivod(put);

    return 0;
}
