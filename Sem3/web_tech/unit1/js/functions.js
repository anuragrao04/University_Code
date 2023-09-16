function greet_and_sum(name, ...nums) {
  console.log("Hello " + name); // Hello cupcake
  console.log(age);
  console.log(nums); // [1,2,3,4]
  console.log("Your sum is: ");
  let total = 0;
  for (let num of nums) {
    total += num;
  }
  return total; // 10
}
console.log(greet_and_sum("cupcake", 1, 2, 3, 4)); 
