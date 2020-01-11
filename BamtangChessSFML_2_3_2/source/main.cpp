/******************************************************************************

  Bamtang Games Entrance Test.

  Question number 2.

  2. CHESS BOARD

  [Spanish original Question:]

  Implementar una función que dibuje un tablero de ajedrez con la posición de
las piezas pasada como parámetro.

*******************************************************************************
   By:	 Alejandro E. Almarza Martín
*******************************************************************************

   Requirements: 

A)	For Executing the program:

   1-	Download 'SFML-2.3.2 - 32 bit' for Visual Studio C++ 2010, from:	https://www.sfml-dev.org/files/SFML-2.3.2-windows-vc10-32-bit.zip
   (Main Download Page: https://www.sfml-dev.org/download/sfml/2.3.2/ )
   
   2-	Copy the '...\bin''s Folder content.

   3-	Paste it in the same Folder as this Code's Executable (.exe).

   4-	Have all images in the same Folder as in step (3).


B)	For Developing (Windows 7, VS C++ 2010):

   1-	Install & Configure Visual Studio C++ 2010.
   
   2-	Follow Step (A - (1)): Download 'SFML-2.3.2 - 32 bit' for Visual Studio C++ 2010:  https://www.sfml-dev.org/download/sfml/2.3.2/

   3-	Configure Visual Studio C++ 2010 to Develop C++ Games using SFML >= 2.0 (Read: (Steps in:  https://www.sfml-dev.org/tutorials/2.3/start-vc.php ) )

   2-	Copy this Script Contents inside the Project.

   3-	Decide: [Dynamic Linked Libraries (DLL) vs. Static/Shared Libraries], and set the IDE Configuration. (Steps in:  https://www.sfml-dev.org/tutorials/2.3/start-vc.php )

   4-	Happy Coding.

*******************************************************************************/

#include <iostream>
//#include <vector>	 // Not necessary, I decided not to use this Lib because Queues are more memory-expensive.
#include <SFML/Graphics.hpp>
using namespace std;


// Global variables:

// Pixel Dimensions of each Chess Piece:
//
const int _OBJECT_WIDTH = 64;
const int _OBJECT_HEIGHT = 64;

// Original Question of the Test:
//
const string _INIT_POSITION = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";


// Playground DIMENSIONS: 	(i.e.: Chess Board).
//
const int _TOTAL_CHESS_BOARD_COLUMNS = 8;
const int _TOTAL_CHESS_BOARD_ROWS = 8;

// For CHAR -> int Interchangeability.
//
const int _ASCII_NUMBER_FOR_CHAR_ZERO = 48;


// List of Totals for Variable Counters, for Validations (i.e.: For not Drawing the same Characters twice):
//
const int _TOTAL_NUMBER_OF_P = 8;	// PEONs
const int _TOTAL_NUMBER_OF_R = 2;	// ROCKs
const int _TOTAL_NUMBER_OF_B = 2;	// BISHOPs
const int _TOTAL_NUMBER_OF_N = 2;	// HORSEs
const int _TOTAL_NUMBER_OF_Q = 1;	// QUEEN
const int _TOTAL_NUMBER_OF_K = 1;	// KING


// Char to Map the Chess Board:
//
// TO SEPARATE 'ROWS' of the Board:
//
const char _INIT_CHAR_SLASH_NEW_ROW = '/';
//
// BLACK CHARACTERS:
//
const char _INIT_CHAR_p = 'p';	// PEON
const char _INIT_CHAR_r = 'r';	// ROCK
const char _INIT_CHAR_b = 'b';	// BISHOP
const char _INIT_CHAR_n = 'n';	// HORSE
const char _INIT_CHAR_q = 'q';	// QUEEN
const char _INIT_CHAR_k = 'k';	// KING
//
// WHITE CHARACTERS:
//
const char _INIT_CHAR_P = 'P';
const char _INIT_CHAR_R = 'R';
const char _INIT_CHAR_B = 'B';
const char _INIT_CHAR_N = 'N';
const char _INIT_CHAR_Q = 'Q';
const char _INIT_CHAR_K = 'K';
//
// Blank SPACES (i.e.: 'Nothing')
//
const char _INIT_CHAR_1 = '1';
const char _INIT_CHAR_2 = '2';
const char _INIT_CHAR_3 = '3';
const char _INIT_CHAR_4 = '4';
const char _INIT_CHAR_5 = '5';
const char _INIT_CHAR_6 = '6';
const char _INIT_CHAR_7 = '7';
const char _INIT_CHAR_8 = '8';


// Name of Chess Pieces, for Error Messages (more verbosity):
//
const string _p = "BLACK PEON";		// PEONs
const string _r = "BLACK ROCK";		// ROCKs
const string _b = "BLACK BISHOP";	// BISHOPs
const string _n = "BLACK HORSE";	// HORSEs
const string _q = "BLACK QUEEN";	// QUEEN
const string _k = "BLACK KING";		// KING
//
// WHITE pieces:
//
const string _P = "WHITE PEON";		// PEONs
const string _R = "WHITE ROCK";		// ROCKs
const string _B = "WHITE BISHOP";	// BISHOPs
const string _N = "WHITE HORSE";	// HORSEs
const string _Q = "WHITE QUEEN";	// QUEEN
const string _K = "WHITE KING";		// KING


/**
 * Array of Sprite Indexes, for Setting Positions IN (x, y) in the Chess Board.
**/
const int _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_KING         = 0;
const int _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_QUEEN        = 1;
const int _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_BISHOP_LEFT  = 2;
const int _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_BISHOP_RIGHT = 3;
const int _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_HORSE_LEFT   = 4;
const int _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_HORSE_RIGHT  = 5;
const int _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_ROCK_LEFT    = 6;
const int _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_ROCK_RIGHT   = 7;
//
// BLACK PEONS : 8 - 15
//
const int _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_PEON_1       = 8;
const int _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_PEON_2       = 9;
const int _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_PEON_3       = 10;
const int _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_PEON_4       = 11;
const int _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_PEON_5       = 12;
const int _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_PEON_6       = 13;
const int _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_PEON_7       = 14;
const int _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_PEON_8       = 15;
//
// WHITE:
//
const int _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_KING         = 16;
const int _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_QUEEN        = 17;
const int _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_BISHOP_LEFT  = 18;
const int _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_BISHOP_RIGHT = 19;
const int _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_HORSE_LEFT   = 20;
const int _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_HORSE_RIGHT  = 21;
const int _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_ROCK_LEFT    = 22;
const int _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_ROCK_RIGHT   = 23;
//
// WHITE PEONS : 24 - 31
//
const int _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_PEON_1       = 24;
const int _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_PEON_2       = 25;
const int _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_PEON_3       = 26;
const int _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_PEON_4       = 27;
const int _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_PEON_5       = 28;
const int _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_PEON_6       = 29;
const int _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_PEON_7       = 30;
const int _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_PEON_8       = 31;



// Global variables to all Scripts (#define has a HIGHER scope than 'const'):
//
#define _SCREEN_WIDTH 512   // 512
#define _SCREEN_HEIGHT 512  // 512

#define _CHESS_CHARACTERS_TOTAL_COUNT 32  // 32
#define _CHESS_CHARACTERS_BLACK_COUNT 16  // 16
#define _CHESS_CHARACTERS_BLACK_PEONS_COUNT 8  // 8


/**
 * Array used for Printing out all the Sprites.
**/
sf::Sprite _myArrayOfSpriteForDrawing[ _CHESS_CHARACTERS_TOTAL_COUNT ];
/**
 * Array Last inserted-element index.
**/
size_t _myLastEmptyIndexToInsertArrayOfSpriteForDrawing = 0;


/**
 * Array used for DISPLAYNG OR NOT: all the Sprites (It is used to 'not Drawing Sprites' when USER INPUT is TRICKY):
**/
bool _myArrayOfSpriteForDrawingTrueOrFalseVisible[ _CHESS_CHARACTERS_TOTAL_COUNT ];
/**
 * Array Last inserted-element index.
**/
size_t _myLastEmptyIndexToInsertArrayOfSpriteForDrawingTrueOrFalseVisible = 0;


/**
 * Sprites of: 	Peons Array (BLACK)
**/
sf::Sprite _myArrayOfSpriteBlackPeons[ _CHESS_CHARACTERS_BLACK_PEONS_COUNT ];
/**
 * Sprites of: 	Peons Array (WHITE)
**/
sf::Sprite _myArrayOfSpriteWhitePeons[ _CHESS_CHARACTERS_BLACK_PEONS_COUNT ];





/**PROCEDURES FOR POSITIONING CHARACTERS ON THE BOARD**********************************/


/**
 * Initializes a Global variable, used for HIDING or DISPLAYING (i.e.: Drawing..) Sprites of the Pieces of Chess.
**/
void InitializeArrayForDisplayingSprites ()
{

	for (int i = 0; i < _CHESS_CHARACTERS_TOTAL_COUNT; i++)
	{

		/**
		 * Array used for DISPLAYNG OR NOT: all the Sprites (It is used to 'not Drawing Sprites' when USER INPUT is TRICKY):
		**/
		_myArrayOfSpriteForDrawingTrueOrFalseVisible[ i ] = false;

	}//End for

}//End Procedure


