from Aktor import Aktor
from Naskah import Naskah
from Panggung import Panggung
from Drama import Drama
from Komedi import Komedi
from Musikal import Musikal

def tampilkan_semua_data(daftar_pertunjukan, judul_sesi):
    # Menentukan lebar maksimal untuk pemisah baris agar rapi
    lebar_garis = 80

    # Mencetak header sesi dengan posisi teks tepat di tengah (center alignment)
    print("\n" + "=" * lebar_garis)
    print(f"{judul_sesi.upper():^{lebar_garis}}")
    print("=" * lebar_garis)

    # Melakukan perulangan pada array of object daftar_pertunjukan
    for idx_p, p in enumerate(daftar_pertunjukan, start=1):
        
        # Pengecekan tipe kelas untuk menentukan kategori pertunjukan
        if isinstance(p, Drama):
            kategori = "Drama"
        elif isinstance(p, Musikal):
            kategori = "Musikal"
        elif isinstance(p, Komedi):
            kategori = "Komedi"
        else:
            kategori = "Umum"

        # Mencetak ID dan Judul pertunjukan beserta kategorinya
        print(f"\n{idx_p}. {p.getIdPertunjukan()} \n{p.getJudul()} ({kategori})")

        # Mengambil objek Naskah dari dalam objek Pertunjukan (Penerapan Composition)
        naskah = p.getNaskah()
        print("- Naskah:")
        if naskah:
            # Menggunakan getter dari objek Naskah untuk menampilkan detailnya
            print(f"     - ID Naskah : {naskah.getIdNaskah()}")
            print(f"     - Penulis   : {naskah.getPenulis()}")
            print(f"     - Halaman   : {naskah.getJumlahHalaman()} Halaman")
        else:
            print("     - Belum ada naskah")

        # Mengambil objek Panggung dari dalam objek Pertunjukan (Penerapan Composition)
        panggung = p.getPanggung()
        print("- Panggung:")
        if panggung:
            # Menggunakan getter dari objek Panggung
            print(f"     - ID Panggung : {panggung.getIdPanggung()}")
            print(f"     - Nama        : {panggung.getNamaPanggung()}")
            print(f"     - Kapasitas   : {panggung.getKapasitas()} Penonton")
        else:
            print("     - Belum ada panggung")

        # Mengambil list/array of object Aktor dari objek Pertunjukan
        aktor_list = p.getDaftarAktor()
        print("- Aktor:")

        if not aktor_list:
            print("     - Belum ada aktor terdaftar")
        else:
            data_aktor = []

            # Memasukkan data spesifik setiap aktor ke dalam list 2 dimensi
            for akt in aktor_list:
                peran_clean = akt.getPeran().replace("(", "").replace(")", "")
                data_aktor.append([
                    akt.getIdAktor(),
                    akt.getNama(),
                    str(akt.getUmur()),
                    peran_clean,
                    str(akt.getPengalaman()) + " tahun"
                ])

            # Mendefinisikan header tabel
            header = ["ID", "Nama", "Umur", "Peran", "Pengalaman"]
            lebar_kolom = []

            # Mencari teks terpanjang di setiap kolom
            for i in range(len(header)):
                lebar = len(header[i]) # Set awal menggunakan panjang teks header
                for baris in data_aktor:
                    if len(baris[i]) > lebar:
                        lebar = len(baris[i]) # Update jika isi data lebih panjang dari header
                lebar_kolom.append(lebar)

            # Membuat garis pembatas tabel yang menyesuaikan lebar maksimal kolom
            border = "+"
            for lebar in lebar_kolom:
                border += "-" * (lebar + 2) + "+"

            # Mencetak garis atas tabel
            print("     " + border)

            # Mencetak baris header tabel dengan format rata kiri menyesuaikan lebar dinamis
            print("     |", end="")
            for i in range(len(header)):
                print(f" {header[i]:<{lebar_kolom[i]}} |", end="")
            print()

            # Mencetak garis pemisah antara header dan isi tabel
            print("     " + border)

            # Mencetak isi baris data aktor
            for baris in data_aktor:
                print("     |", end="")
                for i in range(len(baris)):
                    print(f" {baris[i]:<{lebar_kolom[i]}} |", end="")
                print()

            # Mencetak garis penutup tabel bawah
            print("     " + border)


