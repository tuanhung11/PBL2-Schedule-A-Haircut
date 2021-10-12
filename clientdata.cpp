#include <string.h>
#include <fstream>
#include <iostream>
#include "clientdata.h"
#include "date.h"
using namespace std;


/*
void ClientData::takeinfo(long &a, string &b, string &c, string &d, int &e, int &f, long &g)
{
    long sdt, ngaysinh;
    char mk[15],ln[20],fn[15];
    int gender,check=1,dem;
    //nhap sdt
    do
    {   
        cout << "Nhap so dien thoai KH (10 so) : " ; cin >> sdt;
        dem=0;
        long n = sdt;
        while(n>=10)
        {
            n/=10; // hay n = n /10;
            dem++;
        }
    }
    while (dem==9);
    a=sdt;
    //nhap mat khau
    do
    {
        cout << "Nhap mat khau cua ban (toi da 15 ki tu khong co khoang cach): "; cin.getline(mk,16);
	    for (int i=0; i<=14; i++) 
        {
            if (mk[i]==' ') 
            {
                cout << "Mat khau khong hop le!";
                check = 0;
            }
        }
    }
    while (check==1);
    b=mk;
    //nhap ten ho
    cout << "Nhap ho cua ban: "; cin.getline(ln,21);
    c=ln;
    //nhap ten 
    cout << "Nhap ten cua ban: "; cin.getline(fn,16);
    d=fn;
    //Chon gioi tinh cua ban
    // 0 : Nam, 1: Nu
    do
    {
        cout << "Gioi tinh (1- Nam, 2- Nu): "; cin >> gender;
        if (gender==2) gender = 1;
        if (gender==1) gender = 0;
    }
    while (gender>1||gender<0);
    e=gender;
    f=0;
    //Chon ngay sinh
    g=Day();
}

 void ClientData::updatefile(long  a,string b, string c, string d,int e,int f, long  g)
{
	fstream dataFile; 
	cout << "Thuc hien mo File...\n"; 
	dataFile.open("output.txt", ios::out | ios :: app); // Mở file để ghi them vào cuoi file
	cout << "Du lieu duoc ghi xuong file.\n"; 
	dataFile << a << ","; 
	dataFile << b << ","; 
	dataFile << c << ","; 
    dataFile << d << ","; 
    dataFile << e << ",";
    dataFile << f << ",";
    dataFile << g << endl;
	dataFile.close(); // Đóng file 
	cout << "Xong.\n"; 
}
*/
//----------------------
// tao du lieu khach hang

int main()
{
    createaccount();
    system("pause");
    return 1;
}
