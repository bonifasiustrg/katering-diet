#ifndef KATERINGDIET_H_INCLUDED
#define KATERINGDIET_H_INCLUDED

#include <iostream>
using namespace std;

#define info(P) P->info
#define next(P) P->next
#define first(L) ((L).first)
#define nil NULL

struct jadwalPenerbangan {
    string kode, jenis, tanggal, waktu, asal, tujuan;
    int kapasitas;
};
typedef struct elemenFood *adrFood;
typedef struct elemenPaket *adrPaket;
typedef struct Relation *adrRelation;
typedef char infotype;

struct elemenPaket {
    infotype infoPaket;
    adrRelation child;
    adr nextPaket;
};
struct elemenFood {
    infotype infoPaket;
    adr nextFood;
};

struct elemenRelation {
    adrRelation nextRelation;
    adrFood nextFood;
};


struct Relation {
    adrRelation firstRelation;
};

struct ListPaket {
    adrPaket firstPaket;
};

struct ListFood {
    adrFood firstFood;
};


#endif // KATERINGDIET_H_INCLUDED
