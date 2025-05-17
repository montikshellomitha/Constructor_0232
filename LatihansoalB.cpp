#include <iostream>
#include <string>
using namespace std;

// Forward declaration
class Peminjam;
class Petugas;
class Admin;

class Buku {
private:
    string judul;
    string penulis;
    bool dipinjam;

public:
    Buku(string j, string p) : judul(j), penulis(p), dipinjam(false) {}

    friend class Petugas;
    friend void lihatStatistik(Admin*, Buku*, Peminjam*);
};

class Peminjam {
private:
    string nama;
    int ID;
    int totalPinjaman;

public:
    Peminjam(string n, int id) : nama(n), ID(id), totalPinjaman(0) {}

    friend class Petugas;
    friend void lihatStatistik(Admin*, Buku*, Peminjam*);
};

class Petugas {
private:
    string nama;
    int ID;
    string levelAkses;

public:
    Petugas(string n, int id, string level) : nama(n), ID(id), levelAkses(level) {}

    void prosesPinjam(Buku* b, Peminjam* p) {
        if (!b->dipinjam) {
            b->dipinjam = true;
            p->totalPinjaman++;
            cout << "Buku \"" << b->judul << "\" berhasil dipinjam oleh " << p->nama << endl;
        } else {
            cout << "Buku sudah dipinjam.\n";
        }
    }

    void prosesKembali(Buku* b, Peminjam* p) {
        if (b->dipinjam) {
            b->dipinjam = false;
            p->totalPinjaman--;
            cout << "Buku \"" << b->judul << "\" telah dikembalikan oleh " << p->nama << endl;
        } else {
            cout << "Buku belum dipinjam.\n";
        }
    }

    friend class Admin;
};

class Admin {
public:
    void aksesStatistik(Buku* b, Peminjam* p) {
        lihatStatistik(this, b, p);
    }
};

// Friend function
void lihatStatistik(Admin* a, Buku* b, Peminjam* p) {
    cout << "\n[Statistik untuk Admin]\n";
    cout << "Nama Peminjam  : " << p->nama << endl;
    cout << "Total Pinjaman : " << p->totalPinjaman << endl;
    cout << "Status Buku    : " << (b->dipinjam ? "Sedang Dipinjam" : "Tersedia") << endl;
    cout << "Judul Buku     : " << b->judul << "\n\n";
}

int main() {
    Buku* buku1 = new Buku("Struktur Data", "Budi Santoso");
    Peminjam* peminjam1 = new Peminjam("Rina", 101);
    Petugas* petugas1 = new Petugas("Dedi", 1, "operator");
    Admin* admin1 = new Admin();

    petugas1->prosesPinjam(buku1, peminjam1);
    admin1->aksesStatistik(buku1, peminjam1);

    petugas1->prosesKembali(buku1, peminjam1);
    admin1->aksesStatistik(buku1, peminjam1);

    delete buku1;
    delete peminjam1;
    delete petugas1;
    delete admin1;

    return 0;
}