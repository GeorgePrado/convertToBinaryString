#include <string.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <fstream>

using namespace std;
std::ifstream file("746Data.txt");

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

std::map<char, std::string> getAminoAcid12bits(){
	std::map<char, std::string> collectionAC2;
	collectionAC2['G'] = "000000000000";
	collectionAC2['A'] = "001000000001";
	collectionAC2['V'] = "001000000101";
	collectionAC2['L'] = "001000001001";
	collectionAC2['M'] = "001001001010";
	collectionAC2['I'] = "001000001000";
	collectionAC2['F'] = "011000010110";
	collectionAC2['Y'] = "011100011100";
	collectionAC2['W'] = "011010100101";
	collectionAC2['S'] = "111100000011";
	collectionAC2['T'] = "111100000101";
	collectionAC2['C'] = "111000000011";
	collectionAC2['P'] = "111000000101";
	collectionAC2['N'] = "111110001001";
	collectionAC2['Q'] = "111110001110";
	collectionAC2['K'] = "111010001111";
	collectionAC2['R'] = "111010011011";
	collectionAC2['H'] = "111010010001";
	collectionAC2['D'] = "111100001001";
	collectionAC2['E'] = "111100001110";	
	return collectionAC2;
}

/** function to split aby comma and return in array of bits aminoacid string**/
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

/** main function ...**/
int main() {
	std::map<char, std::string> colect_AC;
	std::string finalCadAminoAcid;
	int nbits = 5;
	if(nbits == 5)
		colect_AC = getAminoAcid5bits();
	else
		colect_AC = getAminoAcid12bits();
	
	if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
        //printf("%s \n", line.c_str());
		std::string strAC = line.c_str();
		std::vector<std::string> userSplitData;
		userSplitData = splitAndParseToBits(strAC, ',');
		//imprimimos para ver el resultado
		std::string lineAux;
		lineAux.append(userSplitData[0]);
		lineAux.append("\t");
		lineAux.append(userSplitData[1]);
		lineAux.append("\n");	
		//std::cout << lineAux << std::endl;
		
		finalCadAminoAcid.append(lineAux);
    	}
    file.close();
	}
	
	//abrimos un archivo para ingresar los resultados
	ofstream myfile;
	myfile.open("dataToBinary.txt");
	myfile << finalCadAminoAcid << endl;
	myfile.close();	
		
    return 0;
}

