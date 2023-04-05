#ifndef BASE_CAR_H_INCLUDED
#define BASE_CAR_H_INCLUDED

#include <iostream>

using namespace std;

class BaseCar
{
private:
	char icon; /// Might need to be a string, depending on how conversion works later.
	int max_speed; // Default: 5
	int position_x;
	int position_y;
	int velocity_x;
	int velocity_y;

public:
	/** Controller **/
	BaseCar();

	/** Methods **/
	/// This is what will differentiate the cars.
	//virtual void controller();

	/// Checks for any collisons along a car's chosen path
	bool pathCheck();

	/// Sets velocities to 0 and lower max_speed by 1.
	/// Potentially have some way to communicate with another car if two cars collide.
	void crashed();


	/** Operator Overloads **/
	/// Displays all the car's information, to be displayed after every round.
	friend ostream& operator << (ostream& out, BaseCar& car);

	/** Accessors **/
	//[INSERT LATER]
	/** Mutators **/
	//[INSERT LATER]
};


#endif //BASE_CAR_H_INCLUDED
