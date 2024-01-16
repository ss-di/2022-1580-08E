
void dfs(const vector<vector<int>> &mat, vector<int> &p, int t, int f) {
    p[t] = f;
    for (int i = 0; i < int(mat[t].size()); i+= 1)
        if (mat[t][i] == 1 && p[i] == -2)
            dfs(mat, p, i, t);
}

int main()
{

    dfs(mat, p, 0, -1);

    return 0;
}