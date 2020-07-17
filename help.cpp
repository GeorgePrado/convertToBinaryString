#include <string.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <fstream>

using namespace std;

std::map<char, std::string> getAminoAcid5bits(){
	std::map<char, std::string> collectionAC;
	collectionAC['G'] = "00000";
	collectionAC['A'] = "00001";
	collectionAC['V'] = "00010";
	collectionAC['L'] = "00011";
	collectionAC['M'] = "00100";
	collectionAC['I'] = "00101";
	collectionAC['F'] = "00110";
	collectionAC['Y'] = "00111";
	collectionAC['W'] = "01000";
	collectionAC['S'] = "01001";
	collectionAC['T'] = "01010";
	collectionAC['C'] = "01011";
	collectionAC['P'] = "01100";
	collectionAC['N'] = "01101";
	collectionAC['Q'] = "01110";
	collectionAC['K'] = "01111";
	collectionAC['R'] = "10000";
	collectionAC['H'] = "10001";
	collectionAC['D'] = "10010";
	collectionAC['E'] = "10011";	
	return collectionAC;
}


std::vector<std::string> splitAndParseToBits(const std::string& data, char delimiter){
	std::map<char, std::string> colect_AC;
	std::vector<std::string> splits;
	std::string auxACstr;	
	std::string split;
	std::istringstream ss(data);
	colect_AC = getAminoAcid5bits();

	while(std::getline(ss, split, delimiter)){
		splits.push_back(split);	
	}
	//doing declaring char array
	int n = splits[0].length();
	char arrayAC[n+1];
	//use strcpy
	strcpy(arrayAC, splits[0].c_str());
	//recorremos array
	for (int i = 0; i < n; i++){
		std::string auxCadAC;
		auxCadAC = colect_AC[arrayAC[i]];
		//vamos concatenando los bits
		auxACstr.append(auxCadAC);
	}
	//devolvemos el valor de la cadena en bits(splits[0])
	splits[0] = auxACstr;
	return splits;
}

int main() {
	string userData = "AE,1";
	std::vector<std::string> userSplitData;
	userSplitData = split(userData, ',');
	std::cout << userSplitData[0] << std::endl;
	return 0;
}
