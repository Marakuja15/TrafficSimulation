#pragma once
enum class LightColor { RED, YELLOW, GREEN };
class TrafficLight {
	private:
		
		float position;
		LightColor currentColor;
public:
	TrafficLight(float position, LightColor startingColor);

	LightColor getColor() const {
		return currentColor;
	}
	float getPosition() const {
		return position;
	}

};