/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
  const nstr = x.toString();

  console.log(nstr);
  const fstr = Array.from(nstr)
    .reverse()
    .join("");
  console.log(fstr);
  const compare = nstr === fstr;
  return compare;
};
const test = isPalindrome(551);
console.log(test);
