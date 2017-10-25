#include "ConnectedComponentLabeling.hpp"

ConnectedComponentLabeling::ConnectedComponentLabeling(Mat &mat) : image{ mat }
{
}


ConnectedComponentLabeling::~ConnectedComponentLabeling()
{
}

void ConnectedComponentLabeling::labelConnectedComponents()
{
	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{
			if (image.data[i][j] == 255) {
				ConnectedComponent connectedComponent;
				std::vector<Component> components;
				connectedComponent.first = connectedComponents.size() + 1;
				components.push_back({ i, j });
				while (components.size() != 0) {
					Component component = components.back();
					components.pop_back();
					if (component.first - 1 >= 0 && image.data[component.first - 1][component.second] == 255) {
						components.push_back({ component.first - 1, component.second });
					}
					if (component.second - 1 >= 0 && image.data[component.first][component.second - 1] == 255) {
						components.push_back({ component.first, component.second - 1 });
					}
					if (component.first + 1 < image.rows && image.data[component.first + 1][component.second] == 255) {
						components.push_back({ component.first + 1, component.second });
					}
					if (component.second + 1 < image.cols && image.data[component.first][component.second + 1] == 255) {
						components.push_back({ component.first, component.second + 1 });
					}
					image.data[component.first][component.second] = connectedComponent.first;
					connectedComponent.second.insert(component);
				}
				connectedComponents.push_back(connectedComponent);
			}
		}
	}
}

ConnectedComponent ConnectedComponentLabeling::getBiggestConnectedComponent()
{
	if (connectedComponents.size() == 0)
		return ConnectedComponent();
	ConnectedComponent *biggest = &connectedComponents[0];
	for (auto &element : connectedComponents)
		if (element.second.size() > biggest->second.size())
			biggest = &element;
	return *biggest;
}

int ConnectedComponentLabeling::getNumberOfConnectedComponents()
{
	return connectedComponents.size();
}
