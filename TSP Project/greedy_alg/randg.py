from galg import galg
import random
import math

class randg(galg):
    def __init__(self, path):
        self.filepath = path
        self.coords = []
        self.cost = 0
        self.min_cost = math.inf
        self.min_start = 0
        self.min_path = []
        self.visited_number = 0

    def _preprocessing(self):
        f = open(self.filepath, 'r')
        readText = f.readlines()[8:]
        f.close()
        tempCoords = []
        for line in readText[:-1]:
            temp = line.split("\n")
            temp = temp[0].split(' ')
            tempCoords.append([int(temp[0]), int(temp[1]), int(temp[2])])
            self.coords = tempCoords

    def _calcEuclidDist(self, v1, v2):
        X1 = v1[1]
        Y1 = v1[2]
        X2 = v2[1]
        Y2 = v2[2]

        return ((X1 - X2) ** 2 + (Y1 - Y2) ** 2) ** 0.5

    def _initPath(self):
        self._preprocessing()
        # random.shuffle(self.coords) # 출발지 랜덤(나중에 가장 빠른 출발지 지정하자)

    def _calcCost(self):
        
        for i in range(1, len(self.coords)):
            current_length = math.inf

            for j in range(len(self.coords) - 1):
                for k in range(j+1, len(self.coords)):
                    if(current_length > self._calcEuclidDist(self.coords[j], self.coords[k])):
                        current_length = self._calcEuclidDist(self.coords[j], self.coords[k])
                        tmp = self.coords[j+1]
                        self.coords[j+1] = self.coords[k]
                        self.coords[k] = tmp
                        
                self.cost += self._calcEuclidDist(self.coords[j], self.coords[j+1])
                current_length = math.inf
                # print('현재 좌표: ' + str(self.coords[j]), ', ' + '방문 좌표: ' + str(self.coords[j+1]))
                
            print('현재 cost: ' + str(self.cost))
            self.visited_number += 1
  
            if(self.min_cost > self.cost):
                self.min_cost = self.cost
                self.min_start = i
                self.min_path = self.coords
                print('\n' + '지금까지의 최소 cost : ' + str(self.min_cost))
                print('출발지 위치: ' + str(self.min_start) + '\n')
            
            self._initPath()

            tmp = self.coords[0]
            self.coords[0] = self.coords[i]
            self.coords[i] = tmp

            self.cost = 0

        print('\n' + '방문 갯수 : ' + str(self.visited_number))
        print('최종 최소 cost : ' + str(self.min_cost))
        print('출발지 위치: ' + str(self.min_start) + '\n')
        print('\n' + '최종 경로: ' + str(self.min_path) + '\n')

    def greedy(self):
        self._preprocessing()
        self._initPath()
        self._calcCost()

    def getPath(self):
        # self._initPath()
        return self.coords

    def getCost(self):
        return self.cost