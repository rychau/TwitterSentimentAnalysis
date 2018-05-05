import linecache
from textblob import TextBlob

def getTweetSentiment(self, count):
    '''
    Utility function to classify sentiment of passed tweet
    using textblob's sentiment method
    '''
    # open file
    fp=open(keywords.txt)
    line = linecache.getline(keywords.txt, count)
    # create TextBlob object of passed tweet text
    analysis = TextBlob(self.line)
    
    # set sentiment
    if analysis.sentiment.polarity > 0:
        return 'positive'
    elif analysis.sentiment.polarity == 0:
        return 'neutral'
    else:
        return 'negative'
    #close file
    fp.close()

