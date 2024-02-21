import pandas
import matplotlib.pyplot as plt
import requests
from lxml import html
from selenium import webdriver
from selenium.webdriver.common.by import By

print("\nV = EPS * (8.5 + 2*g) * 4.4 / Y \n"
      "V = Intrinsic Value \n"
      "EPS = Earnings per share \n"
      "8.5 = P/E Base for s No-Growth company \n"
      "g = Growth rate for next 5 years \n"
      "4.4 = Average yield of AAA corporate Bonds\n"
      "Y = Current yield of AAA Corporate bonds\n")

"""Check FRED AAA bonds"""
browser = webdriver.Firefox()
browser.get('https://fred.stlouisfed.org/series/AAA')
Y_input = browser.find_element(by=By.XPATH, value='/html/body/div/div[2]/div/div[2]/div[1]/div[2]/span[2]')
Y_string = Y_input.text
Y = float(Y_string)
browser.close()

"""What stocks to analyze"""
df = pandas.read_csv("stocks_in_the_sp_500_index.csv")
df_to_list = df["Symbol"]
tickers = df_to_list.values.tolist()
# print(tickers)

for i in range(0, 5):
    stock_to_analyze = tickers[i]
    print(stock_to_analyze)

    try:
        """Check yahoo summary"""
        page_summary = requests.get(
            'https://finance.yahoo.com/quote/{}?p={}'.format(stock_to_analyze, stock_to_analyze))
        tree_summary = html.fromstring(page_summary.content)

        previous_close_list = tree_summary.xpath(
            '/html/body/div[1]/div/div/div[1]/div/div[3]/div[1]/div/div[1]/div/div/div/'
            'div[2]/div[1]/table/tbody/tr[1]/td[2]/text()')
        previous_close = float(previous_close_list[0])

        # PE_ratio_list = tree_summary.xpath(
        #     '/html/body/div[1]/div/div/div[1]/div/div[3]/div[1]/div/div[1]/div/div/div/div[2]/'
        #     'div[2]/table/tbody/tr[3]/td[2]/text()')
        # PE_ratio = float(PE_ratio_list[0])

        EPS_list = tree_summary.xpath(
            '/html/body/div[1]/div/div/div[1]/div/div[3]/div[1]/div/div[1]/div/div/div/div[2]/div[2]/'
            'table/tbody/tr[4]/td[2]/text()')
        EPS = float(EPS_list[0])

        """Check yahoo analysis"""
        browser = webdriver.Firefox()
        browser.get('https://finance.yahoo.com/quote/{}/analysis?p={}'.format(stock_to_analyze, stock_to_analyze))
        g_input = browser.find_element(by=By.XPATH,
                                       value='/html/body/div[1]/div/div/div[1]/div/div[3]/div[1]/div/div[1]/div/div/'
                                             'section/table[6]/tbody/tr[5]/td[2]')
        g_string = g_input.text
        g_string_clean = g_string.replace('%', '')
        g = float(g_string_clean)
        browser.close()

        V = EPS * (8.5 + 2 * g) * 4.4 / Y

        """print results"""
        # print('\nY (current yield from AAA bonds):', Y)
        # print('PE_ratio:', PE_ratio, )
        # print('EPS:', EPS)
        # print('g:', g)
        print('\nprevious_close:', previous_close)
        print('V (=Intrinsic value):', V)
        print('Ratio (previous_close/V):', previous_close / V, "\n")

    except:
        print("something went wrong, probably missing values")
