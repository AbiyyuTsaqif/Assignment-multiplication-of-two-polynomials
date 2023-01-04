#include "tubes.h"
#include <iostream>

using namespace std;

int main()
{
    List L;
    List J;
    List M;
    List O;
    createList(L);
    createList(J);
    createList(M);
    createList(O);
    infotype polynomial;
    adr p;
    int x, y;
    int pilihan = selectMenu();
    string n;

    while(pilihan != 0){
        switch(pilihan){
        case 1:
            add_N_data(L);
            break;
        case 2:
            add_N_data(J);
            break;
        case 3:
            cout << "Sebelum List digabung" << endl << endl;
            cout << "polynomial pertama : ";
            show(L);
            cout << "polynomial kedua   : ";
            show(J);
            cout << "Menampilkan gabungan polynomial" << endl << endl;
            M = gabungfinal(L, J);
            show(M);
            break;
        case 4:
            cout << "Menampilkan hasil kali kedua polynomial" << endl;
            O = MulPolymonial(L, J);
            show(O);
            break;
        case 5:
            int c;
            cout << "Masukkan koefisien pembagi : ";
            cin >> c;
            cout << "Menampilkan hasil pembagian" << endl;
            DivByX0(O, c);
            show(O);
            break;
        }
        cout << "kembali ke menu utama? (YES/NO) : ";
        cout << endl;
        cin >> n;
        if(n == "NO"){
            break;
        }else if (n == "YES"){
            pilihan = selectMenu();
        }
    }

    return 0;
}

