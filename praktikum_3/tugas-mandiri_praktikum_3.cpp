#include <iostream>
#include <string>

class RekeningBank
{
private:
    double saldo;

public:
    RekeningBank(double saldo_awal);
    ~RekeningBank();
    void setor(double jumlah);
    void tarik(double jumlah);
};

RekeningBank::RekeningBank(double saldo_awal)
{
    saldo = saldo_awal;
}

RekeningBank::~RekeningBank()
{
    // Use delete[] var for array/pointer objects
    // Like int var[] or int* var (stated in memory allocation)
}

void RekeningBank::setor(double jumlah)
{
    saldo += jumlah;
}

void RekeningBank::tarik(double jumlah)
{
    double saldo_akhir = saldo - jumlah;
    if (saldo_akhir < 0)
    {
        std::cout << "Penarikan Gagal" << std::endl;
        return;
    }

    saldo = saldo_akhir;
    std::cout << "Saldo akhir = " << saldo << std::endl;
}

int main()
{
    RekeningBank RekeningAldo(10000.0);
    RekeningAldo.setor(1000.0);
    RekeningAldo.tarik(12000.0);
    RekeningAldo.tarik(3000.0);
    return 0;
}