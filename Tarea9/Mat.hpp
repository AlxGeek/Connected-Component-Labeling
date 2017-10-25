#ifndef MAT_H
#define MAT_H

#include <memory>
#include <cstring>
#include <set>

class Mat
{
public:
	int rows;
	int cols;
	std::unique_ptr<std::unique_ptr<double[]>[]>  data;

public:
	Mat();
	Mat(int rows, int cols);
	Mat(int rows, int cols, double value);
	Mat(const Mat &mat);
	~Mat();

	void setValue(double value);
	void setValue(std::set < std::pair<int, int>> set, double value);
	void initData(int rows, int cols);
	void initData();
};

#endif // MAT_H
