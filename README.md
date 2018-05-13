# TwitterSentimentAnalysis

Reads an indicated number of tweets from a given Twitter user and analyzes the number of positive and negative tweets, as well as lists
the top three positive and negative tweets.

It is recommended that Ubuntu Terminal is used to run, as main.cpp uses Python embedded in C++. 
Be sure Ubuntu is updated to install everything properly (such as apt-get).

You need to install Python3+ (Used Python 3.5) 
You need to install PiP (to install python-twitter)
Use pip to install python-twitter ("pip install python-twitter")

If there are problems with pip is picking python2.7 by default. Use:
sudo apt-get install python3-pip
To install pip directly to my python3 install.
Then,
pip3 install python-twitter

Compile using Ubuntu Terminal(navigate to directory, all files in same spot)
g++ -o tweetrate -I /usr/include/python3 main.cpp -lpython3.5m

Run using Ubuntu Terminal:
./tweetrate




