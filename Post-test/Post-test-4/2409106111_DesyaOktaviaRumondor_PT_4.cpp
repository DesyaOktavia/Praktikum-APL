#include <iostream>
#include <string>

using namespace std;

#define MAX_PRODUK 250

struct Produk {
    string Nama;
    int Stok;
    double Harga;
};

struct Toko {
    Produk DaftarProduk[MAX_PRODUK];
    int JumlahSabun;
};

// Function prototypes
int login(bool& isAdmin, int attempts = 0);
int menuAdmin(Toko& toko);
int menuKasir(Toko& toko);
int tambahProduk(Toko& toko, int index = 0);
string lihatProduk(const Toko& toko, int index = 0);
int updateProduk(Toko& toko, const string& nama, double harga = 0, int stok = 0);
int updateProduk(Toko& toko); // Overloaded function
int hapusProduk(Toko& toko, const string& nama);
int displayMenu(bool isAdmin);

// Recursive function to display all products
string displayAllProducts(const Toko& toko, int index) {
    if (index >= toko.JumlahSabun) {
        return "";
    }
    string result = "Nama: " + toko.DaftarProduk[index].Nama + 
                   ", Harga: " + to_string(toko.DaftarProduk[index].Harga) + 
                   ", Stok: " + to_string(toko.DaftarProduk[index].Stok) + "\n";
    return result + displayAllProducts(toko, index + 1);
}

int main() {
    Toko toko;
    toko.JumlahSabun = 0;
    bool isAdmin = false;
    int loginAttempts = 0;

    while (true) {
        loginAttempts = login(isAdmin, loginAttempts);
        if (loginAttempts >= 3) {
            cout << "Anda telah mencoba login sebanyak 3 kali. Program telah berhenti!" << endl;
            return 0;
        }
        if (loginAttempts == -1) { // Successful login
            loginAttempts = 0;
            if (isAdmin) {
                if (menuAdmin(toko) == 6) {
                    return 0;
                }
            } else {
                if (menuKasir(toko) == 4) {
                    return 0;
                }
            }
        }
    }
    return 0;
}

int login(bool& isAdmin, int attempts) {
    string akun, username, password;

    cout << "\nLogin sebagai (admin/kasir): ";
    cin >> akun;
    cout << "Silahkan Masukkan Username Anda: ";
    cin >> username;
    cout << "Silahkan Masukkan Password Anda: ";
    cin >> password;

    if (akun == "admin" && username == "DesyaOktaviaRumondor" && password == "111") {
        isAdmin = true;
        cout << "Anda Berhasil Login Sebagai Admin\n" << endl;
        return -1; // Success code
    } else if (akun == "kasir" && password == "111") {
        isAdmin = false;
        cout << "Anda Berhasil Login Sebagai Kasir\n" << endl;
        return -1; // Success code
    }
    
    cout << "Harap anda masukkan akun anda dengan benar!" << endl;
    return attempts + 1;
}

