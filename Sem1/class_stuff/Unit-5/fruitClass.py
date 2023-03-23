class Fruit:
    def __init__(self, color, name):
        self.color = color
        self.name = name

    def tellColor(self):
        print(f"I am {self.name} and I am", self.color ,"in color")


apple = Fruit("red", "apple")
mango = Fruit("yellow", "mango")
orange = Fruit("orange", "orange")

apple.tellColor()
mango.tellColor()
orange.tellColor()


