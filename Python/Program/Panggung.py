class Panggung:
    def __init__(self, IdPanggung: str, NamaPanggung: str, Kapasitas: int, JenisPanggung: str):
        self.__IdPanggung = str(IdPanggung)
        self.__NamaPanggung = str(NamaPanggung)
        self.__Kapasitas = int(Kapasitas)
        self.__JenisPanggung = str(JenisPanggung)

    # Setter
    def setIdPanggung(self, IdPanggung: str) -> None:
        self.__IdPanggung = str(IdPanggung)

    def setNamaPanggung(self, NamaPanggung: str) -> None:
        self.__NamaPanggung = str(NamaPanggung)

    def setKapasitas(self, Kapasitas: int) -> None:
        self.__Kapasitas = int(Kapasitas)

    def setJenisPanggung(self, JenisPanggung: str) -> None:
        self.__JenisPanggung = str(JenisPanggung)

    # Getter
    def getIdPanggung(self) -> str:
        return self.__IdPanggung

    def getNamaPanggung(self) -> str:
        return self.__NamaPanggung

    def getKapasitas(self) -> int:
        return self.__Kapasitas

    def getJenisPanggung(self) -> str:
        return self.__JenisPanggung
        