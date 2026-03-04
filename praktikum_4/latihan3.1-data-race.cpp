#include <iostream>
#include <vector>

int main()
{
    std::vector<int> data = {10, 20, 30, 40};
    int total; // <-- TARGET BENTROKAN (DATA RACE)
    /*
    Asumsi instruksi eksplorasi maksudnya instansiasi
    total = 0 dimasukkan ke dalam for loop
    */

    // Simulasi: Jika 4 Core berebut mengubah variabel 'total' bersamaan
    // Ditambahkan notasi #pragma untuk akses memory bersama
    // #pragma omp parallel for
    for (int i = 0; i < data.size(); i++)
    {
        int total = 0;
        total = total + data[i];
    }

    std::cout << "Total Akumulasi: " << total << std::endl;
    return 0;
}