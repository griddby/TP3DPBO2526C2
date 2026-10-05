from Pertunjukan import Pertunjukan

# Class Komedi mewarisi properti dari class Pertunjukan (Hierarchical Inheritance)
class Komedi(Pertunjukan):
    def __init__(self, IdPertunjukan: str, Judul: str, Durasi: int, Sutradara: str, GayaHumor: str, TemaCerita: str, TingkatHumor: str, Naskah=None, Panggung=None, DaftarAktor=None):
        super().__init__(IdPertunjukan, Judul, Durasi, Sutradara, Naskah, Panggung, DaftarAktor)
        self.__GayaHumor = str(GayaHumor)
        self.__TemaCerita = str(TemaCerita)
        self.__TingkatHumor = str(TingkatHumor)

    # Setter
    def setGayaHumor(self, GayaHumor: str) -> None:
        self.__GayaHumor = str(GayaHumor)

    def setTemaCerita(self, TemaCerita: str) -> None:
        self.__TemaCerita = str(TemaCerita)

    def setTingkatHumor(self, TingkatHumor: str) -> None:
        self.__TingkatHumor = str(TingkatHumor)

    # Getter
    def getGayaHumor(self) -> str:
        return self.__GayaHumor

    def getTemaCerita(self) -> str:
        return self.__TemaCerita

    def getTingkatHumor(self) -> str:
        return self.__TingkatHumor