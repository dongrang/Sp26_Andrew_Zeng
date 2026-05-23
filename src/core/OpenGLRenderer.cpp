#include "Cervantes/core//window.hpp"
#include "OpenGLRenderer.hpp"
#include <glad/gl.h>

namespace Cervantes {

OpenGLRenderer::OpenGLRenderer()
{
    // handles the mixing of color based on opacity of different overlapping images
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    glGenVertexArrays(1,&VAO_);
    glGenBuffers(1,&VBO_);    
    glGenBuffers(1,&EBO_);    

    unsigned int indices[] = {
    0,1,3, // first triangle
    1,2,3 // second triangle
    };

    glBindVertexArray(VAO_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);
    glBindVertexArray(0);
}

void OpenGLRenderer::draw(Picture& pic, int xCoord,int yCoord, Shader& shader)
{
    float x = static_cast<float>(xCoord);
    float y = static_cast<float>(yCoord);
    float w = static_cast<float>(pic.getDimensions().width);
    float h = static_cast<float>(pic.getDimensions().height);
    float data[] = {
        x,   y,   0.0f, 0.0f, //lower left
        x,   y+h, 0.0f, 1.0f, //upper left
        x+w, y+h, 1.0f, 1.0f, //upper right
        x+w, y,   1.0f, 0.0f// lower right
    };

    glBindVertexArray(VAO_);
    glBindBuffer(GL_ARRAY_BUFFER,VBO_);
    glBufferData(GL_ARRAY_BUFFER,sizeof(data),data,GL_DYNAMIC_DRAW);

    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,4*sizeof(float),0);
    glEnableVertexAttribArray(0);

    // handles vertex coordinates in data array
    glVertexAttribPointer(1 ,2,GL_FLOAT,GL_FALSE,4*sizeof(float),(void*)(2*sizeof(float)));
    glEnableVertexAttribArray(1);

    shader.Bind();

    int window_width = static_cast<int>(Window::get()->getSize().width);
    int window_height = static_cast<int>(Window::get()->getSize().height);
    shader.supplyIntUniform("screenRes", {window_width,window_height});
    pic.Bind();
    
    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
    glBindVertexArray(0);
}

void OpenGLRenderer::screenClear()
{
    glClearColor(0.25f,0.5f,0.75f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

} // end namespace Cervantes