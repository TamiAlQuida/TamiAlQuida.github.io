
import pandas as pd
import requests
from io import StringIO

# ticker = input("What stock/ticker do you want to analyse?")
tickers = ['AAPL', 'MSFT', 'AMZN', 'TSLA', 'META']

headers = {'User-Agent': 'Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:109.0) Gecko/20100101 Firefox/113.0'}

print("V = EPS * (1 + r) * P/E")
print("V = Intrinsic Value \n"
      "EPS = Earnings per share \n"
      "r = Expected earnings growth rate \n"
      "P/E = price per earnings \n")

counter = 0
summary_dict = {}

for i in tickers:
    
    """ Request the page"""
    page_summary = f'https://finance.yahoo.com/quote/{i}?p={i}'
    page_analysis = f'https://finance.yahoo.com/quote/{i}/analysis?p={i}'

    """Parsing the page"""
    actual_price = pd.read_html(StringIO(requests.get(page_summary, headers=headers).text))[0]
    summary_EPS_PE = pd.read_html(StringIO(requests.get(page_summary, headers=headers).text))[1]
    analysis_growth_estimates = pd.read_html(StringIO(requests.get(page_analysis, headers=headers).text))[5]
    #print(actual_price)
    #print(summary_EPS_PE)
    #print(analysis_growth_estimates)

    actual_price_column = actual_price[1]
    actual_price_previous_close = float(actual_price_column.values.tolist()[0])

    summary_EPS_PE_numbers = summary_EPS_PE[1]
    pe = float(summary_EPS_PE_numbers.values.tolist()[2])
    eps = float(summary_EPS_PE_numbers.values.tolist()[3])

    growth_estimates_ticker = analysis_growth_estimates[i]
    r = float(growth_estimates_ticker.values.tolist()[-2].replace("%","")) / 100

    v = pe * eps * (1+r)

    price_evaluation = actual_price_previous_close / v
    
    #print(actual_price_previous_close)
    #print(summary_EPS_PE_numbers)
    #print(pe)
    #print(eps)
    #print(r)
    #print(v)
    
    summary_dict[counter] = i, actual_price_previous_close, v, price_evaluation
    
    print(f"{counter}" + "/" + f"{len(tickers)}")
    counter += 1
      
print(summary_dict)
