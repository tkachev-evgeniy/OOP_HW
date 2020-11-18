#include <iostream>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date(int y, int m, int d) : day(d), month(m), year(y) {}
    int getDay() const { return day;}
    int getMonth() const {return month;}
    int getYear() const {return year;}
    double getYear_d() const { return year+month/12.0+day/365.25; }
    //ostream& operator << (ostream& out, const Date d);
};




ostream& operator << (ostream& out, const Date d) {
    out << d.getYear()<<"."<<d.getMonth()<<"."<<d.getDay()<<"";
    return out;
}

const unique_ptr<Date>& later(const unique_ptr<Date> &date1, const unique_ptr<Date> &date2) {
    if ( date2->getYear_d() >= date1->getYear_d() ) return date2;
    else return date1;
}

//написал сначала для класса Дата, но понял что можно <Date> заменить на шаблонную <T> и все должно работать с любым типом.
template <typename T>
void exchange(unique_ptr<T> &ud1, unique_ptr<T> &ud2) {
    T* date1 = ud1.release();
    T* date2 = ud2.release();
    ud1.reset(date2);
    ud2.reset(date1);

}

int main()
{
    {
    auto today = make_unique<Date>(2020,11,16);
    cout << today->getDay() << today->getMonth() << today->getYear() << endl;
    cout << *today << endl;




    unique_ptr<Date> date(move(today));

    if (today) cout << "today is not null" << endl;
    else cout << "today is null" << endl;

    if (date) cout << "date is not null" << endl;
    else cout <<"date is null";


    }

    {
    auto today = make_unique<Date>(2020,11,16);
    auto tomorrow = make_unique<Date>(2020,11,17);

    //проверим как работает функция.
    cout << *later(today,tomorrow) << endl;

    //проверим не уничтожились ли объекты, обратимся к ним еще раз
    cout << *today << "  " << *tomorrow << endl;

    // Проверим вторую функцию.
    exchange(today, tomorrow);
    cout << *today << "  " << *tomorrow << endl;

    }




}
