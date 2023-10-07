/**
 * @param {Array} arr
 * @param {Function} fn
 * @return {Array}
 */// using quick sort
var sortBy = function(arr, fn) {
  // function quick sort
  const quickSort = (arr, leftBound = 0, rightBound = arr.length-1) => {
    if (leftBound < rightBound) {
      const pivotIdx = partition(arr, leftBound, rightBound);
      quickSort(arr, leftBound,pivotIdx-1);
      quickSort(arr, pivotIdx, rightBound);
    }
    return arr;
  }

  // function partition
  const partition = (arr, left, right) => {
    const pivot = fn(arr[Math.floor((right+left) /2)]);
    while (left <= right) {
      while (fn(arr[left]) < pivot) left++;
      while (fn(arr[right]) > pivot) right--;

      if (left <= right) {
        // swap
        const temp = arr[right];
        arr[right] = arr[left];
        arr[left] = temp;

        left++;
        right--;
      }
    }

    return left;
  }

  return quickSort(arr);
}