class Pertunjukan:
    def __init__(self, IdPertunjukan: str, Judul: str, Durasi: int, Sutradara: str, Naskah=None, Panggung=None, DaftarAktor=None):
        self.__IdPertunjukan = str(IdPertunjukan)
        self.__Judul = str(Judul)
        self.__Durasi = int(Durasi)
        self.__Sutradara = str(Sutradara)
        # Composition
        self.__Naskah = Naskah
        self.__Panggung = Panggung
        # Array of Object
        if DaftarAktor is None:
            self.__DaftarAktor = []
        else:
            self.__DaftarAktor = DaftarAktor

    def setIdPertunjukan(self, IdPertunjukan: str) -> None:
        self.__IdPertunjukan = str(IdPertunjukan)

    def setJudul(self, Judul: str) -> None:
        self.__Judul = str(Judul)

    def setDurasi(self, Durasi: int) -> None:
        self.__Durasi = int(Durasi)

    def setSutradara(self, Sutradara: str) -> None:
        self.__Sutradara = str(Sutradara)

    def setNaskah(self, Naskah) -> None:
        self.__Naskah = Naskah

    def setPanggung(self, Panggung) -> None:
        self.__Panggung = Panggung

    def setDaftarAktor(self, DaftarAktor) -> None:
        self.__DaftarAktor = DaftarAktor

    def getIdPertunjukan(self) -> str:
        return self.__IdPertunjukan

    def getJudul(self) -> str:
        return self.__Judul

    def getDurasi(self) -> int:
        return self.__Durasi

    def getSutradara(self) -> str:
        return self.__Sutradara

    def getNaskah(self):
        return self.__Naskah

    def getPanggung(self):
        return self.__Panggung

    def getDaftarAktor(self):
        return self.__DaftarAktor