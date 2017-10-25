#include "MatPGM.hpp"

MatPGM::MatPGM(const char* filename)
{
	open(filename);
}

MatPGM::MatPGM(const Mat & mat, std::string fileType, int maxValue)
	: Mat(mat), fileType(fileType), maxValue(maxValue)
{
}

MatPGM::MatPGM(int rows, int cols, std::string fileType, int maxValue)
	: Mat(rows, cols), fileType(fileType), maxValue(maxValue)
{
}

MatPGM::MatPGM(int rows, int cols, std::string fileType, int maxValue, double value)
	: Mat(rows, cols, value), fileType(fileType), maxValue(maxValue)
{
}

MatPGM::~MatPGM()
{
}

bool MatPGM::open(const char * filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		return false;
	}
	file >> fileType;
	file >> cols;
	file >> rows;
	file >> maxValue;
	initData();
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			file >> data[i][j];
		}
	}
	file.close();
	return true;
}

bool MatPGM::save(const char * filename)
{
	std::ofstream file(filename);
	if (!file.is_open())
	{
		return false;
	}
	file << fileType << std::endl
		<< cols << std::endl
		<< rows << std::endl
		<< maxValue << std::endl;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			file << data[i][j] << std::endl;
	file.close();
	return true;
}
