#include "DXUT.h"
#include "App.h"
#include "Test/UIScene.h"

App::App() :
	mousePos({ 0, 0 }),
	nowScene(nullptr),
	nextScene(nullptr),
	camera(nullptr),
	deltaTime(0.0f)
{
	ZeroMemory(nowKeys, sizeof(bool) * 256);
	ZeroMemory(oldKeys, sizeof(bool) * 256);
}

void App::Initialize()
{
	DXUTGetD3D9Device()->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_NONE);
	DXUTGetD3D9Device()->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_NONE);
	DXUTGetD3D9Device()->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_NONE);

	Sound::manager.Initialize(DXUTGetHWND(), DSSCL_PRIORITY);

	D3DXCreateSprite(DXUTGetD3D9Device(), &sprite);

	// �ڿ� �ε�
	// �ؽ���
	CreateTexture(L"Resource\\Texture\\DefaultTex.png", L"Default");
	CreateTexture(L"Resource\\Texture\\Fieldstone_DM.png", L"FieldstoneDM");
	CreateTexture(L"Resource\\Texture\\Fieldstone_SM.png", L"FieldstoneSM");
	CreateTexture(L"Resource\\Texture\\Fieldstone_NM.png", L"FieldstoneNM");

	// ����
	CreateSound(L"Resource\\Sound\\TestSound.wav", L"TestSound");

	// ���̴� ��ũ��
	D3DXMACRO macros01[2] = {
		{ "ENABLE_TINT", "1" },
		{ nullptr, nullptr } };
	D3DXMACRO macros02[2] = {
		{ "ENABLE_DIFFUSE_MAP", "1" },
		{ nullptr, nullptr } };
	D3DXMACRO macros03[3] = {
		{ "ENABLE_DIFFUSE_MAP", "1" },
		{ "ENABLE_AMBIENT_LIGHT", "1" },
		{ nullptr, nullptr } };
	D3DXMACRO macros04[5] = {
		{ "ENABLE_DIFFUSE_MAP", "1" },
		{ "ENABLE_DIRECTIONAL_LIGHT", "1" },
		{ "DIRECTIONAL_LIGHT_COUNT", "2" },
		{ "ENABLE_SPECULAR", "1" },
		{ nullptr, nullptr } };
	D3DXMACRO macros05[5] = {
		{ "ENABLE_DIFFUSE_MAP", "1" },
		{ "ENABLE_POINT_LIGHT", "1" },
		{ "POINT_LIGHT_COUNT", "2" },
		{ "ENABLE_SPECULAR", "1" },
		{ nullptr, nullptr } };
	D3DXMACRO macros06[5] = {
		{ "ENABLE_DIFFUSE_MAP", "1" },
		{ "ENABLE_SPOT_LIGHT", "1" },
		{ "SPOT_LIGHT_COUNT", "2" },
		{ "ENABLE_SPECULAR", "1" },
		{ nullptr, nullptr } };
	D3DXMACRO macros07[6] = {
		{ "ENABLE_DIFFUSE_MAP", "1" },
		{ "ENABLE_SPECULAR_MAP", "1" },
		{ "ENABLE_SPOT_LIGHT", "1" },
		{ "SPOT_LIGHT_COUNT", "1" },
		{ "ENABLE_SPECULAR", "1" },
		{ nullptr, nullptr } };
	D3DXMACRO macros08[7] = {
		{ "ENABLE_DIFFUSE_MAP", "1" },
		{ "ENABLE_SPECULAR_MAP", "1" },
		{ "ENABLE_NORMAL_MAP", "1" },
		{ "ENABLE_SPOT_LIGHT", "1" },
		{ "SPOT_LIGHT_COUNT", "1" },
		{ "ENABLE_SPECULAR", "1" },
		{ nullptr, nullptr } };
	D3DXMACRO macros09[3] = {
		{ "COLOR_CONTRAST", "1" },
		{ "FILTER_CUSTOM", "1" },
		{ nullptr, nullptr } };
	D3DXMACRO macros10[2] = {
		{ "ENABLE_BLUR", "1" },
		{ nullptr, nullptr } };
	D3DXMACRO macros11[5] = {
		{ "COLOR_CONTRAST", "1" },
		{ "FILTER_CUSTOM", "1" },
		{ "ENABLE_BLOOM", "1" },
		{ nullptr, nullptr } };

	// ���̴�
	CreateShader(L"Resource\\Shader\\SpriteShader.fx", L"TintSprite", macros01);
	CreateShader(L"Resource\\Shader\\SpriteShader.fx", L"DiffuseMapSprite", macros02);
	CreateShader(L"Resource\\Shader\\SpriteShader.fx", L"AmbientLightSprite", macros03);
	CreateShader(L"Resource\\Shader\\SpriteShader.fx", L"DirectionalLightSprite", macros04);
	CreateShader(L"Resource\\Shader\\SpriteShader.fx", L"PointLightSprite", macros05);
	CreateShader(L"Resource\\Shader\\SpriteShader.fx", L"SpotLightSprite", macros06);
	CreateShader(L"Resource\\Shader\\SpriteShader.fx", L"SpecularMapSprite", macros07);
	CreateShader(L"Resource\\Shader\\SpriteShader.fx", L"NormalMapSprite", macros08);

	CreateShader(L"Resource\\Shader\\CameraShader.fx", L"CameraFilter", macros09);
	CreateShader(L"Resource\\Shader\\CameraShader.fx", L"CameraBlur", macros10);
	CreateShader(L"Resource\\Shader\\CameraShader.fx", L"CameraBloom", macros11);

	// ���� ����
	CreateVertexDeclaration(L"Position");
	CreateVertexDeclaration(L"TexCoord", VERTEX_DECL_TEXCOORD);
	CreateVertexDeclaration(L"Normal", VERTEX_DECL_TEXCOORD | VERTEX_DECL_NORMAL);
	CreateVertexDeclaration(L"TangentBinormal", VERTEX_DECL_TEXCOORD | VERTEX_DECL_NORMAL | VERTEX_DECL_TANGENT_AND_BINORMAL);

	// ����
	CreateMaterial(L"Default", 1, 1);
	CreateMaterial(L"Fieldstone", 1, 1, L"FieldstoneDM", L"FieldstoneSM", L"FieldstoneNM");
	CreateMaterial(L"Fieldstone3x3", 3, 3, L"FieldstoneDM", L"FieldstoneSM", L"FieldstoneNM");

	// ���� Ÿ��
	surfaces[L"BackBuffer"] = new Surface();
	DXUTGetD3D9Device()->GetRenderTarget(0, &surfaces[L"BackBuffer"]->surface);
	surfaces[L"BackBuffer"]->surface->GetDesc(&surfaces[L"BackBuffer"]->desc);

	CreateSurface(L"Scene");
	CreateSurface(L"SourceMap1");
	CreateSurface(L"SourceMap2");
	CreateSurface(L"SourceMap3");
	CreateSurface(L"SourceMap4");

	// ��Ʈ
	CreateFont_(L"DungGeunMo", L"�ü�", 30, FW_NORMAL, FALSE);

	// ù ��
	nextScene = new UIScene();
}

