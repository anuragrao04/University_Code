s = input()
stop_words = ["is", "an", "that", "this"]


print(" ".join(filter(lambda x: x not in stop_words, s.split())))

