from tweepy.streaming import StreamListener
from tweepy import OAuthHandler
from tweepy import Stream
import json

consumer_key='7IDDDPnDZPPW4vFtQNe4cGrf8'
consumer_secret='T3ysP4CyADhEomGmuWyes4wc7EwgAlNOrPb42TYeR3dgVfsd8f'
access_token='3148921273-OtpTEtf2NdAbm9cIH7FsNhlXr9gxhsfs7YCDGor'
access_token_secret='yUtgKo33u4SkGUlIuxJ86sTOh3ZUMCecPVDXtdIgyiUSq'


class tweetRecorder:

	def __init__(self, file_name):
		self.f = open(file_name, 'w')
		self.tweetCount = 0

	def record(self, data):

		data = json.loads(data)
		try:
			tweet = {}
			tweet["text"] = data["text"]
			tweet["created_at"] = data["created_at"]
			if (data["coordinates"] != None):
				tweet["coordinates"] = data["coordinates"]["coordinates"]

				self.f.write(str(json.dumps(tweet)))
				self.f.write("\n")

				self.tweetCount += 1
				if (self.tweetCount%10 == 0):
					print self.tweetCount
		except:
			pass


#This is a basic listener that just prints received tweets to stdout.
class Listener(StreamListener):

	def __init__(self, tweetRecorder):
		self.tR = tweetRecorder


	def on_data(self, data):
		self.tR.record(data)
		return True

	def on_error(self, status):
		print status


if __name__ == '__main__':

	#This handles Twitter authetification and the connection to Twitter Streaming API
	tR = tweetRecorder("tweets_with_time_4.json")
	l = Listener(tR)
	auth = OAuthHandler(consumer_key, consumer_secret)
	auth.set_access_token(access_token, access_token_secret)
	stream = Stream(auth, l)

	Alaska = [-180, 51.2, -130, 71.6]
	Hawaii = [ -160, 18.9, -154, 22.2]
	US = [-124.3, 25.8, -66.9, 49.4]


	stream.filter(locations=US+Hawaii+Alaska)



