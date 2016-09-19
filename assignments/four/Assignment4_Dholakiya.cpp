/*
*    Name: Krishna Dholakiya
*    Recitation TA: Brennan McConnell
*    Assignment: #4
*/

#include <iostream>

using namespace std;

const string humanDNA = "CGCAAATTTGCCGGATTTCCTTTGCTGTTCCTGCATGTAGTTTAAACGAGATTGCCAGCACCGGGTATCATTCACCATTTTTCTTTTCGTTAACTTGCCGTCAGCCTTTTCTTTGACCTCTTCTTTCTGTTCATGTGTATTTGCTGTCTCTTAGCCCAGACTTCCCGTGTCCTTTCCACCGGGCCTTTGAGAGGTCACAGGGTCTTGATGCTGTGGTCTTCATCTGCAGGTGTCTGACTTCCAGCAACTGCTGGCCTGTGCCAGGGTGCAGCTGAGCACTGGAGTGGAGTTTTCCTGTGGAGAGGAGCCATGCCTAGAGTGGGATGGGCCATTGTTCATG";
const string mouseDNA = "CGCAATTTTTACTTAATTCTTTTTCTTTTAATTCATATATTTTTAATATGTTTACTATTAATGGTTATCATTCACCATTTAACTATTTGTTATTTTGACGTCATTTTTTTCTATTTCCTCTTTTTTCAATTCATGTTTATTTTCTGTATTTTTGTTAAGTTTTCACAAGTCTAATATAATTGTCCTTTGAGAGGTTATTTGGTCTATATTTTTTTTTCTTCATCTGTATTTTTATGATTTCATTTAATTGATTTTCATTGACAGGGTTCTGCTGTGTTCTGGATTGTATTTTTCTTGTGGAGAGGAACTATTTCTTGAGTGGGATGTACCTTTGTTCTTG";
const string unknownDNA = "CGCATTTTTGCCGGTTTTCCTTTGCTGTTTATTCATTTATTTTAAACGATATTTATATCATCGGGTTTCATTCACTATTTTTCTTTTCGATAAATTTTTGTCAGCATTTTCTTTTACCTCTTCTTTCTGTTTATGTTAATTTTCTGTTTCTTAACCCAGTCTTCTCGATTCTTATCTACCGGACCTATTATAGGTCACAGGGTCTTGATGCTTTGGTTTTCATCTGCAAGAGTCTGACTTCCTGCTAATGCTGTTCTGTGTCAGGGTGCATCTGAGCACTGATGTGGAGTTTTCTTGTGGATATGAGCCATTCATAGTGTGGGATGTGCCATAGTTCATG";

/*
*    This function takes two strings of DNA (DNA1 and DNA2), calculates the hamming distance
*    between the two by iterating through the first and adding 1 to hammingDistance for
*    every iteration where DNA1 at index i isn't equal to DNA2 at i.
*    It takes the resulting hamming distance and plugs it into the provided function for
*    similarity.
*/
void calculateSimilarity(double *similarity, string DNA1, string DNA2) {
	if (DNA1.length() != DNA2.length()) {
		return;
	}
	double hammingDistance = 0;
	for (int i = 0; i < DNA1.length(); i++) {
		if (DNA1[i] != DNA2[i]) {
			hammingDistance++;
		}
	}
	*similarity = (
		(DNA1.length() - hammingDistance) / 
		DNA1.length()
	);
}

/*
*     This function iterates through the point-of-comparison DNA strand and calculates the hamming distance
*     in the same way as calculateSimilarity does, except instead of using the whole DNA string it uses a
*     substring of the strand starting at index i as long as the user-inputted substring. If the hamming distance
*     is lower than any previous hamming distance in the iteration, it saves the hamming distance and the index at
*     where it occurs. After the iteration, that index serves as the marker of the best matching sequence. Best match score
*     is calculated as simply the # of characters in the substr that are matched in the original DNA sequence.
*/

void calculateBestMatch(double *distance, int *index, string DNA1, string substr) {
	int bestIndex;
	int bestHammingDistance = -1;
	for (int i = 0; i < DNA1.length(); i++) {
		double hammingDistance = 0;
		string DNASubstr = DNA1.substr(i, substr.length());
		for (int j = 0; j < DNASubstr.length(); j++) {
			if (DNASubstr[j] != substr[j]) {
				hammingDistance++;
			}
		}
		if (hammingDistance < bestHammingDistance or bestHammingDistance == -1) {
			bestHammingDistance = hammingDistance;
			bestIndex = i;
		}
	}
	*distance = bestHammingDistance;
	*index = bestIndex;
	string matchingSequence = DNA1.substr(bestIndex, substr.length());
	int numberOfMatching = DNA1.length() - bestHammingDistance;
	if (numberOfMatching <= 1) {
		cout << "Match not found.\n";
		return;
	}
	cout << "Best match: " << matchingSequence << endl;
	cout << "Best match score: " << (substr.length() - bestHammingDistance) << endl;
}

int main() {
	double localSimilarity;
	double *similarity = &localSimilarity;
	
	calculateSimilarity(similarity, humanDNA, unknownDNA);
	double similarityToHuman = localSimilarity;
	
	calculateSimilarity(similarity, mouseDNA, unknownDNA);
	double similarityToMouse = localSimilarity;
	
	if (similarityToHuman > similarityToMouse) {
		cout << "Human\n";
	} else if (similarityToMouse > similarityToHuman) {
		cout << "Mouse\n";
	} else {
		cout << "Identity cannot be determined.\n";
	}
	
	string substr;
	double hamDist;
	double *hamDistPointer = &hamDist;
	int index;
	int *indexPointer = &index;
	cout << "Enter a substring: ";
	cin >> substr;
	cin.ignore();
	calculateBestMatch(hamDistPointer, indexPointer, mouseDNA, substr);
}