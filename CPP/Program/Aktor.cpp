#include <iostream>

using namespace std;

class Aktor{
    private:
        string IdAktor;
        string Nama;
        int Umur;
        string Peran;
        int Pengalaman;

    public:
        Aktor(){
        }

        Aktor(string IdAktor, string Nama, int Umur, string Peran, int Pengalaman){
            this->IdAktor = IdAktor;
            this->Nama = Nama;
            this->Umur = Umur;
            this->Peran = Peran;
            this->Pengalaman = Pengalaman;
        }

        // Setter
        void setIdAktor(string IdAktor){
            this->IdAktor = IdAktor;
        }

        void setNama(string Nama){
            this->Nama = Nama;
        }

        void setUmur(int Umur){
            this->Umur = Umur;
        }

        void setPeran(string Peran){
            this->Peran = Peran;
        }

        void setPengalaman(int Pengalaman){
            this->Pengalaman = Pengalaman;
        }

        // Getter
        string getIdAktor(){
            return this->IdAktor;
        }

        string getNama(){
            return this->Nama;
        }

        int getUmur(){
            return this->Umur;
        }

        string getPeran(){
            return this->Peran;
        }

        int getPengalaman(){
            return this->Pengalaman;
        }
};