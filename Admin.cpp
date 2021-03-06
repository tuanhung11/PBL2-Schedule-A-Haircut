#include "Admin.h"
#include "clientdata.h"

//*HAM HUY ADMIN*
admin::~admin(){
    adphone[15] = 0;
    adpassword[15] = 0;
}

//*DANG NHAP*
void admin::singin(){
    int temp = 0;
    char phone[15], pass[15], ch;
    do{
        system("CLS");
        cout << "\n\t\t============================================================ ADMIN ============================================================\n\n\n\n\n";
        
        cout << "\n\t\t                                                 -----------SIGN IN-----------\t\t\t\n\n";
        if (temp > 0){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),124);
            cout << "\n\t\t\t                             *SO DIEN THOAI HOAC MAT KHAU KHONG DUNG, MOI NHAP LAI!*\n\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),120);   
        }
        cout << "\t\t\t                                         Nhap so dien thoai: ";
        cin >> phone;
        cout << "\t\t\t                                         Nhap mat khau     : ";
        for (int i = 0; i < 12; i++){
            ch = getch();
            pass[i] = ch;
            if (ch == 13){
                pass[i] = '\0';
                break;
            }
            else{
                ch = '*';
                cout << ch;
            }
        }
        temp++;
      }
    while (strcmp(phone, adphone) != 0 || strcmp(pass, adpassword) != 0);
    cout <<     "\n\n\t\t\t                                         -------LOGIN  SUCCEST!-------\n\n";
    system("\tpause");
}

//*HAM BO TRO DOC FILE*
void split(char s[], char temp[][250]){
    int i, j = 0, k = 0;
        for(i = 0; s[i] != '\0'; i++){
            if(s[i] != ','){           
                temp[k][j] = s[i];
                    j = j + 1;
                        }
                        else{
                            temp[k][j] = '\0';
                                k = k + 1;
                                    j = 0;
                                        }
                                            }
                                                temp[k][j] = '\0';
}

//*HAM HUY STAFF*
staff::~staff(){
    staffid[8] = 0;
    firstname[15] = 0;
    lastname[20] = 0;
    staffphone = 0;
    gender = 0;
    BD[15] = 0;
    pay = 0;
}

//*HAM DOC FILE NHAN VIEN*
int  staff::read_file_staff(staff list0[]){
    int n = 0;
    FILE *p;
    p = fopen("staff.txt","r");
    while(feof(p) == false){
    char s[230], temp[200][250], temp3[100];
        int temp2;
            fgets(s,230,p);
                split(s,temp);
                    strcpy(list0[n].staffid,temp[0]);
                        strcpy(list0[n].firstname,temp[1]);
                            strcpy(list0[n].lastname,temp[2]);
                                list0[n].staffphone = atoi(temp[3]);
                                    list0[n].gender = atoi(temp[4]);
                                        list0[n].pay = atoi(temp[5]);
                                            for(int i = 0, k = 0; i < 8; i++, k++){
                                                if(k == 4 || k == 7){
                                                    i--;
                                                    list0[n].BD[k] = '-';   
                                                    continue;
                                                }
                                                list0[n].BD[k] = temp[6][i]; 
        }
        n++;
    }
    fclose(p);
    return n;
}

//*HAM XUAT FILE NHAN VIEN*
void staff::out_file_staff(staff list0[], int s){
    cout << "\n\t                                              --------------DANH SACH NHAN VIEN--------------\n\n";
 
    cout << "                                            _______________________________________________________________________\n";
    cout << "                                            |  ID  |   Ho   |     Ten     |    SDT    | Gioi |Luong($)| Ngay sinh |\n";
    cout << "                                            |``````|````````|`````````````|```````````|``````|````````|```````````|\n";
    for(int i = 0; i < s; i++){
        cout << "                                            |" << setw(6)  << left  << list0[i].staffid;
        cout << "|" << setw(8)  << left  << list0[i].firstname;
        cout << "|" << setw(13) << left  << list0[i].lastname;
        cout << "|" << setw(11) << left  << list0[i].staffphone;
        if (list0[i].gender == 0)
        cout << "|" << setw(6)  << left  << "Nam";
        else
        cout << "|" << setw(6)  << left  << "Nu";
        cout << "|" << setw(8)  << left  << list0[i].pay;
        cout << "|" << setw(11) << right << list0[i].BD;
        cout << "|" << endl;
    }   
    cout << "                                            ```````````````````````````````````````````````````````````````````````\n";
}

