#include "header.h"

class Solution {
private:
    bool isNum(string s) {
        int len = s.size();
        if (!len) return true;
        for (int i = 0; i < len; ++i) {
            if (s[i] >= '0' && s[i] <= '9') continue;
            else return false;
        }
        return true;
    }
    bool isDecimals(string s) {
        int len = s.size();
        if (!len) return false;
        char first = s[0];
        if (first == '+' || first == '-') {
            int pIndex = -1;
            for (int i = 1; i < len; ++i) {
                if (s[i] == '.') {
                    pIndex = i;
                    break;
                }
            }
            if (pIndex == -1) return false;
            else {
                if (isNum(s.substr(1, pIndex - 1)) && isNum(s.substr(pIndex + 1, s.size() - 1 - pIndex))) return true;
                else return false;
            }
        } else {
            int pIndex = -1;
            for (int i = 0; i < len; ++i) {
                if (s[i] == '.') {
                    pIndex = i;
                    break;
                }
            }
            if (pIndex == -1) return false;
            else {
                if (pIndex == 0 && len == 1) return false; 
                if (isNum(s.substr(0, pIndex)) && isNum(s.substr(pIndex + 1, s.size() - 1 - pIndex))) return true;
                else return false;
            }
        }
    }
    bool isInteger(string s) {
        int len = s.size();
        if (!len) return false;
        char first = s[0];
        if (first == '+' || first == '-') {
            if (len == 1) return false;
            for (int i = 1; i < len; ++i) {
                if (s[i] >= '0' && s[i] <= '9') continue;
                else return false;
            }
        } else {
            for (int i = 0; i < len; ++i) {
                if (s[i] >= '0' && s[i] <= '9') continue;
                else return false;
            }
        }
        return true;
    }
public:
    bool isNumber(string s) {
        int eIndex = -1;
        int len = s.size();
        for(int i = 0; i < len; ++i) {
            if (s[i] == 'e' || s[i] == 'E') {
                eIndex = i;
                break;
            }
        }
        if (eIndex == -1) {
            if (isDecimals(s) || isInteger(s)) return true;
            else return false;
        } else {
            if ((isDecimals(s.substr(0, eIndex)) || isInteger(s.substr(0, eIndex))) && isInteger(s.substr(eIndex + 1, len - 1 - eIndex))) return true;
            else return false;
        }
        return false;
    }
};