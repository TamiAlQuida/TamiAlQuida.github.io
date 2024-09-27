
import matplotlib.pyplot as plt

"""Payment input details"""
years = 30
# Initial house prices
cheap_house = 2000000
expensive_house = 3000000
# Monthly payments for each house (assumed to be the same for both)
payment_per_month_cheap = 20000
payment_per_month_expensive = 20000
# Down payment percentage (15%)
kontantinsats = 0.15
# Annual price increase rates for each house
cheap_house_price_increase = 0.19  # 4%
expensive_house_price_increase = 0.19  # 5%
# monthly price increase rate for each house as a function of the annual price increase rate for each house
cheap_house_monthly_price_increase = (1 + cheap_house_price_increase) ** (1/12) - 1
expensive_house_monthly_price_increase = (1 + expensive_house_price_increase) ** (1/12) - 1
print(f"Cheap house monthly price increase: {cheap_house_monthly_price_increase}")
print(f"Expensive house monthly price increase: {expensive_house_monthly_price_increase} \n")
# Annual loan interest rate
loan_interest_rate = 0.0481  # 3%
# Monthly loan interest rate
monthly_interest_rate = loan_interest_rate / 12

"""Calculations"""
# Calculate down payment in SEK for each house
down_payment_cheap = cheap_house * kontantinsats
down_payment_expensive = expensive_house * kontantinsats
# Calculate actual loan amounts after down payment
actual_loan_cheap = cheap_house * (1 - kontantinsats)
actual_loan_expensive = expensive_house * (1 - kontantinsats)

actual_loan_left_cheap = actual_loan_cheap
actual_loan_left_expensive = actual_loan_expensive

counter = 0
money_bank_cheap = -down_payment_cheap
money_bank_expensive = -down_payment_expensive
total_interest_paid_cheap = 0
total_interest_paid_expensive = 0

house_value_cheap_each_month = []
house_value_expensive_each_month = []

money_bank_cheap_each_month = []
money_bank_expensive_each_month = []

total_value_cheap_each_month = []
total_value_expensive_each_month = []

for i in range(12*years):
    counter += 1
    print(f"\nMonth {counter}")

    if actual_loan_left_cheap > 0:
        actual_loan_left_cheap -= payment_per_month_cheap - actual_loan_left_cheap * monthly_interest_rate
        actual_interest_paid_cheap_monthly = actual_loan_left_cheap * monthly_interest_rate
        actual_loan_paid_cheap_monthly = payment_per_month_cheap - actual_interest_paid_cheap_monthly
        total_interest_paid_cheap += actual_interest_paid_cheap_monthly
        money_bank_cheap -= actual_interest_paid_cheap_monthly
        
        print(f"Actual loan left cheap: {actual_loan_left_cheap}")
        print(f"Actual interest paid cheap: {actual_interest_paid_cheap_monthly}")
        print(f"Actual loan paid cheap: {actual_loan_paid_cheap_monthly}")
        print(f"Total interest paid cheap: {total_interest_paid_cheap} \n")
        
    else:
        money_bank_cheap += payment_per_month_cheap
        print(f"Money bank cheap: {money_bank_cheap} \n")

    if actual_loan_left_expensive > 0:
        actual_loan_left_expensive -= payment_per_month_expensive - actual_loan_left_expensive * monthly_interest_rate
        actual_interest_paid_expensive_monthly = actual_loan_left_expensive * monthly_interest_rate
        actual_loan_paid_expensive_monthly = payment_per_month_expensive - actual_interest_paid_expensive_monthly
        total_interest_paid_expensive += actual_interest_paid_expensive_monthly
        money_bank_expensive -= actual_interest_paid_expensive_monthly

        
        
        print(f"Actual loan left expensive: {actual_loan_left_expensive}")
        print(f"Actual interest paid expensive: {actual_interest_paid_expensive_monthly}")
        print(f"Actual loan paid expensive: {actual_loan_paid_expensive_monthly}")
        print(f"Total interest paid expensive: {total_interest_paid_expensive} \n")
        
    else:
        money_bank_expensive += payment_per_month_expensive
        print(f"Money bank expensive: {money_bank_expensive} \n")
    
    cheap_house += cheap_house * cheap_house_monthly_price_increase
    expensive_house += expensive_house * expensive_house_monthly_price_increase
    print(f"House value cheap: {cheap_house}")
    print(f"House value expensive: {expensive_house} \n")

    house_value_cheap_each_month.append(cheap_house)
    house_value_expensive_each_month.append(expensive_house)

    money_bank_cheap_each_month.append(money_bank_cheap)
    money_bank_expensive_each_month.append(money_bank_expensive)

    total_value_cheap_each_month.append(cheap_house + money_bank_cheap)
    total_value_expensive_each_month.append(expensive_house + money_bank_expensive)

"""Plotting"""
plt.figure(figsize=(12, 6))
plt.plot(house_value_cheap_each_month, label='Cheap House Value')
plt.plot(house_value_expensive_each_month, label='Expensive House Value')
plt.xlabel('Months')
plt.ylabel('House Value')
plt.title('House Value Over Time')
plt.legend()
plt.show()

plt.figure(figsize=(12, 6))
plt.plot(money_bank_cheap_each_month, label='Money Bank Cheap')
plt.plot(money_bank_expensive_each_month, label='Money Bank Expensive')
plt.xlabel('Months')
plt.ylabel('Money Bank')
plt.title('Money Bank Over Time')
plt.legend()
plt.show()

plt.figure(figsize=(12, 6))
plt.plot(total_value_cheap_each_month, label='Total Value Cheap')
plt.plot(total_value_expensive_each_month, label='Total Value Expensive')
plt.xlabel('Months')
plt.ylabel('Total Value')
plt.title('Total Value Over Time')
plt.legend()
plt.show()

