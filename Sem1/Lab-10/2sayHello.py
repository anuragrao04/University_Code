from datetime import datetime
now = int(datetime.now().strftime("%H"))

def sevenToTen(func):
    def inner(now):
        if now >= 7 and now <= 22:
            func(now)
        else: print("No greeting for you")
    return inner

@sevenToTen
def sayHello(now):
    print("Hello!")


sayHello(now)