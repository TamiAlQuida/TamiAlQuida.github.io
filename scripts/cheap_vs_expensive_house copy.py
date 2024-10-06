
import matplotlib.pyplot as plt

"""Payment input details"""
years = 20
# Initial house prices
cheap_house = 2000000
expensive_house = 3000000
# Monthly payments for each house (assumed to be the same for both)
payment_per_month_cheap = 20000
payment_per_month_expensive = 20000
# Down payment percentage (15%)
down_payment_cheap_rate = 0.15
down_payment_expensive_rate = 0.15
# Annual price increase rates for each house
cheap_house_price_increase = 0.05  # 4%
expensive_house_price_increase = 0.05  # 5%
# Annual loan interest rate
loan_interest_rate = 0.05 #0.0481  # 4,8%
# Annual stock market return rate
stock_return_rate = 0.1  # 10%

# monthly price increase rate for each house as a function of the annual price increase rate for each house
cheap_house_monthly_price_increase = (1 + cheap_house_price_increase) ** (1/12) - 1
expensive_house_monthly_price_increase = (1 + expensive_house_price_increase) ** (1/12) - 1
# Monthly loan interest rate
monthly_interest_rate = loan_interest_rate / 12
# Monthly stock market return rate
monthly_stock_return_rate = (1 + stock_return_rate) ** (1/12) - 1

print(monthly_stock_return_rate)

"""Calculations"""
# Calculate down payment in SEK for each house
down_payment_cheap = cheap_house * down_payment_cheap_rate
down_payment_expensive = expensive_house * down_payment_expensive_rate
# Calculate actual loan amounts after down payment
actual_debt_cheap = cheap_house * (1 - down_payment_cheap_rate)
actual_debt_expensive = expensive_house * (1 - down_payment_expensive_rate)

actual_debt_left_cheap = actual_debt_cheap
actual_debt_left_expensive = actual_debt_expensive

counter = 0
money_bank_cheap = - down_payment_cheap
money_bank_expensive = - down_payment_expensive

total_interest_paid_cheap = 0
total_interest_paid_expensive = 0

"""Lists to stored values for plotting"""
house_value_cheap_each_month = []
house_value_expensive_each_month = []

money_bank_cheap_each_month = []
money_bank_expensive_each_month = []

dept_cheap_each_month = []
dept_expensive_each_month = []

balance_cheap_each_month = []
balance_expensive_each_month = []

total_value_cheap_each_month = []
total_value_expensive_each_month = []

