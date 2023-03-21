/**
 * @param {number[]} nums
 * @return {number}
 */
var zeroFilledSubarray = function (nums) {
  let a = 0;
  let b = 0;

  for (let x of nums) {
    x === 0 ? (b++, (a = a + b)) : (b = 0);
  }

  return a;
};