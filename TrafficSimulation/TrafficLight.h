#pragma once
enum class LightColor { RED, YELLOW, GREEN };
class TrafficLight {
	private:
		
		float position;
		LightColor currentColor;
		float timer = 0.0f;
		float changeInterval = 10.0f;
public:
	TrafficLight(float position, LightColor startingColor);

	LightColor getColor() const {
		return currentColor;
	}

	float getPosition() const {
		return position;
	}
	void update(float deltaTime);
};