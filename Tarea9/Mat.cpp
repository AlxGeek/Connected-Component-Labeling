#include "Mat.hpp"

Mat::Mat(int rows, int cols) : rows{ rows }, cols{ cols }, data{ std::make_unique< std::unique_ptr<double[]>[] >(rows) }
{
	for (int i = 0; i < rows; ++i)
		data[i] = std::make_unique< double[] >(cols);
}

Mat::Mat(int rows, int cols, double value) : Mat(rows, cols)
{
	setValue(value);
}

Mat::Mat() : rows{ 0 }, cols{ 0 }, data{ nullptr } {
}

Mat::Mat(const Mat &mat) : Mat(mat.rows, mat.cols) {
	for (int i = 0; i < rows; ++i) 
		memcpy(data[i].get(), mat.data[i].get(), cols * sizeof(double));
}

Mat::~Mat()
{
}

void Mat::setValue(double value)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			data[i][j] = value;
}

void Mat::setValue(std::set<std::pair<int, int>> set, double value)
{
	for (auto i : set) {
		data[i.first][i.second] = value;
	}
}



void Mat::initData(int rows, int cols) {
	this->rows = rows;
	this->cols = cols;
	initData();
}

void Mat::initData() {
	data = std::make_unique< std::unique_ptr<double[]>[] >(rows);
	for (int i = 0; i < rows; ++i)
		data[i] = std::make_unique< double[] >(cols);
}