//*HAM THEM NHAN VIEN*
void staff::add_staff(staff list0[], int s){
    int g,lc;
    do{
        cout <<     "\n\t                                            --------------TAO THONG TIN NHAN VIEN--------------\n\n";
        cin.ignore();
        cout <<     "                                                        Nhap ID (Vi du: S456): ";
        cin.getline(staffid,8);
        cout <<     "                                                        Nhap Ho: ";                                   
        cin.getline(firstname,15);
        cout <<     "                                                        Nhap Ten: ";                    
        cin.getline(lastname,20);
        int dem; 
        cout <<     "                                                        Nhap So dien thoai (10 so): ";  
        cin >> staffphone;
        do{
            cout << "                                                        Gioi tinh (1- Nam, 2- Nu): ";   
            cin >> gender;
        }
        while (gender > 2 || gender < 1);
        cout <<     "                                                        Nhap luong thang ($): ";        
        cin >> pay;
        g = Day();
        system("CLS");
        cout << "\n\t                                                --------------THONG TIN NHAN VIEN--------------\n" << endl;

        cout <<     "                                                        ID         : "  << staffid << endl;
        cout <<     "                                                        Ho va ten  : "  << firstname << " " << lastname << endl;
        cout <<     "                                                        Sdt        : 0" << staffphone << endl;
        if (gender == 1) 
        cout <<     "                                                        Gioi tinh  : Nam" << endl;
        else 
        cout <<     "                                                        Gioi tinh  : Nu"  << endl;
        cout <<     "                                                        Ngay sinh  : "  << g / 10000 << "-" << g / 100 % 100<< "-" << g % 100 << endl; //g % 100 << "-" << g / 100 % 100<< "-" << g / 10000
        cout <<     "                                                        Luong thang: " << pay << "$" << endl;

        do{
            cout <<  "\n\n                                               DE NGHI KIEM TRA KI THONG TIN!" << endl;

            cout <<    "\n                                               *Neu co thay doi nhan phim (1)";
            cout <<    "\n                                               *Neu xac nhan tao tai khoan nhan phim (2)";
            cout <<    "\n                                               ----------------------------------------";
            cout <<    "\n                                               *Chu y: Neu chon (1) se tien hanh nhap lai thong tin tu dau!*\n";
            cout <<    "\n                                               Chon: ";
            cin >> lc;
            if (lc > 2 || lc < 1) 
            cout <<    "\n                                                         *YEU CAU KHONG HOP LE*";
        } 
        while (lc > 2 || lc < 1);
        if (lc == 2) 
            cout <<    "\n                                                      DA THIET LAP XONG NHAN VIEN!\n";
    }  
    while (lc == 1);
    fstream f;
	f.open("staff.txt", ios::out | ios :: app); 

	            f << staffid    << ","; 
	        f << firstname  << ","; 
	    f << lastname   << ","; 
    f << staffphone << ","; 
        f << gender     << ",";
            f << pay        << ",";
                f << g          << endl; 

	f.close();  
    s++;
}

//*HAM XOA NHAN VIEN*
void staff::delete_staff(staff list0[]){
    int s = read_file_staff(list0) - 1;
    out_file_staff(list0,s);
        string line, name;
            cout << "\n\n\t                                              Nhap Ma nhan vien ban muon xoa: ";
                cin >> name;
                    ifstream myfile;
                myfile.open("staff.txt");
            ofstream temp;
        temp.open("temp.txt");
    while (getline(myfile, line)){
        if (line.substr(0, name.size()) != name){
            temp << line << endl;
               }
                   }
                        cout << "\t                                    *Nhan vien voi ma " << name << " da bi XOA neu ton tai!*" << endl;
                    myfile.close();
                temp.close();
            remove("staff.txt");
        rename("temp.txt", "staff.txt");
    s--;
}

