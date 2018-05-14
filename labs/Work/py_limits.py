
# 2. find side, active volume and filled volume, price
# 3. count BOV, SOV, BTV, STV
# 4. show table (identical to the one in the Front End)
import csv
import sys


# check arguments and inform user
if len(sys.argv) not in (2,3):
    print("Wrong arguments. Specify filename. Add rate, if you want to multiply values to something.")
    exit(0)
if len(sys.argv) == 3:
    print('I see you want some rate to use. OK!')
    rate = float(sys.argv[2])
else:
    rate = 1
filename = str(sys.argv[1])

# open csv and get the header
with open(filename, 'r', newline='') as fn:
    reader = csv.reader(fn, delimiter=';')
    header = reader.__next__()

    # find columns which we need for calculations
    columns = {}
    columnKeys = set(['Active #', 'Filled #', 'Price', 'Side', 'Factor'])
    for i in range(len(header)):
        if header[i] in columnKeys:
            columns[str(header[i])] = i
    if len(columns) != len(columnKeys):
        print("Warning! Some values are absent. I need {0}. I got {1}.\nI need another file.".format(columnKeys, columns.keys()))
        exit(0)

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
            if not row[columns['Factor']]:
                factor = 1
            else:
                factor = float(row[columns['Factor']])

            if row[columns['Side']] == 'Buy' and row[columns['Price']] != '' and row[columns['Price']] != '0':
                buyOrderVolume += float(row[columns['Active #']])
                buyTradeVolume += float(row[columns['Filled #']])
                buyOrderValue += rate * float(row[columns['Active #']]) * float(row[columns['Price']]) * factor
                buyTradeValue += rate * float(row[columns['Filled #']]) * float(row[columns['Price']]) * factor
                # print("buyOrderVolume = {}\nbuyOrderValue = {}\nbuyTradeVolume = {}\nbuyTradeValue = {}\n".format(
                #     buyOrderVolume, \
                #     buyOrderValue, buyTradeVolume, buyTradeValue))
            if row[columns['Side']] == 'Sell' and row[columns['Price']] != '' and row[columns['Price']] != '0':
                sellOrderVolume += float(row[columns['Active #']])
                sellOrderValue += rate * float(row[columns['Active #']]) * float(row[columns['Price']]) * factor
                sellTradeVolume += float(row[columns['Filled #']])
                sellTradeValue += rate * float(row[columns['Filled #']]) * float(row[columns['Price']]) * factor
                # print("sellOrderVolume = {}\nsellOrderValue = {}\nsellTradeVolume = {}\nsellTradeValue = {}\n".format(
                #     sellOrderVolume, \
                #     sellOrderValue, sellTradeVolume, sellTradeValue))
        except Exception as err:
            print(err)
            print(row)
            exit(0)
    # print('//////////////////////////////////////////////////////////////////////')
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


