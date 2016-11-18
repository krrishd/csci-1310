'''
  Name: Krishna Dholakiya
  Recitation TA: Brennan McConnell
  Assignment: 8
'''

import csv

def CreateDictionary(filename):
    slang = {}
    # Opens file
    with open(filename, 'rU') as f:
        # Converts raw file to parsable CSV
        reader = csv.reader(f)
        # Iterates thru each row and gives each row as a list [shortform, full]
        for row in reader:
            slang[row[0]] = row[1]
    return slang

def PromptUser(dictionaryOfSlang):
  wordsToLookup = raw_input("Enter a text abbreviation: ")
  if wordsToLookup == "quit":
    return False
  wordsToLookupAsList = wordsToLookup.split(' ')
  convertedText = ""
  for i,word in enumerate(wordsToLookupAsList):
    if dictionaryOfSlang.get(word, 'DNE') != 'DNE':
      if i != len(wordsToLookupAsList) - 1:
        convertedText += dictionaryOfSlang[word] + " "
      else:
        convertedText += dictionaryOfSlang[word]
    else:
      print "NF"
      break
  if len(convertedText) > 0:
    print convertedText

if __name__ == '__main__':
    dictionaryOfSlang = CreateDictionary('textToEnglish.csv')
    quit = False
    while quit == False:
      if PromptUser(dictionaryOfSlang) == False:
        quit = True

    

    
    # print CreateDictionary('textToEnglish.csv')