//*HAM DOC FILE CLIENT-DATA*
int  ClientData::read_file_clientdata(ClientData list1[]){
    int n = 0;
    FILE *p;
    p = fopen("Customer-Data.txt","r");
    while(feof(p) == false){
        char s[230], temp[200][250], temp3[100];
        int temp2;
            fgets(s,230,p);
                split(s,temp);
                    list1[n].customerid = atoi(temp[0]);
                        strcpy(list1[n].password,temp[1]);
                            strcpy(list1[n].firstname,temp[2]);
                                strcpy(list1[n].lastname,temp[3]);
                                    list1[n].gender = atoi(temp[4]);
                                        list1[n].AP = atoi(temp[5]);
                                            for(int i = 0, k = 0; i < 8; i++, k++){
                                                if(k == 4 || k == 7){
                                                    i--;
                                                        list1[n].BD[k] = '-';   
                                                            continue;
                                                        } 
                                                    list1[n].BD[k] = temp[6][i]; 
                                                }
                                            n++;
    }
    fclose(p);
    return n;
}

//*HAM XUAT FILE CLIENT-DATA*
void ClientData::out_file_clientdata(ClientData list1[], int c){

    cout << "\n\t                                              --------------DANH SACH KHACH HANG--------------\n\n" << endl;
    cout << "                                         ____________________________________________________________________________\n";
    cout << "                                         |STT|    ID    |  Mat khau  |   Ho   |     Ten     | Gioi | AP | Ngay sinh |\n";
    cout << "                                         |```|``````````|````````````|````````|`````````````|``````|````|```````````|\n";
    for(int i = 0; i < c; i++){
        cout << "                                         |" << setw(3)  << left  << i + 1;
        cout << "|" << setw(10) << left  << list1[i].customerid;
        cout << "|" << setw(12) << left  << list1[i].password;
        cout << "|" << setw(8)  << left  << list1[i].firstname;
        cout << "|" << setw(13) << left  << list1[i].lastname;
        if (list1[i].gender == 0)
            cout << "|" << setw(6)  << left  << "Nam";
        else
            cout << "|" << setw(6)  << left  << "Nu";
        cout << "|" << setw(4)  << left  << list1[i].AP;
        cout << "|" << setw(11) << right << list1[i].BD;
        cout << "|" << endl;
    }   
    cout << "                                         ````````````````````````````````````````````````````````````````````````````\n";
}

//*HAM TIM KHACH HANG*
void ClientData::find_client(ClientData list1[], int c){
    cout << "\t                                          --------------------TIM KIEM KHACH HANG--------------------n" << endl;
    int id, check = 0;
    cout << "\n\t                                          Nhap id cua khach hang muon tim kiem: ";
    cin >> id;
    for(int i = 0; i < c; i++){
        if(list1[i].customerid == id){
            system("CLS");
            cout <<   "\n\t                                                            Khach hang can tim:\n";
            cout <<   "\n\t                                                 ----------------------------------------\n";
            check = 1;
            cout <<     "\t                                                         ID       : " << list1[i].customerid << endl;
            cout <<     "\t                                                         Mat khau : " << list1[i].password   << endl;
            cout <<     "\t                                                         Ho va Ten: " << list1[i].firstname  << " " << list1[i].lastname << endl;
            cout <<     "\t                                                         Gioi tinh: ";
            if (list1[i].gender == 0)
                cout << "Nam\n";
            else
                cout << "Nu\n";
            cout <<     "\t                                                         Diem AP  : " << list1[i].AP         << endl;
            cout <<     "\t                                                         Ngay sinh: " << list1[i].BD         << endl;
            cout <<   "\n\t                                                 ----------------------------------------\n";
        }
    }
    if (check == 0){
        system("CLS");
            cout << "\n\t                                                         *KHACH HANG KHONG TON TAI!*" << endl;
    }
}

