#a
mul = lambda x,y: x*y
print(mul(2,3))

#b
st = lambda x, character: x[0] == character
print(st("python", 'p'))

#c
import datetime
ymd = lambda: print(datetime.date.today().strftime("%B %d, %Y"))
ymd()

#d
laptops = [{'brand':'apple', 'model':'macbook', 'color':'space grey'},
        {'brand':'asus', 'model':'zenbook', 'color':'matte black'}]
#sorting by brand
print(sorted(laptops, key = lambda x: x['color']))






