#include <iostream>
#include <string>
#include "Pertunjukan.cpp"
#include "Drama.cpp"
#include "Komedi.cpp"
#include "Musikal.cpp"

using namespace std;

// Fungsi untuk menampilkan semua data pertunjukan dalam format tabel dinamis
void tampilkan_semua_data(Pertunjukan** daftar_pertunjukan, int jml_pertunjukan, string judul_sesi) {
    // Menentukan lebar maksimal garis pemisah agar rapi
    int lebar_garis = 80;

    // Mencetak judul sesi dengan posisi di tengah
    cout << "\n" << string(lebar_garis, '=') << endl;
    int spasi = (lebar_garis - judul_sesi.length()) / 2;
    for(int i = 0; i < spasi; ++i) {
        cout << " ";
    }
    cout << judul_sesi << endl;
    cout << string(lebar_garis, '=') << endl;

    // Looping untuk setiap objek di dalam array daftar_pertunjukan
    for(int idx_p = 0; idx_p < jml_pertunjukan; ++idx_p) {
        Pertunjukan* p = daftar_pertunjukan[idx_p];
        // Mengambil kategori dari tiap subclass (penerapan Polymorphism)
        string kategori = p->getKategori();
        // Mencetak ID, Judul, dan kategori pertunjukan
        cout << endl;
        cout << idx_p + 1 << ". " << p->getIdPertunjukan() << endl;
        cout << p->getJudul() << " (" << kategori << ")" << endl;
        cout << "- Durasi    : " << p->getDurasi() << " Menit" << endl;
        cout << "- Sutradara : " << p->getSutradara() << endl;

        // Menampilkan atribut khusus sesuai dengan jenis pertunjukan
        if(kategori == "Drama") {
            Drama* drama = (Drama*) p;
            cout << "- Atribut Drama:" << endl;
            cout << "     - Tema          : " << drama->getTema() << endl;
            cout << "     - Jumlah Babak  : " << drama->getJumlahBabak() << endl;
            cout << "     - Konflik Utama : " << drama->getKonflikUtama() << endl;
        } else if(kategori == "Musikal") {
            Musikal* musikal = (Musikal*) p;

            cout << "- Atribut Musikal:" << endl;
            cout << "     - Jumlah Lagu  : " << musikal->getJumlahLagu() << endl;
            cout << "     - Durasi Musik : " << musikal->getDurasiMusik() << " Menit" << endl;
            cout << "     - Tema Musik   : " << musikal->getTemaMusik() << endl;
        } else if(kategori == "Komedi") {
            Komedi* komedi = (Komedi*) p;

            cout << "- Atribut Komedi:" << endl;
            cout << "     - Gaya Humor    : " << komedi->getGayaHumor() << endl;
            cout << "     - Tema Cerita   : " << komedi->getTemaCerita() << endl;
            cout << "     - Tingkat Humor : " << komedi->getTingkatHumor() << endl;
        }

        // Mengambil data Naskah dari dalam objek Pertunjukan (Composition)
        Naskah* naskah = p->getNaskah();
        cout << "- Naskah:" << endl;
        if(naskah != NULL) {
            cout << "     - ID Naskah      : " << naskah->getIdNaskah() << endl;
            cout << "     - Penulis        : " << naskah->getPenulis() << endl;
            cout << "     - Halaman        : " << naskah->getJumlahHalaman() << " Halaman" << endl;
            cout << "     - Bahasa         : " << naskah->getBahasa() << endl;
        } else {
            cout << "     - Belum ada naskah" << endl;
        }

        // Mengambil data Panggung dari dalam objek Pertunjukan (Composition)
        Panggung* panggung = p->getPanggung();
        cout << "- Panggung:" << endl;
        if(panggung != NULL) {
            cout << "     - ID Panggung    : " << panggung->getIdPanggung() << endl;
            cout << "     - Nama           : " << panggung->getNamaPanggung() << endl;
            cout << "     - Kapasitas      : " << panggung->getKapasitas() << " Penonton" << endl;
            cout << "     - Jenis Panggung : " << panggung->getJenisPanggung() << endl;
        } else {
            cout << "     - Belum ada panggung" << endl;
        }

        // Mengambil array daftar Aktor
        Aktor** aktor_list = p->getDaftarAktor();
        cout << "- Aktor:" << endl;
        // Mengecek apakah ada aktor yang terdaftar
        if(aktor_list == NULL || p->getJumlahAktor() == 0) {
            cout << "     - Belum ada aktor terdaftar" << endl;
        } else {
            // Menyiapkan array 2D sementara untuk menyusun isi tabel
            string data_aktor[50][5];

            // Memasukkan data aktor ke array 2D dan memformat tampilannya
            for(int i = 0; i < p->getJumlahAktor(); ++i) {
                string peran_clean = aktor_list[i]->getPeran();
                string peran_baru = "";
                // Menghapus tanda kurung '(' dan ')' dari peran aktor
                for(int j = 0; j < peran_clean.length(); ++j) {
                    if(peran_clean[j] != '(' && peran_clean[j] != ')') {
                        peran_baru += peran_clean[j];
                    }
                }
                data_aktor[i][0] = aktor_list[i]->getIdAktor();
                data_aktor[i][1] = aktor_list[i]->getNama();
                data_aktor[i][2] = to_string(aktor_list[i]->getUmur());
                data_aktor[i][3] = peran_baru;
                data_aktor[i][4] = to_string(aktor_list[i]->getPengalaman()) + " tahun";
            }

            // Menentukan teks header untuk setiap kolom tabel
            string header[5] = {"ID", "Nama", "Umur", "Peran", "Pengalaman"};
            int lebar_kolom[5];
            // Mencari teks terpanjang di tiap kolom agar lebar tabel dinamis
            for(int i = 0; i < 5; ++i) {
                lebar_kolom[i] = header[i].length();
                for(int j = 0; j < p->getJumlahAktor(); ++j) {
                    if(data_aktor[j][i].length() > lebar_kolom[i]) {
                        lebar_kolom[i] = data_aktor[j][i].length();
                    }
                }
            }

            // Membuat garis pembatas tabel menyesuaikan lebar teks
            string border = "+";
            for(int i = 0; i < 5; ++i) {
                border += string(lebar_kolom[i] + 2, '-');
                border += "+";
            }

            // Mencetak baris header tabel dengan format rata kiri
            cout << "     " << border << endl;
            cout << "     |";
            for(int i = 0; i < 5; ++i) {
                cout << " " << header[i];
                for(int j = header[i].length(); j < lebar_kolom[i]; ++j) {
                    cout << " ";
                }
                cout << " |";
            }
            cout << endl;
            cout << "     " << border << endl;

            // Mencetak baris-baris data aktor dengan format rata kiri
            for(int i = 0; i < p->getJumlahAktor(); ++i) {
                cout << "     |";
                for(int j = 0; j < 5; ++j) {
                    cout << " " << data_aktor[i][j];
                    for(int k = data_aktor[i][j].length(); k < lebar_kolom[j]; ++k) {
                        cout << " ";
                    }
                    cout << " |";
                }
                cout << endl;
            }
            cout << "     " << border << endl;
        }
    }
}

