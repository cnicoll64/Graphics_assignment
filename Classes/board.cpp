#include "board.h"
#include "Player.h"

bool Board::fillTile(int x, int y, Player p)
{
	game[x][y].setOccupied();
	game[x][y].setPlayerColor(p.getColor());
	return true;
}

Tile Board::getGameTile(int x, int y)
{
	return game[y][x];
}

int Board::validCornerX(color c) // valid corner functions take a color and returns the x or y coordinate of the corner that color starts in
{
	if (c == Red || c == Green)
	{
		return 0;
	}
	if (c == Blue || c == Yellow)
	{
		return 19;
	}
	return -1;
}

int Board::validCornerY(color c)
{
	if (c == Red || c == Blue)
	{
		return 0;
	}
	if (c == Green || c == Yellow)
	{
		return 19;
	}
	return -1;
}

bool Board::placePiece(int xCenter, int yCenter, Player &p, shape s) // pieces are placed first at their center. if there is no clear center, it will
{															 // be top left of center
	if (p.hasPiece(s))
	{
		switch (s) // Each case contains an algorithm for placing each of the 21 shapes 
		{
		case One: // Shapes One and FiveCross are the only two shapes that have no different combinations when rotated or flipped 
			fillTile(xCenter, yCenter, p);
			p.discardPiece(One);
			break;
			
		case Two:
			fillTile(xCenter, yCenter, p); // fill in center for each shape
			switch (p.getShape(1).getOrientation()) 
			{
			case North: // no rotations
				fillTile(xCenter + 1, yCenter, p);
				break;

			case East: // one rotation clockwise
				fillTile(xCenter, yCenter + 1, p);
				break;

			case South: // two rotations clockwise 
				fillTile(xCenter - 1, yCenter, p);
				break;

			case West: // three rotations clockwise
				fillTile(xCenter, yCenter - 1, p);
				break;
			}
			p.discardPiece(Two);
			break;
			
		case ThreeL:
			fillTile(xCenter, yCenter, p);
				switch (p.getShape(2).getOrientation())
				{
				case North:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter - 1, yCenter, p);
					break;

				case East:
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter - 1, yCenter, p);
					break;

				case South:
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter + 1, yCenter, p);
					break;

				case West:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter, yCenter + 1, p);
					break;
				}
			p.discardPiece(ThreeL);
			break;
			
		case ThreeLine:
			fillTile(xCenter, yCenter, p);
				switch (p.getShape(3).getOrientation())
				{
				case North:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter - 1, yCenter, p);
					break;

				case East:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter, yCenter - 1, p);
					break;

				case South:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter - 1, yCenter, p);
					break;

				case West:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter, yCenter - 1, p);
					break;
				}
			p.discardPiece(ThreeLine);
			break;
			
		case Cube:
			fillTile(xCenter, yCenter, p);
				switch (p.getShape(4).getOrientation())
				{
				case North:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 1, yCenter + 1, p);
					fillTile(xCenter, yCenter + 1, p);
					break;

				case East:
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 1, yCenter + 1, p);
					fillTile(xCenter, yCenter + 1, p);
					break;

				case South:
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 1, yCenter - 1, p);
					fillTile(xCenter, yCenter - 1, p);
					break;

				case West:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 1, yCenter - 1, p);
					fillTile(xCenter, yCenter - 1, p);
					break;
				}
			p.discardPiece(Cube);
			break;
			
		case FourT:
			fillTile(xCenter, yCenter, p);
				switch (p.getShape(5).getOrientation())
				{
				case North:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter, yCenter - 1, p);
					break;

				case East:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter + 1, yCenter, p);
					break;

				case South:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter, yCenter + 1, p);
					break;

				case West:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter - 1, yCenter, p);
					break;
				}
			p.discardPiece(FourT);
			break;

		case FourLine:
			fillTile(xCenter, yCenter, p);
				switch (p.getShape(6).getOrientation())
				{
				case North:
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 2, yCenter, p);
					break;

				case East:
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter, yCenter + 2, p);
					break;

				case South:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 2, yCenter, p);
					break;

				case West:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter, yCenter - 2, p);
					break;
				}
			p.discardPiece(FourLine);
			break;

		case FourL:
			fillTile(xCenter, yCenter, p);
			if (!p.getShape(7).isFlipped()) // checks if shape is not flipped
			{
				switch (p.getShape(7).getOrientation())
				{
				case North:
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 2, yCenter, p);
					fillTile(xCenter, yCenter - 1, p);
					break;

				case East:
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter, yCenter - 2, p);
					fillTile(xCenter + 1, yCenter, p);
					break;

				case South:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 2, yCenter, p);
					fillTile(xCenter, yCenter + 1, p);
					break;

				case West:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter, yCenter + 2, p);
					fillTile(xCenter - 1, yCenter, p);
					break;
				}
			}
			else // if shape is flippped
			{
				switch (p.getShape(7).getOrientation())
				{
				case North:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 2, yCenter, p);
					fillTile(xCenter, yCenter - 1, p);
					break;

				case East:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter, yCenter + 2, p);
					fillTile(xCenter + 1, yCenter, p);
					break;

				case South:
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 2, yCenter, p);
					fillTile(xCenter, yCenter + 1, p);
					break;

				case West:
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter, yCenter - 2, p);
					fillTile(xCenter - 1, yCenter, p);
					break;
				}
			}
			p.discardPiece(FourL);
			break; 
			
		case FourS:
			fillTile(xCenter, yCenter, p);
			if (!p.getShape(8).isFlipped())
			{
				switch (p.getShape(8).getOrientation())
				{
				case North:
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter - 1, yCenter - 1, p);
					fillTile(xCenter + 1, yCenter, p);
					break;

				case East:
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 1, yCenter - 1, p);
					fillTile(xCenter, yCenter + 1, p);
					break;

				case South:
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter + 1, yCenter - 1, p);
					fillTile(xCenter - 1, yCenter, p);
					break;

				case West:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 1, yCenter + 1, p);
					fillTile(xCenter, yCenter - 1, p);
					break;
				}
			}
			else
			{
				switch (p.getShape(8).getOrientation())
				{
				case North:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter, yCenter + 2, p);
					fillTile(xCenter - 1, yCenter, p);
					break;

				case East:
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 1, yCenter + 1, p);
					fillTile(xCenter, yCenter - 1, p);
					break;

				case South:
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter - 1, yCenter - 1, p);
					fillTile(xCenter + 1, yCenter, p);
					break;

				case West:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 1, yCenter - 1, p);
					fillTile(xCenter, yCenter + 1, p);
					break;
				}
			}
			p.discardPiece(FourS);
			break; 
			
		case FiveL:
			fillTile(xCenter, yCenter, p);
			if (!p.getShape(9).isFlipped())
			{
				switch (p.getShape(9).getOrientation())
				{
				case North:
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 2, yCenter, p);
					fillTile(xCenter + 3, yCenter, p);
					break;

				case East:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter, yCenter + 2, p);
					fillTile(xCenter, yCenter + 3, p);
					break;

				case South:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 2, yCenter, p);
					fillTile(xCenter - 3, yCenter, p);
					break;

				case West:
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter, yCenter - 2, p);
					fillTile(xCenter, yCenter - 3, p);
					break;
				}
			}
			else
			{
				switch (p.getShape(9).getOrientation())
				{
				case North:
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 2, yCenter, p);
					fillTile(xCenter - 3, yCenter, p);
					break;

				case East:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter, yCenter - 2, p);
					fillTile(xCenter, yCenter - 3, p);
					break;

				case South:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 2, yCenter, p);
					fillTile(xCenter + 3, yCenter, p);
					break;

				case West:
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter, yCenter + 2, p);
					fillTile(xCenter, yCenter + 3, p);
					break;
				}
			}
			p.discardPiece(FiveL);
			break; 
			
		case FiveT:
			fillTile(xCenter, yCenter, p);
				switch (p.getShape(10).getOrientation())
				{
				case North:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter, yCenter - 2, p);
					break;

				case East:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 2, yCenter, p);
					break;

				case South:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter, yCenter + 2, p);
					break;

				case West:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 2, yCenter, p);
					break;
				}
			p.discardPiece(FiveT);
			break; 
			
		case FiveEvenL:
			fillTile(xCenter, yCenter, p);
				switch (p.getShape(11).getOrientation())
				{
				case North:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 2, yCenter, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter, yCenter - 2, p);
					break;

				case East:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 2, yCenter, p);
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter, yCenter + 2, p);
					break;

				case South:
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 2, yCenter, p);
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter, yCenter + 2, p); 
					break;

				case West:
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 2, yCenter, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter, yCenter - 2, p);
					break;
				}
			p.discardPiece(FiveEvenL);
			break; 
			
		case FiveLongS:
			fillTile(xCenter, yCenter, p);
			if (!p.getShape(12).isFlipped())
			{
				switch (p.getShape(12).getOrientation())
				{
				case North:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter - 1, yCenter + 1, p);
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 2, yCenter, p);
					break;

				case East:
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 1, yCenter - 1, p);
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter, yCenter + 1, p);
					break;

				case South:
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter + 1, yCenter - 1, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 2, yCenter, p);
					break;

				case West:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 1, yCenter + 1, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter, yCenter - 2, p);
					break;
				}
			}
			else
			{
				switch (p.getShape(12).getOrientation())
				{
				case North:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter + 1, yCenter + 1, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 2, yCenter, p);
					break;

				case East:
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 1, yCenter + 1, p);
					fillTile(xCenter , yCenter - 1, p);
					fillTile(xCenter, yCenter - 2, p);
					break;

				case South:
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter - 1, yCenter - 1, p);
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 2, yCenter, p);
					break;

				case West:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 1, yCenter - 1, p);
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter, yCenter + 2, p);
					break;
				}
			}
			p.discardPiece(FiveLongS);
			break; 
			
		case FiveZ:
			fillTile(xCenter, yCenter, p);
			if (!p.getShape(13).isFlipped())
			{
				switch (p.getShape(13).getOrientation())
				{
				case North:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 1, yCenter - 1, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 1, yCenter + 1, p);
					break;

				case East:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter + 1, yCenter + 1, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter - 1, yCenter - 1, p);
					break;

				case South:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 1, yCenter - 1, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 1, yCenter + 1, p);
					break;

				case West:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter + 1, yCenter + 1, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter - 1, yCenter - 1, p);
					break;
				}
			}
			else
			{
				switch (p.getShape(13).getOrientation())
				{
				case North:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 1, yCenter + 1, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 1, yCenter - 1, p);
					break;

				case East:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter + 1, yCenter + 1, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter - 1, yCenter - 1, p);
					break;

				case South:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 1, yCenter + 1, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 1, yCenter - 1, p);
					break;

				case West:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter + 1, yCenter + 1, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter - 1, yCenter - 1, p);
					break;
				}
			}
			p.discardPiece(FiveZ);
			break; 
			
		case FiveLine:
			fillTile(xCenter, yCenter, p);
				switch (p.getShape(14).getOrientation())
				{
				case North:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter, yCenter + 2, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter, yCenter - 2, p);
					break;

				case East:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 2, yCenter, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 2, yCenter, p);
					break;

				case South:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter, yCenter + 2, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter, yCenter - 2, p);
					break;

				case West:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 2, yCenter, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 2, yCenter, p);
					break;
				}
			p.discardPiece(FiveLine);
			break;
			
		case FiveCubeNub:
			fillTile(xCenter, yCenter, p);
			if (!p.getShape(15).isFlipped())
			{
				switch (p.getShape(15).getOrientation())
				{
				case North:
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 1, yCenter + 1, p);
					break;

				case East:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter - 1, yCenter + 1, p);
					break;

				case South:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 1, yCenter - 1, p);
					break;

				case West:
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter + 1, yCenter - 1, p);
					break;
				}
			}
			else
			{
				switch (p.getShape(15).getOrientation())
				{
				case North:
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 1, yCenter + 1, p);
					break;

				case East:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter - 1, yCenter - 1, p);
					break;

				case South:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 1, yCenter + 1, p);
					break;

				case West:
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter + 1, yCenter + 1, p);
					break;
				}
			}
			p.discardPiece(FiveCubeNub);
			break;
			
		case FiveSnake:
			fillTile(xCenter, yCenter, p);
				switch (p.getShape(16).getOrientation())
				{
				case North:
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter + 1, yCenter - 1, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 1, yCenter + 1, p);
					break;

				case East:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter - 1, yCenter + 1, p);
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 1, yCenter + 1, p);
					break;

				case South:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter - 1, yCenter + 1, p);
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 1, yCenter - 1, p);
					break;

				case West:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter + 1, yCenter + 1, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 1, yCenter - 1, p);
					break;
				}
			p.discardPiece(FiveSnake);
			break; 
			
		case FiveC:
			fillTile(xCenter, yCenter, p);
				switch (p.getShape(17).getOrientation())
				{
				case North: //works
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter + 1, yCenter + 1, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter + 1, yCenter - 1, p);
					break;

				case East:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 1, yCenter + 1, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 1, yCenter + 1, p);
					break;

				case South:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter - 1, yCenter + 1, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter - 1, yCenter - 1, p);
					break;

				case West:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 1, yCenter - 1, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 1, yCenter - 1, p);
					break;
				}
			p.discardPiece(FiveC);
			break; 
			
		case FiveSNub:
			fillTile(xCenter, yCenter, p);
			if (!p.getShape(18).isFlipped())
			{
				switch (p.getShape(18).getOrientation())
				{
				case North:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter + 1, yCenter - 1, p);
					break;

				case East:
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 1, yCenter + 1, p);
					break;

				case South:
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter - 1, yCenter + 1, p);
					break;

				case West:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 1, yCenter - 1, p);
					break;
				}
			}
			else
			{
				switch (p.getShape(18).getOrientation())
				{
				case North:
					fillTile(xCenter, yCenter + 1 , p);
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter - 1, yCenter - 1, p);
					break;

				case East:
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 1, yCenter - 1, p);
					break;

				case South:
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter + 1, yCenter + 1, p);
					break;

				case West:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 1, yCenter + 1, p);
					break;
				}
			}
			p.discardPiece(FiveSNub);
			break; 
			
		case FiveCross:
			fillTile(xCenter, yCenter, p);
			fillTile(xCenter + 1, yCenter, p);
			fillTile(xCenter - 1, yCenter, p);
			fillTile(xCenter, yCenter + 1, p);
			fillTile(xCenter, yCenter - 1, p);
			p.discardPiece(FiveCross);
			break; 
			
		case FiveLineNub:
			fillTile(xCenter, yCenter, p);
			if (!p.getShape(20).isFlipped())
			{
				switch (p.getShape(20).getOrientation())
				{
				case North:
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 2, yCenter, p);
					break;

				case East:
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter, yCenter + 2, p);
					break;

				case South:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 2, yCenter, p);
					break;

				case West:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter, yCenter - 2, p);
					break;
				}
			}
			else
			{
				switch (p.getShape(20).getOrientation())
				{
				case North:
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter - 2, yCenter, p);
					break;

				case East:
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter, yCenter - 2, p);
					break;

				case South:
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter + 1, yCenter, p);
					fillTile(xCenter + 2, yCenter, p);
					break;

				case West:
					fillTile(xCenter, yCenter - 1, p);
					fillTile(xCenter - 1, yCenter, p);
					fillTile(xCenter, yCenter + 1, p);
					fillTile(xCenter, yCenter + 2, p);
					break;
				}
			}
			p.discardPiece(FiveLineNub);
			break;
		}
	}
	return true;
}

