#ifndef clientdata_h
#define clientdata_h
#include <string>
#include <string.h>
#include <fstream>
#include <iostream>
#include "date.h"
using namespace std;

class ClientData
{   
    private:
        long customerid;  //sdt k co so 0 o dau
        char password[ 15 ];  //Mk
        char lastname[ 20 ];  //Ho
        char firstname[ 15 ];  //Ten
        int  gender;  //Nam: 0 Nu: 1
        int  AP; //Diem tich luy
        char BD[15]; //Ngay sinh
    public:
        int  read_file_clientdata(ClientData list1[]);
        void out_file_clientdata(ClientData list1[], int c);
        void find_client(ClientData list1[], int c);
        void delete_client(ClientData list1[]);
}; 

void createaccount()
{
	long a,g;
    string b,c,d;
    int e,f;
    long sdt, ngaysinh;
    char ln[20],fn[15], null[10];
    int gender,dem;
    int lc;
    do
    {
        cout << "\t VUI LONG DIEN THONG TIN DUOI DE TAO TAI KHOAN"<<endl;
        //nhap ten ho
        
        cout << "Nhap ho cua ban (toi da 20 ki tu): "; cin.getline(ln,21); 
        c=ln;
        //nhap ten 
        cout << "Nhap ten cua ban (toi da 15 ki tu): "; cin.getline(fn,16); 
        d=fn;
        
        //nhap sdt
        do
        {   
            dem=1;
            cout << "Nhap so dien thoai KH (10 so) : " ; cin >> sdt; 
            a=sdt;
            long n = sdt;
            if (n/100000000<10&&n/100000000>1) cout << "Hop le!" << endl;
            else 
            {
                cout << "Nhap khong hop le! Moi nhap lai" << endl;
                dem=0;
            }
        }
        while (dem==0);
        cin.getline(null,11);
        //nhap mat khau
        char pw[15];
	    int check;
        do
        {
            check =1;
            cout << "Nhap mat khau cua ban (toi da 15 ki tu, khong co khoang trong): "; cin.getline(pw,16);
            b=pw;
            for (int i=0; i<=14; i++) 
            {
                if (pw[i]==' ') 
                {
                    check = 0;
                }
            }
            if (check==0) cout << "Nhap khong hop le! Moi nhap lai" << endl;
            else cout << "Hop le!"<<endl;
        }
        while (check==0);
        
        //Chon gioi tinh cua ban
        // 0 : Nam, 1: Nu
        do
        {
            cout << "Gioi tinh (1- Nam, 2- Nu): "; cin >> gender;
            if (gender==2) gender = 1;
            else gender = 0;
        }
        while (gender>1||gender<0);
        e=gender;
        f=0;
        //Chon ngay sinh
        g=Day();
        //In thong tin
        cout << "----------------------------------------\n";
        cout << "\t THONG TIN TAI KHOAN"<<endl;
        cout << "Ho va ten: " << c << " " << d<<endl;
        cout << "Sdt      : 0" << a<<endl;
        cout << "Ngay sinh: " << g%100 <<"-"<< g/100%100<<"-" << g/10000<< endl;
        if (gender==0) cout << "Gioi tinh: Nam"<<endl;
        else cout <<"Gioi tinh: Nu"<<endl;
        cout << "Ten tk   : " << a << endl;
        cout << "Mat khau : " << b<<endl;
        cout << "----------------------------------------";
        do
        {
            cout << endl<<"De nghi kiem tra ki thong tin.\n*Neu co thay doi nhan phim (1)\n*Neu xac nhan tao tai khoan nhan phim (2)\nLua chon: ";
            cin >> lc;
            if (lc>2||lc<1) cout << "Ban nhap sai cu phap."<<endl;
        } 
        while (lc>2||lc<1);
        if (lc==2) cout << "Da thiet lap tai khoan.\n";
    } 
    while (lc==1);
    //Nhap du lieu vao file
    fstream dataFile;
    cout << "----------------------------------------"<<endl;
	dataFile.open("Customer-Data.txt", ios::out | ios :: app); // Mở file để ghi them vào cuoi file
	cout << "Du lieu duoc ghi vao he thong.\n"; 
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

 // end class ClientData
 #endif