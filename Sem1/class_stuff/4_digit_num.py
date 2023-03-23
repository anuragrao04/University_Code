num = int(input("Enter the 4 digit number: "))
a = num%10
b = int((num/10)%10)
c = int((num/100) % 10)
d = int((num/1000) % 10)
print("digits are: ", a, b, c, d)
sum = a + b + c + d
print("sum of digits: ", sum)