//*HAM XOA KHACH HANG*
void ClientData::delete_client(ClientData list1[]){
    int c = read_file_clientdata(list1) - 1;
    out_file_clientdata(list1,c);
        string line, name;
            cout <<  "\n\n\t                                              Nhap Ma khach hang ban muon xoa: ";
                cin >> name;
                    ifstream myfile;
                myfile.open("Customer-Data.txt");
            ofstream temp;
        temp.open("temp4.txt");
    while (getline(myfile, line)){
        if (line.substr(0, name.size()) != name){
            temp << line << endl;
                }   
                    }
                        cout << "\n\t                                          *Khach hang voi ma " << name << " da bi XOA neu ton tai!*" << endl;
                    myfile.close();
                temp.close();
            remove("Customer-Data.txt");
        rename("temp4.txt", "Customer-Data.txt");
    c--;
}

//*HAM HUY APPOINTMENT*
appointment::~appointment(){
    maDon = 0;
    ngayDatDon[100] = 0;
    ngayDenCatToc[100] = 0;
    status[10] = 0;
    maRenderService = 0;
    sdt = 0;
}

//*HAM DOC FILE APPOINTMENT*
int  appointment::read_file_appointment(appointment list2[]){
    int n = 0;
    FILE *p;
    p = fopen("Appointment-Origin.txt","r");
    while(feof(p) == false){
    char s[230], temp[10][250];
    fgets(s,230,p);
    split(s,temp);
           list2[n].maDon = atoi(   temp[0]);
    strcpy(list2[n].ngayDatDon,     temp[1]);
    strcpy(list2[n].ngayDenCatToc,  temp[2]);
    strcpy(list2[n].status,         temp[3]);
    list2[n].maRenderService = atoi(temp[4]);
                list2[n].sdt = atoi(temp[5]);
                n++;
    }
    fclose(p); 
    return n;
}

//*HAM LOC FILE YES/NO APPOINTMENT*
void appointment::yesorno(appointment list2[], int m, string s1){
    int temp = 0;
    string s[100];
    cout << "                                         _____________________________________________________________________________\n";
    cout << "                                         | Ma |    Ngay dat don    |  Ngay den cat toc  |Status|  Ma RVS  |    SDT   |\n";
    cout << "                                         |````|````````````````````|````````````````````|``````|``````````|``````````|\n";

    for (int i = 0; i < m; i++){
        s[i] = string(list2[i].status);
        if  (s[i] == s1){   
            temp = 1;
            cout << "                                         |" << setw(4)  << right << list2[i].maDon;
            cout << "|" << setw(20) << left  << list2[i].ngayDatDon;
            cout << "|" << setw(20) << left  << list2[i].ngayDenCatToc;
            cout << "|" << setw(6)  << left  << list2[i].status;
            cout << "|" << setw(10) << left  << list2[i].maRenderService;
            cout << "|" << setw(10) << right << list2[i].sdt;
            cout << "|" << endl;
        }
    }
    if (temp == 0)
        cout << "                                         |NULL|        NULL        |        NULL        | NULL |   NULL   |   NULL   |\n";
    cout << "                                         `````````````````````````````````````````````````````````````````````````````\n";

}

//*HAM XUAT FILE APPOINTMENT CHUA XAC NHAN*
void appointment::out_file_appointment(appointment list2[], int m){
    cout << "\n\t                                           ----------------DANH SACH DON DAT HANG----------------\n\n";

    cout << "                                         _____________________________________________________________________________\n";
    cout << "                                         | Ma |    Ngay dat don    |  Ngay den cat toc  |Status|  Ma RVS  |    SDT   |\n";
    cout << "                                         |````|````````````````````|````````````````````|``````|``````````|``````````|\n";

    for (int i = 0; i < m; i++){
            cout << "                                         |" << setw(4)  << right << list2[i].maDon;
            cout << "|" << setw(20) << left  << list2[i].ngayDatDon;
            cout << "|" << setw(20) << left  << list2[i].ngayDenCatToc;
            cout << "|" << setw(6)  << left  << list2[i].status;
            cout << "|" << setw(10) << left  << list2[i].maRenderService;
            cout << "|" << setw(10) << right << list2[i].sdt;
            cout << "|" << endl;
    }
    cout << "                                         `````````````````````````````````````````````````````````````````````````````\n";
}