void App::Shutdown()
{
	SAFE_DELETE(nowScene);
	SAFE_DELETE(nextScene);

	for (auto iter : textures)
	{
		SAFE_DELETE(iter.second);
	}

	for (auto iter : sounds)
	{
		SAFE_DELETE(iter.second);
	}

	for (auto iter : shaders)
	{
		SAFE_DELETE(iter.second);
	}

	for (auto iter : vertexDeclarations)
	{
		SAFE_DELETE(iter.second);
	}

	for (auto iter : materials)
	{
		SAFE_DELETE(iter.second);
	}

	for (auto iter : surfaces)
	{
		SAFE_DELETE(iter.second);
	}

	for (auto iter : fonts)
	{
		SAFE_DELETE(iter.second);
	}

	SAFE_RELEASE(sprite);
}

void App::Update()
{
	// �Է�
	for (unsigned i = 0; i < 256; ++i)
	{
		oldKeys[i] = nowKeys[i];
		nowKeys[i] = GetAsyncKeyState(i) & 0x8000;
	}

	GetCursorPos(&mousePos);
	ScreenToClient(DXUTGetHWND(), &mousePos);

	// ��
	if (nextScene)
	{
		if (nowScene)
		{
			SAFE_DELETE(nowScene);
		}

		nowScene = nextScene;
		nextScene = nullptr;
	}

	nowScene->Update();

	// �ð�
	for (auto iter : timers)
	{
		if (iter->isActivate)
		{
			iter->Update();
		}
	}
}

void App::Render()
{
	nowScene->Render();
}

bool App::IsPressed(unsigned char key)
{
	return nowKeys[key] && !oldKeys[key];
}

bool App::IsPressing(unsigned char key)
{
	return nowKeys[key] && oldKeys[key];
}

bool App::IsReleased(unsigned char key)
{
	return !nowKeys[key] && oldKeys[key];
}

bool App::IsReleasing(unsigned char key)
{
	return !nowKeys[key] && !oldKeys[key];
}

void App::CreateTexture(wstring path, wstring name)
{
	textures[name] = new Texture();

	D3DXCreateTextureFromFileExW(
		DXUTGetD3D9Device(),
		path.c_str(),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		1,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		0,
		&textures[name]->info,
		nullptr,
		&textures[name]->texture);
}

