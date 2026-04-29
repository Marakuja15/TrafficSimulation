#pragma once

#include <string>
class Car {
private:

	std::string ID;
	float position;
	float velocity;
public:

	Car(std::string name, float startPos, float startingSpeed);



	void update(float deltaTime);

	void accelerate(float ammount);

	void brake(float ammount);
	float getPos() const {
		return position;
	}
	std::string getID() const {
		return ID;
	}
	float getVelocity() const {
		return velocity;
	}

};
