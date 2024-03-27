package main

import (
  "fmt"
)
func fun1() {
  for i := 1; i < 5; i++ {
  fmt.Println("fun1: ", i);
  }
}

func fun2() {
  for i := 5; i < 9; i++ {
  fmt.Println("fun2: ", i);
  }
}

func main() {
  go fun1()
  go fun2()
  fmt.Scanln()
  fmt.Println("main terminated")
}
