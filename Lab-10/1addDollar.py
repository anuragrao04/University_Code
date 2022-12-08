def addDollar(func): return lambda number : print(f"${number}"); 


@addDollar
def day_earnings(number):
    pass

day_earnings(40)

