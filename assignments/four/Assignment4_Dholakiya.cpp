#include <iostream>

using namespace std;

const string humanDNA = "CGCAAATTTGCCGGATTTCCTTTGCTGTTCCTGCATGTAGTTTAAACGAGATTGCCAGCACCGGGTATCATTCACCATTTTTCTTTTCGTTAACTTGCCGTCAGCCTTTTCTTTGACCTCTTCTTTCTGTTCATGTGTATTTGCTGTCTCTTAGCCCAGACTTCCCGTGTCCTTTCCACCGGGCCTTTGAGAGGTCACAGGGTCTTGATGCTGTGGTCTTCATCTGCAGGTGTCTGACTTCCAGCAACTGCTGGCCTGTGCCAGGGTGCAGCTGAGCACTGGAGTGGAGTTTTCCTGTGGAGAGGAGCCATGCCTAGAGTGGGATGGGCCATTGTTCATG";
const string mouseDNA = "CGCAATTTTTACTTAATTCTTTTTCTTTTAATTCATATATTTTTAATATGTTTACTATTAATGGTTATCATTCACCATTTAACTATTTGTTATTTTGACGTCATTTTTTTCTATTTCCTCTTTTTTCAATTCATGTTTATTTTCTGTATTTTTGTTAAGTTTTCACAAGTCTAATATAATTGTCCTTTGAGAGGTTATTTGGTCTATATTTTTTTTTCTTCATCTGTATTTTTATGATTTCATTTAATTGATTTTCATTGACAGGGTTCTGCTGTGTTCTGGATTGTATTTTTCTTGTGGAGAGGAACTATTTCTTGAGTGGGATGTACCTTTGTTCTTG";
const string unknownDNA = "CGCATTTTTGCCGGTTTTCCTTTGCTGTTTATTCATTTATTTTAAACGATATTTATATCATCGGGTTTCATTCACTATTTTTCTTTTCGATAAATTTTTGTCAGCATTTTCTTTTACCTCTTCTTTCTGTTTATGTTAATTTTCTGTTTCTTAACCCAGTCTTCTCGATTCTTATCTACCGGACCTATTATAGGTCACAGGGTCTTGATGCTTTGGTTTTCATCTGCAAGAGTCTGACTTCCTGCTAATGCTGTTCTGTGTCAGGGTGCATCTGAGCACTGATGTGGAGTTTTCTTGTGGATATGAGCCATTCATAGTGTGGGATGTGCCATAGTTCATG";

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

void calculateBestMatch(int *distance, int *index, string DNA1, string DNA2) {
	double localSimilarity;
	double *similarity = &localSimilarity;
	double bestSimilarity = -1;
	int bestIndex;
	for (int i = 0; i < DNA1.length(); i++) {
		calculateSimilarity(similarity, DNA1.substr(i), DNA2.substr(i));
		if (localSimilarity < bestSimilarity || bestSimilarity == -1) {
			bestSimilarity = localSimilarity;
			bestIndex = i;
		}
	}
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
}