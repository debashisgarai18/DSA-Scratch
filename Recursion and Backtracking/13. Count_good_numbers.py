# binary exponentiation => square the base and half the exponent
class Solution:
    mod = int(1e9 + 7)
    def binaryExp(self, n: int, pow: int) -> int:
        # it'll check till the pow exists
        # if pow == 0:
        #     return 1
        
        # res = 1
        # while pow:
        #     if (pow & 1):
        #         res = (res * n) % self.mod
        #     n = (n * n) % self.mod
        #     pow = pow // 2
        
        # return res

        # recursive binary exponentiation
        if pow == 0 :
            return 1
        
        if (pow & 1) :
            return (n * self.binaryExp((n * n) % self.mod, (pow - 1) // 2)) % self.mod
        else :
            return self.binaryExp((n * n) % self.mod, pow // 2) % self.mod
    def countGoodNumbers(self, n: int) -> int:
        # for every n, we have odd posi = n / 2 and even posi = n - n / 2
        # eg. n = 7, odd posi = 1, 3, 5 even posi = 0, 2, 4, 6
        # and for every odd posi we have 4 values = 2, 3, 5, 7
        # for every even posi we have 5 values = 0, 2, 4, 6, 8
        # so formuala will be = (4 ** n / 2) * (5 ** (n - n / 2))
        # return int((4 ** (n // 2)) * (5 ** (n - (n // 2))) % self.mod)

        # using binary exponentiation
        return (self.binaryExp(4, n // 2) * self.binaryExp(5, n - (n // 2))) % self.mod
