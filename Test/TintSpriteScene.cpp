#include "DXUT.h"
#include "TintSpriteScene.h"

TintSpriteScene::TintSpriteScene()
{
	// 생성
	camera = new Camera(800.0f, 600.0f);
	AddChild(camera);

	sprite01 = new Sprite(
		app.shaders[L"TintSprite"],
		app.vertexDeclarations[L"Position"],
		app.materials[L"Tint"],
		SPRITE_ENABLE_TINT);
	AddChild(sprite01);

	sprite02 = new Sprite(
		app.shaders[L"TintSprite"],
		app.vertexDeclarations[L"Position"],
		app.materials[L"Tint"],
		SPRITE_ENABLE_TINT);
	AddChild(sprite02);

	// 설정
	app.camera = camera;
	camera->translation.z = -100.0f;

	sprite01->translation = D3DXVECTOR3(100.0f, 100.0f, 0.0f);
	sprite01->color = D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f);
	sprite02->translation = D3DXVECTOR3(-100.0f, -100.0f, 0.0f);
	sprite02->color = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
}

TintSpriteScene::~TintSpriteScene()
{

}

void TintSpriteScene::Update()
{
	Object::Update();

	if (app.IsPressing('D'))
	{
		camera->translation.x += 100.0f * app.deltaTime;
	}
	if (app.IsPressing('A'))
	{
		camera->translation.x -= 100.0f * app.deltaTime;
	}
	if (app.IsPressing('W'))
	{
		camera->translation.y += 100.0f * app.deltaTime;
	}
	if (app.IsPressing('S'))
	{
		camera->translation.y -= 100.0f * app.deltaTime;
	}

	if (app.IsPressing('E'))
	{
		app.materials[L"Tint"]->tint.x += 0.3f * app.deltaTime;
		app.materials[L"Tint"]->tint.y += 0.3f * app.deltaTime;
		app.materials[L"Tint"]->tint.z += 0.3f * app.deltaTime;
	}
	if (app.IsPressing('Q'))
	{
		app.materials[L"Tint"]->tint.x -= 0.3f * app.deltaTime;
		app.materials[L"Tint"]->tint.y -= 0.3f * app.deltaTime;
		app.materials[L"Tint"]->tint.z -= 0.3f * app.deltaTime;
	}
}

void TintSpriteScene::Render()
{
	Object::Render();
}