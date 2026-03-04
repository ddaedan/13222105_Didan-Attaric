#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>  // Pustaka fungsi matematika (std::sqrt)
#include <string> // Pustaka string untuk membaca teks header

// 1. Blueprint Objek
class Partikel
{
private:
    double x, y;
    double jarak_pusat;

public:
    Partikel(double pos_x, double pos_y)
    {
        x = pos_x;
        y = pos_y;
        jarak_pusat = 0.0;
    }

    // Fungsi hitung jarak
    void hitungJarak()
    {
        // jarak_pusat = std::sqrt((x * x) + (y * y));
        double x_temp = x - 5.0;
        double y_temp = y - 5.0;
        jarak_pusat = std::sqrt((x_temp * x_temp) + (y_temp * y_temp));
    }

    // Dua tipe koordinat yang bisa dibaca:
    // koordinat x  = {0}
    // koordinat y  = {1}
    // nilai 0      = default
    double tampilkanPosisi(int tipe_koordinar)
    {
        switch (tipe_koordinar)
        {
        case (0):
            return x;
        case (1):
            return y;
        default:
            return 0;
        }
    }

    double tampilkanJarakPusat()
    {
        return jarak_pusat;
    }
};

int main()
{
    // A. FASE I/O BACA
    std::vector<Partikel> kumpulan_partikel;
    std::ifstream fileBaca("koordinat_mentah.txt");

    std::string header1, header2; // Variabel sementara penampung teks
    double temp_x, temp_y;

    if (fileBaca.is_open())
    {

        fileBaca >> header1 >> header2;

        while (fileBaca >> temp_x >> temp_y)
        {
            kumpulan_partikel.push_back(Partikel(temp_x, temp_y));
        }
        fileBaca.close();
    }
    else
    {
        std::cout << "Gagal! Pastikan file koordinat_mentah.txt sudah Anda buat." << std::endl;
        return 1; // Menghentikan program jika file tidak ada
    }

    // B. FASE KOMPUTASI (Batch Processing)
    // Di sinilah pragma paralel seperti OpenMP nantinya
    for (int i = 0; i < kumpulan_partikel.size(); i++)
    {
        kumpulan_partikel[i].hitungJarak();
    }

    // C. FASE I/O TULIS
    std::ofstream fileHasil("hasil_jarak.txt");
    if (fileHasil.is_open())
    {
        for (int i = 0; i < kumpulan_partikel.size(); i++)
        {
            fileHasil << "Partikel " << i + 1
                      << " | Posisi: (" << kumpulan_partikel[i].tampilkanPosisi(0) << ", " << kumpulan_partikel[i].tampilkanPosisi(1) << ") "
                      << "| Jarak: " << kumpulan_partikel[i].tampilkanJarakPusat() << "\n";
        }
        fileHasil.close();
        std::cout << "=> Selesai! Buka file 'hasil_jarak.txt' untuk melihat kalkulasinya." << std::endl;
    }

    return 0;
}