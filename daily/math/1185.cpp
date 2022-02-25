#include "header.h"

// 一周中的第几天 
//1970年12月12日为周四
class Solution {
private:
    int dayNumber(int day, int month, int year) {
        int sum = 0;
        vector<int> months{31,28,31,30,31,30,31,31,30,31,30,31};
        for (int i = 1971; i < year; ++i) {
            if ((i % 4 == 0 && i % 100 != 0)|| i % 400 == 0) {
                sum += 366;
            } else {
                sum += 365;
            }
        }
        for (int i = 0; i < month - 1; ++i) {
            sum += months[i];
        } 
        if (month > 2)
            if ((year % 4 == 0 && year % 100 != 0)|| year % 400 == 0) sum += 1;
        sum += day;
        return sum;
    }
public:
    string dayOfTheWeek(int day, int month, int year) {
        int inc = dayNumber(day, month, year);
        int mod = inc % 7;
        vector<string> weekday = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        return weekday[(mod + 4) % 7];
    }
};