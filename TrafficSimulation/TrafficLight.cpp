#include "TrafficLight.h"
#include <iostream>
#include <string>

TrafficLight::TrafficLight(float position, LightColor startingColor) :position(position), currentColor(startingColor) {}

void TrafficLight::update(float deltaTime) {
    timer += deltaTime;
    if (timer >= changeInterval) {
       
        currentColor = (currentColor == LightColor::RED) ? LightColor::GREEN : LightColor::RED;
        timer = 0.0f;
    }
}