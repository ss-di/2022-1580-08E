#include <iostream>

using namespace std;

// abssba

bool is_pal(string s) {
    for (int i = 0; i < s.size() / 2; i += 1)
        if  (s.at(i) != s.at(s.size()-1-i))
            return false;
    return true;
}

int main()
{
    string s;
    cin >> s;
    if (is_pal(s))
        cout << "YES";
    else
        cout << "NO";
}