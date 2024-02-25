
import pandas as pd
import requests

# ticker = input("What stock/ticker do you want to analyse?")
ticker = 'AAPL'

""" Request the page"""
#page_summary = 'https://finance.yahoo.com/quote/AAPL?p=AAPL'
page_analysis = 'https://finance.yahoo.com/quote/AAPL/analysis?p=AAPL'

headers = {'User-Agent': 'Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:109.0) Gecko/20100101 Firefox/113.0'}

"""Parsing the page"""
#tree_summary = pd.read_html(requests.get(page_summary, headers=headers).text)[0]
tree_analysis = pd.read_html(requests.get(page_analysis, headers=headers).text)[5]

growth_estimates = tree_analysis[ticker]
growth_next_5_years = growth_estimates.values.tolist()[-1]

#print(tree_summary)
print(growth_next_5_years)