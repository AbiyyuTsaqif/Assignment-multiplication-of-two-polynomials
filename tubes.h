#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>

using namespace std;

#define info(p) (p)->info
#define next(p) (p)->next
#define first(L) ((L).first)

struct polynomial{
    float angka;
    int pangkat;
};

typedef polynomial infotype;

typedef struct element *adr;

struct element{
    infotype info;
    adr next;
};

struct List{
    adr first;
};

void createList(List &L);
adr newElement(infotype data);
void insertLast(List &L, adr p);
void show(List L);
List gabungfinal(List L, List J);
void insertAscending (List &L, adr q);
void insertAfter(List &L, adr prec, adr p);
void insertFirst(List &L, adr p);
void deleteFirst(List &L, adr &p);
List DivByX0 (List L, float angka);
List MulPolymonial (List L, List J);
void deleteAfter(List &L, adr prec, adr &p);
void deleteLast(List &L, adr &p);
void deleteElement (List &L, adr p);
void add_N_data(List &L);
int selectMenu();


#endif // TUBES_H_INCLUDED
