import csv
import unicodedata
import string

def convert(filename, filename_to_save):
  
  csv_to_write = open(filename_to_save, 'w', newline='',encoding="UTF-8-SIG")
  csvwriter = csv.writer(csv_to_write)
  csvwriter.writerow(['ID','Text','Label'])
  with open(filename,newline='', encoding="UTF-8-SIG") as csvfile:
    reader = csv.reader(csvfile, delimiter=',')
    id = 0
    for row in reader:
        if id == 0:
            id+=1
            continue

        indices = row[2]
        if indices == "n/a":
            continue
        
        indices = [int(n)-1 for n in indices[1:-1].split(",")]
        lines = row[1].split("\n")[:-1]
        res_list = []

        for i, line in enumerate(lines):
            replaced = line[2:].replace('\t','').replace('\xa0', ' ')
            if i in indices:
                csvwriter.writerow([id, replaced, "hateful"])
            else:
                csvwriter.writerow([id, replaced, "normal"])
            id+=1

convert("gab.csv","converted_gab.csv")
convert("reddit.csv","converted_reddit.csv")
