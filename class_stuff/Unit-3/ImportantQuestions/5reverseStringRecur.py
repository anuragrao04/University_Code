def reverseString(st):
    if st == '': return ''
    else: return st[-1] + reverseString(st[:-1])

st = "abcd"

print(reverseString(st))