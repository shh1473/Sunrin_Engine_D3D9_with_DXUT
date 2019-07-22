#include "DXUT.h"
#include "FilterScene.h"

FilterScene::FilterScene()
{
	// 생성
	camera = new EffectCamera(
		app.shaders[L"CameraFilter"],
		app.vertexDeclarations[L"TexCoord"],
		app.surfaces[L"SourceMap1"],
		CAMERA_COLOR_CONTRAST |
		CAMERA_FILTER);
	AddChild(camera);

	sptLight = new SpotLight();
	AddChild(sptLight);

	sprite = new Sprite(
		app.shaders[L"NormalMapSprite"],
		app.vertexDeclarations[L"TangentBinormal"],
		app.materials[L"Tint"],
		SPRITE_ENABLE_DIFFUSE_MAP |
		SPRITE_ENABLE_SPECULAR_MAP |
		SPRITE_ENABLE_NORMAL_MAP |
		SPRITE_ENABLE_SPOT_LIGHT |
		SPRITE_ENABLE_SPECULAR);
	AddChild(sprite);

	// 설정
	app.materials[L"Fieldstone"]->specularIntensity = 10.0f;
	app.materials[L"Fieldstone"]->specularPower = 20.0f;

	app.camera = camera;
	camera->sourceMaps[0] = app.surfaces[L"Scene"];
	camera->colorContrast.x = 0.5f;
	camera->colorContrast.z = 0.5f;
	camera->filter = D3DXMATRIX(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
	camera->translation.z = -500.0f;

	sptLight->colorIntensity = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 2.0f);
	sptLight->translation = D3DXVECTOR3(0.0f, 0.0f, -100.0f);
	sptLight->rotation.y = 30.0f;
	sptLight->innerAngle = 85.0f;
	sptLight->outerAngle = 70.0f;
	sptLight->radius = 1000.0f;

	sprite->spotLightCount = 1;
	sprite->spotLights[0] = sptLight;
}

FilterScene::~FilterScene()
{

}

void FilterScene::Update()
{
	Object::Update();

	if (app.IsPressing('D'))
	{
		sptLight->translation.x += 100.0f * app.deltaTime;
	}
	if (app.IsPressing('A'))
	{
		sptLight->translation.x -= 100.0f * app.deltaTime;
	}
	if (app.IsPressing('W'))
	{
		sptLight->translation.y += 180.0f * app.deltaTime;
	}
	if (app.IsPressing('S'))
	{
		sptLight->translation.y -= 180.0f * app.deltaTime;
	}
	if (app.IsPressing('E'))
	{
		sptLight->rotation.y += 90.0f * app.deltaTime;
	}
	if (app.IsPressing('Q'))
	{
		sptLight->rotation.y -= 90.0f * app.deltaTime;
	}

	if (app.IsPressed('1'))
	{
		camera->filter = D3DXMATRIX(
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);
	}
	if (app.IsPressed('2'))
	{
		camera->filter = D3DXMATRIX(
			0.299f, 0.587f, 0.184f, 0.0f,
			0.299f, 0.587f, 0.184f, 0.0f,
			0.299f, 0.587f, 0.184f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);
	}
	if (app.IsPressed('3'))
	{
		camera->filter = D3DXMATRIX(
			0.393f, 0.769f, 0.189f, 0.0f,
			0.349f, 0.686f, 0.168f, 0.0f,
			0.272f, 0.534f, 0.131f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);
	}
	if (app.IsPressed('4'))
	{
		camera->filter = D3DXMATRIX(
			-1.0f, 0.0f, 0.0f, 1.0f,
			0.0f, -1.0f, 0.0f, 1.0f,
			0.0f, 0.0f, -1.0f, 1.0f,
			0.0f, 0.0f, .0f, 1.0f);
	}
	if (app.IsPressing('R'))
	{
		camera->colorContrast.w = 0.0f;
	}
	if (app.IsPressing('Z'))
	{
		camera->colorContrast.w -= 0.5f * app.deltaTime;
		if (camera->colorContrast.w < -0.5f) { camera->colorContrast.w = -0.5f; }
	}
	if (app.IsPressing('X'))
	{
		camera->colorContrast.w += 0.5f * app.deltaTime;
		if (camera->colorContrast.w > 0.5f) { camera->colorContrast.w = 0.5f; }
	}
}

void FilterScene::Render()
{
	camera->Ready();

	Object::Render();

	camera->Effect();
}