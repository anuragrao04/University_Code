class Company:
    def __init__(self, companyName, turnover, revenue, noOfEmployees):
        self.companyName = companyName
        self.turnover = turnover
        self.revenue = revenue
        self.noOfEmployees = noOfEmployees

    def getProductivity(self):
        productivity = self.revenue / self.noOfEmployees
        return productivity


company = Company(
    companyName="GrowPal",
    turnover=2000,
    revenue=5000,
    noOfEmployees=5,
)

print(f"productivity: {company.getProductivity()}")
