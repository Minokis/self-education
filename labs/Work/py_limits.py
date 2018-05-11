# 1. import and parse the header
# 2. find side, active volume and filled volume, price
# 3. count BOV, SOV, BTV, STV
# 4. show table (identical to the one in the Front End)
import csv
import sys


#1
if len(sys.argv) not in (2,3):
    print("Wrong arguments. Specify filename. Add rate, if applicable.")
    exit(0)

filename = str(sys.argv[1])
if len(sys.argv) == 3:
    print('I see you want some rate to use. OK!')
    rate = float(sys.argv[2])
else:
    rate = 1

with open(filename, 'r', newline='') as fn:
    reader = csv.reader(fn, delimiter=';')
    header = reader.__next__()
    print(header)

    #2
    columns = {}
    columnKeys = ['Active #', 'Filled #', 'Price', 'Side', 'Factor', 'Instrument']
    for key in columnKeys:
        for i in range(len(header)):
            if header[i] == key:
                columns[key] = i
    if len(columns) != len(columnKeys):
        print("Warning! Some values are absent.")

    buyOrderVolume = 0
    buyOrderValue = 0
    buyTradeVolume = 0
    buyTradeValue = 0

    sellOrderVolume = 0
    sellOrderValue = 0
    sellTradeVolume = 0
    sellTradeValue = 0

    #3

    for row in reader:
        try:
            if row[columns['Side']] == 'Buy' and row[columns['Price']] != '':
                buyOrderVolume += float(row[columns['Active #']])
                buyOrderValue += rate * float(row[columns['Active #']])*float(row[columns['Price']])* float(row[columns['Factor']])
                buyTradeVolume += float(row[columns['Filled #']])
                buyTradeValue += rate * float(row[columns['Filled #']])*float(row[columns['Price']])*float(row[columns['Factor']])
            if row[columns['Side']] == 'Sell' and row[columns['Price']] != '':
                sellOrderVolume += float(row[columns['Active #']])
                sellOrderValue += rate * float(row[columns['Active #']]) * float(row[columns['Price']]) * float(row[columns['Factor']])
                sellTradeVolume += float(row[columns['Filled #']])
                sellTradeValue += rate * float(row[columns['Filled #']]) * float(row[columns['Price']]) * float(row[columns['Factor']])
        except Exception as err:
            print(err)
            print(row)
            exit(0)

    print("buyOrderVolume = {}\nbuyOrderValue = {}\nbuyTradeVolume = {}\nbuyTradeValue = {}\n".format(buyOrderVolume,\
        buyOrderValue, buyTradeVolume,buyTradeValue))
    print("sellOrderVolume = {}\nsellOrderValue = {}\nsellTradeVolume = {}\nsellTradeValue = {}\n".format(sellOrderVolume,\
        sellOrderValue, sellTradeVolume,sellTradeValue))
print("{:>15}{:>15}{:>15}{:>15}{:>15}{:>15}{:>15}{:>15}".format('Long Volume', 'Short Volume', \
                                                          'Long Value', 'Short Value', \
                                                          'Net Value', 'Net Volume', \
                                                          'Gross Value', 'Gross Volume'))
print("{0:>15.0f}{1:>15.0f}{2:>15.0f}{3:>15.0f}{4:>15.0f}{5:>15.0f}{6:>15.0f}{7:>15.0f}".format(buyOrderVolume, sellOrderVolume, \
    buyOrderValue+buyTradeValue-sellTradeValue, sellOrderValue+sellTradeValue-buyTradeValue, \
    max(buyOrderValue+buyTradeValue-sellTradeValue, sellOrderValue+sellTradeValue-buyTradeValue), \
    max(buyOrderVolume+buyTradeVolume-sellTradeVolume, sellOrderVolume+sellTradeVolume-buyTradeVolume), \
    buyOrderValue + buyTradeValue + sellOrderValue + sellTradeValue, \
    buyOrderVolume+ buyTradeVolume+ sellOrderVolume+ sellTradeVolume))


