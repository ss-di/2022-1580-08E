#include <iostream>
#include <vector>

using namespace std;

void vvod(vector<vector<int>> & mat){
    for (int i = 0; i < int(mat.size()); ++i)
        for (int j = 0; j < int(mat[i].size()); ++j)
            cin >> mat[i][j];
}

void vivod(const vector<int> &put){
    if (put.size() == 0)
        cout << 0;
    else
        for (int i = 0; i < int(put.size()); ++i)
            cout << put[i]+1 << " ";
    cout << endl;
}

bool no_ways(const vector<vector<int>> & mat){
    for (int i = 0; i < int(mat.size()); ++i)
        for (int j = 0; j < int(mat[i].size()); ++j)
            if (mat[i][j] != 0)
                return false;
    return true;
}

bool all_vert(const vector<bool> & p){
    for (int i = 0; i < int(p.size()); ++i)
        if (!p[i])
            return false;
    return true;
}

vector<int> dfs(vector<vector<int>> mat, vector<bool> p, int t, int f, vector<int> put){
    vector<int> cur_put;
    if (f != -1){
        mat[t][f] = 0;
        mat[f][t] = 0;
    }
    p[t] = true;
    put.push_back(t);
    if (t == 0 && no_ways(mat) && all_vert(p))
        return put;
    for (int i = 0; i < int(mat.size()); ++i)
        if (mat[t][i] != 0) {
            cur_put = dfs(mat, p, i, t, put);
            if (cur_put.size() != 0)
                return cur_put;
        }

    return cur_put;
}

bool no_odd_vertex(const vector<vector<int>> & mat){
    for (int i = 0; i < int(mat.size()); ++i) {
        int sum = 0;
        for (int j = 0; j < int(mat[i].size()); ++j)
            sum += mat[i][j];
        if (sum % 2 != 0)
            return false;
    }

    for (int i = 0; i < int(mat.size()); ++i) {
        int sum = 0;
        for (int j = 0; j < int(mat[i].size()); ++j)
            sum += mat[j][i];
        if (sum % 2 != 0)
            return false;
    }
    return true;
}

void solve(vector<vector<int>> mat, vector<int> &put){
    if (no_odd_vertex(mat)){
        vector<int> put2;
        vector<bool> p(mat.size());
        put = dfs(mat, p, 0, -1, put2);
    }
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
