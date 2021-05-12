#include <iostream>
#include <string>
using namespace std;
//漏了情况，看答案了
class Solution {
private:
    bool checkPalindrome(string s, int low, int high) {
        while (s[low] == s[high] && low < high) {
            low++;
            high--;
        }
        if (low >= high) {
            return true;
        } else {
            return false;
        }
    }
public:
    bool validPalindrome(string s) {
        int low = 0, high = s.size() - 1;
        while (low < high) {
            char c1 = s[low], c2 = s[high];
            if (c1 == c2) {
                low++;
                high--;
            } else {
                return checkPalindrome(s, low + 1, high) || checkPalindrome(s, low, high - 1);
            }
        }
        return true;
    }
};

int main (int argc, char* argv[]) {
    Solution test;
    string s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
    bool ans = test.validPalindrome(s);
    cout << ans << endl;
    return 0;
}