/**
 * It Prints an ERROR MESSAGE to the CONSOLE if: the position NUMBER of ROW and COLUMN are not completely specified.
**/
void PrintErrorMessageWhenColumnOrRowIncomplete ( const char & myChar, const int & myColumn, const int & myRow, const bool isAColumnOverflow, const bool isARowOverflow )
{

	// Use Case: The USER DID NOT Write the Whole Board.. It is INCOMPLETE.
	// At least say this IS AN EXTRANGE CASE, almost an ERROR...
	//
	if ( isAColumnOverflow )
	{

		std::cout << "\n\n*********************************\n\n" << "OBSERVATION NOTE:\n\n  * INCOMPLETE number of ---> COLUMNs <---\n\n  *  AT ROW [0..7] = [ " << myRow << " ].\n  *  --> Starting from: COLUMN [0..7] = [ " << myColumn << " ].\nYou did not specify the whole Board. You have MISSING COLUMNS in your INPUT,\nand maybe you missed some Chess Pieces.";

	}//End if ( isAColumnOverflow )
	//
	if ( isARowOverflow )
	{

		std::cout << "\n\n*********************************\n\n" << "OBSERVATION NOTE:\n\n  * INCOMPLETE number of ---> ROWs <---\n\n  *  --> Starting from: ROW [0..7] = [ " << myRow << " ].\n  *  AT COLUMN [0..7] = [ " << myColumn << " ].\nYou did not specify the whole Board. You have MISSING ROWs in your INPUT,\nand maybe you missed some Chess Pieces.";

	}//End if ( isAColumnOverflow )

	std::cout << "\n\n" << "___But it is right if you know what you are doing (maybe you refer to a Chess Game that is about to end...)___" << "\n==========================================\n\n";

}//End Procedure


/**
 * Prints an Error Message to the Console if: the position NUMBER of ROW and COLUMN is INVALID.
**/
void PrintErrorMessageWhenColumnOrRowAreInvalid ( const char & myChar, const int & myColumn, const int & myRow, const bool isAnInvalidColumn, const bool isAnInvalidRow )
{

	// Throw an ERROR, or at least say this IS AN ERROR...
	//...and STOP the ROUTINE!
	//
	if ( isAnInvalidColumn )
	{

		std::cout << "\n\n*********************************\n\n" << "ERROR: INVALID ---> COLUMN <--- number!\nYou attemped to Access a COLUMN (Position number) in the Chess Board that does not exist.";

	}//End if ( isAColumnOverflow )
	//
	if ( isAnInvalidRow )
	{

		std::cout << "\n\n*********************************\n\n" << "ERROR: INVALID ---> ROW <--- number!\nYou attemped to Access a ROW (Position number) in the Chess Board that does not exist.";

	}//End if ( isAColumnOverflow )

	std::cout << "\n\n" << "___INVALID POSITION on the Chess Board:___" << "\n==========================================\n\n";

	std::cout << " * AT ROW    number = " << myRow << "\n";
	std::cout << " * AT COLUMN number = " << myColumn << "\n";
	//
	std::cout << "---\n" << "PLEASE fix it (REMEMBER: There are just eight (8) Columns and eight (8) ROWS in a CHESS BOARD. Inside the Game (internally) they are numbered from ZERO (0) to (7): [ 0..7 ] both.\n\nAnd Please try again.\n\n";

	// Console Pause:
	//
	std::cout << "Press the <ENTER> key to: Watch me Rendering everything until this error appeared.";
	//
	//std::cout << "Press the <ENTER> key to Terminate the Program";
	//
	// Pause:
	//
	std::cin.get();

}//End Procedure


/**
 * Prints an Error Message to the Console if: You attemp to Draw the SAME Chess Piece MORE THAN ONCE (i.e.: It is an Invalid Process).
**/
void PrintErrorMessageWhenTryingToDrawAndUseAPieceMoreThanOnce ( const char & myChar, const string & myCharacterName, const int & myColumn, const int & myRow )
{
	// With a LETTER / CHAR which is already DRAWED:
	//
	// Throw an ERROR, or at least say this IS AN ERROR...
	//...and STOP the ROUTINE!
	//
	std::cout << "\n\n*********************************\n\n" << "ERROR!\nYou attemped to Draw a Chess Piece that has already been Drawed.\n\n  * A ------> \" " << myCharacterName << " \"." << ".\n  * Invalid CHAR Input = [ " << myChar << " ]" << "\n\n";
	std::cout << " * AT ROW    number = " << myRow << "\n";
	std::cout << " * AT COLUMN number = " << myColumn << "\n";
	//
	std::cout << "---\n" << "PLEASE fix it (by removing it, leaving an empty space in its place), and then try again.\n\n";

	// Console Pause:
	//
	std::cout << "Press the <ENTER> key to: Watch me Rendering everything until this error appeared.";
	//
	//std::cout << "Press the <ENTER> key to Terminate the Program";
	//
	// PAUSE:
	//
	std::cin.get();

}//End Procedure


/**
 * Prints an Error Message to the Console if: It finds an INVALID CHAR in User's INPUT.
 * Valid CHARS are: 1..8, r,n,b,q,k,p, R,N,B,Q,K,P, /  (spaces are not allowed - i.e. CHAR # 32)
**/
void PrintErrorMessageWhenInvalidCharacter ( const char & myChar, const int & myColumn, const int & myRow )
{
	// With a LETTER / CHAR which is INVALID:
	//
	// Throw an ERROR, or at least say this IS AN ERROR...
	//...and STOP the ROUTINE!
	//
	std::cout << "\n\n*********************************\n\n" << "ERROR!\nInvalid CHAR Input = [ " << myChar << " ]" << "\n";
	std::cout << " * AT ROW    number = " << myRow << "\n";
	std::cout << " * AT COLUMN number = " << myColumn << "\n";
	//
	std::cout << "---\n" << "PLEASE fix it, and then try again.\n\n";

	// Console Pause:
	//
	std::cout << "Press the <ENTER> key to: Watch me Rendering everything until this error appeared.";
	//
	//std::cout << "Press the <ENTER> key to Terminate the Program";
	//
	// Pause:
	//
	std::cin.get();

}//End Procedure


/**
 * Prints an Error Message to the Console if: 
 * There are TOO MANY BLANK SPACES (i.e.: Numbers are the symbol for BLANK Spaces on the Chess Board); to be Drawn (..And If I can draw this one which is comming up now soon..).
**/
void PrintErrorMessageWhenInvalidNumberOfBlankSpaces ( const char & myChar, const int & myBlankSpacesToAdd, const int & myColumn, const int & myRow, const bool & isAnInvalidColumn, const bool & isAnInvalidRow )
{

	// Invalid Number of BLANK SPACES.
	//
	// Throw an ERROR, or at least say this IS AN ERROR...
	//...and STOP the ROUTINE!
	//
	if ( isAnInvalidColumn )
	{

		std::cout << "\n\n*********************************\n\n" << "ERROR: INVALID number of BLANK SPACES to add.\n\nWrong ---> COLUMN <--- number!\nYou attemped to Access a COLUMN (Position number) in the Chess Board that does not exist.";
		//
		std::cout << "\n*********************************\n\n" << "You attemped to add: [ " << myBlankSpacesToAdd<< " ] BLANK SPACES from COLUMN = [ " << myColumn <<" ]";
		//
		std::cout << "\n------> Resulting in a Definitive [ COLUMN ] = [ " << (myColumn + myBlankSpacesToAdd) << " ]... WHICH IS INVALID.";


	}//End if ( isAnInvalidColumn )
	//
	if ( isAnInvalidRow )
	{

		std::cout << "\n\n*********************************\n\n" << "ERROR: INVALID number of ROWs to add to the Board.\n\nWrong ---> ROW <--- number!\n\nYou attemped to Access a ROW (Position number) in the Chess Board that does not exist.";
		//
		std::cout << "\n*********************************\n\n" << "You attemped to add: [ " << myBlankSpacesToAdd<< " ] ROW more from ROW number = [ " << myRow <<" ]";
		//
		std::cout << "\n------> Resulting in a Definitive [ ROW ] = [ " << (myRow + myBlankSpacesToAdd) << " ]... WHICH IS INVALID.";

	}//End if ( isAnInvalidRow )

	std::cout << "\n\n" << "___DETAILS: INVALID POSITION on the Chess Board:___" << "\n==========================================\n\n";

	std::cout << " --> STARTING POINT OF ERROR:\n";
	std::cout << " * AT ROW    number = " << myRow << "\n";
	std::cout << " * AT COLUMN number = " << myColumn << "\n";
	//
	std::cout << "---\n" << "PLEASE fix it (REMEMBER: Be careful summing up the BLANK EMPTY SPACES you try to add.\n\nThere are just eight (8) Columns and eight (8) ROWS in a CHESS BOARD. Inside the Game (internally) they are numbered from ZERO (0) to (7): [ 0..7 ] both.\n\nAnd Please try again.\n\n";

	// Console Pause:
	//
	std::cout << "Press the <ENTER> key to: Watch me Rendering everything until this error appeared.";
	//
	//std::cout << "Press the <ENTER> key to Terminate the Program";
	//
	// Pause:
	//
	std::cin.get();

}//End Procedure



/**
 * It validates if the NUMBER OF COLUMN SPACES is eight (8) when changing to a NEW ROW (I mean that IT NOT INCOMPLETE)
 * 
 * RETURNS: true if OK. FALSE otherwise.
**/
bool ValidateNumberOfColumnsIsCompleteWhenAddingNewRow( const int &myColumnNow )
{

	// Compare the Result to the MAXIMUM TOTAL:
	//
	if ( myColumnNow >= (_TOTAL_CHESS_BOARD_ROWS - 1) )
	{

		return true;

	}//End if ( myColumnNow >= (_TOTAL...

	return false;

}//End Procedure



/**
 * It validates HOW MANY BLANK SPACES are going to be Drawn (..And If I can draw this one which is comming up now soon..), 
 * ..based on Counters and Totals (integers).
 * 
 * RETURNS: true if OK. FALSE otherwise.
**/
bool ValidateNumberOfRow( const int &myRow, const int &myRowsToAdd )
{

	int rowResult = (myRow + myRowsToAdd);

	// Compare the Result to the MAXIMUM TOTAL:
	//
	if ( rowResult < _TOTAL_CHESS_BOARD_ROWS )
	{

		return true;

	}//End if ( rowResult < _TOTAL_CHESS_BOARD_ROWS )

	return false;

}//End Procedure


