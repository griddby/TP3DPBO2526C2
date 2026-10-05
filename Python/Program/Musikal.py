from Pertunjukan import Pertunjukan

# Class Musikal mewarisi properti dari class Pertunjukan (Hierarchical Inheritance)
class Musikal(Pertunjukan):
    def __init__(self, IdPertunjukan: str, Judul: str, Durasi: int, Sutradara: str, JumlahLagu: int, DurasiMusik: int, TemaMusik: str, Naskah=None, Panggung=None, DaftarAktor=None):
        super().__init__(IdPertunjukan, Judul, Durasi, Sutradara, Naskah, Panggung, DaftarAktor)
        self.__JumlahLagu = int(JumlahLagu)
        self.__DurasiMusik = int(DurasiMusik)
        self.__TemaMusik = str(TemaMusik)

    # Setter
    def setJumlahLagu(self, JumlahLagu: int) -> None:
        self.__JumlahLagu = int(JumlahLagu)

    def setDurasiMusik(self, DurasiMusik: int) -> None:
        self.__DurasiMusik = int(DurasiMusik)

    def setTemaMusik(self, TemaMusik: str) -> None:
        self.__TemaMusik = str(TemaMusik)

    # Getter
    def getJumlahLagu(self) -> int:
        return self.__JumlahLagu

    def getDurasiMusik(self) -> int:
        return self.__DurasiMusik

    def getTemaMusik(self) -> str:
        return self.__TemaMusik