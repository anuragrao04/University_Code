
#  2)Given a list : SRN, P_marks, C_marks, M_marks and B_marks.
#  1. Create a dict with SRN as the key and marks in P, C, M, B as a list.
#  2. Make another dict of srn and total marks and display in the order of marks.

srn = [1,2,3]
P_marks = [90, 89, 91]
C_marks = [99, 85, 99]
M_marks = [88, 86, 89]
B_marks = [98, 88, 85]


#1
d1 = {}
for i in range(len(srn)):
    d1[srn[i]] = [P_marks[i], C_marks[i], M_marks[i], B_marks[i]]
print(d1)

#2
d2 = {}
for i in range(len(srn)):
    d2[srn[i]] = P_marks[i] + C_marks[i] + M_marks[i] + B_marks[i]

d2 = sorted(d2.items(), key=lambda x : x[1])
print(d2)

