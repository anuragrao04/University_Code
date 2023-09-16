arr1 = [1, 2, 3, 4, "hello", ["this another array", "this another"]]; // object literal method
arr2 = new Array(69); // object constructor method. Creates an array of size 69
arr3 = new Array(5, 6, 7); // object constructor method, but creates an array with elements 5, 6, and 7


for (const i of arr1) {
  console.log(i);
}