/**
 * It validates HOW MANY BLANK SPACES are going to be Drawn (..And If I can draw this one which is comming up now soon..), 
 * ..based on Counters and Totals (integers).
 * 
 * RETURNS: true if OK. FALSE otherwise.
**/
bool ValidateNumberOfBlankSpacesInColumn( const int &myColumn, const int &blankSpacesToAdd )
{

	int columnResult = (myColumn + blankSpacesToAdd);

	// Compare the Result to the MAXIMUM TOTAL:
	//
	if ( columnResult <= _TOTAL_CHESS_BOARD_COLUMNS )
	{

		return true;

	}//End if ( columnResult <= _TOTA..

	return false;

}//End Procedure


/**
 * It validates HOW MANY Chess PIECES have been Drawed (..And If I can draw this one which is comming up now soon..), 
 * ..based on Counters and Totals (integers).
 * 
 * RETURNS: true if OK. FALSE otherwise.
**/
bool ValidateTheDrawingOf ( const int &totalAllowedToDraw, const int &alreadyDrawn )
{

	if ( alreadyDrawn < totalAllowedToDraw )
	{

		return true;

	}//End if ( alreadyDrawn < totalAllowedToDraw )

	return false;

}//End Procedure



/****************WHEN ALREADY TRANSLATED*****************************/

/**
* It Sets the Position of the Character / Sprite, according to ITS 'columnX' & 'rowY'.
**/
void SetCharacterPosition ( sf::Sprite &mySprite, const int &columnX, const int &rowY )
{

    //  1- Set Position:
    //
	mySprite.setPosition((float)(columnX * _OBJECT_WIDTH), (float)(rowY * _OBJECT_HEIGHT));

}//End SetCharacterPosition...


/**For TRANSLATING from Input to SPRITES and Drawables***********************************************/


/**
 * Given a Character's NAME <@myCharName>: It returns / gets the Character's SPRITE.
**/
int GetCharacterSpriteFromCharName ( const char myCharName, const int numberOfCharactersOfThisKindAlreadyDrawed, sf::Sprite (& myArrayOfSpriteForDrawing)[ _CHESS_CHARACTERS_TOTAL_COUNT ] )
{

    //  1- Transform / Translate Position
    //
    // Conversion Table
    //
    switch ( myCharName )
    {

        // BLACK:
        //
        case _INIT_CHAR_p:
        {
            // PEON
            //
            ///return myArrayOfSpriteForDrawing[ _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_PEON_1 + numberOfCharactersOfThisKindAlreadyDrawed ];
            //
            return ( _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_PEON_1 + numberOfCharactersOfThisKindAlreadyDrawed );

        }
        break;

        case _INIT_CHAR_r:
        {
            // ROCK
            //
            ///return myArrayOfSpriteForDrawing[ _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_ROCK_LEFT + numberOfCharactersOfThisKindAlreadyDrawed ];
            //
            return ( _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_ROCK_LEFT + numberOfCharactersOfThisKindAlreadyDrawed );

        }
        break;

        case _INIT_CHAR_b:
        {
            // BISHOP
            //
            ///return myArrayOfSpriteForDrawing[  _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_BISHOP_LEFT + numberOfCharactersOfThisKindAlreadyDrawed ];
            //
            return ( _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_BISHOP_LEFT + numberOfCharactersOfThisKindAlreadyDrawed );
        }
        break;

        case _INIT_CHAR_n:
        {
            // HORSE
            //
            ///return myArrayOfSpriteForDrawing[  _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_HORSE_LEFT + numberOfCharactersOfThisKindAlreadyDrawed ];
            //
            return ( _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_HORSE_LEFT + numberOfCharactersOfThisKindAlreadyDrawed );

        }
        break;

        case _INIT_CHAR_q:
        {
            // QUEEN
            //
            return _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_QUEEN;
        }
        break;

        case _INIT_CHAR_k:
        {
            // KING
            //
            ///return myArrayOfSpriteForDrawing[  _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_KING ];
            //
            return _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_KING;
        }
        break;


        /*************************/

        // WHITE:
        //
        case _INIT_CHAR_P:
        {
            // PEON
            //
            ///return myArrayOfSpriteForDrawing[ _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_PEON_1 + numberOfCharactersOfThisKindAlreadyDrawed ];
            //
            return ( _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_PEON_1 + numberOfCharactersOfThisKindAlreadyDrawed );

        }
        break;

        case _INIT_CHAR_R:
        {
            // ROCK
            //
            ///return myArrayOfSpriteForDrawing[ _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_ROCK_LEFT + numberOfCharactersOfThisKindAlreadyDrawed ];
            //
            return ( _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_ROCK_LEFT + numberOfCharactersOfThisKindAlreadyDrawed );

        }
        break;

        case _INIT_CHAR_B:
        {
            // BISHOP
            //
            ///return myArrayOfSpriteForDrawing[  _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_BISHOP_LEFT + numberOfCharactersOfThisKindAlreadyDrawed ];
            //
            return ( _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_BISHOP_LEFT + numberOfCharactersOfThisKindAlreadyDrawed );
        }
        break;

        case _INIT_CHAR_N:
        {
            // HORSE
            //
            ///return myArrayOfSpriteForDrawing[  _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_HORSE_LEFT + numberOfCharactersOfThisKindAlreadyDrawed ];
            //
            return ( _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_HORSE_LEFT + numberOfCharactersOfThisKindAlreadyDrawed );

        }
        break;

        case _INIT_CHAR_Q:
        {
            // QUEEN
            //
            ///return myArrayOfSpriteForDrawing[  _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_QUEEN ];
            //
            return _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_QUEEN;
        }
        break;

        case _INIT_CHAR_K:
        {
            // KING
            //
            ///return myArrayOfSpriteForDrawing[  _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_KING ];
            //
            return _MY_INDEX_ARRAY_FOR_DRAWING_WHITE_KING;
        }
        break;


		default:	 // Return the White King
		{

			// KING
			//
			///return myArrayOfSpriteForDrawing[  _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_KING ];
			//
			return _MY_INDEX_ARRAY_FOR_DRAWING_BLACK_KING;

		}//End default

    }//End switch

}//End GetCharacterSpriteFromCharName...


/**
* It Sets Position of a Sprite / Character on the Board. It is based on its NAME (as it is detailed in the Question Test).
**/
void SetCharacterOnBoard ( const char & myCharName, const int & numberOfCharactersOfThisKindAlreadyDrawed, sf::Sprite (& myArrayOfSpriteForDrawing)[ _CHESS_CHARACTERS_TOTAL_COUNT ], bool (& myArrayOfSpriteForDrawingTrueOrFalseVisible)[ _CHESS_CHARACTERS_TOTAL_COUNT ], const int & columnX, const int & rowY )
{

    //  1-  Translate NAME -> to -> Sprite / Character:
    //
    int myIndexOfCharacterSprite = GetCharacterSpriteFromCharName ( myCharName, numberOfCharactersOfThisKindAlreadyDrawed, myArrayOfSpriteForDrawing );

    //  2- Set Position:
    //
    SetCharacterPosition ( myArrayOfSpriteForDrawing[ myIndexOfCharacterSprite ], columnX, rowY );


    //	3- Tell the .DRAW FUNCTION: "You will draw this one".
    //
    myArrayOfSpriteForDrawingTrueOrFalseVisible[ myIndexOfCharacterSprite ] = true;

}//End SetCharacterOnBoard...




