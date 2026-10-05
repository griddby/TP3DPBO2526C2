class Aktor: 
    def __init__(self, IdAktor: str, Nama: str, Umur: int, Peran: str, Pengalaman: int):
        self.__IdAktor = str(IdAktor)
        self.__Nama = str(Nama)
        self.__Umur = int(Umur)
        self.__Peran = str(Peran)
        self.__Pengalaman = int(Pengalaman)

    def setIdAktor(self, IdAktor: str) -> None:
        self.__IdAktor = str(IdAktor)

    def setNama(self, Nama: str) -> None:
        self.__Nama = str(Nama)

    def setUmur(self, Umur: int) -> None:
        self.__Umur = int(Umur)

    def setPeran(self, Peran: str) -> None:
        self.__Peran = str(Peran)

    def setPengalaman(self, Pengalaman: int) -> None:
        self.__Pengalaman = int(Pengalaman)

    def getIdAktor(self) -> str:
        return self.__IdAktor

    def getNama(self) -> str:
        return self.__Nama

    def getUmur(self) -> int:
        return self.__Umur

    def getPeran(self) -> str:
        return self.__Peran

    def getPengalaman(self) -> int:
        return self.__Pengalaman
