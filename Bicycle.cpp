#include "Bicycle.hpp"
#include <math.h>
#include <stdlib.h>
using namespace bike_details;

Bicycle::Bicycle()
{
	b_type_ = static_cast<bike_type>(rand() % 4);
	curr_speed_ = 0;
	curr_direction_ = 0;
	distance_traveled_ = 0;
	seat_height_ = 10;
    curr_pedal_intensity_ = NONE;
}

Bicycle::Bicycle(int kind_of_bike)
{
	Bicycle();
	b_type_ = static_cast<bike_type>(kind_of_bike);
	curr_speed_ = 0;
	curr_direction_ = 0;
	distance_traveled_ = 0;
	seat_height_ = 10;
	curr_pedal_intensity_ = NONE;

}

float Bicycle::ride(float duration)
{
	float distance_delta_ = curr_speed_ * (duration / 60);
	distance_traveled_ += distance_delta_;
	return distance_traveled_;
}

void Bicycle::changeSeatHeight(int inches)
{
	if (inches > 36)
	{
		inches = 36;
	}
	else if (inches < 0)
	{
		inches = 0;
	}
	seat_height_ = inches;
}

void Bicycle::pedal()
{
	switch (curr_pedal_intensity_)
	{
	case NONE:
		curr_pedal_intensity_ = LOW;
		break;
	case LOW:
		curr_pedal_intensity_ = MEDIUM;
		break;
	case MEDIUM:
		curr_pedal_intensity_ = HIGH;
		break;
	}
	updateSpeed();
}

void Bicycle::brake()
{
	switch (curr_pedal_intensity_)
	{
	case LOW:
		curr_pedal_intensity_ = NONE;
		break;
	case MEDIUM:
		curr_pedal_intensity_ = LOW;
		break;
	case HIGH:
		curr_pedal_intensity_ = MEDIUM;
		break;
	}
	updateSpeed();
}

void Bicycle::turn(float degrees)
{
	degrees = fmod(degrees, 360.0f);
	curr_direction_ += degrees;
	if (curr_direction_ < 0)
	{
		curr_direction_ += 360;
	}
	else if (curr_direction_ > 360)
	{
		curr_direction_ -= 360;
	}
}

std::string Bicycle::getDirection()
{
	if (curr_direction_ == 0)
	{
		return "East";
	}
	else if (curr_direction_ == 90)
	{
		return "North";
	}
	else if (curr_direction_ == 180)
	{
		return "West";
	}
	else if (curr_direction_ == 270)
	{
		return "South";
	}
	else if (curr_direction_ == 360)
	{
		return "East";
	}
	else if (curr_direction_ > 270)
	{
		return "Southeast";
	}
	else if (curr_direction_ > 180)
	{
		return "Southwest";
	}
	else if (curr_direction_ > 90)
	{
		return "Northwest";
	}
	else
	{
		return "Northeast";
	}
}

std::string Bicycle::getBikeType()
{
	switch (b_type_)
	{
	case BMX:
		return "BMX";
		break;
	case MOUNTAIN:
		return "MOUNTAIN";
		break;
	case TOURING:
		return "TOURING";
		break;
	case ROAD:
		return "ROAD";
		break;
	}
	return "";
}

int Bicycle::getSeatHeight()
{
	return seat_height_;
}

float Bicycle::getSpeed()
{
	return curr_speed_;
}

float Bicycle::getDistanceTraveled()
{
	return distance_traveled_;
}

std::string Bicycle::getIntensity()
{
	switch (curr_pedal_intensity_)
	{
	case NONE:
		return "None";
		break;
	case LOW:
		return "Low";
		break;
	case MEDIUM:
		return "Medium";
		break;
	case HIGH:
		return "High";
		break;
	default:
		return "";
		break;
	}
}

void Bicycle::updateSpeed()
{
	if (curr_pedal_intensity_ == NONE) {
		curr_speed_ = 0;
	}
	else {
		curr_speed_ = (curr_pedal_intensity_ / 8) * b_type_ + (curr_pedal_intensity_ / 8 + b_type_);
	}
}
