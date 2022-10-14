"""
Write a python program to read student information (Name, SRN, 5 subject’s marks, and calculate average marks and percentage. Marks are entered out of 100. 
"""
import statistics
from prettytable import PrettyTable

name = input("Enter Name: ")
srn = input("Enter SRN: ")
subject_marks = []
for i in range(1,6):
    subject_marks.append(int(input("Enter Marks Obtained out of 100 in subject "+str(i)+": ")))

avg = statistics.fmean(subject_marks)
grade = ''
if avg >= 90: grade = 'S'
elif avg >= 80: grade = 'A'
elif avg >= 70: grade = 'B'
elif avg >= 60: grade = 'C'
elif avg >= 50: grade = 'D'
elif avg >= 40: grade = 'E'
else: grade = 'F'

table = PrettyTable()
table.field_names = ['Detail', 'Value']
table.add_rows(
    [
        ["Name", name],
        ["SRN", srn],
        ["Subject1 Marks", subject_marks[0]],
        ["Subject2 Marks", subject_marks[1]],
        ["Subject3 Marks", subject_marks[2]],
        ["Subject4 Marks", subject_marks[3]],
        ["Subject5 Marks", subject_marks[4]],
        ["Average Marks:", avg],
        ["Percentage", str(avg)+"%"],
        ["Grade", grade]
    ]
)

print(table)
