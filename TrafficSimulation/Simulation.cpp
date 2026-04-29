#include "Simulation.h"

#include <iostream>

Simulation::Simulation(const std::vector<Car>& scars, const std::vector<TrafficLight>& slights) :
	cars(scars), lights(slights) {};


void Simulation::run() {
	int sum = 0;
	for (int i = 0; i < cars.size(); i++) {
		sum += 1;
	}
	std::cout << sum;
} 