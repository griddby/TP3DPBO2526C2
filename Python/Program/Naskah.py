class Naskah:
    def __init__(self, IdNaskah: str, Penulis: str, JumlahHalaman: int, Bahasa: str):
        self.__IdNaskah = str(IdNaskah)
        self.__Penulis = str(Penulis)
        self.__JumlahHalaman =  int(JumlahHalaman)
        self.__Bahasa = str(Bahasa)

    # Setter
    def setIdNaskah(self, IdNaskah: str) -> None:
        self.__IdNaskah = str(IdNaskah)

    def setPenulis(self, Penulis: str) -> None:
        self.__Penulis = str(Penulis)

    def setJumlahHalaman(self, JumlahHalaman: int) -> None:
        self.__JumlahHalaman = int(JumlahHalaman)

    def setBahasa(self, Bahasa: str) -> None:
        self.__Bahasa = str(Bahasa)

    # Getter
    def getIdNaskah(self) -> str:
        return self.__IdNaskah

    def getPenulis(self) -> str:
        return self.__Penulis

    def getJumlahHalaman(self) -> int:
        return self.__JumlahHalaman

    def getBahasa(self) -> str:
        return self.__Bahasa