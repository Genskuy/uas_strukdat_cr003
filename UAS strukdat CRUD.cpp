#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Buku {
    int id;
    string judul;
    string penulis;
};

vector<Buku> perpustakaan;

void tambahBuku() {
    Buku buku;
    cout << "Masukkan ID buku: ";
    cin >> buku.id;
    cout << "Masukkan judul buku: ";
    cin.ignore();
    getline(cin, buku.judul);
    cout << "Masukkan penulis buku: ";
    getline(cin, buku.penulis);

    perpustakaan.push_back(buku);
    cout << "Buku berhasil ditambahkan!" << endl;
}

void tampilkanBuku() {
    if (perpustakaan.empty()) {
        cout << "Perpustakaan kosong." << endl;
        return;
    }

    cout << "Daftar buku:" << endl;
    for (const auto& buku : perpustakaan) {
        cout << "ID: " << buku.id << ", Judul: " << buku.judul << ", Penulis: " << buku.penulis << endl;
    }
}

void updateBuku() {
    int id;
    cout << "Masukkan ID buku yang ingin diupdate: ";
    cin >> id;

    for (auto& buku : perpustakaan) {
        if (buku.id == id) {
            cout << "Masukkan judul buku baru: ";
            cin.ignore();
            getline(cin, buku.judul);
            cout << "Masukkan penulis buku baru: ";
            getline(cin, buku.penulis);
            cout << "Buku berhasil diupdate!" << endl;
            return;
        }
    }

    cout << "Buku dengan ID tersebut tidak ditemukan." << endl;
}

void hapusBuku() {
    int id;
    cout << "Masukkan ID buku yang ingin dihapus: ";
    cin >> id;

    for (auto it = perpustakaan.begin(); it != perpustakaan.end(); ++it) {
        if (it->id == id) {
            perpustakaan.erase(it);
            cout << "Buku berhasil dihapus!" << endl;
            return;
        }
    }

    cout << "Buku dengan ID tersebut tidak ditemukan." << endl;
}

int main() {
    int pilihan;
    string role;

    do {
        cout << "Masukkan peran Anda (admin/user) atau 0 untuk keluar: ";
        cin >> role;

        if (role == "admin") {
            do {
                cout << "Menu Perpustakaan (Admin)" << endl;
                cout << "1. Tambah Buku" << endl;
                cout << "2. Tampilkan Buku" << endl;
                cout << "3. Update Buku" << endl;
                cout << "4. Hapus Buku" << endl;
                cout << "0. Keluar" << endl;
                cout << "Pilihan Anda: ";
                cin >> pilihan;

                switch (pilihan) {
                    case 1:
                        tambahBuku();
                        break;
                    case 2:
                        tampilkanBuku();
                        break;
                    case 3:
                        updateBuku();
                        break;
                    case 4:
                        hapusBuku();
                        break;
                    case 0:
                        cout << "Terima kasih!" << endl;
                        break;
                    default:
                        cout << "Pilihan tidak valid." << endl;
                        break;
                }

                cout << endl;
            } while (pilihan != 0);
        } else if (role == "user") {
            do {
                cout << "Menu Perpustakaan (User)" << endl;
                cout << "1. Tampilkan Buku" << endl;
                cout << "0. Keluar" << endl;
                cout << "Pilihan Anda: ";
                cin >> pilihan;

                switch (pilihan) {
                    case 1:
                        tampilkanBuku();
                        break;
                    case 0:
                        cout << "Terima kasih!" << endl;
                        break;
                    default:
                        cout << "Pilihan tidak valid." << endl;
                        break;
                }

                cout << endl;
            } while (pilihan != 0);
        } else if (role != "0") {
            cout << "Peran tidak valid." << endl;
        }
    } while (role != "0");

    return 0;
}