//*HAM XUAT FILE APPOINTMENT DA XAC NHAN*
void appointment::out_file_appointmentYES(){
    cout << "\n\t                                             ------------------LICH LAM VIEC------------------\n\n";

    int size2;
        appointment list2[200];
            size2 = read_file_appointment(list2) - 1;
                yesorno(list2, size2, "YES");
}

//*HAM XOA CUOC HEN*
void appointment::deleteappointment(appointment list2[]){
    int size2 = read_file_appointment(list2) - 1;
    out_file_appointment(list2,size2);
    string line, name;
    cout << "\n\n\t                                               Nhap Ma don hang ban muon xoa: ";
    cin >> name;
    ifstream myfile;
    myfile.open("Appointment-Origin.txt");
    ofstream temp;
    temp.open("temp2.txt");
    while (getline(myfile, line)){
       if (line.substr(0, name.size()) != name){
            temp << line << endl;
        }
    }
    cout << "\t                                           *Don hang voi ma " << name << " da bi XOA neu ton tai!*" << endl;
    myfile.close();
    temp.close();
    remove("Appointment-Origin.txt");
    rename("temp2.txt", "Appointment-Origin.txt");
    size2--;
}

//*HAM LAY MA DON HANG*
int  appointment::layi(appointment list2[],int m,int h){
    for (int i = 0; i < m; i++){
        if (h == list2[i].maDon)        
            return i;  
    }  
    return 0;
}

//*HAM CHUYEN STATUS NO -> YES*
void appointment::nosangyes(appointment list2[], int m){   
    ifstream myfile1;
        myfile1.open("Appointment-Origin.txt");
            ofstream temp1;
                temp1.open("temp3.txt");
                    string s1 = "YES", s;
                        int h;
                            out_file_appointment(list2,m);
    cout << "\n\n\t                                               Nhap Ma don hang muon xac nhan: ";
        cin >> h;
            int i = layi(list2,m,h);
    for (int k = 0; k < i; k++){
                temp1 << list2[k].maDon;
                    temp1 << "," << list2[k].ngayDatDon;
                        temp1 << "," << list2[k].ngayDenCatToc;
                            temp1 << "," << list2[k].status;
                                temp1 << "," << list2[k].maRenderService;
                                    temp1 << "," << list2[k].sdt << endl;
    } 
                s = std::string(list2[i].status);
                s = s1;  
                                    temp1 << list2[i].maDon;
                                temp1 << "," << list2[i].ngayDatDon;
                            temp1 << "," << list2[i].ngayDenCatToc;
                        temp1 << "," << s;
                    temp1 << "," << list2[i].maRenderService;
                temp1 << "," << list2[i].sdt << endl; 
    for (int l = i + 1; l < m; l++){
                temp1 << list2[l].maDon;
                    temp1 << "," << list2[l].ngayDatDon;
                        temp1 << "," << list2[l].ngayDenCatToc;
                            temp1 << "," << list2[l].status;
                                temp1 << "," << list2[l].maRenderService;
                                    temp1 << "," << list2[l].sdt << endl;
    }                  
    myfile1.close();
        temp1.close();
            remove("Appointment-Origin.txt");
                rename("temp3.txt","Appointment-Origin.txt");
                    int size2 = read_file_appointment(list2) - 1;
                         out_file_appointment(list2,size2);
/*     int app;
        cout << "\n\n\t                                               1.Tiep tuc xac nhan             2.Tro lai Menu\n";
            cout << "\n\t\t\tChon: ";
                cin >> app;
                    while (app < 1 || app > 2){
                        cout << "\n\t                                                    YEU CAU KHONG HOP LE, MOI NHAP LAI";
                            cout << "\n\t                                               1.Tiep tuc xac nhan             2.Tro lai Menu\n";
                                cout << "\n\t\t\tChon: ";
                                    cin >> app;
    }
    if (app == 1){
        system("CLS");
            return nosangyes(list2,m);
    }
    if (app == 2){
        system("CLS");
            return menu();
    } */
}

