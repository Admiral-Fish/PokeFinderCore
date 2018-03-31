import csv

with open('sapphire.csv', 'r') as f:
    idk = csv.reader(f)

    tables = []
    sorts = []

    for row in idk:
        tables.append(row)

    for i in range(1, len(tables)):
        key = tables[i]

        j = i-1
        while j >= 0 and key[0] < tables[j][0]:
            tables[j+1] = tables[j]
            j = j - 1
        tables[j+1] = key

    for row in tables:
        string = ""
        for i in range(len(row)):
            string = string + row[i]
            if i + 1 != len(row):
                string = string + ","
        print(string)
