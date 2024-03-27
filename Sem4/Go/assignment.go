package main

import "fmt"

func main() {
  var a = "cupcaki";
  b := "mine"; // shorthand for var b = "mine"
  c,d := 5,19;
  d,c = c, d;
  fmt.Println(a, "is", b, "and she is", c, "years old and I am", d, "years old");
}