/**
 * Given a Character's NAME <@myCharName>: It returns / gets the Character's SPRITE.
**/
void TranslateValidateCharsAndDrawChessBoard ( const string &initPosition, sf::Sprite (& myArrayOfSpriteForDrawing)[ _CHESS_CHARACTERS_TOTAL_COUNT ] )
{

	// Vars for the algoritm
	//
	// Char for comparing with the PARAMETERS LIST:
	//
	char myChar = 'r';
	//
	// Rows and Columns that this Algoritm will Translate, using the String 'initPosition' as an Input.
	//
	int myRow 		= 0;
	int myColumn 	= 0;
	//
	int myBlankSpacesToAdd 	= 0;
	//
	// Counters for Validating each Sprite asignation:
	// BLACK pieces:
	//
	int alreadyDrawn_p = 0;	// PEONs
	int alreadyDrawn_r = 0;	// ROCKs
	int alreadyDrawn_b = 0;	// BISHOPs
	int alreadyDrawn_n = 0;	// HORSEs
	int alreadyDrawn_q = 0;	// QUEEN
	int alreadyDrawn_k = 0;	// KING
	//
	// WHITE pieces:
	//
	int alreadyDrawn_P = 0;	// PEONs
	int alreadyDrawn_R = 0;	// ROCKs
	int alreadyDrawn_B = 0;	// BISHOPs
	int alreadyDrawn_N = 0;	// HORSEs
	int alreadyDrawn_Q = 0;	// QUEEN
	int alreadyDrawn_K = 0;	// KING

	// Total Number of Chars inside string 'initPosition'
	//
	size_t stringCharTotalCount = initPosition.length();


	// VALID to continue:
	//
	bool isValidToContinue = true;


	// For-loop for going throught each CHAR of the INPUT STRING: 'initPosition'
	//
	for (size_t i = 0; (i < stringCharTotalCount) && isValidToContinue; i++)
	{

		// Extract the CHAR from the STRING:
		//
		myChar = initPosition[ i ];

		// Some Validations:
		// 1- Number of 'myColumn' must be everytime < 8 (0..7)
		//
		if ( (myColumn > _TOTAL_CHESS_BOARD_COLUMNS) || (myColumn < 0) )
		{

			// ERROR!
			//
			isValidToContinue = false;
			//
			PrintErrorMessageWhenColumnOrRowIncomplete ( myChar, myColumn, myRow, true, false );

		}//End if ( myColumn >= _TOTAL_CHESS_BOARD_COLUMNS )

		// 2- Number of 'myRow' must be < 8 (0..7) too!
		//
		if ( (myRow > _TOTAL_CHESS_BOARD_ROWS) || (myRow < 0) )
		{

			// ERROR!
			//
			isValidToContinue = false;
			//
			PrintErrorMessageWhenColumnOrRowIncomplete ( myChar, myColumn, myRow, false, true );

		}//End if ( myColumn >= _TOTAL_CHESS_BOARD_COLUMNS )


		/**BEGIN: CHECKING EACH LETTER an CHAR in the INPUT***************************************/

	    //  1- Transform / Translate Position
	    //
	    // Conversion Table
	    //
	    switch ( myChar )
	    {

	        // JUMP OF LINE (+ROW): '/' CHAR.
	        //
	        case _INIT_CHAR_SLASH_NEW_ROW:
	        {
	        	// [NEW LINE - ROW]
	        	// 1- Update ROW 		NUMBER: ++
	        	// 2- Update COLUMN 	NUMBER: Set = 0
	        	//
	        	myBlankSpacesToAdd = 1;
	        	//
	        	// Validation of the NEW LINE / ROW:
	        	//
	        	isValidToContinue = ValidateNumberOfRow( myRow, myBlankSpacesToAdd );
	        	bool isNumberOfColumnsCompletelySpecifiedWhenAddingNewRow = ValidateNumberOfColumnsIsCompleteWhenAddingNewRow( myColumn );

	        	// Soft Validation: More of an Observation:
	        	//
				// All Columns were specified: (?)
				//
				if ( !isNumberOfColumnsCompletelySpecifiedWhenAddingNewRow )
				{

					// OBSERVATION!
					//
					/////isValidToContinue = false;
					//
					PrintErrorMessageWhenColumnOrRowIncomplete ( myChar, myColumn, myRow, true, false );

				}//End if


	        	// Real VALIDATION:
	        	//
	        	if ( isValidToContinue )
	        	{

		        	// Update What is detailed up above:
		        	//
		        	myRow += myBlankSpacesToAdd;
	        		myColumn = 0;

	        	}//End if ( isValidToContinue )
				else
				{
		            // Throw an ERROR, or at least say this IS AN ERROR...
		            //...and STOP the ROUTINE!
		            //
					PrintErrorMessageWhenInvalidNumberOfBlankSpaces ( myChar, myBlankSpacesToAdd, myColumn, myRow, false, true );

				}//End else
	        }
	        break;

			
			/****************BLANKS - SPACES : NUMBERS*********************/

	        // NUMBERS 1..8:	(NOTE: 0 ZERO is not allowed).
	        //

	        case _INIT_CHAR_1:
	        {
	        	// [BLANK SPACE]
	        	//
	        	myBlankSpacesToAdd = _INIT_CHAR_1 - _ASCII_NUMBER_FOR_CHAR_ZERO;
	        	//
	        	isValidToContinue = ValidateNumberOfBlankSpacesInColumn( myColumn, myBlankSpacesToAdd );
	        	//
	        	if ( isValidToContinue )
	        	{

		        	// Update COLUMN NUMBER:
		        	//
		        	myColumn += myBlankSpacesToAdd;

	        	}//End if ( isValidToContinue )
				else
				{
		            // Throw an ERROR, or at least say this IS AN ERROR...
		            //...and STOP the ROUTINE!
		            //
					PrintErrorMessageWhenInvalidNumberOfBlankSpaces ( myChar, myBlankSpacesToAdd, myColumn, myRow, true, false );

				}//End else
	        }
	        break;

	        case _INIT_CHAR_2:
	        {
	        	// [BLANK SPACE]
	        	//
	        	myBlankSpacesToAdd = _INIT_CHAR_2 - _ASCII_NUMBER_FOR_CHAR_ZERO;
	        	//
	        	isValidToContinue = ValidateNumberOfBlankSpacesInColumn( myColumn, myBlankSpacesToAdd );
	        	//
	        	if ( isValidToContinue )
	        	{

		        	// Update COLUMN NUMBER:
		        	//
		        	myColumn += myBlankSpacesToAdd;

	        	}//End if ( isValidToContinue )
				else
				{
		            // Throw an ERROR, or at least say this IS AN ERROR...
		            //...and STOP the ROUTINE!
		            //
					PrintErrorMessageWhenInvalidNumberOfBlankSpaces ( myChar, myBlankSpacesToAdd, myColumn, myRow, true, false );

				}//End else
	        }
	        break;

	        case _INIT_CHAR_3:
	        {
	        	// [BLANK SPACE]
	        	//
	        	myBlankSpacesToAdd = _INIT_CHAR_3 - _ASCII_NUMBER_FOR_CHAR_ZERO;
	        	//
	        	isValidToContinue = ValidateNumberOfBlankSpacesInColumn( myColumn, myBlankSpacesToAdd );
	        	//
	        	if ( isValidToContinue )
	        	{

		        	// Update COLUMN NUMBER:
		        	//
		        	myColumn += myBlankSpacesToAdd;

	        	}//End if ( isValidToContinue )
				else
				{
		            // Throw an ERROR, or at least say this IS AN ERROR...
		            //...and STOP the ROUTINE!
		            //
					PrintErrorMessageWhenInvalidNumberOfBlankSpaces ( myChar, myBlankSpacesToAdd, myColumn, myRow, true, false );

				}//End else
	        }
	        break;

	        case _INIT_CHAR_4:
	        {
	        	// [BLANK SPACE]
	        	//
	        	myBlankSpacesToAdd = _INIT_CHAR_4 - _ASCII_NUMBER_FOR_CHAR_ZERO;
	        	//
	        	isValidToContinue = ValidateNumberOfBlankSpacesInColumn( myColumn, myBlankSpacesToAdd );
	        	//
	        	if ( isValidToContinue )
	        	{

		        	// Update COLUMN NUMBER:
		        	//
		        	myColumn += myBlankSpacesToAdd;

	        	}//End if ( isValidToContinue )
				else
				{
		            // Throw an ERROR, or at least say this IS AN ERROR...
		            //...and STOP the ROUTINE!
		            //
					PrintErrorMessageWhenInvalidNumberOfBlankSpaces ( myChar, myBlankSpacesToAdd, myColumn, myRow, true, false );

				}//End else
	        }
	        break;

	        case _INIT_CHAR_5:
	        {
	        	// [BLANK SPACE]
	        	//
	        	myBlankSpacesToAdd = _INIT_CHAR_5 - _ASCII_NUMBER_FOR_CHAR_ZERO;
	        	//
	        	isValidToContinue = ValidateNumberOfBlankSpacesInColumn( myColumn, myBlankSpacesToAdd );
	        	//
	        	if ( isValidToContinue )
	        	{

		        	// Update COLUMN NUMBER:
		        	//
		        	myColumn += myBlankSpacesToAdd;

	        	}//End if ( isValidToContinue )
				else
				{
		            // Throw an ERROR, or at least say this IS AN ERROR...
		            //...and STOP the ROUTINE!
		            //
					PrintErrorMessageWhenInvalidNumberOfBlankSpaces ( myChar, myBlankSpacesToAdd, myColumn, myRow, true, false );

				}//End else
	        }
	        break;

	        case _INIT_CHAR_6:
	        {
	        	// [BLANK SPACE]
	        	//
	        	myBlankSpacesToAdd = _INIT_CHAR_6 - _ASCII_NUMBER_FOR_CHAR_ZERO;
	        	//
	        	isValidToContinue = ValidateNumberOfBlankSpacesInColumn( myColumn, myBlankSpacesToAdd );
	        	//
	        	if ( isValidToContinue )
	        	{

		        	// Update COLUMN NUMBER:
		        	//
		        	myColumn += myBlankSpacesToAdd;

	        	}//End if ( isValidToContinue )
				else
				{
		            // Throw an ERROR, or at least say this IS AN ERROR...
		            //...and STOP the ROUTINE!
		            //
					PrintErrorMessageWhenInvalidNumberOfBlankSpaces ( myChar, myBlankSpacesToAdd, myColumn, myRow, true, false );

				}//End else
	        }
	        break;

	        case _INIT_CHAR_7:
	        {
	        	// [BLANK SPACE]
	        	//
	        	myBlankSpacesToAdd = _INIT_CHAR_7 - _ASCII_NUMBER_FOR_CHAR_ZERO;
	        	//
	        	isValidToContinue = ValidateNumberOfBlankSpacesInColumn( myColumn, myBlankSpacesToAdd );
	        	//
	        	if ( isValidToContinue )
	        	{

		        	// Update COLUMN NUMBER:
		        	//
		        	myColumn += myBlankSpacesToAdd;

	        	}//End if ( isValidToContinue )
				else
				{
		            // Throw an ERROR, or at least say this IS AN ERROR...
		            //...and STOP the ROUTINE!
		            //
					PrintErrorMessageWhenInvalidNumberOfBlankSpaces ( myChar, myBlankSpacesToAdd, myColumn, myRow, true, false );

				}//End else
	        }
	        break;

	        case _INIT_CHAR_8:
	        {
	        	// [BLANK SPACE]
	        	//
	        	myBlankSpacesToAdd = _INIT_CHAR_8 - _ASCII_NUMBER_FOR_CHAR_ZERO;
	        	//
	        	isValidToContinue = ValidateNumberOfBlankSpacesInColumn( myColumn, myBlankSpacesToAdd );
	        	//
	        	if ( isValidToContinue )
	        	{

		        	// Update COLUMN NUMBER:
		        	//
		        	myColumn += myBlankSpacesToAdd;

	        	}//End if ( isValidToContinue )
				else
				{
		            // Throw an ERROR, or at least say this IS AN ERROR...
		            //...and STOP the ROUTINE!
		            //
					PrintErrorMessageWhenInvalidNumberOfBlankSpaces ( myChar, myBlankSpacesToAdd, myColumn, myRow, true, false );

				}//End else
	        }
	        break;


	        /****************CHARACTERS*********************/

	        // BLACK:
	        //
	        case _INIT_CHAR_p:
	        {
	            // PEON
	            // 
	            // 1- VALIDATE for this KIND OF CHESS PIECE:
	            //
	            isValidToContinue = ValidateTheDrawingOf ( _TOTAL_NUMBER_OF_P, alreadyDrawn_p );
	            //
				if ( isValidToContinue )
				{

					// 2- Initialize the Sprite, Set Its POSITION & Draw the Sprite adding it to the Array for Printing.
					//
					SetCharacterOnBoard ( myChar, alreadyDrawn_p, _myArrayOfSpriteForDrawing, _myArrayOfSpriteForDrawingTrueOrFalseVisible, myColumn, myRow );
					//
					// Update the 'alreadyDrawn'  variable:
					//
					alreadyDrawn_p++;

				}//End if ( ValidateTheDrawingOf ( ...
				else
				{
		            // Throw an ERROR, or at least say this IS AN ERROR...
		            //...and STOP the ROUTINE!
		            //
					PrintErrorMessageWhenTryingToDrawAndUseAPieceMoreThanOnce ( myChar, _p, myColumn, myRow );

				}//End else


				// 3- Update the Column and Row Variables:
				//
				myColumn++;
	        }
	        break;

	        case _INIT_CHAR_r:
	        {
	            // ROCK
	            // 
	            // 1- VALIDATE for this KIND OF CHESS PIECE:
	            //
	            isValidToContinue = ValidateTheDrawingOf ( _TOTAL_NUMBER_OF_R, alreadyDrawn_r );
	            //
				if ( isValidToContinue )
				{

					// 2- Initialize the Sprite, Set Its POSITION & Draw the Sprite adding it to the Array for Printing.
					//
					SetCharacterOnBoard ( myChar, alreadyDrawn_r, _myArrayOfSpriteForDrawing, _myArrayOfSpriteForDrawingTrueOrFalseVisible, myColumn, myRow );
					//
					// Update the 'alreadyDrawn'  variable:
					//
					alreadyDrawn_r++;

				}//End if ( ValidateTheDrawingOf ( ...
				else
				{
		            // Throw an ERROR, or at least say this IS AN ERROR...
		            //...and STOP the ROUTINE!
		            //
					PrintErrorMessageWhenTryingToDrawAndUseAPieceMoreThanOnce ( myChar, _r, myColumn, myRow );

				}//End else

				// 3- Update the Column and Row Variables:
				//
				myColumn++;
	        }
	        break;

	        case _INIT_CHAR_b:
	        {
	            // BISHOP
	            // 
	            // 1- VALIDATE for this KIND OF CHESS PIECE:
	            //
	            isValidToContinue = ValidateTheDrawingOf ( _TOTAL_NUMBER_OF_B, alreadyDrawn_b );
	            //
				if ( isValidToContinue )
				{

					// 2- Initialize the Sprite, Set Its POSITION & Draw the Sprite adding it to the Array for Printing.
					//
					SetCharacterOnBoard ( myChar, alreadyDrawn_b, _myArrayOfSpriteForDrawing, _myArrayOfSpriteForDrawingTrueOrFalseVisible, myColumn, myRow );
					//
					// Update the 'alreadyDrawn'  variable:
					//
					alreadyDrawn_b++;

				}//End if ( ValidateTheDrawingOf ( (...))
				else
				{
		            // Throw an ERROR, or at least say this IS AN ERROR...
		            //...and STOP the ROUTINE!
		            //
					PrintErrorMessageWhenTryingToDrawAndUseAPieceMoreThanOnce ( myChar, _b, myColumn, myRow );

				}//End else


				// 3- Update the Column and Row Variables:
				//
				myColumn++;
	        }
	        break;

	        case _INIT_CHAR_n:
	        {
	            // HORSE
	            // 
	            // 1- VALIDATE for this KIND OF CHESS PIECE:
	            //
	            isValidToContinue = ValidateTheDrawingOf ( _TOTAL_NUMBER_OF_N, alreadyDrawn_n );
	            //
				if ( isValidToContinue )
				{

					// 2- Initialize the Sprite, Set Its POSITION & Draw the Sprite adding it to the Array for Printing.
					//
					SetCharacterOnBoard ( myChar, alreadyDrawn_n, _myArrayOfSpriteForDrawing, _myArrayOfSpriteForDrawingTrueOrFalseVisible, myColumn, myRow );
					//
					// Update the 'alreadyDrawn'  variable:
					//
					alreadyDrawn_n++;

				}//End if ( ValidateTheDrawingOf ( (...))
				else
				{
		            // Throw an ERROR, or at least say this IS AN ERROR...
		            //...and STOP the ROUTINE!
		            //
					PrintErrorMessageWhenTryingToDrawAndUseAPieceMoreThanOnce ( myChar, _n, myColumn, myRow );

				}//End else


				// 3- Update the Column and Row Variables:
				//
				myColumn++;
	        }
	        break;

	        case _INIT_CHAR_q:
	        {
	            // QUEEN
	            // 
	            // 1- VALIDATE for this KIND OF CHESS PIECE:
	            //
	            isValidToContinue = ValidateTheDrawingOf ( _TOTAL_NUMBER_OF_Q, alreadyDrawn_q );
	            //
				if ( isValidToContinue )
				{

					// 2- Initialize the Sprite, Set Its POSITION & Draw the Sprite adding it to the Array for Printing.
					//
					SetCharacterOnBoard ( myChar, alreadyDrawn_q, _myArrayOfSpriteForDrawing, _myArrayOfSpriteForDrawingTrueOrFalseVisible, myColumn, myRow );
					//
					// Update the 'alreadyDrawn'  variable:
					//
					alreadyDrawn_q++;

				}//End if ( ValidateTheDrawingOf ( (...))
				else
				{
		            // Throw an ERROR, or at least say this IS AN ERROR...
		            //...and STOP the ROUTINE!
		            //
					PrintErrorMessageWhenTryingToDrawAndUseAPieceMoreThanOnce ( myChar, _q, myColumn, myRow );

				}//End else

				// 3- Update the Column and Row Variables:
				//
				myColumn++;
	        }
	        break;

	        case _INIT_CHAR_k:
	        {
	            // KING
	            // 
	            // 1- VALIDATE for this KIND OF CHESS PIECE:
	            //
	            isValidToContinue = ValidateTheDrawingOf ( _TOTAL_NUMBER_OF_K, alreadyDrawn_k );
	            //
				if ( isValidToContinue )
				{

					// 2- Initialize the Sprite, Set Its POSITION & Draw the Sprite adding it to the Array for Printing.
					//
					SetCharacterOnBoard ( myChar, alreadyDrawn_k, _myArrayOfSpriteForDrawing, _myArrayOfSpriteForDrawingTrueOrFalseVisible, myColumn, myRow );

				}//End if ( ValidateTheDrawingOf ( (...))
				else
				{
		            // Throw an ERROR, or at least say this IS AN ERROR...
		            //...and STOP the ROUTINE!
		            //
					PrintErrorMessageWhenTryingToDrawAndUseAPieceMoreThanOnce ( myChar, _k, myColumn, myRow );

				}//End else


				// 3- Update the Column and Row Variables:
				//
				myColumn++;
	        }
	        break;


	        /*************************/

	        // WHITE:
	        //
	        case _INIT_CHAR_P:
	        {
	            // PEON
	            // 
	            // 1- VALIDATE for this KIND OF CHESS PIECE:
	            //
	            isValidToContinue = ValidateTheDrawingOf ( _TOTAL_NUMBER_OF_P, alreadyDrawn_P );
	            //
				if ( isValidToContinue )
				{

					// 2- Initialize the Sprite, Set Its POSITION & Draw the Sprite adding it to the Array for Printing.
					//
					SetCharacterOnBoard ( myChar, alreadyDrawn_P, _myArrayOfSpriteForDrawing, _myArrayOfSpriteForDrawingTrueOrFalseVisible, myColumn, myRow );
					//
					// Update the 'alreadyDrawn'  variable:
					//
					alreadyDrawn_P++;

				}//End if ( ValidateTheDrawingOf ( ...
				else
				{
		            // Throw an ERROR, or at least say this IS AN ERROR...
		            //...and STOP the ROUTINE!
		            //
					PrintErrorMessageWhenTryingToDrawAndUseAPieceMoreThanOnce ( myChar, _p, myColumn, myRow );

				}//End else


				// 3- Update the Column and Row Variables:
				//
				myColumn++;
	        }
	        break;

	        case _INIT_CHAR_R:
	        {
	            // ROCK
	            // 
	            // 1- VALIDATE for this KIND OF CHESS PIECE:
	            //
	            isValidToContinue = ValidateTheDrawingOf ( _TOTAL_NUMBER_OF_R, alreadyDrawn_R );
	            //
				if ( isValidToContinue )
				{

					// 2- Initialize the Sprite, Set Its POSITION & Draw the Sprite adding it to the Array for Printing.
					//
					SetCharacterOnBoard ( myChar, alreadyDrawn_R, _myArrayOfSpriteForDrawing, _myArrayOfSpriteForDrawingTrueOrFalseVisible, myColumn, myRow );
					//
					// Update the 'alreadyDrawn'  variable:
					//
					alreadyDrawn_R++;

				}//End if ( ValidateTheDrawingOf ( ...
				else
				{
		            // Throw an ERROR, or at least say this IS AN ERROR...
		            //...and STOP the ROUTINE!
		            //
					PrintErrorMessageWhenTryingToDrawAndUseAPieceMoreThanOnce ( myChar, _R, myColumn, myRow );

				}//End else

				// 3- Update the Column and Row Variables:
				//
				myColumn++;
	        }
	        break;

	        case _INIT_CHAR_B:
	        {
	            // BISHOP
	            // 
	            // 1- VALIDATE for this KIND OF CHESS PIECE:
	            //
	            isValidToContinue = ValidateTheDrawingOf ( _TOTAL_NUMBER_OF_B, alreadyDrawn_B );
	            //
				if ( isValidToContinue )
				{

					// 2- Initialize the Sprite, Set Its POSITION & Draw the Sprite adding it to the Array for Printing.
					//
					SetCharacterOnBoard ( myChar, alreadyDrawn_B, _myArrayOfSpriteForDrawing, _myArrayOfSpriteForDrawingTrueOrFalseVisible, myColumn, myRow );
					//
					// Update the 'alreadyDrawn'  variable:
					//
					alreadyDrawn_B++;

				}//End if ( ValidateTheDrawingOf ( (...))
				else
				{
		            // Throw an ERROR, or at least say this IS AN ERROR...
		            //...and STOP the ROUTINE!
		            //
					PrintErrorMessageWhenTryingToDrawAndUseAPieceMoreThanOnce ( myChar, _B, myColumn, myRow );

				}//End else


				// 3- Update the Column and Row Variables:
				//
				myColumn++;
	        }
	        break;

	        case _INIT_CHAR_N:
	        {
	            // HORSE
	            // 
	            // 1- VALIDATE for this KIND OF CHESS PIECE:
	            //
	            isValidToContinue = ValidateTheDrawingOf ( _TOTAL_NUMBER_OF_N, alreadyDrawn_N );
	            //
				if ( isValidToContinue )
				{

					// 2- Initialize the Sprite, Set Its POSITION & Draw the Sprite adding it to the Array for Printing.
					//
					SetCharacterOnBoard ( myChar, alreadyDrawn_N, _myArrayOfSpriteForDrawing, _myArrayOfSpriteForDrawingTrueOrFalseVisible, myColumn, myRow );
					//
					// Update the 'alreadyDrawn'  variable:
					//
					alreadyDrawn_N++;

				}//End if ( ValidateTheDrawingOf ( (...))
				else
				{
		            // Throw an ERROR, or at least say this IS AN ERROR...
		            //...and STOP the ROUTINE!
		            //
					PrintErrorMessageWhenTryingToDrawAndUseAPieceMoreThanOnce ( myChar, _N, myColumn, myRow );

				}//End else


				// 3- Update the Column and Row Variables:
				//
				myColumn++;
	        }
	        break;

	        case _INIT_CHAR_Q:
	        {
	            // QUEEN
	            // 
	            // 1- VALIDATE for this KIND OF CHESS PIECE:
	            //
	            isValidToContinue = ValidateTheDrawingOf ( _TOTAL_NUMBER_OF_Q, alreadyDrawn_Q );
	            //
				if ( isValidToContinue )
				{

					// 2- Initialize the Sprite, Set Its POSITION & Draw the Sprite adding it to the Array for Printing.
					//
					SetCharacterOnBoard ( myChar, alreadyDrawn_Q, _myArrayOfSpriteForDrawing, _myArrayOfSpriteForDrawingTrueOrFalseVisible, myColumn, myRow );
					//
					// Update the 'alreadyDrawn'  variable:
					//
					alreadyDrawn_Q++;

				}//End if ( ValidateTheDrawingOf ( (...))
				else
				{
		            // Throw an ERROR, or at least say this IS AN ERROR...
		            //...and STOP the ROUTINE!
		            //
					PrintErrorMessageWhenTryingToDrawAndUseAPieceMoreThanOnce ( myChar, _Q, myColumn, myRow );

				}//End else

				// 3- Update the Column and Row Variables:
				//
				myColumn++;
	        }
	        break;

	        case _INIT_CHAR_K:
	        {
	            // KING
	            // 
	            // 1- VALIDATE for this KIND OF CHESS PIECE:
	            //
	            isValidToContinue = ValidateTheDrawingOf ( _TOTAL_NUMBER_OF_K, alreadyDrawn_K );
	            //
				if ( isValidToContinue )
				{

					// 2- Initialize the Sprite, Set Its POSITION & Draw the Sprite adding it to the Array for Printing.
					//
					SetCharacterOnBoard ( myChar, alreadyDrawn_K, _myArrayOfSpriteForDrawing, _myArrayOfSpriteForDrawingTrueOrFalseVisible, myColumn, myRow );

				}//End if ( ValidateTheDrawingOf ( (...))
				else
				{
		            // Throw an ERROR, or at least say this IS AN ERROR...
		            //...and STOP the ROUTINE!
		            //
					PrintErrorMessageWhenTryingToDrawAndUseAPieceMoreThanOnce ( myChar, _K, myColumn, myRow );

				}//End else


				// 3- Update the Column and Row Variables:
				//
				myColumn++;
	        }
	        break;

	        default:
	        {
	            // Throw an ERROR, or at least say this IS AN ERROR...
	            //...and STOP the ROUTINE!
	            //
				PrintErrorMessageWhenInvalidCharacter ( myChar, myColumn, myRow );
				//
				isValidToContinue = false;

	        }//End default
	        break;

	    }//End switch

		/**END: CHECKING EACH LETTER an CHAR in the INPUT***************************************/
		//
		// zzz_3- Other cases:
		//
		if (! isValidToContinue)
		{

			// Get out of this Loop, there is an ERROR.
			//
			break;

		}//End if (! isValidToContinue)


	}//End for (size_t i = 0; i < stringCharTotalCount; i++)


	// Final Validation: SPeial cases not catched before:
	//
	if ( isValidToContinue )
	{

		// There are MISSING ROWS
		//
		if ( (myRow < (_TOTAL_CHESS_BOARD_ROWS - 1)) || (myRow < 0) )
		{

			// OBSERVATION!
			//
			/////isValidToContinue = false;
			//
			PrintErrorMessageWhenColumnOrRowIncomplete ( myChar, myColumn, myRow, false, true );

		}//End if ( (myRow < _TOTAL_CHESS_BOARD_ROWS) || (myRow < 0) )

		// There are MISSING COLUMNS
		//
		if ( (myColumn < (_TOTAL_CHESS_BOARD_COLUMNS - 1)) || (myColumn < 0) )
		{

			// OBSERVATION!
			//
			/////isValidToContinue = true;
			//
			PrintErrorMessageWhenColumnOrRowIncomplete ( myChar, myColumn, myRow, true, false );

		}//End if ( (myColumn < _TOTAL_CHESS_BOARD_COLUMNS) || (myColumn < 0) )

	}//End if ( isValidToContinue )

}//End TranslateValidateCharsAndDrawChessBoard...




