#ifndef DRAMA_CPP
#define DRAMA_CPP

#include <iostream>
#include "Pertunjukan.cpp"

using namespace std;

class Drama: public Pertunjukan{
    private:
        string Tema;
        int JumlahBabak;
        string KonflikUtama;

    public:
        Drama(){
        }

        Drama(string IdPertunjukan, string Judul, int Durasi, string Sutradara, string Tema, int JumlahBabak, string KonflikUtama): Pertunjukan(IdPertunjukan, Judul, Durasi, Sutradara){
            this->Tema = Tema;
            this->JumlahBabak = JumlahBabak;
            this->KonflikUtama = KonflikUtama;
        }

        // Setter
        void setTema(string Tema){
            this->Tema = Tema;
        }

        void setJumlahBabak(int JumlahBabak){
            this->JumlahBabak = JumlahBabak;
        }

        void setKonflikUtama(string KonflikUtama){
            this->KonflikUtama = KonflikUtama;
        }

        // Getter
        string getTema(){
            return this->Tema;
        }

        int getJumlahBabak(){
            return this->JumlahBabak;
        }

        string getKonflikUtama(){
            return this->KonflikUtama;
        }

        string getKategori(){
            return "Drama";
        }
};

#endif