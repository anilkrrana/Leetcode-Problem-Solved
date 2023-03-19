
// var WordDictionary = function() {
    
// };

// /** 
//  * @param {string} word
//  * @return {void}
//  */
// WordDictionary.prototype.addWord = function(word) {
    
// };

// /** 
//  * @param {string} word
//  * @return {boolean}
//  */
// WordDictionary.prototype.search = function(word) {
    
// };

/** 
 * Your WordDictionary object will be instantiated and called as such:
 * var obj = new WordDictionary()
 * obj.addWord(word)
 * var param_2 = obj.search(word)
 */

function WordDictionary() {
  const words = {};

  function addWord(word) {
    words[word.length] = words[word.length] || {};
    words[word.length][word] = true;
  }

  function search(word) {
    if (!words[word.length]) {
      return false;
    }
    if (!word.includes('.')) {
      return !!words[word.length][word];
    }
    const regex = new RegExp(`^${word}$`);
    return Object.keys(words[word.length]).some(key => regex.test(key));
  }

  return {
    addWord,
    search
  };
}