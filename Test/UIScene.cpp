#include "DXUT.h"
#include "UIScene.h"

UIScene::UIScene()
{
	// 생성
	camera = new EffectCamera(
		app.shaders[L"CameraBloom"],
		app.vertexDeclarations[L"TexCoord"],
		app.surfaces[L"SourceMap4"],
		CAMERA_COLOR_CONTRAST |
		CAMERA_FILTER |
		CAMERA_BLOOM);
	AddChild(camera);

	sptLight = new SpotLight();
	AddChild(sptLight);

	sprite = new Sprite(
		app.shaders[L"NormalMapSprite"],
		app.vertexDeclarations[L"TangentBinormal"],
		app.materials[L"Fieldstone"],
		SPRITE_ENABLE_DIFFUSE_MAP |
		SPRITE_ENABLE_SPECULAR_MAP |
		SPRITE_ENABLE_NORMAL_MAP |
		SPRITE_ENABLE_SPOT_LIGHT |
		SPRITE_ENABLE_SPECULAR);
	AddChild(sprite);

	image_01 = new Image(
		app.textures[L"Default"]);
	AddChild(image_01);

	image_02 = new Image(
		app.textures[L"Default"]);
	AddChild(image_02);

	UIText = new Text(
		app.fonts[L"DungGeunMo"],
		L"Hello World!");
	AddChild(UIText);

	// 설정
	app.materials[L"Fieldstone"]->specularIntensity = 10.0f;
	app.materials[L"Fieldstone"]->specularPower = 20.0f;

	app.camera = camera;
	camera->sourceMaps[0] = app.surfaces[L"Scene"];
	camera->sourceMaps[1] = app.surfaces[L"SourceMap1"];
	camera->sourceMaps[2] = app.surfaces[L"SourceMap2"];
	camera->sourceMaps[3] = app.surfaces[L"SourceMap3"];
	camera->thresholdIntensityViewportInv.z = 1.0f / static_cast<float>(camera->sourceMaps[0]->desc.Width);
	camera->thresholdIntensityViewportInv.w = 1.0f / static_cast<float>(camera->sourceMaps[0]->desc.Height);
	camera->colorContrast.y = 0.7f;
	camera->colorContrast.z = 0.7f;
	camera->filter = D3DXMATRIX(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
	camera->translation.z = -500.0f;

	sptLight->colorIntensity = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	sptLight->translation = D3DXVECTOR3(0.0f, 0.0f, -100.0f);
	sptLight->rotation.y = 30.0f;
	sptLight->innerAngle = 85.0f;
	sptLight->outerAngle = 70.0f;
	sptLight->radius = 1000.0f;

	sprite->spotLightCount = 1;
	sprite->spotLights[0] = sptLight;

	image_01->alpha = 200;
	image_01->colorG = 0;
	image_01->colorB = 0;

	image_02->alpha = 200;
	image_02->colorR = 0;
	image_02->colorB = 0;

	UIText->alpha = 200;
	UIText->colorR = 0;
	UIText->colorG = 0;
}

UIScene::~UIScene()
{

}

void UIScene::Update()
{
	Object::Update();

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
		camera->thresholdIntensityViewportInv.x = 0.5f;
		camera->thresholdIntensityViewportInv.y = 1.0f;
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
	if (app.IsPressing('C'))
	{
		camera->thresholdIntensityViewportInv.x -= 0.5f * app.deltaTime;
		if (camera->thresholdIntensityViewportInv.x < 0.0f) { camera->thresholdIntensityViewportInv.x = 0.0f; }
	}
	if (app.IsPressing('V'))
	{
		camera->thresholdIntensityViewportInv.x += 0.5f * app.deltaTime;
		if (camera->thresholdIntensityViewportInv.x > 0.99999f) { camera->thresholdIntensityViewportInv.x = 0.99999f; }
	}
	if (app.IsPressing('F'))
	{
		camera->thresholdIntensityViewportInv.y -= 1.0f * app.deltaTime;
		if (camera->thresholdIntensityViewportInv.y < 0.0f) { camera->thresholdIntensityViewportInv.y = 0.0f; }
	}
	if (app.IsPressing('G'))
	{
		camera->thresholdIntensityViewportInv.y += 1.0f * app.deltaTime;
	}

	if (app.IsPressing('M'))
	{
		image_01->translation.x += 100.0f * app.deltaTime;
	}
	if (app.IsPressing('B'))
	{
		image_01->translation.x -= 100.0f * app.deltaTime;
	}
	if (app.IsPressing('H'))
	{
		image_01->translation.y -= 180.0f * app.deltaTime;
	}
	if (app.IsPressing('N'))
	{
		image_01->translation.y += 180.0f * app.deltaTime;
	}
	if (app.IsPressing('L'))
	{
		image_02->translation.x += 100.0f * app.deltaTime;
	}
	if (app.IsPressing('J'))
	{
		image_02->translation.x -= 100.0f * app.deltaTime;
	}
	if (app.IsPressing('I'))
	{
		image_02->translation.y -= 180.0f * app.deltaTime;
	}
	if (app.IsPressing('K'))
	{
		image_02->translation.y += 180.0f * app.deltaTime;
	}
}

void UIScene::Render()
{
	camera->Ready();

	Object::Render();

	camera->Effect();
}