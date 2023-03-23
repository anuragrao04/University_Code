st = "How much would a wood would a wood chuck chuck if a wood chuck could chuck wood"

st = st.split()
map = {}

for i in st:
    print(i)
    if i in map:
        map[i] += 1
    else: map[i] = 1

print(map)
