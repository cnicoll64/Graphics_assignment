#include "board.h"
#include "std.h"

struct options
{
	int x;
	int y;
	shape s;
	direction orientation;
	bool flip;
	options* next;
};

bool AITurnRand(Player AI, Board b)
{
	options** head = nullptr;
	int elements = 0, randNum = 0;
	for (int shapeIndex = 0; shapeIndex < 21; ++shapeIndex)
	{
		for (int flip = 0; flip < 2; ++flip)
		{
			for (int rotate = 0; rotate < 4; ++rotate)
			{
				for (int index_Y = 0; index_Y < 20; ++index_Y)
				{
					for (int index_X = 0; index_X < 20; ++index_X)
					{
						if (AI.getShape(shapeIndex).getStatus())
						{
							if (b.validate(index_X, index_Y, AI, (shape)shapeIndex))
							{
								options* newOption = new options;
								newOption->next = NULL;
								newOption->x = index_X;
								newOption->y = index_Y;
								newOption->s = (shape)shapeIndex;
								newOption->orientation = AI.getShape(shapeIndex).getOrientation();
								newOption->flip = AI.getShape(shapeIndex).isFlipped();
								if (*head == nullptr)
								{
									**head = *newOption;
								}
								else
								{
									options* traverse = *head;
									for (int index = 0; index < elements; ++index)
									{
										traverse = traverse->next;
									}
									traverse->next = newOption;
								}
								++elements;
							}
						}
					}
				}
				AI.getShape(shapeIndex).rotate(true);
			}
		}
		AI.getShape(shapeIndex).flip();
	}
	randNum = rand() % elements;
	options* traverse = *head;
	for (int index = 0; index < randNum; ++index)
	{
		traverse = traverse->next;
	}
	while (AI.getShape(traverse->s).getOrientation() != traverse->orientation)
	{
		AI.getShape(traverse->s).rotate(true);
	}
	if (AI.getShape(traverse->s).isFlipped() != traverse->flip)
	{
		AI.getShape(traverse->s).flip();
	}
	b.placePiece(traverse->x, traverse->y, AI, traverse->s);
	return true;
}