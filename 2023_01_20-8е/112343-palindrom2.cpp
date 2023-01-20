#include <iostream>

using namespace std;

// abssba

bool is_pal(string s) {
    int left = 0, right = s.size() - 1;
    
    while (left < right) {
        if  (s.at(left) != s.at(right))
            return false;
        left += 1;
        right -= 1;
    }
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