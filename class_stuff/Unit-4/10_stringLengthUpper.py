l = ["pes", "pesuacademy", "hello", "anurag"]

print(list(map(str.upper, filter(lambda x: len(x) < 4, l ))))
