#ifndef RENDERINGMANAGER_H_
#define RENDERINGMANAGER_H_

//**Must include glad and GLFW in this order or it breaks**
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Geometry.h"

class Broker; 
struct GLFWwindow;
//class RenderingEngine;
//class Scene;

class RenderingManager {
public:
	RenderingManager(Broker* broker);
	virtual ~RenderingManager();


	void init();
	void updateMilliseconds(double deltaTime);
	void cleanup();

	//Renders each object
	void RenderScene(const std::vector<Geometry>& objects);

	//Create vao and vbos for objects
	static void assignBuffers(Geometry& geometry);
	static void setBufferData(Geometry& geometry);
	static void deleteBufferData(Geometry& geometry);

	//Ensures that vao and vbos are set up properly
	bool CheckGLErrors();

	//Pointer to the current shader program being used to render
	GLuint shaderProgram;

	GLFWwindow* getWindow();

	void QueryGLVersion();

	//Scene* getScene() { return scene; }

private:

	Broker* _broker = nullptr;

	GLFWwindow* _window = nullptr;

	//RenderingEngine* renderingEngine;

	std::vector<Geometry> _objects;
	//Scene* scene;

	

	void openWindow();
};

#endif // RENDERINGMANAGER_H_
