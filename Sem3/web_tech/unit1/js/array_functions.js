let arr1 = [
  {
    name: 'anurag',
    age: 18
  },
  {
    name: 'cupcake',
    age: 5
  },
]


arr1.sort(function(a, b) {
  return a.age - b.age;
});

console.log(arr1);
