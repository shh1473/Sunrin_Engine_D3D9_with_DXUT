#include "DXUT.h"
#include "SoundScene.h"

SoundScene::SoundScene()
{
	sound = app.sounds[L"TestSound"];
}

SoundScene::~SoundScene()
{

}

void SoundScene::Update()
{
	Object::Update();

	if (app.IsPressed('A'))
	{
		sound->sound->Play(0, DSBPLAY_LOOPING, -2000);
	}
	if (app.IsPressed('S'))
	{
		sound->sound->Stop();
	}
	if (app.IsPressed('D'))
	{
		sound->sound->Reset();
	}
}

void SoundScene::Render()
{
	Object::Render();
}