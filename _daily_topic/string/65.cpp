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
                if (pIndex == 1 && len == 2) return false; 
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

//自动机

class Solution {
public:
    enum State {
        STATE_INITIAL,
        STATE_INT_SIGN,
        STATE_INTEGER,
        STATE_POINT,
        STATE_POINT_WITHOUT_INT,
        STATE_FRACTION,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_NUMBER,
        STATE_END
    };

    enum CharType {
        CHAR_NUMBER,
        CHAR_EXP,
        CHAR_POINT,
        CHAR_SIGN,
        CHAR_ILLEGAL
    };

    CharType toCharType(char ch) {
        if (ch >= '0' && ch <= '9') {
            return CHAR_NUMBER;
        } else if (ch == 'e' || ch == 'E') {
            return CHAR_EXP;
        } else if (ch == '.') {
            return CHAR_POINT;
        } else if (ch == '+' || ch == '-') {
            return CHAR_SIGN;
        } else {
            return CHAR_ILLEGAL;
        }
    }

    bool isNumber(string s) {
        unordered_map<State, unordered_map<CharType, State>> transfer{
            {
                STATE_INITIAL, {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_POINT, STATE_POINT_WITHOUT_INT},
                    {CHAR_SIGN, STATE_INT_SIGN}
                }
            }, {
                STATE_INT_SIGN, {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_POINT, STATE_POINT_WITHOUT_INT}
                }
            }, {
                STATE_INTEGER, {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_EXP, STATE_EXP},
                    {CHAR_POINT, STATE_POINT}
                }
            }, {
                STATE_POINT, {
                    {CHAR_NUMBER, STATE_FRACTION},
                    {CHAR_EXP, STATE_EXP}
                }
            }, {
                STATE_POINT_WITHOUT_INT, {
                    {CHAR_NUMBER, STATE_FRACTION}
                }
            }, {
                STATE_FRACTION,
                {
                    {CHAR_NUMBER, STATE_FRACTION},
                    {CHAR_EXP, STATE_EXP}
                }
            }, {
                STATE_EXP,
                {
                    {CHAR_NUMBER, STATE_EXP_NUMBER},
                    {CHAR_SIGN, STATE_EXP_SIGN}
                }
            }, {
                STATE_EXP_SIGN, {
                    {CHAR_NUMBER, STATE_EXP_NUMBER}
                }
            }, {
                STATE_EXP_NUMBER, {
                    {CHAR_NUMBER, STATE_EXP_NUMBER}
                }
            }
        };

        int len = s.length();
        State st = STATE_INITIAL;

        for (int i = 0; i < len; i++) {
            CharType typ = toCharType(s[i]);
            if (transfer[st].find(typ) == transfer[st].end()) {
                return false;
            } else {
                st = transfer[st][typ];
            }
        }
        return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
    }
};
