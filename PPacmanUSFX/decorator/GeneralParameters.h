#pragma once
class GeneralParameters
{
public:
	static GeneralParameters* Instance()
	{
		if (instance == 0)
		{
			instance = new GeneralParameters();
		}

		return instance;
	}
//********Get the boundaries of the game********
	int Getxaxmax()
	{
		return gamewidth;
	}

	int Getyaxmax()
	{
		return gameheight;
	}

	int Getxaxmin()
	{
		return 0;
	}

	int Getyaxmin()
	{
		return 0;
	}
//***********Done getting boundaries**********
private:
	GeneralParameters() {};
	int gamewidth = 1000;
	int gameheight = 990;

	// singleton instance
	static GeneralParameters* instance;
};

typedef GeneralParameters  GP;
//GeneralParameters* instance = 0;



