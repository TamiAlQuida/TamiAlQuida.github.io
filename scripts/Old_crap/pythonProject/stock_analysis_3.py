
import pandas as pd
from requests_html import HTMLSession
from time import sleep
from random import random

# ticker = input("What stock/ticker do you want to analyse?")
#tickers = ['AAPL', 'MSFT', 'BRK-B', 'AMZN', 'TSLA', 'META', 'NVDA', 'GOOG', 'AMD', 'BABA']
tickers = ['AAPL', 'MSFT', 'BRK-B','AMZN', 'TSLA', 'META', 'UNH', 'V', 'NVDA', 'JNJ', 'XOM', 'WMT', 'JPM', 'PG', 'MA', 'HD', 'LLY', 'PFE', 'CVX', 'BAC', 'KO', 'ABBV', 'COST', 'PEP', 'MRK', 'TMO', 'AVGO', 'DHR', 'VZ', 'ORCL', 'ABT', 'ADBE', 'ACN', 'DIS', 'CMCSA', 'MCD', 'CSCO', 'CRM', 'QCOM', 'NKE', 'TMUS', 'INTC', 'WFC', 'UPS', 'BMY', 'NEE', 'TXN', 'AMD', 'MS', 'PM', 'LIN', 'RTX', 'T', 'UNP', 'AMGN', 'LOW', 'SPGI', 'HON', 'CVS', 'MDT', 'INTU', 'SCHW', 'AMT', 'COP', 'IBM', 'AXP', 'GS', 'ELV', 'LMT', 'C', 'NFLX', 'BLK', 'DE', 'CAT', 'PYPL', 'SBUX', 'BA', 'EL', 'PLD', 'NOW', 'ADP', 'AMAT', 'ADI', 'ZTS', 'MDLZ', 'CI', 'CHTR', 'ISRG', 'DUK', 'MMC', 'CB', 'GOOG', 'GOOGL', 'MO', 'GILD', 'MMM', 'SYK', 'SO', 'GE', 'CCI', 'TJX', 'BKNG', 'CME', 'TGT', 'VRTX', 'USB', 'NOC', 'MU', 'BDX', 'CSX', 'MRNA']

#headers = {'User-Agent': 'Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:109.0) Gecko/20100101 Firefox/125.0.2'}
headers={'User-Agent': 'Custom'}

print("V = EPS * (1 + r) * P/E")
print("V = Intrinsic Value \n"
      "EPS = Earnings per share \n"
      "P/E = price per earnings \n"
      "r = Expected earnings growth rate \n")

counter = 1
summary_dict = {'stock': [], 'EPS': [], 'P/E': [], 'growth_5_years': [], 'actual price': [], 'intrinsic value': [], 'price evaluation': []}


def sleep_random_time ():
    time_to_sleep = 5 + (10 * random())
    print(time_to_sleep)
    sleep(time_to_sleep)


def parse_data_yahoo (ticker):
    try:
        print(ticker)
    
        """ Web adresses"""
        page_summary = f'https://finance.yahoo.com/quote/{ticker}'
        page_analysis = f'https://finance.yahoo.com/quote/{ticker}/analysis'

        """Parsing the summary page with requests_html"""
        request_page_summary = HTMLSession().get(page_summary)
        sel_previous_close = 'li.yf-dudngy:nth-child(1) > span:nth-child(2) > fin-streamer:nth-child(1)' #Firefox-> copy CSS Selector.
        previous_close = request_page_summary.html.find(sel_previous_close, first=True).text

        sel_EPS = 'li.last-md:nth-child(12) > span:nth-child(2) > fin-streamer:nth-child(1)' #Firefox-> copy CSS Selector.
        EPS = request_page_summary.html.find(sel_EPS, first=True).text

        sel_PE = 'li.yf-dudngy:nth-child(11) > span:nth-child(2) > fin-streamer:nth-child(1)' #Firefox-> copy CSS Selector.
        PE = request_page_summary.html.find(sel_PE, first=True).text

        """Parsing the analysis page with requests_html"""
        request_page_analysis = HTMLSession().get(page_analysis)
        sel_growth_5_years = '.gridLayout > section:nth-child(9) > div:nth-child(2) > table:nth-child(1) > tbody:nth-child(2) > tr:nth-child(1) > td:nth-child(5)' #Firefox-> copy CSS Selector.
        growth_5_years = request_page_analysis.html.find(sel_growth_5_years, first=True).text

        """Convert strings into floats"""
        previous_close_float = float(previous_close)
        EPS_float = float(EPS)
        PE_float = float(PE)
        growth_5_years_float = float(growth_5_years.replace("%","")) / 100

        """Make calculations"""
        v = PE_float * EPS_float * (1 + growth_5_years_float) #intrinsic value

        price_evaluation = previous_close_float / v #ratio between actual price and intrinsic value

        """Put the values in the dictionary"""
        summary_dict['stock'] += [ticker]
        summary_dict['EPS'] += [EPS]
        summary_dict['P/E'] += [PE]
        summary_dict['growth_5_years'] += [growth_5_years]
        summary_dict['actual price'] += [previous_close_float]
        summary_dict['intrinsic value'] += [v]
        summary_dict['price evaluation'] += [price_evaluation]
        #print(summary_dict)

        print(f"{counter}" + "/" + f"{len(tickers)}")
        counter += 1

        sleep_random_time()

    except:
        print("Failed for some reason")
        sleep_random_time()


for ticker in tickers:
    parse_data_yahoo(ticker)
    sleep_random_time


df = pd.DataFrame.from_dict(summary_dict)
print(df)

df.to_csv('stock_values.csv', index=False)
