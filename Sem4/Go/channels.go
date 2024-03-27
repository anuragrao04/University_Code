package main

import (
  "fmt"
)

func fun1(c chan int) {
  for i := 1; i < 5; i++ {
    c <- i
  }
  close(c)
}

func fun2(c chan int) {
  for i := 5; i < 9; i++ {
    c <- i
  }
  close(c)
}

func main() {
  c1 := make(chan int)
  c2 := make(chan int)
  go fun1(c1)
  go fun2(c2)
  for {
    v1, ok1 := <-c1
    v2, ok2 := <-c2
    if ok1 == false && ok2 == false {
      break
    }
    fmt.Println("Received: ", v1, v2)
  }
  fmt.Println("main terminated")
}
