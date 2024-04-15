#include <iostream>
#include <conio.h>
using namespace std;
int main(){
    int macro[]={1,2,3,4,5};
    int suma=1;

    for(int i=0;i<5;i++){
        suma *=macro[i];
    }
    cout<<suma;
    return 0;
}
