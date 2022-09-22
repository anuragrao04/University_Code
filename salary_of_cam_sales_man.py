num_of_cams = int(input("Enter number of cameras sold: "))
price = int(input("Enter total revenue: "))
salary = 25000 + (0.12*price) + (num_of_cams*200)
print("salary is: ", salary)