import twitter

api = twitter.Api(consumer_key = 'ilKfDdkG3AxnDk8RbMwNDQyFB',
consumer_secret = 'sEkwwrm16xDEIELv1YIudHYVPcffOhWivaqaPdVz7srSCNebR6',
access_token_key = '991065139582455808-gbdjeZGdxjjaqc574EcsGWPEOdNCYrT',
access_token_secret = 'Tv2dp0eah8dy3xdW4Z3ZZwWEuX3Cz7MNFUTXxYZyLoDjb')

f = open('tweets.txt', 'w', encoding='utf-8')

t = api.GetUserTimeline(screen_name="", count = 100)
tweets = [i.AsDict() for i in t]
for tweet in tweets:
    print('----', file = f)
    print(tweet['text'], file = f)

f.close()