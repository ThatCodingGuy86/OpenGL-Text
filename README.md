# OpenGL-Text

Needs the contents of both the `includes` and `lib` files to be in their respective paths. Also needs `font.png` to be in the working directory of the EXE.

Usage example: 

```C++
    #include "opengl-text.h"
    
    const char* tShaderVert = "#version 330 core\n"
    "layout(location = 0) in vec4 vertex;\n"
    "out vec2 TexCoords;\n"
    "uniform mat4 projection; \n"
    "void main()\n"
    "{\n"
    "gl_Position = projection * vec4(vertex.xy, 0.0, 1.0); \n"
    "TexCoords = vertex.zw; \n"
    "}\0";

    const char* tShaderFrag = "#version 330 core\n"
    "in vec2 TexCoords;\n"
    "out vec4 color;\n"
    "uniform vec2 atlasSize;\n"
    "uniform sampler2D text;\n"
    "uniform vec3 textColor;\n"
    "void main()\n"
    "{\n"
    "vec4 sampled = vec4(1.0, 1.0, 1.0, texture(text, vec2(TexCoords.x / atlasSize.x, (1.0 - (TexCoords.y + 1)) / atlasSize.y)).a);\n"
    "color = vec4(textColor, 1.0) * sampled;\n"
    "}\0";

    [...]
    
    // Initialize OpenGL-Text (You have to initialize OpenGL and GLFW before doing this)
    Text();
    
    // Create and initialize the text shader
    
    unsigned int vert, frag;
    
    vert = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vert, 1, &tShaderVert, NULL);
    glCompileShader(vert);
    
    frag = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(frag, 1, &tShaderFrag, NULL);
    glCompileShader(frag);
    
    int textShader = glCreateProgram();
    glAttachShader(textShader, vert);
    glAttachShader(textShader, frag);
    
    glDeleteShader(vert);
    glDeleteShader(frag);
    
    Texture textAtlas("font.png", true);
    
    [...]
    
    // Render loop
    while(true)
    {
        [...]
        
        RenderText(textAtlas, textShader, "Hello, World!", 100, 100, 2, glm::vec3(1, 1, 1));
        
        [..]
    }
```

You will need to edit the massive switch statement to use a different font than the one I've provided, I haven't figured out how to make it work with any font size.