/**[End] PROCEDURES FOR POSITIONING CHARACTERS ON THE BOARD**********************************/



/**LOADING OF IMAGES AND CHARACTERS*************************************/

/**
 * It Creates and Loads Image into a Sprite, at the same time it defines which parts of the Sprite Atlas Sheet the Sprite is from (the 'Focus Area' of the Sprite inside the Atlas).
**/
void LoadChessCharacterFromTextureAtlas (const sf::Texture & myImageAtlasBase, sf::Sprite & mySpriteChessCharactersAtlas, sf::Sprite (& _myArrayOfSpriteForDrawing)[ _CHESS_CHARACTERS_TOTAL_COUNT ], size_t & _myLastEmptyIndexToInsertArrayOfSpriteForDrawing, const int & leftCoord, const int & upCoord, const int & rightCoord, const int & bottomCoord)
{

    // Set the Sprite's Image:
    //
	mySpriteChessCharactersAtlas.setTexture( myImageAtlasBase );	 //SetImage( myImageAtlasBase );
    //
    // Read from the Atlas the Exact position of this Image/Sprite: Focus on a part of the BIG Atlas/SpriteSheet:
    //
	mySpriteChessCharactersAtlas.setTextureRect(sf::IntRect(leftCoord, upCoord, _OBJECT_WIDTH, _OBJECT_HEIGHT));   // coord LEFT, TOP, RIGHT, BOTTON	 // SetSubRect(sf::IntRect(leftCoord, upCoord, rightCoord, bottomCoord));   // coord LEFT, TOP, RIGHT, BOTTON

    // WWW- FINAL:
    // Add to Print Qeue:
    //
    _myArrayOfSpriteForDrawing[ _myLastEmptyIndexToInsertArrayOfSpriteForDrawing ] = mySpriteChessCharactersAtlas;
    //
    // Increment Index, don't forget!
    //
    _myLastEmptyIndexToInsertArrayOfSpriteForDrawing++;

}//End Method


