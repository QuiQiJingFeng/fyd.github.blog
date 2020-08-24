#ifndef __MESH_H__
#define __MESH_H__

#include "Shader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct Vertex {
    glm::vec3 Position;  //位置
    glm::vec3 Normal;    //法向量
    glm::vec2 TexCoords; //贴图坐标
};

struct Texture {
    unsigned int id;     //纹理ID
    string type;         //纹理类型 比如是漫反射贴图或者是镜面光贴图
};

class Mesh
{
public:
	//定点数据
	vector<Vertex> vertices;
	//索引数组
	vector<unsigned int> indices;
	//贴图数组
	vector<Texture> textures;

	Mesh(vector<Vertex> vertices,vector<unsigned int> indices, vector<Texture> textures);
	void Draw(Shader shader);
private:
	//渲染数据
	unsigned int VAO,VBO,EBO;
	void setupMesh();
};




#endif