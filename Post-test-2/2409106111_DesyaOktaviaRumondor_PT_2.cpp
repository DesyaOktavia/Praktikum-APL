#include <iostream>
#include <string>

using namespace std;

#define MAX_PRODUK 250

int main() {
    string NamaSabun[MAX_PRODUK];
    int Stok[MAX_PRODUK];
    double Harga[MAX_PRODUK];
    int JumlahSabun = 0;

    while (true) {
        string akun, username, password;
        bool Admin = false;

        cout << "Login sebagai (admin/kasir): ";
        cin >> akun;
        cout << "Silahkan Masukkan Username Anda: ";
        cin >> username;
        cout << "Silahkan Masukkan Password Anda: ";
        cin >> password;

        if (akun == "admin" && password == "02468") {
            Admin = true;
            cout << "Anda Berhasil Login Sebagai Admin\n" << endl;
        } else if (akun == "kasir" && password == "13579") {
            Admin = false;
            cout << "Anda Berhasil Login Sebagai Kasir\n" << endl;
        } else {
            cout << "akun atau password salah!" << endl;
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
                cout << "======================================" << endl;
            } else {
                cout << "======================================" << endl;
                cout << "|             Menu Kasir             |" << endl;
                cout << "======================================" << endl;
                cout << "| 1   | Lihat Produk                 |" << endl;
                cout << "| 2   | Update Produk                |" << endl;
                cout << "| 3   | Keluar                       |" << endl;
                cout << "======================================" << endl;
            }

            int Opsi;
            cout << "Pilih menu: ";
            cin >> Opsi;

            if (Admin) {
                if (Opsi == 1) {
                    if (JumlahSabun < MAX_PRODUK) {
                        cout << "Silahkan Masukkan Nama Sabun: ";
                        cin.ignore();
                        getline(cin, NamaSabun[JumlahSabun]);
                        cout << "Tetapkan untuk harga produk: ";
                        cin >> Harga[JumlahSabun];
                        cout << "Masukkan Jumlah Stok Sabun: ";
                        cin >> Stok[JumlahSabun];
                        JumlahSabun++;
                        cout << "Produk Telah berhasil ditambahkan!" << endl;
                    } else {
                        cout << "Maaf, Stok Penyimpanan Produk Sudah Penuh!" << endl;
                    }

                } else if (Opsi == 2) {
                    cout << "\n=== Daftar Produk ===" << endl;
                    for (int i = 0; i < JumlahSabun; i++) {
                        cout << "Nama: " << NamaSabun[i] << ", Harga: " << Harga[i] << ", Stok: " << Stok[i] << endl;
                    }

                } else if (Opsi == 3) {
                    string namasabun;
                    cout << "Silahkan Masukkan Nama Produk Yang Diupdate: ";
                    cin.ignore();
                    getline(cin, namasabun);

                    bool Update = false;
                    for (int i = 0; i < JumlahSabun; i++) {
                        if (NamaSabun[i] == namasabun) {
                            cout << "Silahkan Masukkan Harga Baru: ";
                            cin >> Harga[i];
                            cout << "Masukkan Jumlah Stok Baru: ";
                            cin >> Stok[i];
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
                    for (int i = 0; i < JumlahSabun; i++) {
                        if (NamaSabun[i] == namasabun) {
                            for (int j = i; j < JumlahSabun - 1; j++) {
                                NamaSabun[j] = NamaSabun[j + 1];
                                Harga[j] = Harga[j + 1];
                                Stok[j] = Stok[j + 1];
                            }
                            JumlahSabun--;
                            cout << "Produk berhasil dihapus!" << endl;
                            Update = true;
                            break;
                        }
                    }
                    if (!Update) {
                        cout << "Produk tidak ditemukan!" << endl;
                    }

                } else if (Opsi == 5) {
                    cout << "Keluar dari menu admin/kasir." << endl;
                    break;
                } else {
                    cout << "Pilihan tidak valid!" << endl;
                }

            } else {
                if (Opsi == 1) {
                    cout << "\n=== Daftar Produk ===" << endl;
                    for (int i = 0; i < JumlahSabun; i++) {
                        cout << "Nama: " << NamaSabun[i] << ", Harga: " << Harga[i] << ", Stok: " << Stok[i] << endl;
                    }

                } else if (Opsi == 2) {
                    string namasabun;
                    cout << "Silahkan Masukkan Nama Produk Yang Diupdate: ";
                    cin.ignore();
                    getline(cin, namasabun);

                    bool found = false;
                    for (int i = 0; i < JumlahSabun; i++) {
                        if (NamaSabun[i] == namasabun) {
                            cout << "Silahkan Masukkan Harga Baru: ";
                            cin >> Harga[i];
                            cout << "Masukkan Jumlah Stok Baru: ";
                            cin >> Stok[i];
                            cout << "Produk Telah Berhasil Diupdate!" << endl;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Maaf, Produk Tidak Ditemukan!" << endl;
                    }

                } else if (Opsi == 3) {
                    cout << "Keluar dari menu admin/kasir." << endl;
                    break;
                } else {
                    cout << "Pilihan tidak valid!" << endl;
                }
            }
        }
    }

    return 0;
}