//*HAM NHAN ESC DE THOAT*
void esc(){
    cout << "\n\n\t                                                              NHAN ESC DE THOAT...";
        while(1){
            if(getch() == 0x1b)
                break;
    }
}

//*MENU*
void menu(){
  int n, st1, st2, st3, st4;
  staff       list0[200];
  staff       stf;
  ClientData  list1[200];
  ClientData  client;
  appointment list2[200];
  appointment apt;
  int s = stf.read_file_staff(list0) - 1;
  int c = client.read_file_clientdata(list1) - 1;
  int m = apt.read_file_appointment(list2) - 1;

  cout << "\n\t\t============================================================ ADMIN ============================================================\n\n\n\n\n";

  cout << "\n\t\t                                            ______________________________________";
  cout << "\n\t\t                                            | *1. Quan ly nhan vien            * |";
  cout << "\n\t\t                                            | *2. Lich lam viec cua nhan vien  * |";
  cout << "\n\t\t                                            | *3. Quan ly khach hang           * |";
  cout << "\n\t\t                                            | *4. Xem don hang                 * |";
  cout << "\n\t\t                                            | *5. Thoat                        * |";
  cout << "\n\t\t                                            |_________________BHH________________|\n";

  cout << "\n\t\t\tChon: ";
  cin >> n;
  switch (n){
    case 1:{
        system("CLS");
        cout << "\n\t\t============================================================ ADMIN ============================================================\n\n\n";
        stf.out_file_staff(list0,s);
        cout << "\n                                                       1.Tro lai                                   2.Sua\n";
        cout << "\n\t\t\tChon: ";
        cin >> st1;
        switch (st1){
                case 1:{
                    system("CLS");
                        return menu();
                            break;
                }
                case 2:{
                    system("CLS");
                    int nv;
                    cout <<     "\n\t\t============================================================ ADMIN ============================================================\n\n\n";

                    cout <<  "\n\t                                          ----------------SUA THONG TIN NHAN VIEN----------------\n\n";
                    
                    cout <<  "\n\t                                                          ______________________";
                    cout <<  "\n\t                                                          | *1.Them nhan vien* |";
                    cout <<  "\n\t                                                          | *2.Xoa nhan vien * |";
                    cout <<  "\n\t                                                          | *3.Tro lai Menu  * |";
                    cout <<  "\n\t                                                          |________BHH_________|\n";

                    cout << "\n\t\t\tChon: ";
                    cin >> nv;
                    switch(nv){
                            case 1:{
                                system("CLS");
                                cout << "\n\t\t============================================================ ADMIN ============================================================\n\n\n";
                                    stf.add_staff(list0,s);
                                        system("\tpause");
                                            system("CLS");
                                                return menu();
                                                    break;
                            }
                            case 2:{
                                system("CLS");
                                cout << "\n\t\t============================================================ ADMIN ============================================================\n\n\n";
                                stf.delete_staff(list0);   
                                int st;
                                cout << "\n\t                                               1.Tiep tuc xoa                  2.Tro lai Menu\n";
                                cout << "\n\t\t\tChon: ";
                                cin >> st;
                                while (st < 1 || st > 2){
                                    cout << "\n\t                                                    *YEU CAU KHONG HOP LE, MOI NHAP LAI*";
                                    cout << "\n\t                                               1.Tiep tuc xoa                  2.Tro lai Menu\n";
                                    cout << "\n\t\t\tChon: ";
                                    cin >> st;
                                }
                                if (st == 1){
                                    system("CLS");
                                    return stf.delete_staff(list0);
                                }
                                if (st == 2){
                                    system("CLS");
                                    return menu();
                                }                                                                                                                           
                                break;
                            }
                            case 3:{
                                system("CLS");
                                    return menu();
                                        break;
                            }
                           default:{
                                cout << "\n\t                                                         *YEU CAU KHONG HOP LE!*" << endl;
                                    system("\tpause");
                                        return menu();
                                            break;
                            }
                    }
          
                }
                default:{
                    cout << "\n\t                                                         *YEU CAU KHONG HOP LE!*" << endl;
                        system("\tpause");
                            return menu();
                                break;
                }
        }
    break;
    }
    case 2:{
        system("CLS");
        cout << "\n\t\t============================================================ ADMIN ============================================================\n\n\n";
        apt.out_file_appointmentYES();
        cout << "\n\t                                                           Nhan phim 1 de tro lai Menu!\n";
        cout << "\n\t\t\tChon: ";
        cin >> st2;
        switch (st2){
                case 1:{
                    system("CLS");
                        return menu();
                            break;
                }
                default:{
                    cout << "\n\t                                                         *YEU CAU KHONG HOP LE!*" << endl;
                        system("\tpause");
                            return menu();
                                break;
                }
        }
        break;
    }
    case 3:{
        system("CLS");
        cout << "\n\t\t============================================================ ADMIN ============================================================\n\n\n";
        client.out_file_clientdata(list1,c);
        cout << "\n                                                      1.Tro lai                                   2.Sua\n";
        cout << "\n\t\t\tChon: ";
        cin >> st3;
        switch (st3){
                case 1:{
                    system("CLS");
                        return menu();
                            break;
                }
                case 2:{
                    system("CLS");
                    int nv;
                    cout <<        "\n\t\t============================================================ ADMIN ============================================================\n\n\n";

                    cout <<    "\n\t                                           ---------------SUA THONG TIN KHACH HANG---------------\n\n";
                    
                    cout <<    "\n\t                                                           ______________________";
                    cout <<    "\n\t                                                           | *1.Tim khach hang* |";
                    cout <<    "\n\t                                                           | *2.Xoa khach hang* |";
                    cout <<    "\n\t                                                           | *3.Tro lai Menu  * |";
                    cout <<    "\n\t                                                           |________BHH_________|\n";

                    cout << "\n\t\t\tChon: ";
                    cin >> nv;
                    switch(nv){
                            case 1:{
                                system("CLS");
                                cout << "\n\t\t============================================================ ADMIN ============================================================\n\n\n";
                                client.find_client(list1,c);
                                int cli;
                                cout << "\n                                                    1.Tiep tuc tim                   2.Tro lai Menu\n";
                                cout << "\n\t\t\tChon: ";
                                cin >> cli;
                                while (cli < 1 || cli > 2){
                                    cout << "\n\t                                                   *YEU CAU KHONG HOP LE, MOI NHAP LAI*";
                                    cout << "\n                                                          1.Tiep tuc tim                   2.Tro lai Menu\n";
                                    cout << "\n\t\t\tChon: ";
                                    cin >> cli;
                                }
                                if (cli == 1){
                                    system("CLS");
                                    return client.find_client(list1,c);
                                }
                                if (cli == 2){
                                    system("CLS");
                                    return menu();
                                }
                                break;
                            }
                            case 2:{
                                system("CLS");
                                cout << "\n\t\t============================================================ ADMIN ============================================================\n\n\n";
                                client.delete_client(list1);   
                                int cli1;
                                cout <<   "\n\t                                               1.Tiep tuc xoa                  2.Tro lai Menu\n";
                                cout << "\n\t\t\tChon: ";
                                cin >> cli1;
                                while (cli1 < 1 || cli1 > 2){
                                    cout << "\n\t                                                    *YEU CAU KHONG HOP LE, MOI NHAP LAI*";
                                    cout << "\n\t                                                          1.Tiep tuc xoa                  2.Tro lai Menu\n";
                                    cout << "\n\t\t\tChon: ";
                                    cin >> cli1;
                                }
                                if (cli1 == 1){
                                    system("CLS");
                                    return client.delete_client(list1);
                                }
                                if (cli1 == 2){
                                    system("CLS");
                                    return menu();
                                }                                                                      
                                break;
                            }
                            case 3:{
                                system("CLS");
                                    return menu();
                                        break;
                            }
                           default:{
                                cout << "\n\t                                                         *YEU CAU KHONG HOP LE!*" << endl;
                                    system("\tpause");
                                        return menu();
                                            break;
                            }
                    }
                }
                default:{
                    cout << "\n\t                                                         *YEU CAU KHONG HOP LE!*" << endl;
                        system("\tpause");
                            return menu();
                                break;
                }
        }
        break;
    }
    case 4:{
        system("CLS");
        cout << "\n\t\t============================================================ ADMIN ============================================================\n\n\n";
        apt.out_file_appointment(list2,m);

        cout << "\n                                                      1.Tro lai                                   2.Sua\n";

        cout << "\n\t\t\tChon: ";
        cin >> st4;
        switch (st4){
                case 1:{
                    system("CLS");
                        return menu();
                            break;
                }
                case 2:{
                    system("CLS");
                    cout <<       "\n\t\t============================================================ ADMIN ============================================================\n\n\n";
                    int ch;
                    cout <<  "\n\t                                          ------------------SUA THONG TIN CUOC HEN------------------\n\n";
                    
                    cout <<  "\n\t                                                           _________________________";
                    cout <<  "\n\t                                                           | *1.Xac nhan cuoc hen* |";
                    cout <<  "\n\t                                                           | *2.Xoa cuoc hen     * |";
                    cout <<  "\n\t                                                           | *3.Tro lai Menu     * |";
                    cout <<  "\n\t                                                           |__________BHH__________|\n";
                    
                    cout << "\n\t\t\tChon: ";
                    cin >> ch;
                    switch(ch){
                        case 1:{
                            system("CLS");
                            cout << "\n\t\t============================================================ ADMIN ============================================================\n\n\n";
                            apt.nosangyes(list2,m);
                            int app;
                            cout << "\n\n\t                                               1.Tiep tuc xac nhan             2.Tro lai Menu\n";
                            cout << "\n\t\t\tChon: ";
                            cin >> app;
                            while (app < 1 || app > 2){
                                cout << "\n\t                                                    YEU CAU KHONG HOP LE, MOI NHAP LAI";
                                cout << "\n\t                                               1.Tiep tuc xac nhan             2.Tro lai Menu\n";
                                cout << "\n\t\t\tChon: ";
                                cin >> app;
                            }
                            if (app == 1){
                                system("CLS");
                                return apt.nosangyes(list2,m);
                            }
                            if (app == 2){
                                system("CLS");
                                return menu();
                            }
                            break;
                        }
                        case 2:{
                            system("CLS");
                            cout << "\n\t\t============================================================ ADMIN ============================================================\n\n\n";
                            apt.deleteappointment(list2);       
                            int ap1;
                            cout << "\n\t                                               1.Tiep tuc xoa                  2.Tro lai Menu\n";
                            cout << "\n\t\t\tChon: ";
                            cin >> ap1;
                            while (ap1 < 1 || ap1 > 2){
                                cout << "\n\t                                                    *YEU CAU KHONG HOP LE, MOI NHAP LAI*";
                                cout << "\n\t                                                          1.Tiep tuc xoa                  2.Tro lai Menu\n";
                                cout << "\n\t\t\tChon: ";
                                cin >> ap1;
                            }
                            if (ap1 == 1){
                                system("CLS");
                                return apt.deleteappointment(list2);
                            }
                            if (ap1 == 2){
                                system("CLS");
                                return menu();
                            }                         
                            break;
                        }
                        case 3:{
                            system("CLS");
                                return menu();
                                    break;
                        }
                        default:{
                            cout << "\n\t                                                         *YEU CAU KHONG HOP LE!*" << endl;
                                system("\tpause");
                                    return menu();
                                        break;
                        }
                    }    
                }
                default:{
                    cout << "\n\t                                                         *YEU CAU KHONG HOP LE!*" << endl;
                        system("\tpause");
                            return menu();
                                break;
                }
        }  
        break;
  }
    case 5:{
        esc();
            break;  
    }
    default:{
        cout << "\n\t                                                         *YEU CAU KHONG HOP LE!*";
            system("\tpause");
                return menu();
                    break;
    }
  }
}