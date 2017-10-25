#include <iostream>
#include <ctime>

#include "MatPGM.hpp"
#include "ConnectedComponentLabeling.hpp"

int main() {
	MatPGM img("CC.pgm");
	MatPGM outImage(img.rows, img.cols, img.fileType, img.maxValue, 0);
	ConnectedComponentLabeling ccl(img);

	clock_t begin = clock();
	ccl.labelConnectedComponents();
	clock_t end = clock();

	std::cout << "Numero de elementos conectados: " << ccl.getNumberOfConnectedComponents() << std::endl;
	for (auto c : ccl.connectedComponents)
		std::cout << "Clase de elemento: " << c.first << " Tam del elemento: " << c.second.size() << std::endl;
	std::cout << "Tiempo de ejecucion: " << double(end - begin) / CLOCKS_PER_SEC << " segundos." << std::endl;

	outImage.setValue(ccl.getBiggestConnectedComponent().second, 255);
	outImage.save("image.pgm");
	
	std::cin.get();
	return 0;

}