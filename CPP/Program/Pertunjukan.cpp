#ifndef PERTUNJUKAN_CPP
#define PERTUNJUKAN_CPP

#include <iostream>
#include "Naskah.cpp"
#include "Panggung.cpp"
#include "Aktor.cpp"

using namespace std;

class Pertunjukan{
    private:
        string IdPertunjukan;
        string Judul;
        int Durasi;
        string Sutradara;
        Naskah* NaskahPertunjukan;
        Panggung* PanggungPertunjukan;
        Aktor** DaftarAktor;
        int JumlahAktor;

    public:
        Pertunjukan(){
            this->NaskahPertunjukan = NULL;
            this->PanggungPertunjukan = NULL;
            this->DaftarAktor = NULL;
            this->JumlahAktor = 0;
        }

        Pertunjukan(string IdPertunjukan, string Judul, int Durasi, string Sutradara){
            this->IdPertunjukan = IdPertunjukan;
            this->Judul = Judul;
            this->Durasi = Durasi;
            this->Sutradara = Sutradara;
            this->NaskahPertunjukan = NULL;
            this->PanggungPertunjukan = NULL;
            this->DaftarAktor = NULL;
            this->JumlahAktor = 0;
        }

        // Setter
        void setIdPertunjukan(string IdPertunjukan){
            this->IdPertunjukan = IdPertunjukan;
        }

        void setJudul(string Judul){
            this->Judul = Judul;
        }

        void setDurasi(int Durasi){
            this->Durasi = Durasi;
        }

        void setSutradara(string Sutradara){
            this->Sutradara = Sutradara;
        }

        void setNaskah(Naskah* NaskahPertunjukan){
            this->NaskahPertunjukan = NaskahPertunjukan;
        }

        void setPanggung(Panggung* PanggungPertunjukan){
            this->PanggungPertunjukan = PanggungPertunjukan;
        }

        void setDaftarAktor(Aktor** DaftarAktor, int JumlahAktor){
            this->DaftarAktor = DaftarAktor;
            this->JumlahAktor = JumlahAktor;
        }

        // Getter
        string getIdPertunjukan(){
            return this->IdPertunjukan;
        }

        string getJudul(){
            return this->Judul;
        }

        int getDurasi(){
            return this->Durasi;
        }

        string getSutradara(){
            return this->Sutradara;
        }

        Naskah* getNaskah(){
            return this->NaskahPertunjukan;
        }

        Panggung* getPanggung(){
            return this->PanggungPertunjukan;
        }

        Aktor** getDaftarAktor(){
            return this->DaftarAktor;
        }

        int getJumlahAktor(){
            return this->JumlahAktor;
        }

        // Menentukan kategori pertunjukan
        virtual string getKategori(){
            return "Pertunjukan";
        }
};

#endif