/**
 * It Loads Image into all PEON Sprites', at the same time it defines which parts of the 'Sprite Atlas Sheet' each Sprite is from (the 'Focus Area' of the Sprite inside the Atlas).
**/
 void LoadAndInitializeSpriteOfPeonsFromTextureAtlas (const sf::Texture & myImageAtlasBase, sf::Sprite (& _myArrayOfSpriteForDrawing)[ _CHESS_CHARACTERS_TOTAL_COUNT ], size_t & _myLastEmptyIndexToInsertArrayOfSpriteForDrawing, sf::Sprite (& _myArrayOfSpritePeons)[ _CHESS_CHARACTERS_BLACK_PEONS_COUNT ], const int & leftCoord, const int & upCoord, const int & rightCoord, const int & bottomCoord)
{

    // For-Loop to Load Image inside each Peon (First Black, the White):
    // PEONS:
    //
    for (int i = 0; i < _CHESS_CHARACTERS_BLACK_PEONS_COUNT; i++)
    {

        // Load IMAGE for EACH PEON: Pointer and object loaded in HEAP.
        //
        sf::Sprite* mySpriteChessCharactersAtlasPeonPointer = new sf::Sprite();

        // Load Image and Set Dimensions:
        //
        LoadChessCharacterFromTextureAtlas ( myImageAtlasBase, *mySpriteChessCharactersAtlasPeonPointer, _myArrayOfSpriteForDrawing, _myLastEmptyIndexToInsertArrayOfSpriteForDrawing, leftCoord, upCoord, rightCoord, bottomCoord );


        // Add to PEON ARRAY
        //
        _myArrayOfSpritePeons [ i ] = (* mySpriteChessCharactersAtlasPeonPointer);

    }//End for

}//End Method


