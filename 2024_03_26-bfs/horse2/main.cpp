#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct hod {
    int x, y, cnt;
};

void solve (vector <vector<int>> &pole, int x, int y) {
    queue <struct hod> q;
    q.push({x, y, 0});
    while (!q.empty()) {
        struct hod h = q.front();
        q.pop();
        if (h.x >= 1 && h.x <= 8 &&
            h.y >= 1 && h.y <= 8 &&
            pole[h.x][h.y] == -1) {

            pole[h.x][h.y] = h.cnt;
            q.push({h.x+2, h.y+1, h.cnt+1});
            q.push({h.x+2, h.y-1, h.cnt+1});
            q.push({h.x-2, h.y+1, h.cnt+1});
            q.push({h.x-2, h.y-1, h.cnt+1});
            q.push({h.x+1, h.y+2, h.cnt+1});
            q.push({h.x+1, h.y-2, h.cnt+1});
            q.push({h.x-1, h.y+2, h.cnt+1});
            q.push({h.x-1, h.y-2, h.cnt+1});
        }
    }
}

int find_ans (const vector <vector<int>> &pole1,
               const vector <vector<int>> &pole2) {

    int ans = -1;
    for (int x = 1; x <= 8; ++x)
        for (int y = 1; y <= 8; ++y)
            if (pole1[x][y] == pole2[x][y] &&
                (ans == -1 || pole1[x][y] < ans) )
                    ans = pole1[x][y];
    return ans;
}

int main2()
{
    string h1, h2;
    cin >> h1 >> h2;

    int x1 = h1[0]-'a'+1, y1 = h1[1]-'0';
    int x2 = h2[0]-'a'+1, y2 = h2[1]-'0';

    vector <vector<int>> pole(9, vector<int>(9, -1));

    solve(pole, x1, y1);

    int ans = pole[x2][y2];

    if (ans %2 == 0)
        cout << ans / 2 << endl;
    else
        cout << -1 << endl;
    return 0;
}

int main()
{
    string h1, h2;
    cin >> h1 >> h2;

    int x1 = h1[0]-'a'+1, y1 = h1[1]-'0';
    int x2 = h2[0]-'a'+1, y2 = h2[1]-'0';

    vector <vector<int>> pole1(9, vector<int>(9, -1));
    vector <vector<int>> pole2(9, vector<int>(9, -1));

    solve(pole1, x1, y1);
    solve(pole2, x2, y2);

    cout << find_ans(pole1, pole2) << endl;

    return 0;
}
