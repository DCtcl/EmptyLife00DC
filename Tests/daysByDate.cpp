#include <bits/stdc++.h>

using namespace std;


const vector<int> leapMonth = { 0, 31, 29, 31,30,31,30,31,31,30,31,30,31 };
const vector<int> normalMonth = { 0, 31, 28, 31,30,31,30,31,31,30,31,30,31 };

bool isLeapYear(int year) {
    /*
    @Brief: 是否是闰年
    */
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void getDaysInDaysPlus(const int& startDays, const int& endDays, int& days) {
    for (int iDay = startDays; iDay < endDays; iDay++) {
        days++;
    }

}

void getDaysInDaysMinus(const int& startDays, const int& endDays, int& days) {

    for (int iDay = endDays; iDay < startDays; iDay++) {
        days--;
    }
}

void getDaysInMonthPlus(const int& startMonth, const int& endMonth, const int& year, int& days) {
    /*
    @Brief:startMonth < endMonth
    */
    for (int i = startMonth; i < endMonth; i++) {
        if (isLeapYear(year)) {
            days += leapMonth[i];
        }
        else {
            days += normalMonth[i];
        }
    }

}

void getDaysInMonthMinus(const int& startMonth, const int& endMonth,const int& year, int& days) {
    /*
    @Brief:startMonth > endMonth
    */
    for (int i = endMonth; i < startMonth; i++) {
        if (isLeapYear(year)) {
            days -= leapMonth[i];
        }
        else {
            days -= normalMonth[i];
        }
    }
}


void getDaysInYearPlus(const int& startYears, const int& endYears, int& days) {

    for (int iYear = startYears; iYear < endYears; iYear++) {
        if (isLeapYear(iYear)) {
            days += 366;
        }
        else {
            days += 365;
        }
    }
}

int getDaysBetweenDates(const vector<int>& startDate, const vector<int>& endDate) {
    int days = 0;

    //判断输入是否合法，不合法返回-1
    if( endDate[0] < startDate[0] || (endDate[0] == startDate[0] && endDate[1] < startDate[1]) || (endDate[0] == startDate[0] && endDate[1] == startDate[1] && endDate[2] < startDate[2]))
        return -1;

    // 情况一： = < <
    if (startDate[0] == endDate[0] && startDate[1] <= endDate[1] && startDate[2] <= endDate[2]) {
        getDaysInMonthPlus(startDate[1], endDate[1], endDate[0], days);
        getDaysInDaysPlus(startDate[2], endDate[2], days);
        return days;
    }

    //情况二：= < >
    if (startDate[0] == endDate[0] && startDate[1] < endDate[1] && startDate[2] > endDate[2]) {
        getDaysInMonthPlus(startDate[1], endDate[1],endDate[0], days);
        getDaysInDaysMinus(startDate[2], endDate[2], days);
        return days;

    }

    //情况三：< < <
    if (startDate[0] < endDate[0] && startDate[1] <= endDate[1] && startDate[2] <= endDate[2]) {
        
        getDaysInYearPlus(startDate[0], endDate[0], days);

        if (isLeapYear(endDate[0])&& startDate[1] > 2) {
            days++;
        }
        if (isLeapYear(startDate[0]) && startDate[1] > 2) {
            days--;
        }
        
        getDaysInMonthPlus(startDate[1], endDate[1], endDate[0], days);
        getDaysInDaysPlus(startDate[2], endDate[2], days);
        return days;
    }
    //情况四：< < >
    if (startDate[0] < endDate[0] && startDate[1] <= endDate[1] && startDate[2] > endDate[2]) {

        getDaysInYearPlus(startDate[0], endDate[0], days);
        if (isLeapYear(endDate[0]) && startDate[1] > 2) {
            days++;
        }
        if (isLeapYear(startDate[0]) && startDate[1] > 2) {
            days--;
        }

        getDaysInMonthPlus(startDate[1], endDate[1], endDate[0], days);
        getDaysInDaysMinus(startDate[2], endDate[2], days);
        return days;
    }
    //情况五: < > <
    if (startDate[0] < endDate[0] && startDate[1] > endDate[1] && startDate[2] <= endDate[2]) {
        getDaysInYearPlus(startDate[0], endDate[0], days);
        if (isLeapYear(endDate[0]) && startDate[1] > 2) {
            days++;
        }
        if (isLeapYear(startDate[0]) && startDate[1] > 2) {
            days--;
        }
        getDaysInMonthMinus(startDate[1], endDate[1], endDate[0], days);
        getDaysInDaysPlus(startDate[2], endDate[2], days);
        return days;
    }
    //情况五: < > >
    if (startDate[0] < endDate[0] && startDate[1] > endDate[1] && startDate[2] > endDate[2]) {
        getDaysInYearPlus(startDate[0], endDate[0], days);
        if (isLeapYear(endDate[0]) && startDate[1] > 2) {
            days++;
        }
        if (isLeapYear(startDate[0]) && startDate[1] > 2) {
            days--;
        }
        getDaysInMonthMinus(startDate[1], endDate[1], endDate[0], days);
        getDaysInDaysMinus(startDate[2], endDate[2], days);
        return days;
    }

    return days;
}




int main() {
	vector<int> data1(3, -1);  //终止日期
	vector<int> data2(3,-1);  // 起始日期
	//cin >> data1[0] >> data1[1] >> data1[2];
	//cin >> data2[0] >> data2[1] >> data2[2];

    data1 = { 2024, 3, 1 };
    data2 = { 2020, 2, 1 };
	
    int result = getDaysBetweenDates(data2, data1);

    cout << result;

	return 0;

}
