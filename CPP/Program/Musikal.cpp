#ifndef MUSIKAL_CPP
#define MUSIKAL_CPP

#include <iostream>
#include "Pertunjukan.cpp"

using namespace std;

class Musikal: public Pertunjukan{
    private:
        int JumlahLagu;
        int DurasiMusik;
        string TemaMusik;

    public:
        Musikal(){
        }

        Musikal(string IdPertunjukan, string Judul, int Durasi, string Sutradara, int JumlahLagu, int DurasiMusik, string TemaMusik): Pertunjukan(IdPertunjukan, Judul, Durasi, Sutradara){
            this->JumlahLagu = JumlahLagu;
            this->DurasiMusik = DurasiMusik;
            this->TemaMusik = TemaMusik;
        }

        // Setter
        void setJumlahLagu(int JumlahLagu){
            this->JumlahLagu = JumlahLagu;
        }

        void setDurasiMusik(int DurasiMusik){
            this->DurasiMusik = DurasiMusik;
        }

        void setTemaMusik(string TemaMusik){
            this->TemaMusik = TemaMusik;
        }

        // Getter
        int getJumlahLagu(){
            return this->JumlahLagu;
        }

        int getDurasiMusik(){
            return this->DurasiMusik;
        }

        string getTemaMusik(){
            return this->TemaMusik;
        }

        string getKategori(){
            return "Musikal";
        }
};

#endif