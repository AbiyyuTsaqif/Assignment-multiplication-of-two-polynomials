#include "tubes.h"

void createList(List &L){
    first(L) = NULL;
}

adr newElement(infotype data){
    adr p = new element;
    info(p) = data;
    next(p) = NULL;
    return p;
}

void insertLast(List &L, adr p){
    if (first(L) == NULL){
        first(L) = p;
    }else{
        adr q = first(L);
        while (next(q) != NULL){
            q = next(q);
        }
        next(q) = p;
    }
}

void show(List L){
    if (first(L) != NULL) {
        adr p = first(L);
        while (p != NULL){
            if (info(p).pangkat != 0){
                if (info(p).angka > 0){
                    cout << info(p).angka << "X" << "^" << "(" << info(p).pangkat << ")";
                }else {
                    cout << "(" << info(p).angka << "X" << "^" << "(" << info(p).pangkat << ")" << ")";
                }
            }else{
                if (info(p).angka > 0){
                    cout << info(p).angka;
                }else {
                    cout << "(" << info(p).angka << ")";
                }
            }

            if (next(p) != NULL) {
                cout << " + ";
            }

            p = next(p);
        }
        cout << endl;
        cout << "List selesai ditampilkan" << endl;
        cout << endl;
    }
    else {
        cout << "List Kosong" << endl;
    }
}

void insertFirst(List &L, adr p){
    if (first(L) == NULL){
        first(L) = p;
    }else {
        next(p) = first(L);
        first(L) = p;
    }
}

void insertAfter(List &L, adr prec, adr p){
    next(p) = next(prec);
    next(prec) = p;
}

void insertAscending (List &L, adr q){
    if (info(q).angka != 0){
        if (info(q).pangkat != 0){
            if (first(L) == NULL ){
                insertFirst(L, q);
            }else if(info(q).pangkat >= info(first(L)).pangkat){
                insertFirst(L, q);
            }else {
                adr prec = first(L);

                if(prec != NULL) {
                    while (next(prec) != NULL && info(next(prec)).pangkat > info(q).pangkat) {
                        prec = next(prec);
                    }
                    insertAfter(L, prec, q);
                }else {
                    insertLast(L, q);
                }
            }
        }else{
            insertLast(L, q);
        }
    }
}

List gabungfinal(List L, List J){
    List K;
    createList(K);
    adr p,r;
    p = first(L);
    while(p != NULL){
        r = newElement(info(p));
        insertAscending(K,r);
        p = next(p);
    }
    p = first(J);
    while(p != NULL){
        r = newElement(info(p));
        insertAscending(K,r);
        p = next(p);
    }
    return K;
}

void deleteFirst(List &L, adr &p){
    if (first(L) == NULL){
        cout << "List Kosong" << endl;
    }else {
        p = first(L);
        first(L) = next(first(L));
        next(p) = NULL;
    }
}

List DivByX0 (List L, float angka){
    adr q = first(L);
    while(q != NULL){
        info(q).angka /= angka;
        q = next(q);
    }
    return L;
}

List MulPolymonial (List L, List J){
    List K;
    createList(K);
    adr q,r;
    adr p = first(L);
    int pangkat;
    float angka;
    infotype data;
    /*while(p != NULL){
        q = newElement(info(p));
        insertLast(K,q);
        p = next(p);
    }
    p = first(K);
    q = first(J);
    while(q != NULL){
        info(p).angka = info(q).angka * info(p).angka;
        info(p).pangkat = info(q).pangkat + info(p).pangkat;

        if(p == NULL){
            r = newElement(info(q));
            insertLast(K,r);
        }
        p = next(p);
        q = next(q);
    }*/
    q = first(J);
    while (p != NULL) {
        q = first(J);
        while (q != NULL) {
            data.angka = info(p).angka * info(q).angka;
            data.pangkat = info(p).pangkat + info(q).pangkat;
            r = newElement(data);
            insertAscending(K,r);
            //insertLast(K, r);
            q = next(q);
        }
        p = next(p);
    }
    cout << "Sebelum disederhanakan : ";
    show(K);

    p = first(K);
    while (p != NULL) {
        if (next(p) != NULL && info(next(p)).pangkat == info(p).pangkat) {
            angka = info(p).angka + info(next(p)).angka;
            info(p).angka = angka;
            deleteElement(K, next(p));
        } else {
            p = next(p);
        }
        if (next(p) == NULL) {
            break;
        }
        if (info(next(p)).pangkat != info(p).pangkat) {
            p = next(p);
        }
    }
    cout << "Setelah disederhanakan : ";
    return K;

}

void deleteAfter(List &L, adr prec, adr &p) {
     if (first(L) == NULL){
        cout << "List Kosong" << endl;
    }else {
        next(prec) = next(p);
        next(p) = NULL;
    }
}

void deleteLast(List &L, adr &p) {
     if (first(L) == NULL){
        cout << "List Kosong" << endl;
    }else {
        adr q = first(L);
        while (next(next(q)) != NULL) {
            p = next(q);
            next(q) = NULL;
        }
    }
}

void deleteElement (List &L, adr p){
    if (first(L) == p){
        deleteFirst(L, p);
    }else {
        adr prec = next(first(L));
        while (next(prec) != NULL && next(prec) != p){
            prec = next(prec);
        }
        if(prec != NULL){
            deleteAfter(L, prec, p);
        }else {
            deleteLast(L, p);
        }
    }
}

void add_N_data(List &L){
    int N;
    int i = 0 ;
    infotype poly;
    adr P;
    cout << "Jumlah suku bilangan yang ingin ditambah : ";
    cin >> N;
    cout << endl;
    while (i < N){
        cout << "Angka           : ";
        cin >> poly.angka;
        cout << "Pangkat         : ";
        cin >> poly.pangkat;
        P = newElement(poly);
        insertAscending(L, P);
        i++;
    }
    cout << endl;
}

int selectMenu(){
    int userInput = 0;
    cout<<"======MENU======="<<endl;
    cout<<"1. Masukkan banyaknya suku bilangan polynomial pertama"<<endl;
    cout<<"2. Masukkan banyaknya suku bilangan polynomial kedua"<<endl;
    cout<<"3. Menampilkan list" << endl;
    cout<<"4. Meng-kali kedua list"<<endl;
    cout<<"5. Membagi list dengan suatu koefisien"<< endl;
    cout<<"0. Exit"<<endl << endl;

    cout<<"Masukkan menu : " ;
    cin>>userInput;
    cout << endl;

    return userInput;
}
