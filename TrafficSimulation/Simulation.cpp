#include "Simulation.h"

#include <iostream>

Simulation::Simulation(const std::vector<Car>& scars, const std::vector<TrafficLight>& slights) :
	cars(scars), lights(slights) {};

void Simulation::check(Car& car, TrafficLight &currLight) {
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



void Simulation::run() {
	if (lights.empty()) return;
	if (cars.empty()) return;
	TrafficLight last = lights.back();


	while (!cars.empty()) {
		for (auto it = cars.begin(); it != cars.end();) {
			it->accelerate(10.0f);
			check(*it, last);
			it->update(1.0f);
			if (it->getPos() > last.getPosition()) {
	
				it = cars.erase(it);
			}
			else {
			
				it++;

			}
		}

	}
	std::cout << "THEEND" << "\n";
 } 