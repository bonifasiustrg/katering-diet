#include "kateringdiet.h"

void createListPaket(ListPaket &LP) {
    firstPaket(LP) = nil;
}
void createListFood(ListFood &LF) {
    firstFood(LF) = nil;
}

adrPaket createElemenPaket(string paket) {
    adrPaket p;
    p = new elemenPaket;
    infoPaket(p) = paket;
    child(p) = nil;
    nextPaket(p) = nil;

    return p;
}

adrFood createElemenFood(string food) {
    adrFood p;
    p = new elemenFood;
    infoFood(p).foodName = food;
    infoFood(p).nFood = 0;
    nextFood(p) = nil;

    return p;
}

void addFirstPaket(ListPaket &LP, adrPaket p) {
    if (firstPaket(LP) == nil) {
        firstPaket(LP) = p;
    } else {
        nextPaket(p) = firstPaket(LP);
        firstPaket(LP) = p;
    }
}

void addFirstFood(ListFood &LF, adrFood p) {
    if (firstFood(LF) == nil) {
        firstFood(LF) = p;
    } else {
        nextFood(p) = firstFood(LF);
        firstFood(LF) = p;
    }
}

// Mencari adrFood dari nama makanan yang diinginkan
adrFood searchFood(ListFood LF, string x) {
    adrFood q;
    if (firstFood(LF) != nil) {
        q = firstFood(LF);

        while (q != nil) {
            if (infoFood(q).foodName == x) {
                return q;
            }

            q = nextFood(q);
        }
    }
    return nil;
}

// Mencari adrPaket dari nama paket yang diinginkan
adrPaket searchPaket(ListPaket LP, string y) {
    adrPaket p;
    if (firstPaket(LP) != nil) {
        p = firstPaket(LP);
        while (p != nil) {
            if (infoPaket(p) == y)
                return p;

            p = nextPaket(p);
        }
    }
    return nil;
}

// Menampilkan semua makanan yang ada di list Food
void showFood(ListFood LF) {
    adrFood f;
    if (firstFood(LF) == nil) {
        cout<<"List food kosong"<<endl;
    } else {
        f = firstFood(LF); int i=1;
        while (f != nil) {
            cout<<"Makanan "<<i<<": "<<infoFood(f).foodName<<endl;
            f = nextFood(f);
            i++;
        }
    }
}
void showPaket(ListPaket LP) {
    adrPaket p;
    if (firstPaket(LP) == nil) {
        cout<<"List paket kosong"<<endl;
    } else {
        p = firstPaket(LP); int i=1;
        while (p != nil) {
            cout<<"Paket "<<i<<": "<<infoPaket(p)<<endl;
            p = nextPaket(p);
            i++;
        }
    }
}

// Memasukkan dan menghubungkan makanan yang dipilih ke dalam paket yang dipilih
void addFoodToPaket(ListPaket &LP, ListFood &LF, string namaPaket, string namaFood) {
    // menambahkan/menghubungkan food dengan paket yang dipilih
    adrPaket paket = searchPaket(LP, namaPaket);
    adrFood food = searchFood(LF, namaFood);

    if (paket == nil) { cout<<"Paket tidak ditemukan"<<endl; return;}
    if (food == nil) { cout<<"Makanan tidak ditemukan"<<endl; return;}

    adrRelation r = new elemenRelation;
    if (child(paket) == nil) {
        child(paket) = r;
        nextRelation(r) = nil;
        foodRelation(r) = food;
        infoFood(food).nFood = infoFood(food).nFood + 1;
    } else {
        nextRelation(r) = child(paket);
        child(paket) = r;
        foodRelation(r) = food;
        infoFood(food).nFood = infoFood(food).nFood + 1;
    }
    cout<<infoFood(food).foodName<<" "<<infoFood(food).nFood<<" telah ditambahkan ke paket "<<infoPaket(paket)<<endl;
}

void showAll(ListFood LF, ListPaket LP) {
    if (firstPaket(LP) == nil) {
        cout<<"Paket kosong"<<endl;
    } else {
        adrPaket p = firstPaket(LP);
        adrRelation r;
        adrFood f = firstFood(LF);
        while (p != nil) {
            cout<<"Paket "<<infoPaket(p)<<endl<<"Terdiri dari ";
            r = child(p);
            if (r != nil) {
                //cout<<"Relation ada"<<endl;
                adrFood food;
                while (r != nil) {
                    cout<<infoFood(foodRelation(r)).foodName<<", ";
                    r = nextRelation(r);
                }

            } else { cout<<"Relation kosong";}

            p = nextPaket(p);
            //r = child(p);
            cout<<endl<<endl;
        }
    }
}

void nData(ListFood LF, ListPaket LP) {
    adrPaket p = firstPaket(LP);
    adrFood f = firstFood(LF);
    int nPaket = 0, nFood = 0;

    while (p != nil) {
        nPaket += 1;
        p = nextPaket(p);
    }
    while (f != nil) {
        nFood += 1;
        f = nextFood(f);
    }
    cout<<"Jumlah paket ada sebanyak "<<nPaket<<endl;
    cout<<"Jumlah food ada sebanyak "<<nFood<<endl;
}

