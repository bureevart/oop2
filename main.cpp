/*
Создайте класс Date, который будет содержать информацию о
дате (день, месяц, год).
С помощью механизма перегрузки операторов, определите
операцию разности двух дат (результат в виде количества дней
между датами), а также операцию увеличения даты на определен-
ное количество дней.
 */

#include <iostream>

using namespace std;

class Date {
    int dd;
    int mm;
    int yyyy;

public:
    int maxDaysInMonth(int mm, int yyyy) {
        int maxDays;
        if(mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12){
            maxDays = 31;
        } else if (mm == 4 || mm == 6 || mm == 9  || mm == 11) {
            maxDays = 30;
        } else if ((yyyy % 4 == 0 && yyyy % 100 != 0) || yyyy % 400 == 0) {
            maxDays = 29;
        } else {
            maxDays = 28;
        }

        return maxDays;
    }

    Date (int dd, int mm, int yyyy) {
        int maxDays;
        maxDays = maxDaysInMonth(mm, yyyy);

        if(dd > maxDays) {
            cout << "Превышено количество дней в текущем месяце!\n"
                    " Оставшееся количество дней будут конвертировано!" << endl;
            while (dd > maxDays) {
                dd -= maxDays;
                mm++;
                if(mm > 12){
                    yyyy++;
                    mm = 1;
                }
                maxDays = maxDaysInMonth(mm, yyyy);
            }
        }

        this->yyyy = yyyy;
        this->mm = mm;
        this->dd = dd;
    }

    int getDay() const {
        return dd;
    }

    int getMonth() const {
        return mm;
    }

    int getYear() const {
        return yyyy;
    }

    void setDay(int dd) {
        this->dd = dd;
    }

    void setMonth(int mm) {
        this->mm = mm;
    }

    void setYear(int yyyy) {
        this->yyyy = yyyy;
    }
};

int main() {
    setlocale(LC_ALL, "RUS");

    int dd;
    int mm;
    int yyyy;

    cin >> dd;
    cin >> mm;
    cin >> yyyy;

    Date date = Date(dd, mm, yyyy);

    cout << date.getDay() << ":" << date.getMonth()<< ":" << date.getYear() << endl;
    return 0;
}
