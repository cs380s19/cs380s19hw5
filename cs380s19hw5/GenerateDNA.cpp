//********************************************************
// File name:  generateDNA.cpp
// Author:     Chadd Williams, edited Chris Lane
// Date:       11/11/2013, 3/16/2019
// Class:      CS380
// Assignment: DNA Sequences
// Purpose:    To generate random DNA strands and fragments
//********************************************************

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

int main () {
	std::string filename;
	int minSizeDNA = 12;
	int maxSizeDNA = 24;

	int minSizeFrag = 2;
	int maxSizeFrag = 8;

	int numbDNA = 5;
	int numbFrag = 10;
	const int DNA_LETTERS = 4;

	const char ALPHABET[] = { 'A','C','T','G' };

	std::ofstream outfile;

	std::cout << "What is the maximum size for a DNA strand? ";
	std::cin >> maxSizeDNA;

	std::cout << "What is the minimum size for a DNA strand? ";
	std::cin >> minSizeDNA;

	if (maxSizeDNA < minSizeDNA) {
		std::cout << "DNA SIZE Error: max size < min size.\n\n";
		exit (-1);
	}

	std::cout << "How many DNA strands will be produced? ";
	std::cin >> numbDNA;

	if (numbDNA < 1) {
		std::cout << "Number of DNA Strands must be greater than zero.\n\n";
		exit (-3);
	}

	std::cout << "What is the maximum size for a DNA fragment? ";
	std::cin >> maxSizeFrag;

	std::cout << "What is the minimum size for a DNA fragment? ";
	std::cin >> minSizeFrag;

	if (maxSizeFrag < minSizeFrag) {
		std::cout << "DNA Fragment SIZE Error: max size < min size.\n\n";
		exit (-2);
	}

	std::cout << "How many DNA fragments will be produced? ";
	std::cin >> numbFrag;

	if (numbFrag < 1) {
		std::cout << "Number of DNA Fragments must be greater than zero.\n\n";
		exit (-3);
	}

	std::cout << "What file will the DNA be written to? ";
	std::cin >> filename;

	outfile.open (filename.c_str ());

	srand (time (NULL));

	outfile << numbDNA << "\n";
	for (int j = 0; j < numbDNA; j++) {
		for (int i = rand () % (maxSizeDNA - minSizeDNA) + minSizeDNA; i > 0; i--) {
			outfile << ALPHABET[rand () % DNA_LETTERS];
		}
		outfile << "\n";
	}

	outfile << numbFrag << "\n";
	for (int j = 0; j < numbFrag; j++) {
		for (int i = rand () % (maxSizeFrag - minSizeFrag) + minSizeFrag; i > 0; i--) {
			outfile << ALPHABET[rand () % DNA_LETTERS];
		}
		outfile << "\n";
	}
	outfile.close ();

	return EXIT_SUCCESS;
}