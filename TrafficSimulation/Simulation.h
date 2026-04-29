#pragma once
#include "TrafficLight.h"
#include "Car.h"
#include <vector>
class Simulation {
private:
	std::vector<Car> cars;
	std::vector<TrafficLight> lights;

public:
	Simulation(const std::vector<Car>& scars,const std::vector<TrafficLight>& slights);

	void run();
	void check(Car &car, TrafficLight &currentLight);
	
};