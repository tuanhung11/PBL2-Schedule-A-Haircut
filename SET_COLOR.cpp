#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    int i;
    for (i = 1; i <= 256; i++){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
        cout << i << ". Hello World" << endl;
    }
    return 0;
}
        