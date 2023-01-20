#include <iostream>

using namespace std;

void perebor(string s, int k, string cur, int &cnt) {
    if (k == 0) {
        cout << cur << '\n';
        cnt += 1;
    } else {
        if (cur.size()==1)
            perebor(s, k-1, cur + s.at(0), cnt);
        else
            for (int i = 0; i < s.size(); i += 1)
                perebor(s, k-1, cur + s.at(i), cnt);
    }
}

int main()
{
    int n, cnt = 0;
    string s;
    cin >> s;
    cin >> n;
    perebor(s, n, "", cnt);
    cout << cnt;
}