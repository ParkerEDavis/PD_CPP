#ifndef GAME_CONTROLLER_H_INCLUDED
#define GAME_CONTROLLER_H_INCLUDED

#include <iostream>
#include "Racetrack.h"
#include "Player_Car.h"
#include "Fast_Car.h"
#include "Smart_Car.h"
using namespace std;

class GameController
{
private:
	Racetrack current_track;
	/// Classes will have better names when implemented. Likely similar to variable names.
	/// Player
	PlayerCar player_car;

	/// Will randomly pick a direction with the smallest possible weight in it, and will also go max possible speed, so might crash into a wall after reaching desired weight.
	FastCar fast_car;

	/// Will randomly pick a direction with the smallest weight, and stop on the smallest weight.
	SmartCar smart_car;

public:
	/** Controller **/
	GameController();

	/** Methods **/
	/// Handles the main game loop.
	void playGame();

	/// Can't really picture what exactly will be needed here, but will, at the very least, be splitting the playGame function into several seperate functions, as it will likely get large.


	/// Lets player change all settings found in the below Selector functions.
	void settingsMenu();

	/// User Selects track
	void trackSelector();

	/// If the player car is customizable.
	void characterSelector();

	/// Cause why not? Changes command prompt text colors (Not the buggy method I was messing around with.)
	void colorSelector();


	/** Accessors **/
	//[INSERT LATER]
	/** Mutators **/
	//[INSERT LATER]
};


#endif //GAME_CONTROLLER_H_INCLUDED
