//
//  main.cpp
//  test sentiment
//
//  Created by michelle natasha on 5/4/18.
//  Copyright © 2018 michelle natasha. All rights reserved.
//
/*
 The program is doing:
 - take values of keywords from AFINN file
 - take clean tweets file and compare to keywords value
 - get the score for each tweet
 - display how many positive, negative, and neutral tweets
 */

// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main () {
    //Get words and their values
    string buffer;
    string key[2500];
    int val[2500];
    ifstream myfile;
    int count = 0;
    myfile.open("/Users/michellenatasha/Desktop/CMPE 130/test sentiment/test sentiment/AFINN-111.txt");
    if (myfile.is_open())
    {
        while (! myfile.eof() )
        {
            getline (myfile, buffer);
            stringstream ss (buffer);
            ss >> key[count] >> val[count];
            count++;
        }
        myfile.close();
    }
    else
        cout << "Unable to open file";
    
    //print words with values
    for(int i=0;i<count;i++)
    {
        if(key[i] != "")
        {
            cout << key[i] << " " << val[i] << endl;
        }
    }
    //cout << count << endl;
    //get keywords from tweets line by line
    int positive = 0, neutral = 0, negative = 0;
    int score = 0;
    int lineCount = 0;
    string keywords[200];
    ifstream keywordFile;
    keywordFile.open("/Users/michellenatasha/Desktop/CMPE 130/test sentiment/test sentiment/keywords.txt");
    if(keywordFile.is_open())
    {
        while(!keywordFile.eof())
        {
            getline(keywordFile, buffer);
            lineCount++;
            for(int i=0;i<buffer.length();i++)
                tolower(buffer[i]);
            stringstream ss1 (buffer);
            int wordCount=0;
            while(ss1)
            {
                ss1 >> keywords[wordCount];
                wordCount++;
            
                score=0;
                for(int j=0; j<wordCount; j++)
                {
                    for(int k=0;k<count;k++)
                    {
                        if(keywords[j]==key[k])
                        {
                            score += val[k];
                        }
                    }
                }
            }
                if(score >= 0)
                    positive++;
                else if(score==0)
                    neutral++;
                else
                    negative++;
        }
        keywordFile.close();
        cout << "There are " << positive << " positive tweets\n";
        cout << "There are " << neutral << " neutral tweets\n";
        cout << "There are " << negative << " negative tweets\n";
        cout << lineCount << endl;
    }
    else
    cout << "Could not open keyword file" << endl;
    return 0;
}

