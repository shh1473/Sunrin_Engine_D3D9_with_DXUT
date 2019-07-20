#pragma once

#include "Camera.h"
#include "Timer.h"
#include "Material.h"
#include "Sound.h"
#include "Shader.h"
#include "VertexDeclaration.h"

class App
{
public:
	App();

	void Initialize();
	void Shutdown();

	void Update();
	void Render();

	bool IsPressed(unsigned char key);
	bool IsPressing(unsigned char key);
	bool IsReleased(unsigned char key);
	bool IsReleasing(unsigned char key);

	void CreateTexture(wstring path, wstring name);
	void CreateSound(wstring path, wstring name);
	void CreateShader(
		wstring path,
		wstring name,
		D3DXMACRO *macros = nullptr);
	void CreateVertexDeclaration(
		wstring name,
		unsigned flag = 0);
	void CreateMaterial(
		wstring name,
		unsigned widthCount = 1,
		unsigned heightCount = 1,
		wstring diffuseMapName = L"Default",
		wstring specularMapName = L"Default",
		wstring normalMapName = L"Default");

public:
	// �Է�
	bool nowKeys[256];
	bool oldKeys[256];
	POINT mousePos;

	// ��
	Object *nowScene;
	Object *nextScene;

	// ī�޶�
	Camera *camera;

	// �ð�
	float deltaTime;
	list<Timer*> timers;

	// �ڿ�
	map<wstring, Texture*> textures;
	map<wstring, Sound*> sounds;
	map<wstring, Shader*> shaders;
	map<wstring, VertexDeclaration*> vertexDeclarations;
	map<wstring, Material*> materials;

};

extern App app;