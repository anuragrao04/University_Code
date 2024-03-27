package main

import "fmt"

func main() {
  var a = [10] int {1,2,3,4,5,6,7,8,9,10};
  k := 3; // amount to rotate by
  var b [10] int;
  counter := 0;
  for i:=k; i<10; i++ {
    b[counter] = a[i];
    counter++;
  }
  for i:=0; i < k; i++{
    b[counter] = a[i];
    counter++;
  }
  fmt.Println(b);
}
