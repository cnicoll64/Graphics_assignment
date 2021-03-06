#pragma once

class Piece
{
public:
	Piece(int p);
	~Piece();

	void rotate();
	void setPlayer(int p);
	int getPlayer();
	void setShape(int s1);
	void setShape(int s1, int s2);
	void setShape(int s1, int s2, int s3);
	void setShape(int s1, int s2, int s3, int s4);
	void setShape(int s1, int s2, int s3, int s4, int s5);
	void setPlayed(bool state);
	bool getPlayed();
	bool getSelected();
	void setSelected(bool sel);

private:
	int player;//1-4
	int geometry[5][5]; //grid to determine the shape of the piece. Can be rotated and will be altered when 
	int x;
	int y;
	bool played;
	bool selected;

};

Piece::Piece(int p)
{
	player = p;
	x = -1;
	y = -1;
	played = false;
	selected = false;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			geometry[i][j] = 0;
		}
	}

}

Piece::~Piece()
{
}

void Piece::rotate()
{
	int newGeo[5][5];
	int temp;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			newGeo[i][j] = geometry[5 - 1 - j][i];
		}
	}

	for (int k = 0; k < 5; k++)
	{
		for (int l = 0; l < 5; l++)
		{
			geometry[k][l] = newGeo[k][l];
		}
	}

}

void Piece::setShape(int s1)
{
	//geometry[s1][] = player;   <- fix me
}
void Piece::setShape(int s1, int s2)
{
	//geometry[][] = player;
	//geometry[][] = player;
}
void Piece::setShape(int s1, int s2, int s3)
{
	//geometry[][] = player;
	//geometry[][] = player;
	//geometry[][] = player;
}
void Piece::setShape(int s1, int s2, int s3, int s4)
{
	//geometry[][] = player;
	//geometry[][] = player;
	//geometry[][] = player;
	//geometry[][] = player;
}
void Piece::setShape(int s1, int s2, int s3, int s4, int s5)
{
	//geometry[][] = player;
	//geometry[][] = player;
	//geometry[][] = player;
	//geometry[][] = player;
	//geometry[][] = player;
}

void Piece::setPlayed(bool state)
{
	played = state;
}
bool Piece::getPlayed()
{
	return played;
}
bool Piece::getSelected()
{
	return selected;
}

void Piece::setSelected(bool sel)
{
	selected = sel;
}
