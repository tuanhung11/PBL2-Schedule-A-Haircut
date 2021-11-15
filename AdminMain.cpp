#include "Admin.cpp"

main(){
    system("CLS");
    system("COLOR F0");
    cout << "\n\t\t                        ********************************* ADMIN ONLY **********************************\n\n\n\n\n";
    cout << "\n\t\t                                                 ----------DANG NHAP----------\t\t\t\n\n";
    admin ad;
    ad.singin();
    system("CLS");
    menu();
    getch();
}
 