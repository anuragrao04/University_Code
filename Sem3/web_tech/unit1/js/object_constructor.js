function Person(name, age) {
  this.name = name;
  this.age = age;
}

Person.prototype.sayName = function() {
  console.log(this.name);
}


let person1 = new Person("Anurag", 18);
let person2 = new Person("Cupcake", 18);

person1.sayName(); // Anurag
person2.sayName(); // Cupcake


