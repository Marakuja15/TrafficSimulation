#include "Car.h"
#include <iostream>
#include <string>
Car::Car(std::string name, float startingPos, float StartingSpeed) : 
	ID(name), position(startingPos), velocity(StartingSpeed) {};
void Car::update(float deltaTime) {
	position += velocity * deltaTime;
}
void Car::accelerate(float ammount) {
	velocity += ammount;
}
void Car::brake(float ammount) {
	velocity -= ammount;
	if (velocity <= 0) {
		velocity = 0.0f;
	}
}