/**
* Answer to the Test, Question number 2: Draw a 'CHESS BOARD'.
*/
void DrawChessBoard( const string &initPosition )
{
    //std::cout << "Window creation" << '\n';

    // 0-   Variables initialization:
    //  0.1-    Array for Displaying (or not) Sprites, based on the USER'S INPUT: Initialization:
    //
    InitializeArrayForDisplayingSprites ();


    // Set the Window:
    //
    sf::RenderWindow Window (sf::VideoMode(_SCREEN_WIDTH, _SCREEN_HEIGHT, 32), "Chess Game" /*, sf::Style::Fullscreen*/);


    // 1-   Background: Chess Board:
    //
	sf::Texture myImageBackground;
    sf::Sprite mySpriteBackground;

    // Validation:
    //
	if ( !myImageBackground.loadFromFile("chess_board.png") )	 // .LoadFromFile("chess_board.png"  /*"Chess_board.png"*/) )
    {
        std::cout << "\n\n" << "ERROR: Could not load Image file" << endl;

    }//End if ( !myImageBackground...
    //
    // Set the Image on the: Sprite
    //
	mySpriteBackground.setTexture( myImageBackground );
    //
    // Set Size/Scale, Position, and other Parameters.

    //... Load all other players...
    //... Set their Positions...

    // PLAYERS: Chess characters:
    //
	sf::Texture myImageChessCharactersAtlas;
    //
    // Validation:
    //
	if ( !myImageChessCharactersAtlas.loadFromFile("chess_characters.png") )
    {
        std::cout << "\n\n" << "ERROR: Could not load Image file" << endl;

    }//End if ( !myImageChessCharactersAtlas...
    //    
    ///Example:     mySpriteChessCharactersAtlas.SetPosition(150.f, 150.f);
    //
    // CHARACTERS:
    //
    // BLACK:
    // 1-   BLACK KING:     Position E = Col = 4 (de: 0..7)
    //
    sf::Sprite mySpriteChessCharactersAtlasBlackKing;    
    //
    // Sets the Sprite's Image, with correct focus in the Sprite Texture Atlas:
    //
    LoadChessCharacterFromTextureAtlas( myImageChessCharactersAtlas, mySpriteChessCharactersAtlasBlackKing, _myArrayOfSpriteForDrawing, _myLastEmptyIndexToInsertArrayOfSpriteForDrawing, 0, 0, _OBJECT_WIDTH, _OBJECT_HEIGHT );
    //
    ///// coord LEFT, TOP, RIGHT, BOTTON


    // 2-   BLACK QUEEN:
    //
    sf::Sprite mySpriteChessCharactersAtlasBlackQueen;
    //
    // Sets the Sprite's Image, with correct focus in the Sprite Texture Atlas:
    //
    LoadChessCharacterFromTextureAtlas( myImageChessCharactersAtlas, mySpriteChessCharactersAtlasBlackQueen, _myArrayOfSpriteForDrawing, _myLastEmptyIndexToInsertArrayOfSpriteForDrawing, (1 * _OBJECT_WIDTH), (0), (2 * _OBJECT_WIDTH), (1 * _OBJECT_HEIGHT) );
    //
    ///// coord LEFT, TOP, RIGHT, BOTTON


    // 3-   BLACK BISHOP (LEFT):
    //
    sf::Sprite mySpriteChessCharactersAtlasBlackBishopLeft;
    //
    // Sets the Sprite's Image, with correct focus in the Sprite Texture Atlas:
    //
    LoadChessCharacterFromTextureAtlas( myImageChessCharactersAtlas, mySpriteChessCharactersAtlasBlackBishopLeft, _myArrayOfSpriteForDrawing, _myLastEmptyIndexToInsertArrayOfSpriteForDrawing, (3 * _OBJECT_WIDTH), (0), ((3 + 1) * _OBJECT_WIDTH), (1 * _OBJECT_HEIGHT) );
    //
    ///// coord LEFT, TOP, RIGHT, BOTTON


    // 4-   BLACK BISHOP (RIGHT):
    //
    sf::Sprite mySpriteChessCharactersAtlasBlackBishopRight;
    //
    // Sets the Sprite's Image, with correct focus in the Sprite Texture Atlas:
    //
    LoadChessCharacterFromTextureAtlas( myImageChessCharactersAtlas, mySpriteChessCharactersAtlasBlackBishopRight, _myArrayOfSpriteForDrawing, _myLastEmptyIndexToInsertArrayOfSpriteForDrawing, (3 * _OBJECT_WIDTH), (0), ((3 + 1) * _OBJECT_WIDTH), (1 * _OBJECT_HEIGHT) );
    //
    ///// coord LEFT, TOP, RIGHT, BOTTON


    // 5-   BLACK HORSE (LEFT):
    //
    sf::Sprite mySpriteChessCharactersAtlasBlackHorseLeft;
    //
    // Sets the Sprite's Image, with correct focus in the Sprite Texture Atlas:
    //
    LoadChessCharacterFromTextureAtlas( myImageChessCharactersAtlas, mySpriteChessCharactersAtlasBlackHorseLeft, _myArrayOfSpriteForDrawing, _myLastEmptyIndexToInsertArrayOfSpriteForDrawing, (4 * _OBJECT_WIDTH), (0), ((4 + 1) * _OBJECT_WIDTH), (1 * _OBJECT_HEIGHT) );
    //
    ///// coord LEFT, TOP, RIGHT, BOTTON


    // 6-   BLACK HORSE (RIGHT):
    //
    sf::Sprite mySpriteChessCharactersAtlasBlackHorseRight;
    //
    // Sets the Sprite's Image, with correct focus in the Sprite Texture Atlas:
    //
    LoadChessCharacterFromTextureAtlas( myImageChessCharactersAtlas, mySpriteChessCharactersAtlasBlackHorseRight, _myArrayOfSpriteForDrawing, _myLastEmptyIndexToInsertArrayOfSpriteForDrawing, (4 * _OBJECT_WIDTH), (0), ((4 + 1) * _OBJECT_WIDTH), (1 * _OBJECT_HEIGHT) );
    //
    ///// coord LEFT, TOP, RIGHT, BOTTON    


    // 7-   BLACK ROCK (LEFT):
    //
    sf::Sprite mySpriteChessCharactersAtlasBlackRockLeft;
    //
    // Sets the Sprite's Image, with correct focus in the Sprite Texture Atlas:
    //
    LoadChessCharacterFromTextureAtlas( myImageChessCharactersAtlas, mySpriteChessCharactersAtlasBlackRockLeft, _myArrayOfSpriteForDrawing, _myLastEmptyIndexToInsertArrayOfSpriteForDrawing, (2 * _OBJECT_WIDTH), (0), ((2 + 1) * _OBJECT_WIDTH), (1 * _OBJECT_HEIGHT) );
    //
    ///// coord LEFT, TOP, RIGHT, BOTTON


    // 8-   BLACK ROCK (RIGHT):
    //
    sf::Sprite mySpriteChessCharactersAtlasBlackRockRight;
    //
    // Sets the Sprite's Image, with correct focus in the Sprite Texture Atlas:
    //
    LoadChessCharacterFromTextureAtlas( myImageChessCharactersAtlas, mySpriteChessCharactersAtlasBlackRockRight, _myArrayOfSpriteForDrawing, _myLastEmptyIndexToInsertArrayOfSpriteForDrawing, (2 * _OBJECT_WIDTH), (0), ((2 + 1) * _OBJECT_WIDTH), (1 * _OBJECT_HEIGHT) );
    //
    ///// coord LEFT, TOP, RIGHT, BOTTON


    /** 9 - 16: BLACK PEONS:*******************************************/
    //
    LoadAndInitializeSpriteOfPeonsFromTextureAtlas (myImageChessCharactersAtlas, _myArrayOfSpriteForDrawing, _myLastEmptyIndexToInsertArrayOfSpriteForDrawing, _myArrayOfSpriteBlackPeons, (5 * _OBJECT_WIDTH), (0), ((5 + 1) * _OBJECT_WIDTH), (1 * _OBJECT_HEIGHT) );
    //
    ///// coord LEFT, TOP, RIGHT, BOTTON


    /**WHITE CHARACTERS***************************************************************/
    //
    // 17-   WHITE KING:     Position E = Col = 4 (de: 0..7)
    //
    sf::Sprite mySpriteChessCharactersAtlasWhiteKing;    
    //
    // Sets the Sprite's Image, with correct focus in the Sprite Texture Atlas:
    //
    LoadChessCharacterFromTextureAtlas( myImageChessCharactersAtlas, mySpriteChessCharactersAtlasWhiteKing, _myArrayOfSpriteForDrawing, _myLastEmptyIndexToInsertArrayOfSpriteForDrawing, 0, (1 * _OBJECT_HEIGHT), _OBJECT_WIDTH, (2 * _OBJECT_HEIGHT) );
    //
    ///// coord LEFT, TOP, RIGHT, BOTTON


    // 18-   WHITE QUEEN:
    //
    sf::Sprite mySpriteChessCharactersAtlasWhiteQueen;
    //
    // Sets the Sprite's Image, with correct focus in the Sprite Texture Atlas:
    //
    LoadChessCharacterFromTextureAtlas( myImageChessCharactersAtlas, mySpriteChessCharactersAtlasWhiteQueen, _myArrayOfSpriteForDrawing, _myLastEmptyIndexToInsertArrayOfSpriteForDrawing, (1 * _OBJECT_WIDTH), (1 * _OBJECT_HEIGHT), (2 * _OBJECT_WIDTH), (2 * _OBJECT_HEIGHT) );
    //
    ///// coord LEFT, TOP, RIGHT, BOTTON


    // 19-   WHITE BISHOP (LEFT):
    //
    sf::Sprite mySpriteChessCharactersAtlasWhiteBishopLeft;
    //
    // Sets the Sprite's Image, with correct focus in the Sprite Texture Atlas:
    //
    LoadChessCharacterFromTextureAtlas( myImageChessCharactersAtlas, mySpriteChessCharactersAtlasWhiteBishopLeft, _myArrayOfSpriteForDrawing, _myLastEmptyIndexToInsertArrayOfSpriteForDrawing, (3 * _OBJECT_WIDTH), (1 * _OBJECT_HEIGHT), ((3 + 1) * _OBJECT_WIDTH), (2 * _OBJECT_HEIGHT) );
    //
    ///// coord LEFT, TOP, RIGHT, BOTTON


    // 20-   WHITE BISHOP (RIGHT):
    //
    sf::Sprite mySpriteChessCharactersAtlasWhiteBishopRight;
    //
    // Sets the Sprite's Image, with correct focus in the Sprite Texture Atlas:
    //
    LoadChessCharacterFromTextureAtlas( myImageChessCharactersAtlas, mySpriteChessCharactersAtlasWhiteBishopRight, _myArrayOfSpriteForDrawing, _myLastEmptyIndexToInsertArrayOfSpriteForDrawing, (3 * _OBJECT_WIDTH), (1 * _OBJECT_HEIGHT), ((3 + 1) * _OBJECT_WIDTH), (2 * _OBJECT_HEIGHT) );
    //
    ///// coord LEFT, TOP, RIGHT, BOTTON


    // 21-   WHITE HORSE (LEFT):
    //
    sf::Sprite mySpriteChessCharactersAtlasWhiteHorseLeft;
    //
    // Sets the Sprite's Image, with correct focus in the Sprite Texture Atlas:
    //
    LoadChessCharacterFromTextureAtlas( myImageChessCharactersAtlas, mySpriteChessCharactersAtlasWhiteHorseLeft, _myArrayOfSpriteForDrawing, _myLastEmptyIndexToInsertArrayOfSpriteForDrawing, (4 * _OBJECT_WIDTH), (1 * _OBJECT_HEIGHT), ((4 + 1) * _OBJECT_WIDTH), (2 * _OBJECT_HEIGHT) );
    //
    ///// coord LEFT, TOP, RIGHT, BOTTON


    // 22-   WHITE HORSE (RIGHT):
    //
    sf::Sprite mySpriteChessCharactersAtlasWhiteHorseRight;
    //
    // Sets the Sprite's Image, with correct focus in the Sprite Texture Atlas:
    //
    LoadChessCharacterFromTextureAtlas( myImageChessCharactersAtlas, mySpriteChessCharactersAtlasWhiteHorseRight, _myArrayOfSpriteForDrawing, _myLastEmptyIndexToInsertArrayOfSpriteForDrawing, (4 * _OBJECT_WIDTH), (1 * _OBJECT_HEIGHT), ((4 + 1) * _OBJECT_WIDTH), (2 * _OBJECT_HEIGHT) );
    //
    ///// coord LEFT, TOP, RIGHT, BOTTON


    // 23-   WHITE ROCK (LEFT):
    //
    sf::Sprite mySpriteChessCharactersAtlasWhiteRockLeft;
    //
    // Sets the Sprite's Image, with correct focus in the Sprite Texture Atlas:
    //
    LoadChessCharacterFromTextureAtlas( myImageChessCharactersAtlas, mySpriteChessCharactersAtlasWhiteRockLeft, _myArrayOfSpriteForDrawing, _myLastEmptyIndexToInsertArrayOfSpriteForDrawing, (2 * _OBJECT_WIDTH), (1 * _OBJECT_HEIGHT), ((2 + 1) * _OBJECT_WIDTH), (2 * _OBJECT_HEIGHT) );
    //
    ///// coord LEFT, TOP, RIGHT, BOTTON


    // 24-   WHITE ROCK (RIGHT):
    //
    sf::Sprite mySpriteChessCharactersAtlasWhiteRockRight;
    //
    // Sets the Sprite's Image, with correct focus in the Sprite Texture Atlas:
    //
    LoadChessCharacterFromTextureAtlas( myImageChessCharactersAtlas, mySpriteChessCharactersAtlasWhiteRockRight, _myArrayOfSpriteForDrawing, _myLastEmptyIndexToInsertArrayOfSpriteForDrawing, (2 * _OBJECT_WIDTH), (1 * _OBJECT_HEIGHT), ((2 + 1) * _OBJECT_WIDTH), (2 * _OBJECT_HEIGHT) );
    //
    ///// coord LEFT, TOP, RIGHT, BOTTON


    /** 25 - 32: WHITE PEONS:*******************************************/
    //    
    LoadAndInitializeSpriteOfPeonsFromTextureAtlas (myImageChessCharactersAtlas, _myArrayOfSpriteForDrawing, _myLastEmptyIndexToInsertArrayOfSpriteForDrawing, _myArrayOfSpriteWhitePeons, (5 * _OBJECT_WIDTH), (1 * _OBJECT_HEIGHT), ((5 + 1) * _OBJECT_WIDTH), (2 * _OBJECT_HEIGHT) );
    //
    ///// coord LEFT, TOP, RIGHT, BOTTON


    //... Load all other players... (if there are any left).

  
	//***... Set their Positions...**********************************/
    //
    // Parting from a string with all Board Setting: Set Positions:
    //
    TranslateValidateCharsAndDrawChessBoard ( initPosition, _myArrayOfSpriteForDrawing );


    // ************************************************************
    // Main Game Loop
    //
	while ( Window.isOpen() )
    {

        sf::Event myEvent;

        while ( Window.pollEvent( myEvent ) )
        {

			if ( (myEvent.type == sf::Event::Closed) || (myEvent.key.code == sf::Keyboard::Escape) )
            {

				Window.close();

            }//End if

        }//End while ( Window.pollEvent( myEvent ) )

		Window.clear();
        //
        // Draw actions: (for EVERY OBJECT)
        // BEGIN
        //
		Window.draw(mySpriteBackground);
		//
        ///// For Testing:  Window.Draw (mySpriteChessCharactersAtlas);
        //
        // CHESS CHARACTERS:
        //
        // DRAWING FROM AN ARRAY
        //
        for (int i = 0; i < _CHESS_CHARACTERS_TOTAL_COUNT; i++)
        {

        	// Only Draw the Chess pieces that have been previously initialized:
        	//
            if ( _myArrayOfSpriteForDrawingTrueOrFalseVisible[ i ] )
            {

				Window.draw( _myArrayOfSpriteForDrawing[ i ] );

            }//End if ( _myArrayOfSpriteForDrawingTrueOrFalseVisible[ i ] )

        }//End for
        //
        // Draw actions:
        // END

		Window.display();

    }//End while1 Main Game Loop (while ( Window.IsOpened() ))

    // ************************************************************

}//End Procedure



