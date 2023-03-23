
fall_of_wickets = [10, 50, 100, 145, 150, 175]
diff = []
for i in range(1, len(fall_of_wickets)):
    diff.append(fall_of_wickets[i] - fall_of_wickets[i-1])

print(diff)
