#include <iostream>

using namespace std;

class Panggung{
    private:
        string IdPanggung;
        string NamaPanggung;
        int Kapasitas;
        string JenisPanggung;

    public:
        Panggung(){
        }

        Panggung(string IdPanggung, string NamaPanggung, int Kapasitas, string JenisPanggung){
            this->IdPanggung = IdPanggung;
            this->NamaPanggung = NamaPanggung;
            this->Kapasitas = Kapasitas;
            this->JenisPanggung = JenisPanggung;
        }

        // Setter
        void setIdPanggung(string IdPanggung){
            this->IdPanggung = IdPanggung;
        }

        void setNamaPanggung(string NamaPanggung){
            this->NamaPanggung = NamaPanggung;
        }

        void setKapasitas(int Kapasitas){
            this->Kapasitas = Kapasitas;
        }

        void setJenisPanggung(string JenisPanggung){
            this->JenisPanggung = JenisPanggung;
        }

        // Getter
        string getIdPanggung(){
            return this->IdPanggung;
        }

        string getNamaPanggung(){
            return this->NamaPanggung;
        }

        int getKapasitas(){
            return this->Kapasitas;
        }

        string getJenisPanggung(){
            return this->JenisPanggung;
        }
};