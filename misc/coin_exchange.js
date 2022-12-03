var s;

class Solution {
  coinChange(coins, amount2) {
    var backtrack;

    backtrack = (amount = 0, count = 0, start = 0, path = []) => {
      if (amount === 0) {
        if (this.mincoin > count) {
          this.res = path;
          this.mincoin = count;
        }
      } else {
        if (amount > 0) {
          for (var i = start, _pj_a = coins.length; i < _pj_a; i += 1) {
            if (coins[i][1] > 0) {
              coins[i][1] -= 1;
              backtrack(amount - coins[i][0], count + 1, i, path + [coins[i][0]]);
              coins[i][1] += 1;
            }
          }
        }
      }
    };

    this.mincoin = Number.parseFloat("inf");
    this.res = [];
    coins.sort();
    backtrack(amount2);
    console.log(this.res);
    return this.mincoin === Number.parseFloat("inf") ? -1 : this.mincoin;
  }

}

s = new Solution();
console.log(s.coinChange([[4, 1], [2, 6], [5, 3]], 22));
