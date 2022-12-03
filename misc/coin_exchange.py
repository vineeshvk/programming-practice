class Solution:
    def coinChange(self, coins, amount2):
        def backtrack(amount=0,count=0,start=0,path=[]):
            print(amount, path)
            if amount == 0:
                if self.mincoin > count:
                    self.res = path
                    self.mincoin = count
            elif amount > 0:
                for i in range(start,len(coins)):
                    if coins[i][1] > 0:
                        coins[i][1] -= 1
                        backtrack(amount - coins[i][0], count + 1, i, path + [coins[i][0]] )
                        coins[i][1] += 1
                        
                         
        self.mincoin = 1000
        self.res = []
        coins.sort(key=lambda x: x[0],reverse=True)
        backtrack(amount2)
        print(self.res)
        return -1 if self.mincoin == float("inf") else self.mincoin
    
s = Solution()
print(s.coinChange([[4,1],[2,6],[5,3]],22))