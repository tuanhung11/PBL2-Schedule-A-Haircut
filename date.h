/*BÀI 1. 
Viết chương trình cho phép thực hiện các thao tác trên kiểu struct Date gồm ngày, tháng, năm:
    v- Hàm toán tử nhập, xuất 01 ngày Date (>>, <<)
    v- Hàm xác định thứ trong tuần.
    v- Hàm toán tử ++, -- để tăng, giảm 01 ngày; 
    v- toán tử so sánh: <, >, ==, != giữa hai ngày.
*/
#ifndef date_h
#define date_h
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<string.h>
using namespace std;

struct Date
{
    int D,M,Y;
};

// Kiem tra nam nhuan
bool check_leap_year(int year)
{
    if (((year % 4)==0) && ((year % 100)!=0))
    {
    return true;
    }
    else if ((year % 400)==0)
    {
    return true;
    }
    else 
    {
    return false;
    }
}


// Kiem tra ngay hop le
bool check_date(int day, int month, int year)
{
    if ((month==2) && (day>0) && (day<29) && check_leap_year(year) != true)
    {
    return true;
    }
    if ((month==2) && (day>0) && (day<30) && check_leap_year(year) == true)
    {
    return true;
    }
    if (((month==1) || (month==3) || (month==5) || (month==7) || (month==8) || (month==10)|| (month==12) ) && ((day>0) && (day<32)))
    {
    return true;
    }
    if (((month==4) || (month==6) || (month==9) || (month==11)) && ((day>0) && (day<31)))
    {
    return true;
    }
    return false;
}
 
// Kiem tra thang hop le
bool check_month(int month)
{
    if ((month>0) && (month<13))
    {
    return true;
    }
    else
    {
    return false;
    }
}
 
// Kiem tra nam hop le
bool check_year(int year)
{
    if ((year>999) && (year < 10000))
    {
    return true;
    }
    else
    {
    return false;
    }
}


/*
int main()
{
    Date DMY1, DMY2;
    cout << "Input Day 1: " << endl;
    cin >> DMY1;
    cout << "Input Day 2: " << endl;
    cin >> DMY2;
    cout << "Day 1 (D-M-Y): " << DMY1 << " (" << getday(DMY1.D, DMY1.M, DMY1.Y) << ")" << endl;
    cout << "   Day 1+ (D-M-Y): "; ++DMY1;
    cout << "   Day 1- (D-M-Y): "; --DMY1;
    cout << "Day 2 (D-M-Y): " << DMY2 << " (" << getday(DMY2.D, DMY2.M, DMY2.Y) << ")" << endl;
    cout << "   Day 2+ (D-M-Y): "; ++DMY2;
    cout << "   Day 2- (D-M-Y): "; --DMY2;
    cout << "COMPARISION:" << endl;
    cout << "Day 1 (D-M-Y): " << DMY1 << " (" << getday(DMY1.D, DMY1.M, DMY1.Y) << ")" << endl;
    cout << "Day 2 (D-M-Y): " << DMY2 << " (" << getday(DMY2.D, DMY2.M, DMY2.Y) << ")" << endl;
    DMY1<DMY2;
    cout << endl;
    DMY1>DMY2;
    cout << endl;
    DMY1==DMY2;
    cout << endl;
    DMY1!=DMY2;
    return 0;    
}
*/

// cin >> DMY
void Nhap(Date &DMY)
{
    cout << "                                                            Nam sinh (YYYY): "; cin >> DMY.Y;
    if (check_year(DMY.Y))
    {}
    else
    {
    cout << "                                                        # Nhap sai!\n";
    exit(0);
    }
    
    cout << "                                                            Thang sinh (MM): "; cin >> DMY.M;
    if (check_month(DMY.M))
    {}
    else
    {
    cout << "                                                        # Nhap sai!";
    exit(0);
    }

    cout << "                                                            Ngay sinh (DD): "; cin >> DMY.D;
    if (check_date(DMY.D, DMY.M, DMY.Y))
    {}
    else
    {
        cout << "                                                    # Nhap sai!";
        exit(0);
    }
}

/*  
    Tim chính xác thu theo ngày-tháng-nam dã biêt
    http://en.wikipedia.org/wiki/Julian_day#Calculation
*/

long Day()
{
    Date DMY1;
    long ngaysinh;
    cout << "                                                        Nhap ngay sinh nhat cua ban: " << endl;
    Nhap(DMY1);
    cout << "                                                        Ngay sinh cua ban (D-M-Y): " << DMY1.D <<"-"<< DMY1.M<<"-" << DMY1.Y<< endl;
    //YYYY-MM-DD
    ngaysinh=(DMY1.Y*100+DMY1.M)*100+DMY1.D;
    return ngaysinh;
}
const char *getday(int day, int month, int year)
{
    int JMD;
    JMD = (day + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5) +
    (365 * (year + 4800 - ((14 - month) / 12))) +
     ((year + 4800 - ((14 - month) / 12)) / 4) - 
    ((year + 4800 - ((14 - month) / 12)) / 100) + 
    ((year + 4800 - ((14 - month) / 12)) / 400)  - 32045) % 7;
    //cout << JMD;
    const char *weekday[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    return weekday[JMD];
}

#endif