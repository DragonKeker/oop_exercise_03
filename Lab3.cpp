#include <iostream>
#include "figure.h"
#include "triangle.h"
#include "octagon.h"
#include "hexagon.h"
#include <vector>
#include <string>

void read_figt(std::vector<Figure*>& fig)
{
	int figt;
	Figure* f = nullptr;

	std::cout << "Fig types: 1 - triangle; 2 - hexagon; 3 - octagon\n";
	std::cin >> figt;
	if (figt == 1) {
		f = new Triangle(std::cin);	
	}
	else if (figt == 2) {
		f = new Hexagon(std::cin);
	}
	else if (figt == 3) {
	f = new Octagon(std::cin);
	
}else{
	std::cout << "Wrong. Try 1 - triangle, 2 - hexagon or 3 - octagon\n";
		}
	fig.push_back(dynamic_cast<Figure*>(f));
	}

	
int main() {
	unsigned int index;
	double Tarea = 0;
	std::string operation;
	std::vector<Figure*> fig;
	
	std::cout << "Operations: add / delete / out / quit\n";

	while (std::cin >> operation) {
		if (operation == "add") {
			read_figt(fig);
		}
		else if (operation == "delete") {
			std::cin >> index;
			delete fig[index];
			for (; index < fig.size() - 1; ++index) {
				fig[index] = fig[index + 1];
			}
			fig.pop_back();
		}
		else if (operation == "out") {
			Tarea = 0;
			for (unsigned int i = 0; i < fig.size(); i++) {
				std::cout << i << ":\n";
				std::cout << "Area: " << fig[i]->area() << std::endl;
				std::cout << "Center: " << fig[i]->center() << std::endl;
				std::cout << "Coordinates: ";
				fig[i]->print(std::cout);
				std::cout << std::endl;
				Tarea += fig[i]->area();
			}
			std::cout << "Total area: " << Tarea << std::endl;
		}
		else if (operation == "quit") {
			for (unsigned int i = 0; i < fig.size(); ++i) {
				delete fig[i];
			}
			return 0;
		}
		else {
			std::cout << "Wrong. Operations: add / delete / out / quit\n";
		}
	}
}