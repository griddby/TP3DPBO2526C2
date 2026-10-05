from Pertunjukan import Pertunjukan

# Class Drama mewarisi properti dari class Pertunjukan (Hierarchical Inheritance)
class Drama(Pertunjukan):
    def __init__(self, IdPertunjukan: str, Judul: str, Durasi: int, Sutradara: str, Tema: str, JumlahBabak: int, KonflikUtama: str, Naskah=None, Panggung=None, DaftarAktor=None):
        # Memanggil konstruktor class induk dan membuat atribut private (Encapsulation)
        super().__init__(IdPertunjukan, Judul, Durasi, Sutradara, Naskah, Panggung, DaftarAktor)
        self.__Tema = str(Tema)
        self.__JumlahBabak = int(JumlahBabak)
        self.__KonflikUtama = str(KonflikUtama)

    # Setter
    def setTema(self, Tema: str) -> None:
        self.__Tema = str(Tema)

    def setJumlahBabak(self, JumlahBabak: int) -> None:
        self.__JumlahBabak = int(JumlahBabak)

    def setKonflikUtama(self, KonflikUtama: str) -> None:
        self.__KonflikUtama = str(KonflikUtama)

    # Getter
    def getTema(self) -> str:
        return self.__Tema

    def getJumlahBabak(self) -> int:
        return self.__JumlahBabak

    def getKonflikUtama(self) -> str:
        return self.__KonflikUtama