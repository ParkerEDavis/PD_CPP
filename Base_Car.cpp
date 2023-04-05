#include "Base_Car.h"


BaseCar::BaseCar()
{
    this->icon = '1';
    this->max_speed = 5;
    this->position_x = 0;
    this->position_y = 0;
    this->velocity_x = 0;
    this->velocity_y = 0;
}


ostream& operator << (ostream& out, BaseCar& car)
{
    out << "Car ID: " << car.icon << " | ";
    out << "Coordinates: (" << car.position_x << ',' << car.position_y << ") | ";
    out << "Max Speed: " << car.max_speed << " | ";
    out << "Velocity: (" << car.velocity_x << ',' << car.velocity_y << ')';

    return out;
}
