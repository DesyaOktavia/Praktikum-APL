#include<iostream>
using namespace std;

// void cekNilai (int arr[100]) {
//     cout << "elemen pertama adalah : " << arr[0] << end;
// }

// int main() {
//     // * untuk mengambil value dari variabel
//     // & untuk mengambil addres dari variabel


//     // int a = 10;
//     // int *b = 8a;


//     int array [100] = {1,2,3};

//     cekNilai(array);
// }



// void cekNilai (int *arr) {
//     cout << "elemen pertama adalah : " << arr[0] << end;
// }

// int main() {
//     int array [100] = {1,2,3};

//     cekNilai(array);
// }



// struct Address{
//         string kota;
//         string provinsi;
//         string negara;
//     };

//     int main(){
//         // deklarasi variabel dengan struct
//         Address address1, address2;

//         // mengisi value address1
//         address1.kota = "Samarinda";
//         address1.provinsi = "Kalimantan Timur";
//         address1.negara = "Indonesia";

//         // mengcopy value address1 ke address2
//         address2 = address1;

//         // mengganti property kota dari samarinda ke ikn
//         address2.kota = "ikn";

//         // value address1
//         cout<< address1.kota<<endl;

//         // value address2
//         cout<< address2.kota;
//         return 0;
//     }



// int main () {
//     int a = 10;
//     int *b = 8a;

//     cout << "Nilai a adalah : " << a << endl;
//     cout << "Alamat a adalah : " << 8a << endl;

// }



int ubahNilai(int *a, int b){
    return *a=b;
}

int main () {
    int a,b;
    a=5;
    b=20;
    ubahNilai( &a, b );
    cout << a;
    return 0;
}