import datetime
date = input("dd/mm/yy : ")
d, m, y = date.split('/')

valid = True
try: 
    date = datetime.datetime(int(y), int(m), int(d))
except: 
    print("Invalid Date")
    valid = False

if valid: 
    nextday = date + datetime.timedelta(days=1)
    print(nextday.date())


