class Solution:
    def func(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        
        # check for -ve power
        if n < 0:
            return 1.0 / self.func(x, -1 * n)
        
        if n % 2 != 0 :
            return x * self.func(x * x, (n - 1) // 2)
        else : 
            return self.func(x * x, n // 2)
    def myPow(self, x: float, n: int) -> float:
        # using binary exponentiation w/ recursion
        return self.func(x, n)