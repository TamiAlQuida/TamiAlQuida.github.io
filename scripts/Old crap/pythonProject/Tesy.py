from lxml import html
import requests

page_analysis = requests.get('https://finance.yahoo.com/quote/AAPL/analysis?p=AAPL')

tree_analysis = html.fromstring(page_analysis.content)

g = tree_analysis.xpath('/html/body/div[1]/div/div/div[1]/div/div[3]/div[1]/div/div[1]/section/table[6]/tbody/tr[5]/td[2]')


print("g (growth rate for next 5 years per year):", g)