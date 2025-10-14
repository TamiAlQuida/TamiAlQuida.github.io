import matplotlib.pyplot as plt

invested_from_start = int(input('How much have you got invested in the stock market?'))
print(invested_from_start)

yearly_interest = float(input("Whats the expected yearly interest of the stock market? (in form 1.xx) "))
monthly_interest = yearly_interest ** (1 / 12)
print("the monthly interest: ", monthly_interest)

saved_money_from_salary_each_month = int(input('How much can you save each month?'))
print(saved_money_from_salary_each_month)

how_many_years_you_are_investing = int(input('How many years are you planning to do this for?'))
amount_of_months = how_many_years_you_are_investing * 12
print("so you will have {} months".format(amount_of_months))


def modify_values():
    """A function that lets you update values"""

    modify_a_value = input("Change a value value? (number + enter) \n \
        1 Start capital \n \
        2 Yearly interest\n \
        3 How much you save each month\n \
        4 How many years\n")

    if modify_a_value == "1":
        global invested_from_start
        invested_from_start = int(input('How much have you got invested in the stock market?'))

    elif modify_a_value == "2":
        global yearly_interest, monthly_interest
        yearly_interest = float(input("Whats the expected yearly interest of the stock market? (in form 1.xx) "))
        monthly_interest = yearly_interest ** (1 / 12)

    elif modify_a_value == "3":
        global saved_money_from_salary_each_month
        saved_money_from_salary_each_month = int(input('How much can you save each month?'))

    elif modify_a_value == "4":
        global how_many_years_you_are_investing, amount_of_months
        how_many_years_you_are_investing = int(input('How many years are you planning to do this for?'))
        amount_of_months = how_many_years_you_are_investing * 12

    else:
        modify_values()


def calculate_end_result():
    """A function that calculates how much money you will have if you invest"""

    new_total_amount = invested_from_start

    new_total_amount_of_months = 0
    total_amount_of_months = []
    for i in range(1, amount_of_months + 1):
        new_total_amount_of_months += 1
        total_amount_of_months.append(new_total_amount_of_months)

    total_investment_each_month = []

    for i in range(1, amount_of_months + 1):
        new_total_amount += new_total_amount * monthly_interest - new_total_amount + saved_money_from_salary_each_month
        total_investment_each_month.append(new_total_amount)
    # print(list(total_investment_each_month))

    new_total_amount_if_not_investing = invested_from_start
    if_you_do_not_invest = []
    for i in range(1, amount_of_months + 1):
        new_total_amount_if_not_investing += saved_money_from_salary_each_month
        if_you_do_not_invest.append(new_total_amount_if_not_investing)

    # plt.scatter(total_amount_of_months, total_investment_each_month)
    plt.plot(total_amount_of_months, total_investment_each_month)
    plt.plot(total_amount_of_months, if_you_do_not_invest)
    plt.legend(['invested', 'not invested'])
    plt.show()


while True:
    print(calculate_end_result())
    print(modify_values())
