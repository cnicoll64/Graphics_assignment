#include "board.h"

bool Board::fillTile(int x, int y, Player p)
{
	game[x][y].setOccupied;
	game[x][y].setPlayerColor(p.getColor);
	return true;
}

bool placePiece(int xCenter, int yCenter, Player p, shape s) // pieces are placed first at their center. if there is no clear center, it will
{															 // be top left of center
	if (p.hasPiece)
	{
		switch (s)
		{
		case One:
			fillTile(xCenter, yCenter, p);
			p.discardPiece(One);
			break;
			
		case Two:
			fillTile(xCenter, yCenter, p);
			switch (p.pieces[1].getOrientation())
			{
			case North:
				fillTile(xCenter + 1, yCenter, p);
				break;

			case East:
				fillTile(xCenter, yCenter + 1, p);
				break;

			case South:
				fillTile(xCenter - 1, yCenter, p);
				break;

			case West:
				fillTile(xCenter, yCenter - 1, p);
				break;
			}
			p.discardPiece(Two);
			break;
			
		case ThreeL:
			fillTile(xCenter, yCenter, p);
				switch (p.pieces[2].getOrientation())
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
				switch (p.pieces[3].getOrientation())
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
				switch (p.pieces[4].getOrientation())
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
				switch (p.pieces[5].getOrientation())
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
				switch (p.pieces[6].getOrientation())
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
			if (!p.getShape(7).isFlipped())
			{
				switch (p.pieces[7].getOrientation())
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
			else
			{
				switch (p.pieces[8].getOrientation())
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
				switch (p.pieces[8].getOrientation())
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
				switch (p.pieces[8].getOrientation())
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
				switch (p.pieces[9].getOrientation())
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
				switch (p.pieces[9].getOrientation())
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
				switch (p.pieces[10].getOrientation())
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
				switch (p.pieces[11].getOrientation())
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
				switch (p.pieces[12].getOrientation())
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
				switch (p.pieces[12].getOrientation())
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
				switch (p.pieces[13].getOrientation())
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
				switch (p.pieces[13].getOrientation())
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
				switch (p.pieces[14].getOrientation())
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
				switch (p.pieces[15].getOrientation())
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
				switch (p.pieces[15].getOrientation())
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
				switch (p.pieces[16].getOrientation())
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
				switch (p.pieces[17].getOrientation())
				{
				case North:
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
				switch (p.pieces[18].getOrientation())
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
				switch (p.pieces[18].getOrientation())
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
				switch (p.pieces[20].getOrientation())
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
				switch (p.pieces[20].getOrientation())
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
	return false;
}

bool validate(Player p, shape s);
{
	return false;
}
int redTiles();
{
	return 0;
}
int blueTiles();
{
	return 0;
}
int greenTiles();
{
	return 0;
}
int yellowTiles();
{
	return 0;
}