#pragma once
#include "TextureManager.h"


class AudioManager
{

private:

	static AudioManager* sInstance;

	TextureManager* mAssetMgr;


public:

	static AudioManager* Instance();
	static void Release();


	void PlayMusic(string filename, int loops = -1);
	void PauseMusic();
	void ResumeMusic();


	void PlaySFX(std::string filename, int loops = 0, int channel = 0);



private:

	AudioManager();
	~AudioManager();

	 
};

