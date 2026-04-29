#include "Simulation.h"

#include <iostream>

Simulation::Simulation(const std::vector<Car>& scars, const std::vector<TrafficLight>& slights) :
	cars(scars), lights(slights) {};

void Simulation::checkLights(Car& car, TrafficLight &currLight) {
	float pos = car.getPos();
	float speed = car.getVelocity();
	float nearest = 10000.0f;
	TrafficLight currentLight = currLight;
	for (const TrafficLight& light : lights) {
		float checkDistance = light.getPosition() - pos;
		if (checkDistance < 0) {
			continue;
		}
		if (checkDistance < nearest) {
			nearest = checkDistance;
			currentLight = light;
		}
	}
	if (nearest < 100.0f && currentLight.getColor() == LightColor::RED) {
		car.brake(20.0f);
	
	}
	

}

void Simulation::checkCars(Car& currentCar) {

	float currentPos = currentCar.getPos();
	for (const Car& car : cars) {
		float distance = currentPos - car.getPos();
		if (distance < 50.0f && distance > 0) {
			currentCar.brake(20.0f);
		}
	}
}


void Simulation::run() {
	if (lights.empty()) return;
	if (cars.empty()) return;
	TrafficLight last = lights.back();


	while (!cars.empty()) {
		for (auto& light : lights) {
			light.update(1.0f);
		}
		for (auto it = cars.begin(); it != cars.end();) {
			it->accelerate(10.0f);
			checkLights(*it, last);
			it->update(1.0f);
			if (it->getPos() > last.getPosition()) {
				std::cout << "Car: " << it->getID() << " passed the race!\n";
				it = cars.erase(it);
			}
			else {
			
				it++;

			}
		}

	}
	std::cout << "THEEND" << "\n";
 } 