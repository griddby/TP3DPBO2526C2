#include <iostream>

using namespace std;

class Naskah{
    private:
        string IdNaskah;
        string Penulis;
        int JumlahHalaman;
        string Bahasa;

    public:
        Naskah(){
        }

        Naskah(string IdNaskah, string Penulis, int JumlahHalaman, string Bahasa){
            this->IdNaskah = IdNaskah;
            this->Penulis = Penulis;
            this->JumlahHalaman = JumlahHalaman;
            this->Bahasa = Bahasa;
        }

        // Setter
        void setIdNaskah(string IdNaskah){
            this->IdNaskah = IdNaskah;
        }

        void setPenulis(string Penulis){
            this->Penulis = Penulis;
        }

        void setJumlahHalaman(int JumlahHalaman){
            this->JumlahHalaman = JumlahHalaman;
        }

        void setBahasa(string Bahasa){
            this->Bahasa = Bahasa;
        }

        // Getter
        string getIdNaskah(){
            return this->IdNaskah;
        }

        string getPenulis(){
            return this->Penulis;
        }

        int getJumlahHalaman(){
            return this->JumlahHalaman;
        }

        string getBahasa(){
            return this->Bahasa;
        }
};