int main()
{

	// Get INPUT from Keyboard:
	//
	std::cout << "\n\n\n\n\n***************************************\nBy: Alejandro E. Almarza Martin";
	std::cout << "\n***************************************\n\n";
	std::cout << "Bamtang Games Entrance Test:\nANSWER TO THE C++ GAME DEV EXAM QUESTION: __2__ CHESS BOARD.\n\n";
	std::cout << "OBSERVATION: The INPUT String is HARDCODED, meaning that It is inside the Script: Main.cpp.\n";
	std::cout << "\n23/12/2019\n\n***************************************\n\n";
	//
	std::cout << "** If you want to use ANOTHER INPUT, write it down WITH YOUR KEYBOARD HERE in the CONSOLE;\n** otherwise, just leave it blank and Press <ENTER>.\n\n   * Your Chess Board (and <ENTER>)\n     ( Default Input: " << _INIT_POSITION << " )\n\n   Input --> ";


	// Initialize Input string:
	//
	string initPosition = "";
	//
	// Before I used "cin", but if there is any empty space in the user's input, it will only cut the String right there: // std::cin >> initPosition;
	//
	std::getline(cin, initPosition);


	// INPUT Validation: If the User only presses <ENTER>, with no more data about the Board:
	//
	if ( initPosition == "" )
	{

		// Use the Standard Constant String Global Variable (Declared and Initialized near Line # 1 in this Script: 'Main.cpp'):
		//
		initPosition = _INIT_POSITION;
		//
		// Print to Console your Input:
		//
		std::cout << "   Standard Input Confirmed --> " << initPosition;

	}//End if ( initPosition == "" )


	// This is the ANSWER TO QUESTION # 2:
	//
	DrawChessBoard( initPosition );


	// Pause Console:
	//
	std::cout << "\n\n***************************************\n\nBy: Alejandro E. Almarza Martin\n\n";
	std::cout << "\nPress the <ENTER> key to Terminate the Program.";
	// // Pause:
	// //
	cin.get();

	// return 0;

}//End main
