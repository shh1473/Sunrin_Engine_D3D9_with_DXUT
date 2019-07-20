#include "DXUT.h"
#include "DiffuseMapSpriteScene.h"

DiffuseMapSpriteScene::DiffuseMapSpriteScene()
{
	// 생성
	camera = new Camera(800.0f, 600.0f);
	AddChild(camera);

	sprite01 = new Sprite(
		app.shaders[L"DiffuseMapSprite"],
		app.vertexDeclarations[L"TexCoord"],
		app.materials[L"Fieldstone3x3"],
		SPRITE_ENABLE_DIFFUSE_MAP);
	AddChild(sprite01);

	sprite02 = new Sprite(
		app.shaders[L"DiffuseMapSprite"],
		app.vertexDeclarations[L"TexCoord"],
		app.materials[L"Fieldstone3x3"],
		SPRITE_ENABLE_DIFFUSE_MAP);
	AddChild(sprite02);

	// 설정
	app.camera = camera;
	camera->translation.z = -100.0f;

	sprite01->translation = D3DXVECTOR3(100.0f, 100.0f, 0.0f);
	sprite01->color = D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f);
	sprite02->translation = D3DXVECTOR3(-100.0f, -100.0f, 0.0f);
	sprite02->color = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
}

DiffuseMapSpriteScene::~DiffuseMapSpriteScene()
{

}

void DiffuseMapSpriteScene::Update()
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

	if (app.IsPressed('Z'))
	{
		sprite01->ChangeFrameIndex(0, 0);
	}
	if (app.IsPressed('X'))
	{
		sprite01->ChangeFrameIndex(1, 1);
	}
	if (app.IsPressed('C'))
	{
		sprite01->ChangeFrameIndex(2, 2);
	}
}

void DiffuseMapSpriteScene::Render()
{
	Object::Render();
}