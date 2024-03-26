#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct hod {
    int x, y, cnt=-1, xf, yf;
};

void solve(vector<vector<struct hod>> &pole,
           int n,
           int x1,
           int y1,
           int x2,
           int y2) {



    queue <struct hod> q;
    q.push({x1, y1, 0, -1, -1});

    while (!q.empty()) {
        struct hod h = q.front();
        q.pop();
        if (h.x >= 1 && h.x <= n &&
            h.y >= 1 && h.y <= n &&
            pole[h.x][h.y].cnt == -1) {
            pole[h.x][h.y] = h;
            q.push({h.x+1, h.y+2, h.cnt+1, h.x, h.y});
            q.push({h.x+1, h.y-2, h.cnt+1, h.x, h.y});
            q.push({h.x-1, h.y+2, h.cnt+1, h.x, h.y});
            q.push({h.x-1, h.y-2, h.cnt+1, h.x, h.y});
            q.push({h.x+2, h.y+1, h.cnt+1, h.x, h.y});
            q.push({h.x+2, h.y-1, h.cnt+1, h.x, h.y});
            q.push({h.x-2, h.y+1, h.cnt+1, h.x, h.y});
            q.push({h.x-2, h.y-1, h.cnt+1, h.x, h.y});
        }
    }
}

vector<struct hod> get_way(vector<vector<struct hod>> &pole, int n, int x, int y) {
    vector<struct hod> way;
    way.push_back(pole[x][y]);
    while (way.back().cnt != 0) {
        way.push_back(pole[way.back().xf][way.back().yf]);
    }
    return way;
}

void print_way(vector<struct hod> way) {
    for (int i = way.size()-1; i >= 0; --i)
        cout << way[i].x << " " << way[i].y << endl;
}

int main()
{
    int n;
    cin >> n;
    int x1, y1;
    cin >> x1 >> y1;
    int x2, y2;
    cin >> x2 >> y2;

    vector<vector<struct hod>> pole (n+1, vector<struct hod>(n+1));

    solve(pole, n, x1, y1, x2, y2);

    vector<struct hod> way = get_way(pole, n, x2, y2);

    cout << pole[x2][y2].cnt << endl;

    print_way(way);

    return 0;
}
