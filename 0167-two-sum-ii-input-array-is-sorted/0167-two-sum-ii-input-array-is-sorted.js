/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
// var twoSum = function(numbers, target) {
    
// };
function twoSum(numbers, target) {
    let l = 0;
    let r = numbers.length - 1;

    while (l < r) {
        if (numbers[l] + numbers[r] === target) {
            return [l + 1, r + 1];
        } else if (numbers[l] + numbers[r] > target) {
            r--;
        } else {
            l++;
        }
    }

    return [];
}

// Example usage:
// let numbers = [2, 7, 11, 15];
// let target = 9;
// console.log(twoSum(numbers, target)); // Output: [1, 2]
