#include "Racetrack.h"

/** Special Weights **/
// Wall Weight Value
const int Racetrack::W_WALL   = 1000000;
// Finish Line Weight Value
const int Racetrack::W_FINISH = 0;
// Uninitialized Weight Value
const int Racetrack::W_UNINIT = -1;

/**
 *
 */
Racetrack::Racetrack()
    : track()
{
    // Let the initializer list construct the track vector
    // weights can not be created until the size of the track is known
    weights = NULL;
}

/**
 *Destroy object and weights pointer
 */
Racetrack::~Racetrack() {
    // I can not delete an array if it has not yet been created
    if( weights != NULL ) {
        // delete each row
        for( int i = 0; i < this->height(); i++ ) {
            delete[] weights[i];
        }

        //delete the array of pointers
        delete[] weights;
    }
}

/**
 *Read track and add elements to vector and weights to weight array
 */
void Racetrack::read( istream &ins )
{
    string element;
    while (ins >> element)
    {
        for (int i = 0; i < element.size(); i++)
        {
			//Replace the T's with blank/track spaces
            element = replaceStrChar(element, "T", ' ');
        }
		// Add current element to the track vector
        track.push_back(element);
    }
	// Initialize weights after track has been created
    this->initWeights();
}

/**
 *Convert string into character
 */
string Racetrack::replaceStrChar(string str, const string& replace, char ch)
{
  // set our locator equal to the first appearance of any character in replace
  size_t found = str.find_first_of(replace);

  while (found != string::npos) { // While our position in the sting is in range.
    str[found] = ch; // Change the character at position.
    found = str.find_first_of(replace, found+1); // Relocate again.
  }

  return str; // return our new string.
}

/**
 *Access an element from the track
*/
char Racetrack::getTrack(int x, int y)
{
    return track[x][y];
}

/**
 *Update an element from the track
*/
void Racetrack::setTrack(int x, int y, char value)
{
    track[x][y] = value;
}

/**
*Get value of weight location
**/
int Racetrack::getWeight(int x,int y)
{
    return weights[x][y];
}

/**
 *Update a weight from the weight track
*/
void Racetrack::setWeight(int x, int y, int value)
{
    weights[x][y] = value;
}



/**
 *Displays Track in Game Mode
 */
void Racetrack::displayTrack()
{
    for(int i = 0; i < height(); i++ )
    {
        for(int j = 0; j < width(); j++)
        {
            cout << setw(3) << track[i][j];
        }
        cout << endl;
    }
}

/**
 *Displays the weights of the current track.  Used for Testing/Debugging Purposes
 */
void Racetrack::displayWeights()
{
	cout <<"********************TRACK WEIGHTS***********************" << endl;
    for( int i = 0; i < height(); i++ )
    {
        for( int j = 0; j < width(); j++ )
        {
            if (weights[i][j] > 100)
            {
                cout << setw(3) << "X";
            }
            else
            {
                cout << setw(3) << weights[i][j];
            }
        }
        cout << endl;
    }
	cout <<"********************TRACK WEIGHTS***********************" << endl << endl;

}

/**
 *Initialize weight values
 */
void Racetrack::initWeights()
{
    // Allocate the number of required rows (pointers)
    weights = new int*[ height() ];

    // Allocate each row
    for( int i = 0; i < height(); i++ ) {
        weights[i] = new int[ width() ];

        //Set each cell as uninitialized
        for( int j = 0; j < width(); j++ ) {
            weights[i][j] = W_UNINIT;

            // Set wall weights
            if( toupper(track[i][j]) == 'X' ) {
                weights[i][j] = W_WALL;
            }
            else if( toupper(track[i][j]) == 'F' ) {
                // Set finish line weight
                weights[i][j] = W_FINISH;
            }
        }
    }
    /**Assign Weights to blank spaces here**/
	
	/**
	*PLEASE READ
	*The weights below are specific to the current track ONLY
	*You will need to develop an algorithm to dynamically 
	*initialize weights to any track
	**/
	
	//all coords for weight of 11
    weights[1][1] = 11;
    weights[1][2] = 11;
    weights[1][3] = 11;
    weights[1][4] = 11;
    weights[1][5] = 11;
    weights[1][6] = 11;
	weights[2][6] = 11;

	//all coords for weight of 10
    weights[2][1] = 10;
	weights[2][2] = 10;
    weights[2][3] = 10;
    weights[2][4] = 10;
    weights[2][5] = 10;
    weights[3][1] = 10;
	weights[3][5] = 10;
    weights[4][1] = 10;
    weights[5][1] = 10;
    weights[6][1] = 10;
    weights[7][1] = 10;

    //all coords for weight of 9

    weights[3][2] = 9;
	weights[3][3] = 9;
    weights[3][4] = 9;
    weights[4][2] = 9;
    weights[5][2] = 9;
    weights[6][2] = 9;
    weights[7][2] = 9;

    //all coords for weight of 8
    weights[4][3] = 8;
    weights[5][3] = 8;
    weights[6][3] = 8;
    weights[7][3] = 8;

    //all coords for weight of 7
    weights[5][4] = 7;
    weights[6][4] = 7;
    weights[7][4] = 7;

    //all coords for weight of 6
    weights[5][5] = 6;
    weights[6][5] = 6;
    weights[7][5] = 6;
    weights[7][6] = 6;
    weights[7][7] = 6;
    weights[7][8] = 6;
    weights[7][9] = 6;

    //all coords for weight of 5
    weights[5][6] = 5;
    weights[6][6] = 5;
    weights[6][7] = 5;
    weights[6][8] = 5;
    weights[6][9] = 5;

    //all coords for weight of 4
    weights[5][7] = 4;
    weights[5][8] = 4;
    weights[5][9] = 4;
    weights[4][8] = 4;
    weights[4][9] = 4;

    //all coords for weight of 3
    weights[4][8] = 3;
    weights[4][9] = 3;

    //all coords for weight of 2
    weights[3][8] = 2;
    weights[3][9] = 2;

    //all coords for weight of 1
    weights[2][8] = 1;
    weights[2][9] = 1;
}


