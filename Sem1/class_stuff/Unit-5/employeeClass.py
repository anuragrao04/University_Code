class Employee:
    def __init__(self, name, salary):
        self.legs = 2
        self.hands = 2
        self.name = name
        self.salary = salary

    def tellNameSalary(self):
        print(f"I am {self.name} and I earn {self.salary}. I have {self.hands} hands and {self.legs} legs")



bhanuPrakash = Employee("Bhanu Prakash", 69000)
bhanuPrakash.tellNameSalary()
