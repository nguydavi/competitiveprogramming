/*
ID: david241
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int DAYS_IN_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31 ,30, 31};
int START_YEAR = 1900;

bool isLeap(int year) {
    if(year % 4 == 0) {
       if(year % 100 == 0) {
          if(year % 400 == 0) {
            return true;
          } else {
              return false;
          }
       }
       return true;
    }
    return false;
    // OR
    // return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int main() {
    ofstream fout("friday.out");
    ifstream fin ("friday.in");

    int N;
    fin >> N;

    int endYear = START_YEAR + N;
    // in order : Sunday, Monday, .., Saturday
    int days[7] = {0};
    
    int currentYear = START_YEAR;
    int currentMonth = 0;
    int numberDays = 0;
    while(currentYear < endYear) {
        ++days[(numberDays + 13) % 7];

        if(isLeap(currentYear) && currentMonth == 1) {
            numberDays += DAYS_IN_MONTH[currentMonth] + 1;
        } else {
            numberDays += DAYS_IN_MONTH[currentMonth];
        }

        ++currentMonth;
        if(currentMonth == 12) {
            currentMonth = 0;
            ++currentYear;
        }

    }
    
    fout << days[6] << " " << days[0];
    for(int i = 1; i < 6; ++i) {
        fout << " " << days[i];
    } 
    fout << endl;
    return 0;
}