// Menampilkan makanan dengan jlh terbanyak
void nmaxFood(ListFood LF) {
    adrFood p;

    if (firstFood(LF) != nil) {
        adrFood maxFood = firstFood(LF);
        p = nextFood(maxFood);
        while (nextFood(p) != nil) {
            if (infoFood(maxFood).nFood < infoFood(p).nFood) {
                maxFood = p;
            }

            p = nextFood(p);
        }
        cout<<"Makanan dengan jumlah terbanyak adalah "<<infoFood(maxFood).foodName<<" sebanyak "<<infoFood(maxFood).nFood<<endl;
        //cout<<"Makanan dengan jlh terbanyak adalah "<<infoFood(p).foodName<<endl;
    }
}

// Menampilkan makanan dengan jlh terbanyak
void nminFood(ListFood LF) {
    adrFood p;

    if (firstFood(LF) != nil) {
        adrFood minFood = firstFood(LF);
        p = nextFood(minFood);
        while (nextFood(p) != nil) {
            if (infoFood(minFood).nFood > infoFood(p).nFood) {
                minFood = p;
            }

            p = nextFood(p);
        }
        cout<<"Makanan dengan jumlah paling sedikit adalah "<<infoFood(minFood).foodName<<" sebanyak "<<infoFood(minFood).nFood<<endl;
        //cout<<"Makanan dengan jlh terbanyak adalah "<<infoFood(p).foodName<<endl;
    }
}

//Menghapus data (parent) beserta relasinya (child-nya).
void deletePaket(ListPaket &LP, adrPaket p) {
    // menambahkan/menghubungkan food dengan paket yang dipilih

//    p = searchPaket(LP, string namaPaket);
    if (p != nil) {
        deleteRelation(LP, p);
        //delete first kalo posisi p di awal
        firstPaket(LP) = nextPaket(p);
        p = nil;
        delete(p);

    } else { cout<<"List Paket tidak ditemukan"<<endl;}

    //cout<<infoFood(food).foodName<<infoFood(food).nFood<<" telah ditambahkan ke paket "<<infoPaket(paket)<<endl;
}

void deleteFood(ListPaket &LP, string namaPaket, string namaFood) {
    adrPaket p = searchPaket(LP, namaPaket);
    if (child(p) == nil) {
        cout<<"Makanan tidak ditemukan"<<endl;
    } else {
        adrRelation r, q;
        r = child(p);
        while (r != nil) {
            //delete first
            q = r;
            if (infoFood(foodRelation(q)).foodName == namaFood ) {
                break;
            }

            r = nextRelation(q);
        }

        //cout<<infoFood(foodRelation(q)).foodName<<endl;
        infoFood(foodRelation(q)).nFood = infoFood(foodRelation(q)).nFood - 1;

        child(p) = nextRelation(q);
        foodRelation(q) = nil;
        nextRelation(q) = nil;

        delete(q);
    }
}

void deleteRelation(ListPaket &LP, adrPaket p) {
    if (child(p) == nil) {
            cout<<"relation kosong"<<endl;
        } else {
            adrRelation r, q;
            r = child(p);
            while (r != nil) {
                //delete first
                q = r;
                foodRelation(q) = nil;
                r = nextRelation(q);
                delete(q);
            }
            child(p) = nil;
        }
}

int selectMenu(){
    cout<<"=================================================="<<endl;
    cout<<"================Kelompok Fullstack================"<<endl;
    cout<<"=====================IF-45-12====================="<<endl;
    cout<<"=======================MENU======================="<<endl;
    cout<<"=================================================="<<endl;
    cout<<"# 1.  Tambah paket baru                          #"<<endl;
    cout<<"# 2.  Tambah makanan                             #"<<endl;
    cout<<"# 3.  Tambahkan makanan ke dalam paket           #"<<endl;
    cout<<"# 4.  Cari paket atau makanan                    #"<<endl; //output berupa daftar makanan
    cout<<"# 5.  Tampilkan Daftar Paket & Makanan tersedia  #"<<endl;
    cout<<"# 6.  Tampilkan Paket beserta isinya             #"<<endl;
    cout<<"# 7.  Hitung banyaknya paket beserta makanannya  #"<<endl;
    cout<<"# 8.  Tampilkan jumlah makanan paling banyak     #"<<endl; //output = paket
    cout<<"# 9.  Tampilkan jumlah makanan paling sedikit    #"<<endl; //output = paket
    cout<<"# 10. Hapus paket makanan                        #"<<endl; //hapus sama makanannya, abis apus show current list
    cout<<"# 11. Hapus makanan dari satu paket              #"<<endl;
    cout<<"# 0.  Exit                                       #"<<endl;
    cout<<"=================================================="<<endl;
    cout<<"=================================================="<<endl;

//    int select;
//    cin>>select;
//    return select;
}
