#ifndef MATPGM_H
#define MATPGM_H

#include <fstream>
#include <string>

#include "Mat.hpp"

class MatPGM :
	public Mat
{
public:
	std::string fileType;
	int maxValue;


public:
	MatPGM(const char* filename);
	MatPGM(const Mat &mat, std::string fileType, int maxValue);
	MatPGM(int rows, int cols, std::string fileType, int maxValue);
	MatPGM(int rows, int cols, std::string fileType, int maxValue, double value);
	
	~MatPGM();

	bool open(const char * filename);
	bool save(const char * filename);
	

};

#endif //MATPGM_H