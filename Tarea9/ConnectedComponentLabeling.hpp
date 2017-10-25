#ifndef CCL_H
#define CCL_H

#include <vector>
#include <set>

#include "Mat.hpp"

using Component = std::pair<int, int>;
using ConnectedComponent = std::pair<int, std::set<Component>>;

class ConnectedComponentLabeling
{
public:
	Mat image;
	std::vector<ConnectedComponent> connectedComponents;


public:
	ConnectedComponentLabeling(Mat &mat);
	~ConnectedComponentLabeling();

	void labelConnectedComponents();
	ConnectedComponent getBiggestConnectedComponent();
	int getNumberOfConnectedComponents();

};

#endif //CCL_H
