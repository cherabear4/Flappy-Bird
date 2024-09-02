#pragma once

class Logic
{
public:
	Logic()
	{
		gameRunning = false;
	}

	bool isGameRunning()
	{
		return gameRunning;
	}

	void setGameRunning(bool val)
	{
		gameRunning = val;
	}

	~Logic()
	{
	}

private:
	bool gameRunning;
};
