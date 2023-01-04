#ifndef KATERINGDIET_H_INCLUDED
#define KATERINGDIET_H_INCLUDED

#include <iostream>
using namespace std;

#define infoFood(P) P->infoFood
#define infoPaket(P) P->infoPaket
#define nextFood(P) P->nextFood
#define nextPaket(P) P->nextPaket
#define nextRelation(P) P->nextRelation
#define foodRelation(P) P->foodRelation
#define child(P) P->child

#define firstRelation(LR) ((LR).firstRelation)
#define firstPaket(LP) ((LP).firstPaket)
#define firstFood(LF) ((LF).firstFood)
#define nil NULL

struct Food {
    string foodName;
    int nFood;
};

typedef Food food;
typedef struct elemenFood *adrFood;
typedef struct elemenPaket *adrPaket;
typedef struct elemenRelation *adrRelation;

struct elemenPaket {
    string infoPaket;
    adrPaket nextPaket;
    adrRelation child;
};
struct elemenFood {
    food infoFood;
    adrFood nextFood;
};

struct elemenRelation {
    adrRelation nextRelation;
    adrFood foodRelation;
};

struct ListPaket {
    adrPaket firstPaket;
};

struct ListFood {
    adrFood firstFood;
};

void createListPaket(ListPaket &LP);
void createListFood(ListFood &LF);

adrPaket createElemenPaket(string paket);
adrFood createElemenFood(string food);

//Menambahkan data pada parent dan child.
void addFirstPaket(ListPaket &LP, adrPaket p);
void addFirstFood(ListFood &LF, adrFood p);

//Mencari data pada parent dan child.
adrFood searchFood(ListFood LF, string food);
adrPaket searchPaket(ListPaket LP, string paket);

//Menampilkan data pada parent dan child.
void showAll(ListFood LF, ListPaket LP);
void showFood(ListFood LF);
void showPaket(ListPaket LP);


//Menambahkan relasi antara parent dan child.
void addFoodToPaket(ListPaket &LP, ListFood &LF, string namaPaket, string namaFood);

//Menghapus data (parent) beserta relasinya (child-nya).
void deletePaket(ListPaket &LP, string namaPaket);
void deleteRelation(ListPaket &LP, adrPaket p);

//Menghitung jumlah data pada parent dan child-nya.
void nData(ListFood LF, ListPaket LP);

//Menampilkan jumlah data paling banyak.
void nmaxFood(ListFood LF);

//Menampilkan jumlah data paling sedikit.
void nminFood(ListFood LF);

//tambahan
//UI pilihan menu
int selectMenu();



#endif // KATERINGDIET_H_INCLUDED
