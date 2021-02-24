from collections import defaultdict 
import re
import csv
import numpy as np
from string import ascii_lowercase
  
def check_correctness(word):
    if word[0] == '@' or word == "rt" or (len(word) > 4 and word[:4] == 'http'):
        return None
    if word[0] == '#':
        return word[1:]
    if word[0] not in ascii_lowercase:
        return None
    return word

def remove_weirdshit_at_end(word):
    remove = 0
    length = len(word)
    if length == 1:
        return word
    while word[length-1-remove] not in ascii_lowercase:
        remove+=1
        if remove > length:
            return None
    if remove == 0:
        return word
    return word[:-remove]


def get_counts(filename):
    choices = ["abusive", "hateful", "normal", "spam"]
    Dict = {k : defaultdict(lambda : 0) for k in choices}
    Len = {k : 0 for k in choices}

    with open(filename,newline='', encoding="UTF-8-SIG") as csvfile:
        reader = csv.DictReader(csvfile, skipinitialspace = True)
        for row in reader:
            words = row["Tweet"].split()
            list_of_words = []
            for word in words:
                w = check_correctness(word.lower())
                if w != None:
                    list_of_words.append(remove_weirdshit_at_end(w))

            verdict = row["Kind"]
            Len[verdict] += len(list_of_words)
            for word in list_of_words:
                Dict[verdict][word] += 1
    
    for key , d in Dict.items():
        for item , value in d.items():
            Dict[key][item] = value / Len[key]

    return Dict, Len

D = get_counts("hate_text.csv")[0]
print(D["abusive"])
print(D["hateful"])
print(D["spam"])
print(D["normal"])

print(sum)
