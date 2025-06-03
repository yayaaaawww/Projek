#include <iostream>
#include <conio.h>
#include <iomanip>
#include <fstream>
using namespace std;


struct pengguna
{
    int ID;
    string username;
    string password;
};

struct Mobil
{
    string merek;
    string tipe;
    int tahun;
    int kapasitas;
    int hargaPerHari;
    bool tersedia;
};

struct Riwayat
{
    string username;
    string merek;
    string tipe;
    int lamaSewa;
    int totalHarga;
};

pengguna *login = new pengguna[100];
Mobil *mobil = new Mobil[30]{
    {"BMW", "X5", 2023, 7, 1500000, false},
    {"BMW", "320i", 2022, 5, 1200000, true},
    {"BMW", "530i", 2021, 5, 1350000, false},
    {"BMW", "M3", 2023, 5, 2000000, false},
    {"BMW", "X7", 2023, 7, 2500000, false},

    {"Hyundai", "Tucson", 2023, 5, 1000000, true},
    {"Hyundai", "Elantra", 2021, 5, 800000, true},
    {"Hyundai", "Santa Fe", 2022, 7, 950000, false},
    {"Hyundai", "Palisade", 2023, 8, 1200000, false},
    {"Hyundai", "Ioniq 5", 2023, 5, 1500000, true},

    {"Ferrari", "488 GTB", 2022, 2, 5000000, true},
    {"Ferrari", "Portofino", 2023, 2, 6000000, true},
    {"Ferrari", "F8 Tributo", 2023, 2, 7000000, false},
    {"Ferrari", "Roma", 2023, 2, 6500000, false},
    {"Ferrari", "SF90 Stradale", 2023, 2, 8000000, true},

    {"Toyota", "Fortuner", 2022, 7, 1200000, true},
    {"Toyota", "Camry", 2021, 5, 1000000, true},
    {"Toyota", "Avanza", 2020, 7, 600000, true},
    {"Toyota", "Innova Zenix", 2023, 7, 1300000, true},
    {"Toyota", "Supra", 2022, 2, 2500000, false},

    {"Honda", "Civic RS", 2022, 5, 1100000, true},
    {"Honda", "CR-V", 2023, 7, 1200000, true},
    {"Honda", "Brio", 2021, 5, 500000, true},
    {"Honda", "HR-V", 2022, 5, 900000, true},
    {"Honda", "Accord", 2023, 5, 1400000, false},

    {"Mercedes", "A-Class", 2022, 4, 2000000, true},
    {"Mercedes", "C-Class", 2023, 5, 2200000, true},
    {"Mercedes", "E-Class", 2023, 6, 2500000, true},
    {"Mercedes", "S-Class", 2022, 5, 3000000, false},
    {"Mercedes", "GLS", 2023, 7, 3500000, true}};
Riwayat *riwayat = new Riwayat[100];

int jumlahPengguna = 0, jumlahRiwayat = 0;
string penggunaAktif;

void menuLogin();
void menu();
void simpanAkunKeFile();
void muatAkunDariFile();
void simpanRiwayat();
void muatRiwayat();

void tampil(int indeks)
{
    if (indeks >= 30)
        return;
    cout << "|" << setw(3) << indeks + 1 << "   |  " << setw(15) << left << mobil[indeks].merek
         << "  |  " << setw(15) << left << mobil[indeks].tipe
         << "  |  " << setw(10) << mobil[indeks].tahun << " |" << endl;
    tampil(indeks + 1);
}

void tampilkanSemuaMobil(Mobil arr[], int jumlah)
{
    cout << "======================================================================================" << endl;
    cout << "| Kode |       Merek       |        Tipe       |    Tahun   | Kapasitas |   Harga   |" << endl;
    cout << "======================================================================================" << endl;
    for (int i = 0; i < jumlah; i++)
    {
        cout << "|" << setw(5) << i + 1 << " | " << setw(17) << left << arr[i].merek
             << "| " << setw(17) << left << arr[i].tipe
             << "| " << setw(10) << arr[i].tahun
             << "| " << setw(10) << arr[i].kapasitas
             << "| " << setw(9) << arr[i].hargaPerHari << "|" << endl;
    }
    cout << "======================================================================================" << endl;
}

