/*
	topicfinder.cpp

	By Brian Tran

 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

	ifstream ifs;
	ofstream ofs;
	string line;
	char firstLetter; // to check upper case letter
	int count = 0; // Just to check if 1 word has been written already

	ifs.open("tweets.txt");
	if (ifs.fail()) {
		cout << "Input file has failed to open..." << endl;
		exit(1);
	}

	ofs.open("keywords.txt");

	while(!ifs.eof()) {
		getline(ifs, line, ' '); // read word by word
		if(line == "-----") {
			getline(ifs, line, ' '); // ignore "-----"
			ofs << endl;
		}

		firstLetter = line[0];
		cout << firstLetter << endl;
		if (isupper(firstLetter)) { // check if first letter is upper case
			ofs << line << " ";
			count++;
		}
		else if (line == "of" && count > 0) {
			ofs << line << " "; // end of keyword if keyword > 1 word
			count++;
		}
		else if (count > 0){
			ofs << endl;
			count = 0;
		}
	}

	ifs.close();
	ofs.close();

	return 0;

}