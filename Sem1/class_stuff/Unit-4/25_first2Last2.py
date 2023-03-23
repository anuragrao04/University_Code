l = ["pear", "apple", "banana", "kiwi"]
print([i[:2] + i[-2:] for i in l if len(i) >= 4])