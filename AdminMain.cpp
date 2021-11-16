#include "Admin.cpp"

main(){
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),120);
    admin ad;
    ad.singin();
    system("CLS");
    menu();
    getch();
}
