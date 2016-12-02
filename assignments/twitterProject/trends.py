import sys
import json
import csv
from state import load_states
from country import Country
from colors import get_sentiment_color
from tweet import Tweet
from geo import GeoPosition

class SentimentAnalysis:
    def __init__(self):
        self.states = load_states()
    def showCountry(self):
        self.usa = Country(self.states, 1200)
    def findStateCodeBasedOnGeo(self, geoPosition):
        shortestDistance = -1
        closestState = ""
        for state in self.states:
            distance = geoPosition.distance(state.centroid())
            distanceIsShortest = (distance < shortestDistance)
            if (shortestDistance == -1 or distanceIsShortest):
                shortestDistance = distance
                closestState = state.abbrev()
        return closestState
    def pushSentimentToState(self, stateCode, sentiment):
        for state in self.states:
            if state.abbrev() == stateCode:
                state.addSentiment(sentiment)
    #finish


if __name__ == "__main__":
    query = ""
    if len(sys.argv) > 1:
        query = ' '.join(sys.argv[1:])
        print ("Starting process for " + query + "...")
    else:
        print "Starting process..."

    sa = SentimentAnalysis()

    sentiments = {}

    with open('./data/sentiments.csv', 'rb') as sentimentsFile:
        sentimentReader = csv.reader(sentimentsFile)
        for row in sentimentReader:
            sentiments[row[0]] = row[1]

    filenamesToLoad = [
        './tweets/tweets.json',
        './tweets/tweets2.json',
        './tweets/tweets3.json',
        './tweets/tweets4.json',
        './tweets/tweets5.json',
        './tweets/tweets_with_time.json',
        './tweets/tweets_with_time_2.json',
        './tweets/tweets_with_time_3.json',
        './tweets/tweets_with_time_4.json'
    ]

    fileContents = ""

    print "Reading data files..."
    for filename in filenamesToLoad:
        fileContents += open(filename, 'r').read() + '\n'

    print "Aggregating data to one file..."
    aggregateFile = open('./tweets/aggregate.json', 'w')
    aggregateFile.write(fileContents)
    aggregateFile.close()
    
    tweetsRaw = open('./tweets/aggregate.json', 'r')

    tweetsParsed = []

    for line in tweetsRaw:
        try:
            tweetDict = json.loads(line)
        except ValueError:
            pass
        if query in tweetDict['text']:
            tweetsParsed.append(
                Tweet(
                    tweetDict['text'],
                    0,
                    GeoPosition(
                        tweetDict['coordinates'][1],
                        tweetDict['coordinates'][0]
                    )
                )
            )

    print "Conducting sentiment analysis on each tweet..."
    for tweet in tweetsParsed:
        sumOfSentiment = 0
        words = tweet.message().split()
        for word in words:
            if word in sentiments:
                sumOfSentiment += float(sentiments[word])
        averageSentiment = sumOfSentiment/len(words)
        stateCode = sa.findStateCodeBasedOnGeo(tweet.position())
        sa.pushSentimentToState(stateCode, averageSentiment)

    print "And we're ready!"

    sa.showCountry()

    for state in sa.states:
        sa.usa.setFillColor(
            state.abbrev(),
            get_sentiment_color(
                state.calculateAverageSentiment()
            )
        )

    #finish