void katalog()
{
    system("cls");
    cout << "\t\t-----KATALOG MOBIL-----" << endl << endl;

    tampilkanSemuaMobil(mobil, 30);

    int pilihan;
    cout << "\nIngin mengurutkan berdasarkan:\n";
    cout << "1. Harga (termurah ke termahal)\n";
    cout << "2. Kapasitas (terkecil ke terbesar)\n";
    cout << "3. Kembali ke menu\n";
    cout << "Pilihan Anda: ";
    cin >> pilihan;

    if (pilihan == 3)
    {
        menu();
        return;
    }

    Mobil mobilCopy[30];
    for (int i = 0; i < 30; i++)
        mobilCopy[i] = mobil[i];

    if (pilihan == 1)
    {
        for (int i = 0; i < 29; i++)
        {
            for (int j = i + 1; j < 30; j++)
            {
                if (mobilCopy[i].hargaPerHari > mobilCopy[j].hargaPerHari)
                    swap(mobilCopy[i], mobilCopy[j]);
            }
        }
    }
    else if (pilihan == 2)
    {
        for (int i = 0; i < 29; i++)
        {
            for (int j = i + 1; j < 30; j++)
            {
                if (mobilCopy[i].kapasitas > mobilCopy[j].kapasitas)
                    swap(mobilCopy[i], mobilCopy[j]);
            }
        }
    }
    else
    {
        cout << "Pilihan tidak valid.\n";
        system("pause");
        menu();
        return;
    }

    system("cls");
    cout << "\t\t-----KATALOG (TERURUT)-----" << endl << endl;
    tampilkanSemuaMobil(mobilCopy, 30);

    cin.ignore();
    cin.get();
    menu();
}

void sewa()
{
    system("cls");
    cout << "\t-----SEWA MOBIL-----" << endl;

    string merkPilihan;
    cout << "Masukkan merk mobil yang ingin disewa (BMW/Hyundai/Ferrari/Toyota/Honda/Mercedes): ";
    cin.ignore(); 
    getline(cin, merkPilihan);
    
    

    bool foundMerk = false;
    for (int i = 0; i < 35; ++i)
    {
        if (mobil[i].merek == merkPilihan && mobil[i].tersedia)
        {
            cout << "Mobil ke " << i + 1 << endl;
            cout << "Merek          : " << mobil[i].merek << endl;
            cout << "Tipe           : " << mobil[i].tipe << endl;
            cout << "Tahun          : " << mobil[i].tahun << endl;
            cout << "Kapasitas maks : " << mobil[i].kapasitas << " Orang " << endl;
            cout << "Harga Per Hari : " << mobil[i].hargaPerHari << endl;
            cout << "Ketersediaan   : Tersedia" << endl << endl;
            foundMerk = true;
        }
    }

    if (!foundMerk)
    {
        cout << "Tidak ada mobil tersedia untuk merk tersebut." << endl;
        system("pause");
        return;
    }

    string tipePilihan;
    cout << "Masukkan tipe mobil yang ingin disewa: ";
    getline(cin, tipePilihan);

    for (int i = 0; i < 35; i++)
    {
        if (mobil[i].merek == merkPilihan && mobil[i].tipe == tipePilihan && mobil[i].tersedia)
        {
            int lamaSewa;
            cout << "Berapa hari ingin menyewa mobil ini? ";
            cin >> lamaSewa;

            int total = lamaSewa * mobil[i].hargaPerHari;

            char konfirmasi;
            cout << "\nTotal biaya sewa adalah Rp. " << total << endl;
            cout << "Lanjut ke pembayaran? (y/n): ";
            cin >> konfirmasi;

            if (konfirmasi == 'y' || konfirmasi == 'Y') {
                mobil[i].tersedia = false;

                riwayat[jumlahRiwayat++] = {penggunaAktif, mobil[i].merek, mobil[i].tipe, lamaSewa, total};
                simpanRiwayat();

                cout << "\n====== RESI SEWA MOBIL ======" << endl;
                cout << "Nama Penyewa   : " << penggunaAktif << endl;
                cout << "Merek Mobil    : " << mobil[i].merek << endl;
                cout << "Tipe Mobil     : " << mobil[i].tipe << endl;
                cout << "Lama Sewa      : " << lamaSewa << " hari" << endl;
                cout << "Harga per Hari : " << mobil[i].hargaPerHari << endl;
                cout << "Total Bayar    : Rp. " << total << endl;
                cout << "Status         : Berhasil disewa" << endl;
                cout << "==============================\n" << endl;
            } else {
                cout << "\nPemesanan dibatalkan oleh pengguna.\n";
            }

            system("pause");
            return;
        }
    }

    cout << "Mobil tidak ditemukan atau tidak tersedia." << endl;
    system("pause");
}


void lihatHistori()
{
    system("cls");
    cout << "\t-----HISTORI PEMESANAN-----\n"
         << endl;
    bool ada = false;
    for (int i = 0; i < jumlahRiwayat; i++)
    {
        if (riwayat[i].username == penggunaAktif)
        {
            cout << "Pemesanan ke-" << i + 1 << endl;
            cout << "Mobil : " << riwayat[i].merek << " " << riwayat[i].tipe << endl;
            cout << "Lama Sewa : " << riwayat[i].lamaSewa << " hari" << endl;
            cout << "Total Harga : Rp. " << riwayat[i].totalHarga << endl
                 << endl;
            ada = true;
        }
    }
    if (!ada)
        cout << "Belum ada histori pemesanan.\n";
    system("pause");
}

