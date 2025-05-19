#include <iostream>
using namespace std;

class Mahasiswa {
    private:
        static int totalMahasiswa;
    public:
        string nama;
        string status;
        int umur;
    
        Mahasiswa(string pnama, int pumur) {
            nama = pnama;
            umur = pumur;
            status = "New Student";
            totalMahasiswa++;
            cout << nama << " Created " << endl;
            cout << endl;
        }
        ~Mahasiswa() {
            cout << nama << " Destroyed " << endl;
            --totalMahasiswa;
            cout << endl;
        }

        static int getTotalMahasiswa() {
            return totalMahasiswa;
        }

        static void setTotalMahasiswa(int value) {
            totalMahasiswa = value;
        }
};

int Mahasiswa::totalMahasiswa = 0;

int main() {
    
    cout << "Total Mahasiswa: " << Mahasiswa::getTotalMahasiswa() << endl;

    Mahasiswa mhs1("Maman", 40);
    Mahasiswa mhs2("Agus", 34);

    Mahasiswa::setTotalMahasiswa(10);

    cout << "Total Mahasiswa: " << Mahasiswa::getTotalMahasiswa() << endl;
    {
         Mahasiswa mhs3("Budi", 19);
         Mahasiswa mhs4("Caca", 21);
         cout << "Total Mahasiswa: " << Mahasiswa::getTotalMahasiswa() << endl;
    } 

    cout << "Total Mahasiswa: " << Mahasiswa::getTotalMahasiswa() << endl;

    return 0;
}