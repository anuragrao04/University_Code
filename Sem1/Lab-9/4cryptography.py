def encrypt(s):
    for i in range(len(s)):
        s[i] = chr(ord(s[i]) + 1) 

def decrypt(s):
    for i in range(len(s)):
        s[i] = chr(ord(s[i]) - 1) 


s = "hello!"
s = list(s)

encrypt(s)
print("Encrypted:", ''.join(s))
decrypt(s)
print("Decrypted:", ''.join(s))