int menuAdmin(Toko& toko) {
    while (true) {
        int choice = displayMenu(true);
        
        switch (choice) {
            case 1: 
                tambahProduk(toko);
                break;
            case 2: 
                cout << "\n=== Daftar Produk ===\n" << displayAllProducts(toko, 0);
                break;
            case 3: 
                updateProduk(toko);
                break;
            case 4: {
                string nama;
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin.ignore();
                getline(cin, nama);
                hapusProduk(toko, nama);
                break;
            }
            case 5: 
                cout << "Keluar dari menu admin." << endl;
                return 0;
            case 6: 
                cout << "Anda telah keluar dari program, terimakasih" << endl;
                return 6;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }
}

int menuKasir(Toko& toko) {
    while (true) {
        int choice = displayMenu(false);
        
        switch (choice) {
            case 1: 
                cout << "\n=== Daftar Produk ===\n" << displayAllProducts(toko, 0);
                break;
            case 2: 
                updateProduk(toko);
                break;
            case 3: 
                cout << "Keluar dari menu kasir." << endl;
                return 0;
            case 4: 
                cout << "Anda telah keluar dari program, terimakasih" << endl;
                return 4;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }
}

int displayMenu(bool isAdmin) {
    if (isAdmin) {
        cout << "======================================" << endl;
        cout << "|              Menu Admin            |" << endl;
        cout << "======================================" << endl;
        cout << "| 1   | Tambah Produk                |" << endl;
        cout << "| 2   | Lihat Produk                 |" << endl;
        cout << "| 3   | Update Produk                |" << endl;
        cout << "| 4   | Hapus Produk                 |" << endl;
        cout << "| 5   | Keluar                       |" << endl;
        cout << "| 6   | Keluar dari Program          |" << endl;
        cout << "======================================" << endl;
    } else {
        cout << "======================================" << endl;
        cout << "|             Menu Kasir             |" << endl;
        cout << "======================================" << endl;
        cout << "| 1   | Lihat Produk                 |" << endl;
        cout << "| 2   | Update Produk                |" << endl;
        cout << "| 3   | Keluar                       |" << endl;
        cout << "| 4   | Keluar dari Program          |" << endl;
        cout << "======================================" << endl;
    }

    int Opsi;
    cout << "Pilih menu: ";
    cin >> Opsi;
    return Opsi;
}

int tambahProduk(Toko& toko, int index) {
    if (toko.JumlahSabun >= MAX_PRODUK) {
        cout << "Maaf, Stok Penyimpanan Produk Sudah Penuh!" << endl;
        return -1;
    }
    
    if (index == 0) {
        cout << "Silahkan Masukkan Nama Sabun: ";
        cin.ignore();
        getline(cin, toko.DaftarProduk[toko.JumlahSabun].Nama);
        cout << "Tetapkan untuk harga produk: ";
        cin >> toko.DaftarProduk[toko.JumlahSabun].Harga;
        cout << "Masukkan Jumlah Stok Sabun: ";
        cin >> toko.DaftarProduk[toko.JumlahSabun].Stok;
        toko.JumlahSabun++;
        cout << "Produk Telah berhasil ditambahkan!" << endl;
        return 1;
    }
    return 0;
}

string lihatProduk(const Toko& toko, int index) {
    if (index >= toko.JumlahSabun) {
        return "";
    }
    return "Nama: " + toko.DaftarProduk[index].Nama + 
           ", Harga: " + to_string(toko.DaftarProduk[index].Harga) + 
           ", Stok: " + to_string(toko.DaftarProduk[index].Stok) + "\n" + 
           lihatProduk(toko, index + 1);
}

int updateProduk(Toko& toko) {
    string nama;
    cout << "Silahkan Masukkan Nama Produk Yang Diupdate: ";
    cin.ignore();
    getline(cin, nama);
    
    double harga;
    int stok;
    cout << "Silahkan Masukkan Harga Baru: ";
    cin >> harga;
    cout << "Masukkan Jumlah Stok Baru: ";
    cin >> stok;
    
    return updateProduk(toko, nama, harga, stok);
}

int updateProduk(Toko& toko, const string& nama, double harga, int stok) {
    for (int i = 0; i < toko.JumlahSabun; i++) {
        if (toko.DaftarProduk[i].Nama == nama) {
            toko.DaftarProduk[i].Harga = harga;
            toko.DaftarProduk[i].Stok = stok;
            cout << "Produk Telah Berhasil Diupdate!" << endl;
            return 1;
        }
    }
    cout << "Maaf, Produk Tidak Ditemukan!" << endl;
    return 0;
}

int hapusProduk(Toko& toko, const string& nama) {
    for (int i = 0; i < toko.JumlahSabun; i++) {
        if (toko.DaftarProduk[i].Nama == nama) {
            for (int j = i; j < toko.JumlahSabun - 1; j++) {
                toko.DaftarProduk[j] = toko.DaftarProduk[j + 1];
            }
            toko.JumlahSabun--;
            cout << "Produk berhasil dihapus!" << endl;
            return 1;
        }
    }
    cout << "Produk tidak ditemukan!" << endl;
    return 0;
}