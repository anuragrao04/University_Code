
# Using input as the number of terms
def recursiveFibonacci(n):  
   if n <= 1:  
       return n  
   else:  
       return(recursiveFibonacci(n-1) + recursiveFibonacci(n-2))  
 
nterms = int(input("How many terms? "))   

print("Fibonacci sequence:")  
for i in range(nterms):  
    print(recursiveFibonacci(i))  

# Time Complexity: O(2^N) => terrible


# Using input as max term
maxTerm = int(input("Max term? "))
i = 0
term = 0
while(True):
    term = recursiveFibonacci(i)
    if(term > maxTerm): break
    
    # The below part of the code executes only if not broke out of loop
    print(term)
    i += 1
