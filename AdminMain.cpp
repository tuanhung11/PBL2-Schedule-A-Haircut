#include "Admin.cpp"

int main(){
  system("CLS");
  cout << "\n*********************************ADMIN ONLY**********************************";
  cout <<                   "\n\t\t\t----------DANG NHAP----------\t\t\t\n";
  admin ad;
  ad.singin();
  system("CLS");
  menu();
  return 0;
}
 