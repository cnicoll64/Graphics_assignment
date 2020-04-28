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

private:
	int player;//1-4
	int geometry[5][5]; //grid to determine the shape of the piece. Can be rotated and will be altered when 
	int x;
	int y;

};

Piece::Piece(int p)
{
	player = p;
	x = -1;
	y = -1;
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
	geometry = newGeo;
}

void Piece::setShape(int s1)
{
	geometry[][] = player;
}
void Piece::setShape(int s1, int s2)
{
	geometry[][] = player;
	geometry[][] = player;
}
void Piece::setShape(int s1, int s2, int s3)
{
	geometry[][] = player;
	geometry[][] = player;
	geometry[][] = player;
}
void Piece::setShape(int s1, int s2, int s3, int s4)
{
	geometry[][] = player;
	geometry[][] = player;
	geometry[][] = player;
	geometry[][] = player;
}
void Piece::setShape(int s1, int s2, int s3, int s4, int s5)
{
	geometry[][] = player;
	geometry[][] = player;
	geometry[][] = player;
	geometry[][] = player;
	geometry[][] = player;
}
