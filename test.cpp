#include "header.h"
#include <ctime>
int main() {
    string s = "abcde";
    int index = 2;
    cout << s.substr(2 + 1, s.size() - index - 1);
}