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

void TambahProdukPointer(Toko* toko);
void UpdateHarga(Produk* produk);

void LihatProduk(const Toko &toko);
void LihatProduk(const Toko &toko, const string &namaProduk);
bool UpdateProduk(Toko &toko, const string &nama);
bool HapusProduk(Toko &toko, const string &nama);
void CetakProdukRekursif(const Toko &toko, int index);

int main() {
    Toko toko;
    toko.JumlahSabun = 0;
    int MasaPercobaan = 0;

    while (true) {
        string akun, username, password;
        bool Admin = false;

        cout << "\nLogin sebagai (admin/kasir): ";
        cin >> akun;
        cout << "Silahkan Masukkan Username Anda: ";
        cin >> username;
        cout << "Silahkan Masukkan Password Anda: ";
        cin >> password;

        if (akun == "admin" && username == "DesyaOktaviaRumondor" && password == "111") {
            Admin = true;
            cout << "Anda Berhasil Login Sebagai Admin\n" << endl;
            MasaPercobaan = 0;
        } else if (akun == "kasir" && password == "111") {
            Admin = false;
            cout << "Anda Berhasil Login Sebagai Kasir\n" << endl;
            MasaPercobaan = 0;
        } else {
            cout << "Harap anda masukkan akun anda dengan benar!" << endl;
            MasaPercobaan++;
            if (MasaPercobaan >= 3) {
                cout << "Anda telah mencoba login sebanyak 3 kali. Program telah berhenti!." << endl;
                return 0;
            }
            continue;
        }

        while (true) {
            if (Admin) {
                cout << "======================================" << endl;
                cout << "|              Menu Admin            |" << endl;
                cout << "======================================" << endl;
                cout << "| 1   | Tambah Produk                |" << endl;
                cout << "| 2   | Lihat Semua Produk           |" << endl;
                cout << "| 3   | Update Produk                |" << endl;
                cout << "| 4   | Hapus Produk                 |" << endl;
                cout << "| 5   | Lihat Produk (Filter Nama)   |" << endl;
                cout << "| 6   | Cetak Produk Rekursif        |" << endl;
                cout << "| 7   | Keluar dari Menu             |" << endl;
                cout << "| 8   | Keluar dari Program          |" << endl;
                cout << "======================================" << endl;
            } else {
                cout << "======================================" << endl;
                cout << "|             Menu Kasir             |" << endl;
                cout << "======================================" << endl;
                cout << "| 1   | Lihat Semua Produk           |" << endl;
                cout << "| 2   | Update Produk                |" << endl;
                cout << "| 3   | Lihat Produk (Filter Nama)   |" << endl;
                cout << "| 4   | Cetak Produk Rekursif        |" << endl;
                cout << "| 5   | Keluar dari Menu             |" << endl;
                cout << "| 6   | Keluar dari Program          |" << endl;
                cout << "======================================" << endl;
            }

            int Opsi;
            cout << "Pilih menu: ";
            cin >> Opsi;

            if (Admin) {
                switch (Opsi) {
                    case 1: TambahProdukPointer(&toko); break;
                    case 2: LihatProduk(toko); break;
                    case 3: {
                        string nama;
                        cin.ignore();
                        cout << "Masukkan Nama Produk yang Ingin Diupdate: ";
                        getline(cin, nama);
                        if (!UpdateProduk(toko, nama))
                            cout << "Produk tidak ditemukan.\n";
                        break;
                    }
                    case 4: {
                        string nama;
                        cin.ignore();
                        cout << "Masukkan Nama Produk yang Ingin Dihapus: ";
                        getline(cin, nama);
                        if (!HapusProduk(toko, nama))
                            cout << "Produk tidak ditemukan.\n";
                        break;
                    }
                    case 5: {
                        string nama;
                        cin.ignore();
                        cout << "Masukkan Nama Produk yang Ingin Dicari: ";
                        getline(cin, nama);
                        LihatProduk(toko, nama);
                        break;
                    }
                    case 6: {
                        cout << "\n=== Cetak Produk Rekursif ===\n";
                        CetakProdukRekursif(toko, 0);
                        break;
                    }
                    case 7: cout << "Keluar dari menu admin.\n"; break;
                    case 8: cout << "Keluar dari program.\n"; return 0;
                    default: cout << "Pilihan tidak valid!\n";
                }

                if (Opsi == 7) break;

            } else {
                switch (Opsi) {
                    case 1: LihatProduk(toko); break;
                    case 2: {
                        string nama;
                        cin.ignore();
                        cout << "Masukkan Nama Produk yang Ingin Diupdate: ";
                        getline(cin, nama);
                        if (!UpdateProduk(toko, nama))
                            cout << "Produk tidak ditemukan.\n";
                        break;
                    }
                    case 3: {
                        string nama;
                        cin.ignore();
                        cout << "Masukkan Nama Produk yang Ingin Dicari: ";
                        getline(cin, nama);
                        LihatProduk(toko, nama);
                        break;
                    }
                    case 4: {
                        cout << "\n=== Cetak Produk Rekursif ===\n";
                        CetakProdukRekursif(toko, 0);
                        break;
                    }
                    case 5: cout << "Keluar dari menu kasir.\n"; break;
                    case 6: cout << "Keluar dari program.\n"; return 0;
                    default: cout << "Pilihan tidak valid!\n";
                }

                if (Opsi == 5) break;
            }
        }
    }

    return 0;
}

