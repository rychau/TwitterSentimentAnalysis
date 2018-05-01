/*
 * main.cpp
 *
 *  Created on: Apr 30, 2018
 *      Author: Ryanc
 */
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
using namespace std;

int main(){
ifstream a;
ofstream b;
string line;

a.open("tweets.txt");
b.open("cleaned.txt");

if(a.is_open()){
while(getline(a, line)){
	if(line == "----"){
		b << "----\n";
		getline(a, line);
	}

	regex r("[^A-Za-z0-9']"), r1("what's"), r2("\\'s"), r3("\\'ve"), r4("can't"), r5("n't"), r6("i'm"), r7("\\'re"), r8("\\'ll"), r9("\\'d"), r10("'");

	for(int i= 0; line[i]; i++)
	line[i]= tolower(line[i]);
	line= regex_replace(line, r, " ");
	line= regex_replace(line, r1, "what is ");
	line= regex_replace(line, r2, " ");
	line= regex_replace(line, r3, " have ");
	line= regex_replace(line, r4, "cannot ");
	line= regex_replace(line, r5, " not ");
	line= regex_replace(line, r6, "i am ");
	line= regex_replace(line, r7, " are ");
	line= regex_replace(line, r8, " will ");
	line= regex_replace(line, r9, " would ");
	line= regex_replace(line, r10, " ");

	b << line << "\n";

}
a.close();
b.close();
}

else cout << "Unable to open file";
return 0;
}



