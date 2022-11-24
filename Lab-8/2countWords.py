search = input("Enter search word: ")
with open("2.txt", "r") as f:
    st = f.read().lower().split()
print(f"Occurances: {st.count(search)}")