if __name__ == "__main__":
    # Membuat objek komponen (Naskah dan Panggung) serta Array of Object Aktor
    naskah1 = Naskah("NSK-01", "Lin-Manuel Miranda", 150, "Inggris")
    panggung1 = Panggung("PNG-A", "Richard Rodgers Theatre", 1319, "Proscenium")
    aktor_hamilton = [
        Aktor("AKT-01", "Lin-Manuel Miranda", 40, "Alexander Hamilton", 15),
        Aktor("AKT-02", "Leslie Odom Jr.", 39, "Aaron Burr", 12),
        Aktor("AKT-03", "Phillipa Soo", 36, "Eliza Hamilton", 11)
    ]
    
    # Membuat objek utama Musikal, lalu memasukkan objek komponen ke dalamnya (Composition)
    hamilton = Musikal("PRT-01", "Hamilton", 160, "Thomas Kail", 46, 140, "Hip-Hop Musikal")
    hamilton.setNaskah(naskah1)
    hamilton.setPanggung(panggung1)
    hamilton.setDaftarAktor(aktor_hamilton)

    # Menyiapkan data pertunjukan kedua
    naskah2 = Naskah("NSK-02", "Anais Mitchell", 110, "Inggris")
    panggung2 = Panggung("PNG-B", "Walter Kerr Theatre", 975, "Proscenium")
    aktor_hadestown = [
        Aktor("AKT-04", "Reeve Carney", 37, "Orpheus", 10),
        Aktor("AKT-05", "Eva Noblezada", 25, "Eurydice", 7),
        Aktor("AKT-06", "Andre De Shields", 78, "Hermes", 30)
    ]

    hadestown = Musikal("PRT-02", "Hadestown", 145, "Rachel Chavkin", 30, 120, "Folk Jazz")
    hadestown.setNaskah(naskah2)
    hadestown.setPanggung(panggung2)
    hadestown.setDaftarAktor(aktor_hadestown)

    # Membuat Array of Object utama untuk menyimpan sekumpulan objek Pertunjukan
    daftar_pertunjukan = [hamilton, hadestown]

    # Menampilkan kondisi data awal
    tampilkan_semua_data(daftar_pertunjukan, "DATA SEBELUM DITAMBAHKAN")

    # Menyiapkan data pertunjukan baru berjenis Drama
    naskah3 = Naskah("NSK-03", "Putu Wijaya", 125, "Indonesia")
    panggung3 = Panggung("PNG-C", "Teater Salihara", 300, "Proscenium")
    aktor_bunga = [
        Aktor("AKT-07", "Happy Salma", 45, "Nyai Ontosoroh", 20),
        Aktor("AKT-08", "Reza Rahadian", 39, "Minke", 18),
        Aktor("AKT-09", "Chelsea Islan", 30, "Annelies", 10)
    ]

    bunga = Drama("PRT-03", "Bunga Penutup Abad", 130, "Wawan Sofwan", "Keluarga", 3, "Perjuangan dan kehidupan keluarga")
    bunga.setNaskah(naskah3)
    bunga.setPanggung(panggung3)
    bunga.setDaftarAktor(aktor_bunga)

    naskah4 = Naskah("NSK-04", "Garin Nugroho", 135, "Indonesia")
    panggung4 = Panggung("PNG-D", "Teater Besar Taman Ismail Marzuki", 1200, "Proscenium")
    aktor_opera = [
        Aktor("AKT-10", "Artika Sari Devi", 46, "Siti", 18),
        Aktor("AKT-11", "Retno Maruti", 64, "Rama", 35),
        Aktor("AKT-12", "Eko Supriyanto", 49, "Ludiro", 25)
    ]

    opera_jawa = Drama("PRT-04", "Opera Jawa", 140, "Garin Nugroho", "Budaya Jawa", 4, "Kehidupan dan tradisi Jawa")
    opera_jawa.setNaskah(naskah4)
    opera_jawa.setPanggung(panggung4)
    opera_jawa.setDaftarAktor(aktor_opera)

    # Menambahkan objek pertunjukan baru ke dalam Array of Object utama
    daftar_pertunjukan.append(bunga)
    daftar_pertunjukan.append(opera_jawa)

    # Menampilkan kondisi data setelah penambahan objek baru
    tampilkan_semua_data(daftar_pertunjukan, "DATA SESUDAH DITAMBAHKAN")