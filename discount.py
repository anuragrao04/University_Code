price = int(input("Enter Price: "))

if price >= 5000: price -= 0.2*price
elif price >= 3000: price -= 0.15*price
elif price >= 1000: price -= 0.1*price

print("Discounted price: ", price)