void App::CreateSound(wstring path, wstring name)
{
	sounds[name] = new Sound();

	Sound::manager.Create(&sounds[name]->sound, const_cast<LPWSTR>(path.c_str()), DSBCAPS_CTRLVOLUME);
}

void App::CreateShader(wstring path, wstring name, D3DXMACRO *macros)
{
	shaders[name] = new Shader();

	ID3DXBuffer *errorBuffer = nullptr;
	unsigned flag{ 0 };

#if defined(DEBUG) || defined(_DEBUG)
	flag |= D3DXSHADER_DEBUG;
	flag |= D3DXSHADER_SKIPOPTIMIZATION;
#endif

	D3DXCreateEffectFromFileW(
		DXUTGetD3D9Device(),
		path.c_str(),
		macros,
		nullptr,
		D3DXFX_LARGEADDRESSAWARE,
		nullptr,
		&shaders[name]->shader,
		&errorBuffer);

	if (errorBuffer)
	{
		char *buffer = reinterpret_cast<char*>(errorBuffer->GetBufferPointer());

		MessageBoxA(DXUTGetHWND(), buffer, "Shader Error", MB_OK);

		SAFE_RELEASE(errorBuffer);
	}
}

void App::CreateVertexDeclaration(wstring name, unsigned flag)
{
	vertexDeclarations[name] = new VertexDeclaration();

	static const D3DVERTEXELEMENT9 vertexElements[5] = {
		{ 0, 0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 },
		{ 0, 0, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0 },
		{ 0, 0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_NORMAL, 0 },
		{ 0, 0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TANGENT, 0 },
		{ 0, 0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_BINORMAL, 0 } };

	unsigned count = 1;

	count = (flag & VERTEX_DECL_TEXCOORD) ? count + 1 : count;
	count = (flag & VERTEX_DECL_NORMAL) ? count + 1 : count;
	count = (flag & VERTEX_DECL_TANGENT_AND_BINORMAL) ? count + 2 : count;

	D3DVERTEXELEMENT9 *tmpElements = new D3DVERTEXELEMENT9[count + 1];

	unsigned index = 0;
	unsigned offset = 0;

	tmpElements[index] = vertexElements[0];
	tmpElements[index++].Offset = offset;
	offset += sizeof(float) * 3;

	if (flag & VERTEX_DECL_TEXCOORD)
	{
		tmpElements[index] = vertexElements[1];
		tmpElements[index++].Offset = offset;
		offset += sizeof(float) * 2;
	}

	if (flag & VERTEX_DECL_NORMAL)
	{
		tmpElements[index] = vertexElements[2];
		tmpElements[index++].Offset = offset;
		offset += sizeof(float) * 3;
	}

	if (flag & VERTEX_DECL_TANGENT_AND_BINORMAL)
	{
		tmpElements[index] = vertexElements[3];
		tmpElements[index++].Offset = offset;
		offset += sizeof(float) * 3;

		tmpElements[index] = vertexElements[4];
		tmpElements[index++].Offset = offset;
		offset += sizeof(float) * 3;
	}

	tmpElements[index] = D3DDECL_END();

	DXUTGetD3D9Device()->CreateVertexDeclaration(tmpElements, &vertexDeclarations[name]->vertexDeclaration);

	SAFE_DELETE_ARRAY(tmpElements);
}

void App::CreateMaterial(wstring name, unsigned widthCount, unsigned heightCount, wstring diffuseMapName, wstring specularMapName, wstring normalMapName)
{
	materials[name] = new Material(widthCount, heightCount, diffuseMapName, specularMapName, normalMapName);
}

void App::CreateSurface(wstring name, unsigned width, unsigned height)
{
	if (width == 0 || height == 0)
	{
		RECT rt = DXUTGetWindowClientRect();

		width = (width == 0) ? rt.right : width;
		height = (height == 0) ? rt.bottom : height;
	}

	surfaces[name] = new Surface();

	DXUTGetD3D9Device()->CreateTexture(
		width,
		height,
		1,
		D3DUSAGE_RENDERTARGET,
		D3DFMT_A8R8G8B8,
		D3DPOOL_DEFAULT,
		&surfaces[name]->texture,
		NULL);

	surfaces[name]->texture->GetSurfaceLevel(0, &surfaces[name]->surface);
	surfaces[name]->surface->GetDesc(&surfaces[name]->desc);
}

void App::CreateFont_(wstring name, wstring fontName, int height, unsigned fontWeight, BOOL isItalic)
{
	fonts[name] = new Font();

	D3DXCreateFont(
		DXUTGetD3D9Device(),
		height,
		0,
		fontWeight,
		1,
		isItalic,
		DEFAULT_CHARSET,
		OUT_TT_PRECIS,
		CLEARTYPE_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE,
		fontName.c_str(),
		&fonts[name]->font);
}

App app;