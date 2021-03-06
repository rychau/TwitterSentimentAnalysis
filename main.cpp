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
#include <python2.7/Python.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int array[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
    
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
            swap(&array[i], &array[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int arr[], int array[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
         at right place */
        int pi = partition(arr, array, low, high);
        
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, array, low, pi - 1);
        quickSort(arr, array, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main () { 
             // Added 5/7/18

    Py_Initialize();
    FILE* pfile = fopen("twitterpull.py", "r");
    PyRun_SimpleFile(pfile, "twitterpull.py");
    Py_Finalize();

    cout << "\nTweetPull Successfully Completed\n" << endl;


    //Get words and their values
    string buffer;
    string key[2500];
    int val[2500];
    ifstream myfile;
    int count = 0;
    double total = 0;
    double percent = 0;
    double posminusneg = 0;
    double percentweight = 0;

    myfile.open("AFINN-111.txt");
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
    /*for(int i=0;i<count;i++)
    {
        if(key[i] != "")
        {
            cout << key[i] << " " << val[i] << endl;
        }
    }*/
    //cout << count << endl;
    //get keywords from tweets line by line
    int positive = 0, neutral = 0, negative = 0;
    int score = 0;
    int lineCount = 0;
    string keywords[200];
    string bufferArr[60];
    ifstream keywordFile;
    int scoreArr[60];
    int index[60];
    for(int i = 0; i<60;i++)
    {
        index[i]= i;
    }
    keywordFile.open("tweets.txt");
    if(keywordFile.is_open())
    {
        while(!keywordFile.eof())
        {
            getline(keywordFile, buffer);
            if(buffer != "----")
            {
            lineCount++;
            for(int i=0;i<buffer.length();i++) {
                tolower(buffer[i]);
            }
            stringstream ss1 (buffer);
            int wordCount=0;
            score=0;
            while(ss1)
            {
                ss1 >> keywords[wordCount];
                wordCount++;
            
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
             bufferArr[lineCount-1]=buffer;
                scoreArr[lineCount-1]=score;
            cout << buffer<< " " << score<<endl<<endl;
            
                if(score > 0)
                    positive++;
                else if(score==0)
                    neutral++;
                else
                    negative++;
            }
        }
        lineCount--;
        neutral--;
        //call quicksort
        quickSort(scoreArr, index, 0, lineCount-1);
        keywordFile.close();
        cout << "\nThere are " << positive << " positive tweets\n";
        cout << "There are " << neutral << " neutral tweets\n";
        cout << "There are " << negative << " negative tweets\n";

        total = positive + neutral + negative;
        percent = positive/total;
        percent *= 100;

       posminusneg = (positive - negative);
       percentweight = posminusneg / total;

        cout << "\nSentiment Weight of last 50 tweets from user: " << percentweight << endl;

        cout << "\nUser has " << percent << "% " << "positive tweets" << endl << endl;
        cout << "Top 3 positive tweets:\n";
        cout << bufferArr[index[lineCount-1]] << " " << scoreArr[lineCount-1] << endl<<endl;
        cout << bufferArr[index[lineCount-2]] << " " << scoreArr[lineCount-2] << endl<<endl;
        cout << bufferArr[index[lineCount-3]] << " " << scoreArr[lineCount-3] << endl<<endl;
        cout << "Top 3 negative tweets:\n";
        cout << bufferArr[index[0]] << " " << scoreArr[0] << endl<<endl;
        cout << bufferArr[index[1]] << " " << scoreArr[1] << endl<<endl;
        cout << bufferArr[index[2]] << " " << scoreArr[2] << endl<<endl;
    }
    else
    cout << "Could not open keyword file" << endl;
    return 0;
}