#include "Leg.h"

// construct both Legs
Leg Left(3,5,6);
Leg Right(9,10,11);

void setup()
{
	Serial.begin(115200);
	// can be random values depending on hardware and design
	Left.initialise(19,180,60);
	Right.initialise(12,13,14);
}

void loop()
{
	// Let's just issue a simple move()
	Left.move(0,0,0);
	while(!Left.update());

	// now we'll increase precision
	Left.higherPrecision(true);
	// Even though we increased precision, the function
	// works with values from 0 to 180 for convenience.

	// Default delay of 2ms steps will be used
	Left.move(5,5,5);
	while(!Left.update());	// keep looping till we get a true
	
	// we'll lose a little accuracy here, depending on the division
	Left.higherPrecision(false);

	// We'll now take 5 seconds to revert back to original position
	Left.move(0,0,5,5000);
	while(!Left.update());
	// Remember that the transTime passed with the move() is not stored.
	// The next move(), even though you don't pass transTime, will be independent of the previous' transTime.
	
	// You can, however, set and store the transTime easily.
	Left.setTransTime(3141);	// whatever
	Left.move(3, 1, 41);		// this will take 3.141 seconds
	while(!Left.update());

	// We can also input the transTime to be 0, which is also the default value
	// because I want the initialise() to end as fast as possible.
	// But it is not recommended for weak servos
	// Whatever happens, the shortest transition time is limited by mechanics
	Left.move(19,180,60,0);
	
	//Right.move(13,6,24);
	//while(!Left.update() && !Right.update())
	
	delay(1000);
}