bool Board::validate(int xCenter, int yCenter, Player p, shape s)
{
	/*
		*Function must take in a cooordinate pair, a shape that is being placed, and a player who is placing the shape and return
		 whether or not the coordinates for the center tile are a valid place to put the peice
		*Center coordinate is defined the same way as in the placing function, where if there is no clear center to the shape, it is
		 the tile to the top left of center

		VALIDATION CRITERIA:
		-None of the tiles under the shape can be occupied
		-No tiles may be outside the 2D array
		-There must be a tile of the player's color at the corner of one of the shapes
		-There must not be any tiles of the players color touching any of the edges of the shape

		If all of these conditions are met, the function returns true
		Also, if any shapes are placed at their starting corner and the conditions are fulfilled, then this is a valid placement

		Template:

			case Two:
		switch (p.getShape(1).getOrientation())
		{
		case North:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter).isOccupied())
			{
				if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case East:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter).isOccupied())
			{
				if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case South:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter).isOccupied())
			{
				if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case West:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter).isOccupied())
			{
				if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;
		}
	*/
	switch (s)
	{
	case One:
		if (!getGameTile(xCenter, yCenter).isOccupied())
		{
			if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
			{
				if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
				{
					return true;
				}
				if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
					(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
					(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
					(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
				{
					if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
						(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
						(getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()))
					{
						return true;
					}
				}

			}
			return false;
		}
		break;

	case Two:
		switch (p.getShape(1).getOrientation())
		{
		case North:
			if ((!getGameTile(xCenter, yCenter).isOccupied()) && (!getGameTile(xCenter + 1, yCenter).isOccupied()))
			{
				if ((xCenter > 0 && xCenter + 1 < 20) && (yCenter > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 2, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case East:
			if ((!getGameTile(xCenter, yCenter).isOccupied()) && (!getGameTile(xCenter + 1, yCenter).isOccupied()))
			{
				if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter + 1 < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case South:
			if ((!getGameTile(xCenter - 1, yCenter).isOccupied()) && (!getGameTile(xCenter, yCenter).isOccupied()))
			{
				if ((xCenter - 1 > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter - 2, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case West:
			if ((!getGameTile(xCenter, yCenter).isOccupied()) && (!getGameTile(xCenter, yCenter - 1).isOccupied()))
			{
				if ((xCenter > 0 && xCenter < 20) && (yCenter - 1 > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;
		}
		break;

	case ThreeL:
		switch (p.getShape(2).getOrientation())
		{
		case North:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter - 1, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter + 1).isOccupied()) // check if spaces are occupied
			{
				if ((xCenter - 1 > 0 && xCenter < 20) && (yCenter > 0 && yCenter + 1 < 20)) //check if tiles go out of bounds
				{
					if ((xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor())) ||
						(xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor())) ||
						(xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()))) //check if piece is in a valid 
					{																						  //corner
						return true;
					}

					if (getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor() ||//check if corner is the right color
						getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() == p.getColor() ||
						getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() == p.getColor() ||
						getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() == p.getColor() ||
						getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() == p.getColor())
					{
						if (getGameTile(xCenter - 2, yCenter).getPlayerColor() != p.getColor() && //check for same color edges
							getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor() &&
							getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor() &&
							getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor() &&
							getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor() &&
							getGameTile(xCenter, yCenter + 2).getPlayerColor() != p.getColor() &&
							getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor())
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case East:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter - 1, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter - 1).isOccupied())
			{
				if ((xCenter - 1 > 0 && xCenter < 20) && (yCenter - 1 > 0 && yCenter < 20))
				{
					if ((xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor())) ||
						(xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor())) ||
						(xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor())))
					{
						return true;
					}

					if (getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor() ||
						getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() == p.getColor() ||
						getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() == p.getColor() ||
						getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() == p.getColor() ||
						getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() == p.getColor())
					{
						if (getGameTile(xCenter - 2, yCenter).getPlayerColor() != p.getColor() &&
							getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor() &&
							getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor() &&
							getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor() &&
							getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor() &&
							getGameTile(xCenter, yCenter - 2).getPlayerColor() != p.getColor() &&
							getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor())
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case South:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter + 1, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter - 1).isOccupied())
			{
				if ((xCenter > 0 && xCenter + 1 < 20) && (yCenter - 1 > 0 && yCenter < 20))
				{
					if ((xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor())) ||
						(xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor())) ||
						(xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor())))
					{
						return true;
					}

					if (getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor() ||
						getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() == p.getColor() ||
						getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() == p.getColor() ||
						getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() == p.getColor() ||
						getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() == p.getColor())
					{
						if (getGameTile(xCenter + 2, yCenter).getPlayerColor() != p.getColor() &&
							getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor() &&
							getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor() &&
							getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor() &&
							getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor() &&
							getGameTile(xCenter, yCenter - 2).getPlayerColor() != p.getColor() &&
							getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor())
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case West:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter + 1, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter + 1).isOccupied())
			{
				if ((xCenter > 0 && xCenter + 1 < 20) && (yCenter > 0 && yCenter + 1 < 20))
				{
					if ((xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor())) ||
						(xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor())) ||
						(xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor())))
					{
						return true;
					}

					if (getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor() ||
						getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() == p.getColor() ||
						getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() == p.getColor() ||
						getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() == p.getColor() ||
						getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() == p.getColor())
					{
						if (getGameTile(xCenter + 2, yCenter).getPlayerColor() != p.getColor() &&
							getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor() &&
							getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor() &&
							getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor() &&
							getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor() &&
							getGameTile(xCenter, yCenter + 2).getPlayerColor() != p.getColor() &&
							getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor())
						{
							return true;
						}
					}
				}
			}
			return false;
			break;
		}
		break;

	case ThreeLine:

		switch (p.getShape(3).getOrientation())
		{
		case North:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter + 1, yCenter).isOccupied() &&
				!getGameTile(xCenter - 1, yCenter).isOccupied())
			{
				if ((xCenter - 1 > 0 && xCenter + 1 < 20) && (yCenter > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 2, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case East:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter + 1).isOccupied() &&
				!getGameTile(xCenter, yCenter - 1).isOccupied())
			{
				if ((xCenter > 0 && xCenter < 20) && (yCenter - 1 > 0 && yCenter + 1 < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case South:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter + 1, yCenter).isOccupied() &&
				!getGameTile(xCenter - 1, yCenter).isOccupied())
			{
				if ((xCenter - 1 > 0 && xCenter + 1 < 20) && (yCenter > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 2, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case West:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter + 1).isOccupied() &&
				!getGameTile(xCenter, yCenter - 1).isOccupied())
			{
				if ((xCenter > 0 && xCenter < 20) && (yCenter - 1 > 0 && yCenter + 1 < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;
		}
		break;

	case Cube:
		switch (p.getShape(4).getOrientation())
		{
		case North:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter + 1, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter + 1).isOccupied() && !getGameTile(xCenter + 1, yCenter + 1).isOccupied())
			{
				if ((xCenter > 0 && xCenter + 1 < 20) && (yCenter > 0 && yCenter + 1 < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter + 1 == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 2, yCenter + 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 2, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case East:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter - 1, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter + 1).isOccupied() && !getGameTile(xCenter - 1, yCenter + 1).isOccupied())
			{
				if ((xCenter - 1 > 0 && xCenter < 20) && (yCenter > 0 && yCenter + 1 < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter - 1 == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter - 2, yCenter + 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter - 2, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case South:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter - 1, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter - 1).isOccupied() && !getGameTile(xCenter - 1, yCenter - 1).isOccupied())
			{
				if ((xCenter - 1 > 0 && xCenter < 20) && (yCenter - 1 > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter - 1 == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter - 2, yCenter - 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter - 2, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case West:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter + 1, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter - 1).isOccupied() && !getGameTile(xCenter + 1, yCenter - 1).isOccupied())
			{
				if ((xCenter > 0 && xCenter + 1 < 20) && (yCenter - 1 > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter + 1 == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 2, yCenter - 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 2, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;
		}
		break;

	case FourT:
		switch (p.getShape(5).getOrientation())
		{
		case North:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter - 1, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter - 1).isOccupied() && !getGameTile(xCenter + 1, yCenter).isOccupied())
			{
				if ((xCenter - 1 > 0 && xCenter + 1 < 20) && (yCenter - 1 > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
						xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() == p.getColor()))

					{
						if ((getGameTile(xCenter + 2, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case East:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter - 1).isOccupied() &&
				!getGameTile(xCenter + 1, yCenter).isOccupied() && !getGameTile(xCenter, yCenter + 1).isOccupied())
			{
				if ((xCenter > 0 && xCenter + 1 < 20) && (yCenter - 1 > 0 && yCenter + 1 < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
						xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() == p.getColor()))

					{
						if ((getGameTile(xCenter, yCenter + 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case South:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter - 1, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter + 1).isOccupied() && !getGameTile(xCenter + 1, yCenter).isOccupied())
			{
				if ((xCenter - 1 > 0 && xCenter + 1 < 20) && (yCenter > 0 && yCenter + 1 < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
						xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() == p.getColor()))

					{
						if ((getGameTile(xCenter + 2, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case West:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter - 1, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter - 1).isOccupied() && !getGameTile(xCenter, yCenter + 1).isOccupied())
			{
				if ((xCenter - 1 > 0 && xCenter < 20) && (yCenter - 1 > 0 && yCenter + 1 < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
						xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() == p.getColor()))

					{
						if ((getGameTile(xCenter, yCenter - 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;
		}
		break;

	case FourL:
		if (!p.getShape(6).isFlipped())
		{
			switch (p.getShape(6).getOrientation())
			{
			case North:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter - 1).isOccupied() &&
					!getGameTile(xCenter - 1, yCenter).isOccupied() && !getGameTile(xCenter - 2, yCenter).isOccupied())
				{
					if ((xCenter - 2 > 0 && xCenter < 20) && (yCenter - 1 > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter - 2 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 3, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 3, yCenter + 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 3, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case East:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter + 1, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter - 1).isOccupied() && !getGameTile(xCenter, yCenter - 2).isOccupied())
				{
					if ((xCenter > 0 && xCenter + 1 < 20) && (yCenter - 2 > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 2 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 3).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 3).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 3).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case South:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter + 1).isOccupied() &&
					!getGameTile(xCenter + 1, yCenter).isOccupied() && !getGameTile(xCenter + 2, yCenter).isOccupied())
				{
					if ((xCenter - 2 > 0 && xCenter < 20) && (yCenter - 1 > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter + 2 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 3, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case West:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter - 1, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter + 1).isOccupied() && !getGameTile(xCenter, yCenter + 2).isOccupied())
				{
					if ((xCenter - 1 > 0 && xCenter < 20) && (yCenter > 0 && yCenter + 2 < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter + 2 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 3).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 3).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 3).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;
			}
		}
		else
		{
			switch (p.getShape(6).getOrientation())
			{
			case North:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter - 1).isOccupied() &&
					!getGameTile(xCenter + 1, yCenter).isOccupied() && !getGameTile(xCenter + 2, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter + 2 < 20) && (yCenter - 1 > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter + 2 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 3, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 3, yCenter + 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 3, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case East:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter + 1, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter + 1).isOccupied() && !getGameTile(xCenter, yCenter + 2).isOccupied())
				{
					if ((xCenter > 0 && xCenter + 1 < 20) && (yCenter > 0 && yCenter + 2 < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter + 2 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 3).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 3).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 3).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case South:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter + 1).isOccupied() &&
					!getGameTile(xCenter - 1, yCenter).isOccupied() && !getGameTile(xCenter - 2, yCenter).isOccupied())
				{
					if ((xCenter - 2 > 0 && xCenter < 20) && (yCenter > 0 && yCenter + 1 < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter - 2 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 3, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 3, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 3, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case West:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter - 1, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter - 1).isOccupied() && !getGameTile(xCenter, yCenter - 2).isOccupied())
				{
					if ((xCenter - 1 > 0 && xCenter < 20) && (yCenter - 2 > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 2 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 3).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 3).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 3).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;
			}
		}
		break;

	case FourS: // //
		if (!p.getShape(8).isFlipped())
		{
			switch (p.getShape(8).getOrientation())
			{
			case North:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter + 1, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter + 1).isOccupied() && !getGameTile(xCenter - 1, yCenter + 1).isOccupied())
				{
					if ((xCenter - 1 > 0 && xCenter + 1 < 20) && (yCenter > 0 && yCenter + 1 < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case East:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter + 1).isOccupied() &&
					!getGameTile(xCenter - 1, yCenter).isOccupied() && !getGameTile(xCenter - 1, yCenter - 1).isOccupied())
				{
					if ((xCenter - 1 > 0 && xCenter < 20) && (yCenter - 1 > 0 && yCenter + 1 < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter, yCenter - 2).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case South:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter - 1, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter - 1).isOccupied() && !getGameTile(xCenter + 1, yCenter - 1).isOccupied())
				{
					if ((xCenter - 1 > 0 && xCenter + 1 < 20) && (yCenter - 1 > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case West:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter - 1).isOccupied() &&
					!getGameTile(xCenter + 1, yCenter).isOccupied() && !getGameTile(xCenter + 1, yCenter + 1).isOccupied())
				{
					if ((xCenter > 0 && xCenter + 1 < 20) && (yCenter - 1 > 0 && yCenter + 1 < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter, yCenter + 2).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;
			}
		}
		else
		{
			switch (p.getShape(8).getOrientation())
			{
			case North:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter - 1, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter + 1).isOccupied() && !getGameTile(xCenter + 1, yCenter + 1).isOccupied())
				{
					if ((xCenter - 1 > 0 && xCenter + 1 < 20) && (yCenter > 0 && yCenter + 1 < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case East:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter - 1).isOccupied() &&
					!getGameTile(xCenter - 1, yCenter).isOccupied() && !getGameTile(xCenter - 1, yCenter + 1).isOccupied())
				{
					if ((xCenter - 1 > 0 && xCenter < 20) && (yCenter - 1 > 0 && yCenter + 1 < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) || // // //
							xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter, yCenter + 2).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case South:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter + 1, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter - 1).isOccupied() && !getGameTile(xCenter - 1, yCenter - 1).isOccupied())
				{
					if ((xCenter - 1 > 0 && xCenter + 1 < 20) && (yCenter - 1 > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case West:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter + 1).isOccupied() &&
					!getGameTile(xCenter + 1, yCenter).isOccupied() && !getGameTile(xCenter + 1, yCenter - 1).isOccupied())
				{
					if ((xCenter > 0 && xCenter + 1 < 20) && (yCenter - 1 > 0 && yCenter + 1 < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) || // // //
							xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter, yCenter - 2).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;
			}
		}
		break;

	case FiveL:
		if (!p.getShape(9).isFlipped())
		{
			switch (p.getShape(9).getOrientation())
			{
			case North:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter - 1).isOccupied() &&
					!getGameTile(xCenter + 1, yCenter).isOccupied() && !getGameTile(xCenter + 2, yCenter).isOccupied() &&
					!getGameTile(xCenter + 3, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter + 3 < 20) && (yCenter - 1 > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter + 2 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter + 3 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 4, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 4, yCenter + 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 3, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 4, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 3, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case East:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter + 1, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter + 1).isOccupied() && !getGameTile(xCenter, yCenter + 2).isOccupied() &&
					!getGameTile(xCenter, yCenter + 3).isOccupied())
				{
					if ((xCenter > 0 && xCenter + 1 < 20) && (yCenter > 0 && yCenter + 3 < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter + 2 == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter + 3 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 4).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 4).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 3).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 4).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 3).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case South:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter + 1).isOccupied() &&
					!getGameTile(xCenter - 1, yCenter).isOccupied() && !getGameTile(xCenter - 2, yCenter).isOccupied() &&
					!getGameTile(xCenter - 3, yCenter).isOccupied())
				{
					if ((xCenter - 3 > 0 && xCenter < 20) && (yCenter > 0 && yCenter + 1 < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter - 2 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter - 3 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 4, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 4, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 3, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 4, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 3, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case West:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter - 1, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter - 1).isOccupied() && !getGameTile(xCenter, yCenter - 2).isOccupied() &&
					!getGameTile(xCenter, yCenter - 3).isOccupied())
				{
					if ((xCenter - 1 > 0 && xCenter < 20) && (yCenter - 3 > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 2 == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 3 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 4).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 4).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 3).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 4).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 3).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;
			}
		}
		else
		{
			switch (p.getShape(1).getOrientation())
			{
			case North:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter - 1).isOccupied() &&
					!getGameTile(xCenter - 1, yCenter).isOccupied() && !getGameTile(xCenter - 2, yCenter).isOccupied() &&
					!getGameTile(xCenter - 3, yCenter).isOccupied())
				{
					if ((xCenter - 3 > 0 && xCenter < 20) && (yCenter - 1 > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter - 2 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter - 3 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 4, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 4, yCenter + 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 3, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 4, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 3, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case East:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter + 1, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter - 1).isOccupied() && !getGameTile(xCenter, yCenter - 2).isOccupied() &&
					!getGameTile(xCenter, yCenter - 3).isOccupied())
				{
					if ((xCenter > 0 && xCenter + 1 < 20) && (yCenter - 3 > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 2 == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 3 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 4).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 4).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 3).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 4).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 3).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case South:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter + 1).isOccupied() &&
					!getGameTile(xCenter + 1, yCenter).isOccupied() && !getGameTile(xCenter + 2, yCenter).isOccupied() &&
					!getGameTile(xCenter + 3, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter + 3 < 20) && (yCenter > 0 && yCenter + 1 < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter + 2 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter + 3 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 4, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 4, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 3, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 4, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 3, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case West:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter - 1, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter + 1).isOccupied() && !getGameTile(xCenter, yCenter + 2).isOccupied() &&
					!getGameTile(xCenter, yCenter + 3).isOccupied())
				{
					if ((xCenter - 1 > 0 && xCenter < 20) && (yCenter > 0 && yCenter + 3 < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter + 2 == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter + 3 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 4).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 4).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 3).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 4).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 3).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;
			}
		}
		break;

	case FiveT:
		switch (p.getShape(10).getOrientation())
		{
		case North:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter - 1, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter - 1).isOccupied() && !getGameTile(xCenter, yCenter - 2).isOccupied() &&
				!getGameTile(xCenter + 1, yCenter).isOccupied())
			{
				if ((xCenter - 1 > 0 && xCenter + 1 < 20) && (yCenter - 2 > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter - 2 == validCornerY(p.getColor()) ||
						xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 3).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 3).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter - 2, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 3).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case East:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter - 1).isOccupied() &&
				!getGameTile(xCenter + 1, yCenter).isOccupied() && !getGameTile(xCenter + 2, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter + 1).isOccupied())
			{
				if ((xCenter > 0 && xCenter + 2 < 20) && (yCenter - 1 > 0 && yCenter + 1 < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
						xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter + 2 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 3, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 3, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter, yCenter - 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 3, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case South:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter + 1, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter + 1).isOccupied() && !getGameTile(xCenter, yCenter + 2).isOccupied() &&
				!getGameTile(xCenter - 1, yCenter).isOccupied())
			{
				if ((xCenter - 1 > 0 && xCenter + 1 < 20) && (yCenter > 0 && yCenter + 2 < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter + 2 == validCornerY(p.getColor()) ||
						xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 3).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter + 3).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 2, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 3).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case West:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter + 1).isOccupied() &&
				!getGameTile(xCenter - 1, yCenter).isOccupied() && !getGameTile(xCenter - 2, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter - 1).isOccupied())
			{
				if ((xCenter - 2 > 0 && xCenter < 20) && (yCenter - 1 > 0 && yCenter + 1 < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
						xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter - 2 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 3, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 3, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter, yCenter + 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 3, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;
		}
		break;

	case FiveEvenL:
		switch (p.getShape(11).getOrientation())
		{
		case North:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter + 2, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter - 1).isOccupied() && !getGameTile(xCenter, yCenter - 2).isOccupied() &&
				!getGameTile(xCenter + 1, yCenter).isOccupied())
			{
				if ((xCenter > 0 && xCenter + 2 < 20) && (yCenter - 2 > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter + 2 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter - 2 == validCornerY(p.getColor()) ||
						xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 3, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 3, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 3).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 3).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 3).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 3, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case East:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter + 2, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter + 1).isOccupied() && !getGameTile(xCenter, yCenter + 2).isOccupied() &&
				!getGameTile(xCenter + 1, yCenter).isOccupied())
			{
				if ((xCenter > 0 && xCenter + 2 < 20) && (yCenter > 0 && yCenter + 2 < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter + 2 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter + 2 == validCornerY(p.getColor()) ||
						xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 3, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 3, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 3).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter + 3).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 3).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 3, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case South:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter - 2, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter + 1).isOccupied() && !getGameTile(xCenter, yCenter + 2).isOccupied() &&
				!getGameTile(xCenter - 1, yCenter).isOccupied())
			{
				if ((xCenter - 2 > 0 && xCenter < 20) && (yCenter > 0 && yCenter + 2 < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter - 2 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter + 2 == validCornerY(p.getColor()) ||
						xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 3, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 3, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter + 3).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 3).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 3).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 3, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case West:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter - 2, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter - 1).isOccupied() && !getGameTile(xCenter, yCenter - 2).isOccupied() &&
				!getGameTile(xCenter - 1, yCenter).isOccupied())
			{
				if ((xCenter - 2 > 0 && xCenter < 20) && (yCenter - 2 > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter - 2 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter - 2 == validCornerY(p.getColor()) ||
						xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 3, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 3, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 3).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 3).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 3).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 3, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		}
		break;

	case FiveLongS:
		if (!p.getShape(12).isFlipped())
		{
			switch (p.getShape(12).getOrientation())
			{
			case North:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter + 1, yCenter).isOccupied() &&
					!getGameTile(xCenter + 2, yCenter).isOccupied() && !getGameTile(xCenter, yCenter + 1).isOccupied() &&
					!getGameTile(xCenter - 1, yCenter + 1).isOccupied())
				{
					if ((xCenter - 1 > 0 && xCenter + 2 < 20) && (yCenter > 0 && yCenter + 1 < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter + 2 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 3, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 3, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 3, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case East:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter + 1).isOccupied() &&
					!getGameTile(xCenter, yCenter + 2).isOccupied() && !getGameTile(xCenter - 1, yCenter).isOccupied() &&
					!getGameTile(xCenter - 1, yCenter - 1).isOccupied())
				{
					if ((xCenter - 1 > 0 && xCenter < 20) && (yCenter - 1 > 0 && yCenter + 2 < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter + 2 == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 3).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 3).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter, yCenter - 2).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 3).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case South:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter - 1, yCenter).isOccupied() &&
					!getGameTile(xCenter - 2, yCenter).isOccupied() && !getGameTile(xCenter, yCenter - 1).isOccupied() &&
					!getGameTile(xCenter + 1, yCenter - 1).isOccupied())
				{
					if ((xCenter - 2 > 0 && xCenter + 1 < 20) && (yCenter - 1 > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter - 2 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 3, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 3, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 3, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case West:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter - 1).isOccupied() &&
					!getGameTile(xCenter, yCenter - 2).isOccupied() && !getGameTile(xCenter + 1, yCenter).isOccupied() &&
					!getGameTile(xCenter + 1, yCenter + 1).isOccupied())
				{
					if ((xCenter > 0 && xCenter + 1 < 20) && (yCenter - 2 > 0 && yCenter + 1 < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 2 == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 3).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 3).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter, yCenter + 2).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 3).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;
			}
		}
		else
		{
			switch (p.getShape(12).getOrientation())
			{
			case North:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter - 1, yCenter).isOccupied() &&
					!getGameTile(xCenter - 2, yCenter).isOccupied() && !getGameTile(xCenter, yCenter + 1).isOccupied() &&
					!getGameTile(xCenter + 1, yCenter + 1).isOccupied())
				{
					if ((xCenter - 2 > 0 && xCenter + 1 < 20) && (yCenter > 0 && yCenter + 1 < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter - 2 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 3, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 3, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 3, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case East:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter - 1).isOccupied() &&
					!getGameTile(xCenter, yCenter - 2).isOccupied() && !getGameTile(xCenter - 1, yCenter).isOccupied() &&
					!getGameTile(xCenter - 1, yCenter + 1).isOccupied())
				{
					if ((xCenter - 1 > 0 && xCenter < 20) && (yCenter - 2 > 0 && yCenter + 1 < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 2 == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 3).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 3).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter, yCenter + 2).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 3).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case South:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter + 1, yCenter).isOccupied() &&
					!getGameTile(xCenter + 2, yCenter).isOccupied() && !getGameTile(xCenter, yCenter - 1).isOccupied() &&
					!getGameTile(xCenter - 1, yCenter - 1).isOccupied())
				{
					if ((xCenter - 1 > 0 && xCenter + 2 < 20) && (yCenter - 1 > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter + 2 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 3, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 3, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 3, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case West:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter + 1).isOccupied() &&
					!getGameTile(xCenter, yCenter + 2).isOccupied() && !getGameTile(xCenter + 1, yCenter).isOccupied() &&
					!getGameTile(xCenter + 1, yCenter - 1).isOccupied())
				{
					if ((xCenter > 0 && xCenter + 1 < 20) && (yCenter - 1 > 0 && yCenter + 2 < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter + 2 == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 3).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter + 3).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter, yCenter - 2).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 3).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;
			}
		}
		break;

	case FiveZ:
		if (p.getShape(13).isFlipped())
		{
			switch (p.getShape(13).getOrientation())
			{
			case North:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter + 1, yCenter).isOccupied() &&
					!getGameTile(xCenter + 1, yCenter - 1).isOccupied() && !getGameTile(xCenter - 1, yCenter).isOccupied() &&
					!getGameTile(xCenter - 1, yCenter + 1).isOccupied())
				{
					if ((xCenter - 1 > 0 && xCenter + 1 < 20) && (yCenter - 1 > 0 && yCenter + 1 < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter, yCenter + 2).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case East:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter + 1).isOccupied() &&
					!getGameTile(xCenter + 1, yCenter + 1).isOccupied() && !getGameTile(xCenter, yCenter - 1).isOccupied() &&
					!getGameTile(xCenter - 1, yCenter - 1).isOccupied())
				{
					if ((xCenter - 1 > 0 && xCenter + 1 < 20) && (yCenter - 1 > 0 && yCenter + 1 < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
							xCenter + 1 == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter - 1 == validCornerY(p.getColor()) ||
							xCenter - 1 == validCornerX(p.getColor()) && yCenter + 1 == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter - 1, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter + 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 2, yCenter).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter - 2).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 2, yCenter).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 2, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 2, yCenter - 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 2).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() != p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case South:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case West:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;
			}
		}
		else
		{
			switch (p.getShape(1).getOrientation())
			{
			case North:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case East:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case South:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case West:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;
			}
		}
		break;

	case FiveLine:
		switch (p.getShape(1).getOrientation())
		{
		case North:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter).isOccupied())
			{
				if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case East:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter).isOccupied())
			{
				if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case South:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter).isOccupied())
			{
				if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case West:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter).isOccupied())
			{
				if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;
		}
		break;

	case FiveCubeNub:
		if (p.getShape(15).isFlipped())
		{
			switch (p.getShape(1).getOrientation())
			{
			case North:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case East:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case South:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case West:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;
			}
		}
		else
		{
			switch (p.getShape(1).getOrientation())
			{
			case North:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case East:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case South:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case West:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;
			}
		}
		break;

	case FiveSnake:
		switch (p.getShape(1).getOrientation())
		{
		case North:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter).isOccupied())
			{
				if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case East:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter).isOccupied())
			{
				if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case South:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter).isOccupied())
			{
				if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case West:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter).isOccupied())
			{
				if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;
		}
		break;

	case FiveC:
		switch (p.getShape(1).getOrientation())
		{
		case North:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter).isOccupied())
			{
				if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case East:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter).isOccupied())
			{
				if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case South:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter).isOccupied())
			{
				if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;

		case West:
			if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
				!getGameTile(xCenter, yCenter).isOccupied())
			{
				if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
				{
					if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
						xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
					{
						return true;
					}

					if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
						(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
					{
						if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
							(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							return true;
						}
					}
				}
			}
			return false;
			break;
		}
		break;

	case FiveSNub:
		if (p.getShape(18).isFlipped())
		{
			switch (p.getShape(1).getOrientation())
			{
			case North:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case East:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case South:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case West:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;
			}
		}
		else
		{
			switch (p.getShape(1).getOrientation())
			{
			case North:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case East:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case South:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case West:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;
			}
		}
		break;

	case FiveCross:

		break;

	case FiveLineNub:
		if (!p.getShape(20).isFlipped())
		{
			switch (p.getShape(1).getOrientation())
			{
			case North:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case East:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case South:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case West:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;
			}
		}
		else
		{
			switch (p.getShape(1).getOrientation())
			{
			case North:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case East:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case South:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;

			case West:
				if (!getGameTile(xCenter, yCenter).isOccupied() && !getGameTile(xCenter, yCenter).isOccupied() &&
					!getGameTile(xCenter, yCenter).isOccupied())
				{
					if ((xCenter > 0 && xCenter < 20) && (yCenter > 0 && yCenter < 20))
					{
						if (xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()) ||
							xCenter == validCornerX(p.getColor()) && yCenter == validCornerY(p.getColor()))
						{
							return true;
						}

						if ((getGameTile(xCenter + 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter + 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter + 1, yCenter - 1).getPlayerColor() == p.getColor()) ||
							(getGameTile(xCenter - 1, yCenter - 1).getPlayerColor() == p.getColor()))
						{
							if ((getGameTile(xCenter + 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter - 1, yCenter).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter + 1).getPlayerColor() != p.getColor()) ||
								(getGameTile(xCenter, yCenter - 1).getPlayerColor() == p.getColor()))
							{
								return true;
							}
						}
					}
				}
				return false;
				break;
			}
		}
		break;
	}

	/*
		So, upon doing the example, I learned a few things. A: this is going to be very long, as there are 20 of those left to do.
		B: I am sorry for anyone who has to work on this. I would not have done this if I thought that anyone but me would have to work
		on this function. C: I found out that for each orientation, you can just reverse certain x and y values. for East, reverse
		y values. For south, reverse x and y values. For west, reverse x values. For each case, logically figure out North orientation,
		then reverse values accordingly for the rest of the orientations
	*/
}
int Board::redTiles()
{
	return 0;
}
int Board::blueTiles()
{
	return 0;
}
int Board::greenTiles()
{
	return 0;
}
int Board::yellowTiles()
{
	return 0;
}