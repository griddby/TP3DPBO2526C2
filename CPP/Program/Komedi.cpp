#ifndef KOMEDI_CPP
#define KOMEDI_CPP

#include <iostream>
#include "Pertunjukan.cpp"

using namespace std;

class Komedi: public Pertunjukan{
    private:
        string GayaHumor;
        string TemaCerita;
        string TingkatHumor;

    public:
        Komedi(){
        }

        Komedi(string IdPertunjukan, string Judul, int Durasi, string Sutradara, string GayaHumor, string TemaCerita, string TingkatHumor): Pertunjukan(IdPertunjukan, Judul, Durasi, Sutradara){
            this->GayaHumor = GayaHumor;
            this->TemaCerita = TemaCerita;
            this->TingkatHumor = TingkatHumor;
        }

        // Setter
        void setGayaHumor(string GayaHumor){
            this->GayaHumor = GayaHumor;
        }

        void setTemaCerita(string TemaCerita){
            this->TemaCerita = TemaCerita;
        }

        void setTingkatHumor(string TingkatHumor){
            this->TingkatHumor = TingkatHumor;
        }

        // Getter
        string getGayaHumor(){
            return this->GayaHumor;
        }

        string getTemaCerita(){
            return this->TemaCerita;
        }

        string getTingkatHumor(){
            return this->TingkatHumor;
        }

        string getKategori(){
            return "Komedi";
        }
};

#endif