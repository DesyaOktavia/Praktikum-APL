#include <iostream>
using namespace std;

bool IsPrima(int angka) {
    if (angka < 2) return false;
    for (int i = 2; i * i <= angka; i++) {
        if (angka % i == 0) return false;
    }
    return true;
}

bool IsDivisible(int num) {
    return (num % 2 == 0 && num % 3 == 0 && num % 5 != 0);
}

int main() {
    string username, inputnama;
    string password, inputpassword;
    
    username = "Desya Oktavia Rumondor";
    password = "2409106111";
    
    cout << "Menu Login" << endl;
    cout << "Username: ";
    getline(cin, inputnama);
    cout << "Password: ";
    cin >> inputpassword;
    
    if (inputnama != username || inputpassword != password) {
        cout << "Password atau nama anda salah, silahkan coba lagi";
        return 0;
    }
    
    int kode;
    do {
        cout << "Masukkan kode sandi (bilangan bulat positif): ";
        cin >> kode;
        
        if (kode < 100 || kode > 99999) {
            cout << "Kode sandi harus kurang dari 100 dan tidak boleh lebih dari 99999! Coba lagi.";
        }
    } while (kode < 100 || kode > 99999);
    
    int pilihan;
    do {
        cout << "\n Menu Veritifikasi Kode Sandi" << endl;
        cout << "1. Cek verifikasi kode sandi bilangan prima" << endl;
        cout << "2. Cek verifikasi kode sandi habis dibagi 2 dan 3 tetapi tidak habis dibagi 5" << endl;
        cout << "3. Keluar program" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                if (IsPrima(kode))
                    cout << "Kode sandi termasuk bilangan prima" << endl;
                else
                    cout << "Kode sandi bukan termasuk bilangan prima" << endl;
                break;
            case 2:
                if (IsDivisible(kode))
                    cout << "Kode sandi valid dengan aturan pembagian" << endl;
                else
                    cout << "Kode sandi tidak valid dengan aturan pembagian" << endl;
                break;
            case 3:
                cout << "Program telah berhenti" << endl;
                break;
            default:
                cout << "Pilihan tidak valid! Silakan pilih kembali" << endl;
        }
    } while (pilihan != 3);
    
    return 0;
}