int main() {
    // Menyiapkan data Naskah dan Panggung untuk pertunjukan pertama
    Naskah* naskah1 = new Naskah("NSK-01", "Lin-Manuel Miranda", 150, "Inggris");
    Panggung* panggung1 = new Panggung("PNG-A", "Richard Rodgers Theatre", 1319, "Proscenium");
    // Menyiapkan array berisi data aktor
    Aktor* aktor_hamilton[3] = {
        new Aktor("AKT-01", "Lin-Manuel Miranda", 40, "Alexander Hamilton", 15),
        new Aktor("AKT-02", "Leslie Odom Jr.", 39, "Aaron Burr", 12),
        new Aktor("AKT-03", "Phillipa Soo", 36, "Eliza Hamilton", 11)
    };

    // Membuat objek Musikal dan memasukkan komponennya (Dependency Injection)
    Musikal* hamilton = new Musikal("PRT-01", "Hamilton", 160, "Thomas Kail", 46, 140, "Hip-Hop Musikal");
    hamilton->setNaskah(naskah1);
    hamilton->setPanggung(panggung1);
    hamilton->setDaftarAktor(aktor_hamilton, 3);

    // Menyiapkan data untuk pertunjukan kedua
    Naskah* naskah2 = new Naskah("NSK-02", "Anais Mitchell", 110, "Inggris");
    Panggung* panggung2 = new Panggung("PNG-B", "Walter Kerr Theatre", 975, "Proscenium");
    Aktor* aktor_hadestown[3] = {
        new Aktor("AKT-04", "Reeve Carney", 37, "Orpheus", 10),
        new Aktor("AKT-05", "Eva Noblezada", 25, "Eurydice", 7),
        new Aktor("AKT-06", "Andre De Shields", 78, "Hermes", 30)
    };

    // Membuat objek Musikal kedua dan memasukkan komponennya
    Musikal* hadestown = new Musikal("PRT-02", "Hadestown", 145, "Rachel Chavkin", 30, 120, "Folk Jazz");
    hadestown->setNaskah(naskah2);
    hadestown->setPanggung(panggung2);
    hadestown->setDaftarAktor(aktor_hadestown, 3);

    // Membuat array utama untuk menyimpan seluruh pertunjukan
    Pertunjukan* daftar_pertunjukan[10];
    int jml_pertunjukan = 0;

    // Memasukkan objek Musikal ke dalam array utama
    daftar_pertunjukan[jml_pertunjukan++] = hamilton;
    daftar_pertunjukan[jml_pertunjukan++] = hadestown;

    // Menampilkan kondisi data sebelum ada penambahan
    tampilkan_semua_data(daftar_pertunjukan, jml_pertunjukan, "DATA SEBELUM DITAMBAHKAN");

    // Menyiapkan data pertunjukan ketiga
    Naskah* naskah3 = new Naskah("NSK-03", "Putu Wijaya", 125, "Indonesia");
    Panggung* panggung3 = new Panggung("PNG-C", "Teater Salihara", 300, "Proscenium");
    Aktor* aktor_bunga[3] = {
        new Aktor("AKT-07", "Happy Salma", 45, "Nyai Ontosoroh", 20),
        new Aktor("AKT-08", "Reza Rahadian", 39, "Minke", 18),
        new Aktor("AKT-09", "Chelsea Islan", 30, "Annelies", 10)
    };

    // Membuat objek Drama dan memasukkan komponennya
    Drama* bunga = new Drama("PRT-03", "Bunga Penutup Abad", 130, "Wawan Sofwan", "Keluarga", 3, "Perjuangan dan kehidupan keluarga");
    bunga->setNaskah(naskah3);
    bunga->setPanggung(panggung3);
    bunga->setDaftarAktor(aktor_bunga, 3);

    // Menyiapkan data pertunjukan keempat berjenis Komedi
    Naskah* naskah4 = new Naskah("NSK-04", "Raditya Dika", 100, "Indonesia");
    Panggung* panggung4 = new Panggung("PNG-D", "Teater Jakarta", 500, "Proscenium");
    Aktor* aktor_komedi[3] = {
        new Aktor("AKT-10", "Raditya Dika", 41, "Pemain Utama", 15),
        new Aktor("AKT-11", "Ernest Prakasa", 43, "Sahabat", 12),
        new Aktor("AKT-12", "Ge Pamungkas", 37, "Pemeran Pendukung", 10)
    };

    // Membuat objek Komedi dan memasukkan komponennya
    Komedi* komedi = new Komedi("PRT-04", "Cinta Dalam Komedi", 115, "Ernest Prakasa", "Satire", "Percintaan", "Tinggi");
    komedi->setNaskah(naskah4);
    komedi->setPanggung(panggung4);
    komedi->setDaftarAktor(aktor_komedi, 3);

    // Memasukkan objek Drama dan Komedi yang baru ke dalam array utama
    daftar_pertunjukan[jml_pertunjukan++] = bunga;
    daftar_pertunjukan[jml_pertunjukan++] = komedi;

    // Menampilkan kondisi data setelah penambahan
    tampilkan_semua_data(daftar_pertunjukan, jml_pertunjukan, "DATA SESUDAH DITAMBAHKAN");

    return 0;
}