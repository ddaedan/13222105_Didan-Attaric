#include <iostream>
#include <vector>
#include <fstream>

int main()
{
    // Inisialisasi
    std::vector<double> sensor;
    sensor.push_back(100.5);
    sensor.push_back(200.0);
    sensor.push_back(150.5);

    // Kalibrasi
    int temp_sensor_vector_size = sensor.size();
    for (int i = 0; i < temp_sensor_vector_size; i++)
    {
        sensor[i] = sensor[i] * 1.1;
    }

    // Penyimpanan ke file eksternal
    std::ofstream file_hasil_kalibrasi("hasil_kalibrasi.txt");

    if (file_hasil_kalibrasi.is_open())
    {
        // Ukuran jumlah sensor dihitung lagi biar nilainya sesuai sebelum dipakai lagi
        int temp_sensor_vector_size = sensor.size();
        for (int i = 0; i < temp_sensor_vector_size; i++)
        {
            file_hasil_kalibrasi << "Nilai sensor " << i + 1 << " | "
                                 << sensor[i] << "\n";
        }
        std::cout << "File hasil kalibrasi berhasil berhasil ditulis." << std::endl;
    }
    else
    {
        std::cout << "File hasil kalibrasi tidak berhasil ditulis!";
    }

    return 0;
}