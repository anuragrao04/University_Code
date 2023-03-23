import datetime
print("Enter birthday in yyyy:mm:dd format: ")
bd = datetime.date(int(input()), int(input()), int(input()))
tdy = datetime.date.today()
days = (tdy-bd).days
seconds = days*86400
print("days: ", days, "seconds: ", seconds)

