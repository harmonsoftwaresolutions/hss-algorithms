/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
  const stringInt = x.toString();
  const sign = stringInt.startsWith("-"); // returns true or false
  const unsignedStringInt = stringInt.replace("-", ""); // remove sign
  const reversedUnsignedStringInt = Array.from(unsignedStringInt)
    .reverse()
    .join(""); // make array from string, reverse, then join individual letters back in to a single string

  // stupid checking for 32bit overflow in javascript
  if (parseInt(reversedUnsignedStringInt) > Math.pow(2, 31) - 1) return 0;

  const signedString =
    sign === true
      ? `-${reversedUnsignedStringInt}`
      : `${reversedUnsignedStringInt}`; // append sign to beginning of string if found in beginning

  const reversedX = parseInt(signedString); // convert string back to integer
  return reversedX;
};