void menu()
{
    int pilih;
    system("cls");
    cout << "\t\t\t-----CAR RENTAL-----" << endl
         << endl;
    cout << "MENU UTAMA" << endl;
    cout << "1. Lihat Katalog\n2. Sewa Mobil\n3. Histori Pemesanan\n4. Keluar" << endl;
    cout << "Pilih : ";
    cin >> pilih;
    switch (pilih)
    {
    case 1:
        katalog();
        break;
    case 2:
        sewa();
        break;
    case 3:
        lihatHistori();
        break;
    case 4:
        exit(0);
    default:
        cout << "Pilihan tidak tersedia!" << endl;
        break;
    }
    menu();
}

bool ceklogin(string user, string pass)
{
    for (int i = 0; i < jumlahPengguna; i++)
    {
        if (login[i].username == user && login[i].password == pass)
            return true;
    }
    return false;
}

void loginy()
{
    string user, pass;
    cin.ignore();
    int percobaan = 3;
    do
    {
        system("cls");
        if (jumlahPengguna != 0)
        {
            cout << "\t\tLAMAN LOGIN\t\t" << endl;
            cout << "Masukkan Username: ";
            getline(cin, user);
            cout << "Masukkan Password: ";
            getline(cin, pass);
            if (ceklogin(user, pass))
            {
                penggunaAktif = user;
                cout << "Anda berhasil login" << endl;
                system("pause");
                menu();
                return;
            }
            else
            {
                percobaan--;
                if (percobaan > 0)
                {
                    cout << "Username atau Password salah! Sisa percobaan: " << percobaan << endl;
                    system("pause");
                }
                else
                {
                    cout << "Anda telah gagal login 3 kali!" << endl;
                    system("pause");
                    exit(0);
                }
            }
        }
        else
        {
            cout << "Akun tidak ditemukan! Harap Sign Up!" << endl;
            system("pause");
            menuLogin();
        }
    } while (percobaan > 0);
}

void signup()
{
    system("cls");
    cout << "\t\tLAMAN SIGN UP\t\t" << endl;
    cin.ignore();
    cout << "Masukkan Username: ";
    getline(cin, login[jumlahPengguna].username);
    cout << "Masukkan Password: ";
    getline(cin, login[jumlahPengguna].password);
    jumlahPengguna++;
    simpanAkunKeFile();
    menuLogin();
}

void menuLogin()
{
    int pilih;
    system("cls");
    cout << "\t\t\t----CAR RENTAL-----" << endl
         << endl;
    cout << "note: Jika belum punya akun harap Sign Up dahulu!" << endl;
    cout << "1. SIGN UP \n2. LOGIN" << endl;
    cout << "pilih: ";
    cin >> pilih;
    switch (pilih)
    {
    case 1:
        signup();
        break;
    case 2:
        loginy();
        break;
    default:
        cout << "\nPilihan tidak tersedia! Anda keluar dari program" << endl;
        system("pause");
        exit(0);
    }
}

void simpanAkunKeFile()
{
    ofstream out("pengguna.txt");
    for (int i = 0; i < jumlahPengguna; ++i)
    {
        out << login[i].username << "|" << login[i].password << "\n";
    }
    out.close();
}

void muatAkunDariFile()
{
    ifstream in("pengguna.txt");
    string user, pass;
    while (getline(in, user, '|') && getline(in, pass))
    {
        login[jumlahPengguna].username = user;
        login[jumlahPengguna].password = pass;
        jumlahPengguna++;
    }
    in.close();
}

void simpanRiwayat()
{
    ofstream out("riwayat.txt");
    for (int i = 0; i < jumlahRiwayat; ++i)
    {
        out << riwayat[i].username << "|" << riwayat[i].merek << "|"
            << riwayat[i].tipe << "|" << riwayat[i].lamaSewa << "|"
            << riwayat[i].totalHarga << "\n";
    }
    out.close();
}

void muatRiwayat()
{
    ifstream in("riwayat.txt");
    while (getline(in, riwayat[jumlahRiwayat].username, '|') &&
           getline(in, riwayat[jumlahRiwayat].merek, '|') &&
           getline(in, riwayat[jumlahRiwayat].tipe, '|'))
    {
        in >> riwayat[jumlahRiwayat].lamaSewa;
        in.ignore(1);
        in >> riwayat[jumlahRiwayat].totalHarga;
        in.ignore();
        jumlahRiwayat++;
    }
    in.close();
}

int main()
{
    muatAkunDariFile();
    muatRiwayat();
    menuLogin();
    return 0;
}