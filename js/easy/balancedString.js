/**
 * @param {string} s
 * @return {number}
 */
var balancedStringSplit = function(s) {
  let cntr = 0;
  let ans = 0;
  for (let c of s) {
    if (c === "L") {
      cntr = cntr + 1;
    } else {
      cntr = cntr - 1;
    }

    if (cntr === 0) ans = ans + 1;
  }

  return ans;
};
