class Solution:
    def romanToInt(self, s: str) -> int:
        romans = {"I": 1,
                  "V": 5,
                  "X": 10,
                  "L": 50,
                  "C": 100,
                  "D": 500,
                  "M": 1000, }
        
        int_list = []
        
        for i, x in enumerate(list(s)):
            num = romans.get(x, 0)
            if(int_list[i - 1] > num):
                int_list[i - 1] *= -1
            
            int_list.append(num)
        return sum(int_list)
            