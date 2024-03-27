package main

import "fmt"

func removeDuplicates(a[10] int) [10] int {
  for i:=0; i<10; i++ {
    for j:=i+1; j<10; j++ {
      if a[i] == a[j] {
        a[j] = 0;
      }
    }
  }
  return a;
}

func main() {
  var a = [10] int {1,2,3,4,5,5,7,8,8,10};
  // we have to remove duplicates
  a = removeDuplicates(a);
  fmt.Println(a);
}
