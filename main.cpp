#include <iostream>
#include "kateringdiet.h"

using namespace std;

int main()
{
    ListPaket LP;
    ListFood LF;
    createListPaket(LP);
    createListFood(LF);

    int pilihan = 0, nPaket, nFood, nFood2, i;

    selectMenu();
    cout<<"Masukkan menu: ";cin>>pilihan; cout<<endl;

    string inputpaket, inputpaket2;
    string inputfood, inputfood2;
    string delPaket, delPaket2;
    string delFood;

    while (pilihan != 0) {
        switch (pilihan) {
        case 1:{
                cout<<"Masukkan jumlah paket yang akan ditambah: ";cin>>nPaket;
                i=0;
                while (i<nPaket){
                    cout<<"Masukkan paket baru: ";cin>>inputpaket;
                    addFirstPaket(LP, createElemenPaket(inputpaket));
                    i++;
                }
                    cout<<"Paket sudah ditambahkan."<<endl; cout<<endl;

            ///////// #1 Menambahkan data pada parent dan child.///////////
            // sudah termasuk #2 Mencari data pada parent dan child.
        break;}
        case 2:{
                cout<<"Masukkan jumlah makanan yang akan ditambah: ";cin>>nFood;
                i=0;
                while (i<nFood) {
                    cout<<"Masukkan nama makanan: ";cin>>inputfood;
                    addFirstFood(LF, createElemenFood(inputfood));
                    i++;
                }
                cout<<"Makanan sudah ditambahkan"<<endl; cout<<endl;
            break;
        }
        case 3:{
            ///////// #4 Menambahkan relasi antara parent dan child.///////////
            cout<<"Daftar makanan yang tersedia: "<<endl; showFood(LF); cout<<endl;
            cout<<"Masukkan paket yang ingin ditambahkan: ";cin>>inputpaket2;
            cout<<"Masukkan jumlah makanan yang ingin ditambahkan: ";cin>>nFood2;cout<<endl;
            i=0;
            while (i<nFood2) {
                cout<<"Masukkan makanan yang ingin ditambahkan: ";cin>>inputfood2;
                addFoodToPaket(LP, LF, inputpaket2, inputfood2);cout<<endl;
                i++;
            }
            cout<<"Makanan sudah ditambahkan ke dalam paket"<<endl;cout<<endl;
            break;
        }
        case 4:{
            cout<<"Anda ingin mencari apa? :"<<endl;
            int i;
            cout<<"1. paket || 2. makanan ==> "; cin>>i;cout<<endl;
            if (i == 1) {
                string y; cout<<"Paket yang ingin dicari: "; cin>>y;

                if (searchPaket(LP, y) != NULL) {
                    cout<<"Paket tersedia, yaitu ";
                    cout<<infoPaket(searchPaket(LP, y))<<endl;
                    cout<<endl;
                } else {
                    cout<<"Paket tidak tersedia"<<endl;
                    cout<<endl;
                }
            } else if  (i == 2) {
                string x; cout<<"Makanan yang ingin dicari: "; cin>>x;
                if (searchFood(LF, x) != NULL) {

                    cout<<"Makanan tersedia, yaitu ";
                    cout<<infoFood(searchFood(LF, x)).foodName<<" sebanyak ";
                    cout<<infoFood(searchFood(LF, x)).nFood<<endl;
                    cout<<endl;
                } else {
                    cout<<"Makanan tidak tersedia"<<endl;
                    cout<<endl;
                }

            }

            break;
        }
        case 5:{
            cout<<"Menampilkan Daftar Paket & Makanan tersedia"<<endl;
            showPaket(LP);
            showFood(LF);
            cout<<endl;
            break;
        }
        case 6:{
            ///////// #3 Menampilkan data pada parent dan child.///////////
            cout<<"Menampilkan Paket beserta isinya"<<endl;
            showAll(LF, LP);
            cout<<endl;
            break;
        }
        case 7:{
            ///////// #6 Menghitung jumlah data pada parent dan child-nya.///////////
            cout<<"Menghitung banyaknya paket beserta makanannya"<<endl;
            nData(LF, LP);
            cout<<endl;
            break;
        }case 8:{
            ///////// #7 Menampilkan jumlah data paling banyak.///////////
            cout<<"Menampilkan jumlah makanan paling banyak"<<endl;
            nmaxFood(LF);
            cout<<endl;
            break;
        }case 9:{
            ///////// #8 Menampilkan jumlah data paling sedikit.///////////
            cout<<"Menampilkan jumlah makanan paling sedikit"<<endl;
            nminFood(LF);
            cout<<endl;
            break;
        }
        case 10:{
            ///////// #5 Menghapus data (parent) beserta relasinya (child-nya).///////////
            cout<<"Masukkan nama paket makanan yang ingin dihapus: ";cin>>delPaket;
            //search paket -> delete paket
            deletePaket(LP, searchPaket(LP, delPaket));
            showAll(LF, LP);
            cout<<"Paket berhasil dihapus."<<endl;
            cout<<endl;
            break;
        }
        case 11:{
            ///////// #11 Menghapus relasinya (child-nya).///////////
            cout<<"Masukkan nama paket: "; cin>>delPaket2;
            cout<<"Masukkan nama makanan yang ingin dihapus: ";cin>>delFood;
            //search paket -> search food -> delete food
            deleteFood(LP, delPaket2, delFood);
            showAll(LF, LP);
            cout<<"Makanan berhasil dihapus"<<endl;
            cout<<endl;
            break;

        }default:{
            cout<<"Pilihan tidak tersedia."<<endl; cout<<endl;}
        }
        selectMenu();
        cout<<"Masukkan menu: ";cin>>pilihan; cout<<endl;
    }
    cout<<"Program selesai"<<endl;cout<<endl;
    ///////// END OF PROGRAM ///////////
    return 0;
}