"""Loop through each month for the duration of the loan"""
for i in range(12*years):
    counter += 1
    print(f"\nMonth {counter}")

    """Calculate payments for the cheap house"""
    if actual_debt_left_cheap > 0:
        actual_debt_left_cheap -= payment_per_month_cheap - actual_debt_left_cheap * monthly_interest_rate

        actual_interest_paid_cheap_monthly = actual_debt_left_cheap * monthly_interest_rate
        actual_loan_paid_cheap_monthly = payment_per_month_cheap - actual_interest_paid_cheap_monthly
        total_interest_paid_cheap += actual_interest_paid_cheap_monthly
        
        print(f"Actual debt left cheap: {actual_debt_left_cheap}")
        print(f"Actual interest paid cheap: {actual_interest_paid_cheap_monthly}")
        print(f"Actual debt paid cheap: {actual_loan_paid_cheap_monthly}")
        print(f"Total interest paid cheap: {total_interest_paid_cheap} \n")
        
    else:
        """If the loan is paid off, add the monthly payment to the money bank"""
        money_bank_cheap += money_bank_cheap * monthly_stock_return_rate
        money_bank_cheap += payment_per_month_cheap
        print(f"Money bank cheap: {money_bank_cheap} \n")


    """Calculate payments for the expensive house"""
    if actual_debt_left_expensive > 0:
        actual_debt_left_expensive -= payment_per_month_expensive - actual_debt_left_expensive * monthly_interest_rate

        actual_interest_paid_expensive_monthly = actual_debt_left_expensive * monthly_interest_rate
        actual_loan_paid_expensive_monthly = payment_per_month_expensive - actual_interest_paid_expensive_monthly      
        total_interest_paid_expensive += actual_interest_paid_expensive_monthly  
        
        print(f"Actual dept left expensive: {actual_debt_left_expensive}")
        print(f"Actual interest paid expensive: {actual_interest_paid_expensive_monthly}")
        print(f"Actual dept paid expensive: {actual_loan_paid_expensive_monthly} ")
        print(f"Total interest paid expensive: {total_interest_paid_expensive} \n")

        
    else:
        """If the loan is paid off, add the monthly payment to the money bank"""
        money_bank_expensive += money_bank_expensive * monthly_stock_return_rate
        money_bank_expensive += payment_per_month_cheap
        print(f"Money bank expensive: {money_bank_expensive} \n")
    
    """Calculate the new value of the houses"""
    cheap_house += cheap_house * cheap_house_monthly_price_increase
    expensive_house += expensive_house * expensive_house_monthly_price_increase
    print(f"House value cheap: {cheap_house}")
    print(f"House value expensive: {expensive_house} \n")


    """Store the values for plotting"""
    house_value_cheap_each_month.append(cheap_house)
    house_value_expensive_each_month.append(expensive_house)

    money_bank_cheap_each_month.append(money_bank_cheap)
    money_bank_expensive_each_month.append(money_bank_expensive)

    dept_cheap_each_month.append(actual_debt_left_cheap)
    dept_expensive_each_month.append(actual_debt_left_expensive)

    balance_cheap_each_month.append(money_bank_cheap - actual_debt_left_cheap)
    balance_expensive_each_month.append(money_bank_expensive - actual_debt_left_expensive)

    total_value_cheap_each_month.append(cheap_house + money_bank_cheap - actual_debt_left_cheap)
    total_value_expensive_each_month.append(expensive_house + money_bank_expensive - actual_debt_left_expensive)


"""Plotting"""
"""Plot the house value over time"""
plt.figure(figsize=(12, 6))
plt.plot(house_value_cheap_each_month, label='Cheap House Value')
plt.plot(house_value_expensive_each_month, label='Expensive House Value')
plt.xlabel('Months')
plt.ylabel('House Value')
plt.title('House Value Over Time')
plt.legend()
plt.show()

"""Plot the money on the bank over time"""
plt.figure(figsize=(12, 6))
plt.plot(money_bank_cheap_each_month, label='Money Bank Cheap')
plt.plot(money_bank_expensive_each_month, label='Money Bank Expensive')
plt.xlabel('Months')
plt.ylabel('Money Bank')
plt.title('Money Bank Over Time')
plt.legend()
plt.show()

"""Plot the debt over time"""
plt.figure(figsize=(12, 6))
plt.plot(dept_cheap_each_month, label='Dept Cheap')
plt.plot(dept_expensive_each_month, label='Dept Expensive')
plt.xlabel('Months')
plt.ylabel('Dept')
plt.title('Dept Over Time')
plt.legend()
plt.show()

"""Plot the balance over time"""
plt.figure(figsize=(12, 6))
plt.plot(balance_cheap_each_month, label='Balance Cheap')
plt.plot(balance_expensive_each_month, label='Balance Expensive')
plt.xlabel('Months')
plt.ylabel('Balance')
plt.title('Balance Over Time')
plt.legend()
plt.show()

"""Plot the total value over time"""
plt.figure(figsize=(12, 6))
plt.plot(total_value_cheap_each_month, label='Total Value Cheap')
plt.plot(total_value_expensive_each_month, label='Total Value Expensive')
plt.xlabel('Months')
plt.ylabel('Total Value')
plt.title('Total Value Over Time')
plt.legend()
plt.show()
