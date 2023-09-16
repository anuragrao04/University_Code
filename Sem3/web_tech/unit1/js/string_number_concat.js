let text1 = "ABC"
let text2 = "DEF"


console.log(text1 + text2); // ABCDEF - works intuitively
console.log(text1 + 2 + 2); // ABC22 - wtf
console.log(2 + 2 + text1) // 4ABC - wtf again


console.log("5" + 5); // 55
console.log(5 + 5) // 10
