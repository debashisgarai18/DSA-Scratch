class Solution:
    def isDigit(self, s: str) -> bool :
        return True if s >= '0' and s <= '9' else False
    def func(self, s: str, idx: int, sign: int, res: int) -> int:
        # base check
        if (idx >= len(s) or not self.isDigit(s[idx])) :
            return sign * res

        res = res * 10 + int(s[idx])

        if sign * res > 2 ** 31 - 1 :
            return 2 ** 31 - 1
        elif sign * res < -2 ** 31 :
            return -2 ** 31

        return self.func(s, idx + 1, sign, res)    
    def myAtoi(self, s: str) -> int:
        if len(s) == 0:
            return 0
        
        # check for whitespaces
        ptr = 0
        sign = 1
        while (ptr < len(s) - 1 and s[ptr] == ' ') :
            ptr = ptr + 1
        if s[ptr] == '-' or s[ptr] =='+' :
            sign = 1 if s[ptr] == '+' else -1
            ptr = ptr + 1       
        return self.func(s, ptr, sign, 0)