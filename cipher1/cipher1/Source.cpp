/*cipher1.cpp, written by Annalise Dake 12/6/2016
programs uses a vigenere cipher to encrypt/decrypt text files*/

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;
//function prototypes
char encipher(char key, char plain);
char decipher(char key, char cipher);

int main(int argc, char* argv[]){
	while (true) {
		if (argc != 5) {											//if user incorrectly inputs, prompt them with how to use the program
			cout << "Usage:" << argv[0] << " [-e or -d]  [key]  [infile]  [outfile]" << endl;
			return 1;
		}
		ifstream inFile;										//input file
		ofstream outFile;										//output file
		inFile.open(argv[3]);									//opens the input file
		if (inFile.fail()) {										//failsafe for if the input file is not opened
			cout << "Error opening input file" << endl;
			return 1;
		}
		outFile.open(argv[4]);									//opens output file
		if (outFile.fail()) {									//failsafe for if the output file is not opened
			cout << "Error opening output file" << endl;
			return 1;
		}
		string key = argv[2];									//key that the user puts in in command prompt
		string plain;											//string that holds the text of the text file while encrypted
		string decider = argv[1];								//decides if encryption or decryption
		string cipher;											//string that holds the text of the text file while decrypting

		if (decider == "-e") {									//if encrypting, get the text from the file
			while (getline(inFile, plain)) {
				for (int i = 0; i < plain.length(); i++) {		//for loop processes each character
																//this line actually preforms the encryption using the encipher function
					plain[i] = encipher(key[i % key.length()], plain[i]);
				}
				outFile << plain << endl;						//outputs the text to specified output file
			}
		}

		if (decider == "-d") {									//if decrypting, do the same thing as encryption, but with the decipher function
			while (getline(inFile, cipher)) {
				for (int i = 0; i < cipher.length(); i++) {

					cipher[i] = decipher(key[i % key.length()], cipher[i]);
				}

				outFile << cipher << endl;
			}
		}
	}


	return 0;
}
	
	
/*encrypts the text using vigener cipher
@param key the key that the user input in command line
@param plain the text from the input file
returns the enciphered text "plain"*/

char encipher(char key, char plain){

		if (key >= 'A' && key <= 'Z')
			plain += key - 'A';
		else if (key >= 'a' && key <= 'z')
			plain += key - 'a';
		else if (key < 'A' || key > 'z')
			plain = plain;
			return plain;
	
	
	}

/*decrypts text using Vigenere cipher
@param key user inputed key
@param cipher the text that is being deciphered
returns the deciphered text*/
char decipher(char key, char cipher){

		if (key >= 'A' && key <= 'Z')
			cipher -= key -'A';
		else if (key >= 'a' && key <= 'z')
			cipher -= key - 'a';
		else if (key < 'A' || key > 'z')
			cipher = cipher;
		return cipher;

}