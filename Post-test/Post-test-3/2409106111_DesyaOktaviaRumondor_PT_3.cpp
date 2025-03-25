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

            if (Admin) {
                if (Opsi == 1) {
                    if (toko.JumlahSabun < MAX_PRODUK) {   
                        cout << "Silahkan Masukkan Nama Sabun: ";
                        cin.ignore();
                        getline(cin, toko.DaftarProduk[toko.JumlahSabun].Nama);
                        cout << "Tetapkan untuk harga produk: ";
                        cin >> toko.DaftarProduk[toko.JumlahSabun].Harga;
                        cout << "Masukkan Jumlah Stok Sabun: ";
                        cin >> toko.DaftarProduk[toko.JumlahSabun].Stok;
                        toko.JumlahSabun++;
                        cout << "Produk Telah berhasil ditambahkan!" << endl;
                    } else {
                        cout << "Maaf, Stok Penyimpanan Produk Sudah Penuh!" << endl;
                    }

                } else if (Opsi == 2) {
                cout << "\n=== Daftar Produk ===" << endl;
                for (int i = 0; i < toko.JumlahSabun; i++) {
                    cout << "Nama: " << toko.DaftarProduk[i].Nama << ", Harga: " << toko.DaftarProduk[i].Harga << ", Stok: " << toko.DaftarProduk[i].Stok << endl;
                }

                } else if (Opsi == 3) {
                    string namasabun;
                    cout << "Silahkan Masukkan Nama Produk Yang Diupdate: ";
                    cin.ignore();
                    getline(cin, namasabun);

                    bool Update = false;
                    for (int i = 0; i < toko.JumlahSabun; i++) {
                        if (toko.DaftarProduk[i].Nama == namasabun) {
                            cout << "Silahkan Masukkan Harga Baru: ";
                            cin >> toko.DaftarProduk[i].Harga;
                            cout << "Masukkan Jumlah Stok Baru: ";
                            cin >> toko.DaftarProduk[i].Stok;
                            cout << "Produk Telah Berhasil Diupdate!" << endl;
                            Update = true;
                            break;
                        }
                    }
                    if (!Update) {
                        cout << "Maaf, Produk Tidak Ditemukan!" << endl;
                    }

                } else if (Opsi == 4) {
                    string namasabun;
                    cout << "Masukkan nama produk yang ingin dihapus: ";
                    cin.ignore();
                    getline(cin, namasabun);

                    bool Update = false;
                    for (int i = 0; i < toko.JumlahSabun; i++) {
                        if (toko.DaftarProduk[i].Nama == namasabun) {
                            for (int j = i; j < toko.JumlahSabun - 1; j++) {
                                toko.DaftarProduk[j] = toko.DaftarProduk[j + 1];
                            }
                            toko.JumlahSabun--;
                            cout << "Produk berhasil dihapus!" << endl;
                            Update = true;
                            break;
                        }
                    }
                    if (!Update) {
                        cout << "Produk tidak ditemukan!" << endl;
                    }

                } else if (Opsi == 5) {
                    cout << "Keluar dari menu admin." << endl;
                    break;
                } else if (Opsi == 6) {
                    cout << "Anda telah keluar dari program, terimakasih" << endl;
                    return 0;
                } else {
                    cout << "Pilihan tidak valid!" << endl;
                }

            } else {
                if (Opsi == 1) {
                    cout << "\n=== Daftar Produk ===" << endl;
                    for (int i = 0; i < toko.JumlahSabun; i++) {
                        cout << "Nama: " << toko.DaftarProduk[i].Nama << ", Harga: " << toko.DaftarProduk[i].Harga << ", Stok: " << toko.DaftarProduk[i].Stok << endl;
                    }

                } else if (Opsi == 2) {
                    string namasabun;
                    cout << "Silahkan Masukkan Nama Produk Yang Diupdate: ";
                    cin.ignore();
                    getline(cin, namasabun);

                    bool found = false;
                    for (int i = 0; i < toko.JumlahSabun; i++) {
                        if (toko.DaftarProduk[i].Nama == namasabun) {
                            cout << "Silahkan Masukkan Harga Baru: ";
                            cin >> toko.DaftarProduk[i].Harga;
                            cout << "Masukkan Jumlah Stok Baru: ";
                            cin >> toko.DaftarProduk[i].Stok;
                            cout << "Produk Telah Berhasil Diupdate!" << endl;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Maaf, Produk Tidak Ditemukan!" << endl;
                    }

                } else if (Opsi == 3) {
                    cout << "Keluar dari menu kasir." << endl;
                    break;
                } else if (Opsi == 4) {
                    cout << "Anda telah keluar dari program, terimakasih" << endl;
                    return 0;
                } else {
                    cout << "Pilihan tidak valid!" << endl;
                }
            }
        }
    }

    return 0;
}