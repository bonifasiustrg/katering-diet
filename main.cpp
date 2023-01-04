#include "kateringdiet.h"

using namespace std;

int main()
{
    ListPaket LP;
    ListFood LF;
    createListPaket(LP);
    createListFood(LF);

    int pilihan = selectMenu();
    char kembali = 'Y';
    while (pilihan != 0 && pilihan<=10) {
        switch (pilihan) {
        case 1:{
            ///////// #1 Menambahkan data pada parent dan child.///////////
            // sudah termasuk #2 Mencari data pada parent dan child.
            cout<<"Tambah paket baru"<<endl;
            addFirstPaket(LP, createElemenPaket("A"));
            addFirstPaket(LP, createElemenPaket("B"));
            addFirstPaket(LP, createElemenPaket("C"));
            addFirstPaket(LP, createElemenPaket("D"));

            break;
        }
        case 2:{
            cout<<"Tambah makanan lain"<<endl;
            addFirstFood(LF, createElemenFood("Bala-bala"));
            addFirstFood(LF, createElemenFood("ikan"));
            addFirstFood(LF, createElemenFood("buncis"));
            addFirstFood(LF, createElemenFood("perkedel"));
            addFirstFood(LF, createElemenFood("kentang"));
            addFirstFood(LF, createElemenFood("Nasi"));
            addFirstFood(LF, createElemenFood("Kangkung"));
            break;
        }
        case 3:{
            ///////// #4 Menambahkan relasi antara parent dan child.///////////
            cout<<"Tambahkan makanan ke dalam paket"<<endl;
            addFoodToPaket(LP, LF, "A", "ikan");
            addFoodToPaket(LP, LF, "B", "perkedel");
            addFoodToPaket(LP, LF, "B", "buncis");
            addFoodToPaket(LP, LF, "A", "perkedel");
            addFoodToPaket(LP, LF, "D", "buncis");
            addFoodToPaket(LP, LF, "A", "buncis");
            addFoodToPaket(LP, LF, "C", "buncis");
            addFoodToPaket(LP, LF, "C", "Nasi");
            addFoodToPaket(LP, LF, "C", "Bala-bala");
            break;
        }
        case 4:{
            cout<<"Anda ingin mencari apa? :"<<endl;
            int i;
            cout<<"1. paket || 2. makanan ==> "; cin>>i;
            if (i == 1) {
                string y; cout<<"Paket yang ingin dicari: "; cin>>y;
                searchPaket(LP, y);
            } else if  (i == 2) {
                string x; cout<<"Makanan yang ingin dicari: "; cin>>x;
                searchFood(LF, x);
            }

            break;
        }
        case 5:{
            cout<<"Tampilkan Daftar Paket & Makanan tersedia"<<endl;
            showPaket(LP);
            showFood(LF);
            break;
        }
        case 6:{
            ///////// #3 Menampilkan data pada parent dan child.///////////
            cout<<"Tampilkan Paket besarta isinya"<<endl;
            showAll(LF, LP);

            break;
        }
        case 7:{
            ///////// #5 Menghapus data (parent) beserta relasinya (child-nya).///////////
            cout<<" Hapus paket makanan"<<endl;
            deletePaket(LP, "D");
            showAll(LF, LP);

            break;
        }
        case 8:{
            ///////// #6 Menghitung jumlah data pada parent dan child-nya.///////////
            cout<<"Hitung banyaknya paket beserta makanannya"<<endl;
            nData(LF, LP);
            break;
        }case 9:{
            ///////// #7 Menampilkan jumlah data paling banyak.///////////
            cout<<"Tampilkan jumlah makanan paling banyak"<<endl;
            nmaxFood(LF);
            break;
        }case 10:{
            ///////// #8 Menampilkan jumlah data paling sedikit.///////////
            cout<<"Tampilkan jumlah makanan paling sedikit"<<endl;
            nminFood(LF);
            break;
        }}


        cout<<"selesai"<<endl;
        cout<<endl<<endl;
        pilihan = selectMenu();
    }

    ///////// END OF PROGRAM ///////////
    return 0;
}
