/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function (flowerbed, n) {
  let left = n, i = 0
  while (i < flowerbed.length) {
    if (flowerbed[i]) {
      i += 2
      continue
    }
    if (flowerbed[i - 1]) continue
    if (flowerbed[i + 1]) {
      i += 3
      continue
    }
    // flowerbed[i] = true
    left--
    i += 2
  }
  return left <= 0
};