void TambahProdukPointer(Toko* toko) {
    if (toko->JumlahSabun < MAX_PRODUK) {
        cout << "Silahkan Masukkan Nama Sabun: ";
        cin.ignore();
        getline(cin, toko->DaftarProduk[toko->JumlahSabun].Nama);
        cout << "Tetapkan untuk harga produk: ";
        cin >> toko->DaftarProduk[toko->JumlahSabun].Harga;
        cout << "Masukkan Jumlah Stok Sabun: ";
        cin >> toko->DaftarProduk[toko->JumlahSabun].Stok;
        toko->JumlahSabun++;
        cout << "Produk berhasil ditambahkan!\n";
    } else {
        cout << "Stok penuh!\n";
    }
}

void UpdateHarga(Produk* produk) {
    cout << "Masukkan Harga Baru: ";
    cin >> produk->Harga;
    cout << "Masukkan Stok Baru: ";
    cin >> produk->Stok;
    cout << "Produk berhasil diupdate!\n";
}

void LihatProduk(const Toko &toko) {
    cout << "\n=== Daftar Produk ===" << endl;
    for (int i = 0; i < toko.JumlahSabun; i++) {
        cout << "Nama: " << toko.DaftarProduk[i].Nama
             << ", Harga: " << toko.DaftarProduk[i].Harga
             << ", Stok: " << toko.DaftarProduk[i].Stok << endl;
    }
}

void LihatProduk(const Toko &toko, const string &namaProduk) {
    bool found = false;
    for (int i = 0; i < toko.JumlahSabun; i++) {
        if (toko.DaftarProduk[i].Nama == namaProduk) {
            cout << "Nama: " << toko.DaftarProduk[i].Nama
                 << ", Harga: " << toko.DaftarProduk[i].Harga
                 << ", Stok: " << toko.DaftarProduk[i].Stok << endl;
            found = true;
        }
    }
    if (!found) cout << "Produk tidak ditemukan.\n";
}

bool UpdateProduk(Toko &toko, const string &nama) {
    for (int i = 0; i < toko.JumlahSabun; i++) {
        if (toko.DaftarProduk[i].Nama == nama) {
            UpdateHarga(&toko.DaftarProduk[i]);
            return true;
        }
    }
    return false;
}

bool HapusProduk(Toko &toko, const string &nama) {
    for (int i = 0; i < toko.JumlahSabun; i++) {
        if (toko.DaftarProduk[i].Nama == nama) {
            for (int j = i; j < toko.JumlahSabun - 1; j++) {
                toko.DaftarProduk[j] = toko.DaftarProduk[j + 1];
            }
            toko.JumlahSabun--;
            cout << "Produk berhasil dihapus!\n";
            return true;
        }
    }
    return false;
}

void CetakProdukRekursif(const Toko &toko, int index) {
    if (index >= toko.JumlahSabun) return;
    cout << "Nama: " << toko.DaftarProduk[index].Nama
         << ", Harga: " << toko.DaftarProduk[index].Harga
         << ", Stok: " << toko.DaftarProduk[index].Stok << endl;
    CetakProdukRekursif(toko, index + 1);
}