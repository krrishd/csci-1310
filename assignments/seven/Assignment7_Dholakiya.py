# -*- coding: utf-8 -*-

'''
  Name: Krishna Dholakiya
  Recitation TA: Brennan McConnell
  Assignment #: 7
'''

import random
import re

# This function takes a template string and
# asks the user for all the parts of speech
# that the template needs
def generateQueriesBasedOnTemplate(template):
  start = False
  listOfStuffToAskFor = []
  listOfStuffToReturn = []
  temporaryStr = ""
  
  for char in template:
    if char == '>':
      start = False
      listOfStuffToAskFor.append(temporaryStr)
      temporaryStr = ""
    if start:
      temporaryStr += char
    if char == '<':
      start = True
  
  for partOfSpeech in listOfStuffToAskFor:
    listOfStuffToReturn.append(raw_input("Enter a %s: " % re.sub('\d', '', partOfSpeech)))

  return listOfStuffToReturn

# This function takes a template string,
# runs generateQueriesBasedOnTemplate,
# makes a interpolatable string from the template,
# and passes the query results into that interpolatable string
def printTemplateInterpolated(template):
  queryResults = generateQueriesBasedOnTemplate(template)

  templateWithoutPartsOfSpeech = ""
  start = True

  for char in template:
    if char == '<':
      start = False
    if start:
      templateWithoutPartsOfSpeech += char
    elif char == '>':
      templateWithoutPartsOfSpeech += '%s'
      start = True

  print templateWithoutPartsOfSpeech % tuple(queryResults)




if __name__ == "__main__":
  
  templates = [
    "“Be kind to your <noun>-footed <plural noun>, or a duck may be somebody’s <noun>.”",
    "“It was the <adjective1> of <noun1>, it was the <adjective2> of <noun2>.”",
    "<plural noun>? I don’t have to show you any <adjective> <plural noun>!",
    "My <relative> always said <noun> was like a box of <noun>. You never know what you’re gonna get.",
    "One <time of day>, I <verb> a <noun> in my pajamas. How he got in my pajamas, I don’t know. "
  ]

  playing = True

  while (playing):
    if raw_input("Do you want to play a game? (y) or (n): ") == "y":
      playing = True
    else:
      playing = False
      break
    printTemplateInterpolated(templates[random.randint(0,5)])

  
  

