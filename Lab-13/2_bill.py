from datetime import date

class Bill:
    def __init__(self, date, customerName, deets):
        self.date = date
        self.customerName = customerName
        self.deets = deets

    def generateBill(self):
        billFormatted = ''
        for i in self.deets:
            for j in i:
                billFormatted += j.ljust(12, ' ')
            billFormatted += '\n'

        print(f'''
Date: {self.date}
Customer Name: {self.customerName}
Name        Rate        Quantity    Total
{billFormatted}
''')



bill = Bill(
    date=date.today(),
    customerName="Anurag",
    deets=[
        ["Samosa", "20", "2", "40"],
        ["BhelPuri", "30", "2", "60"],
        ["Limonata", "25", "2", "50"],
        ["BunSamosa", "25", "100", "2500"],
    ]
)

bill.generateBill()