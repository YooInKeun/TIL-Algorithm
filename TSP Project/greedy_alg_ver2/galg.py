from abc import *
class galg(metaclass=ABCMeta):
    @abstractmethod
    def getPath(self):
        pass

    @abstractmethod
    def getCost(self):
        pass