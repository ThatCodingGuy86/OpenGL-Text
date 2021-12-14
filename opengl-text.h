#pragma once
#include "glad/glad.h"
#include "texture.h"

unsigned int textVAO, textVBO;

void Text()
{
    glGenVertexArrays(1, &textVAO);
    glGenBuffers(1, &textVBO);
    glBindVertexArray(textVAO);
    glBindBuffer(GL_ARRAY_BUFFER, textVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void RenderText(Texture font, int textShader, std::string text, float x, float y, float scale, glm::vec3 color)
{

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glUseProgram(textShader);
    glUniform3f(glGetUniformLocation(textShader, "textColor"), color.x, color.y, color.z);
    glUniformMatrix4fv(glGetUniformLocation(textShader, "projection"), 1, GL_FALSE, &glm::ortho(0.0f, 800.0f, 0.0f, 600.0f)[0][0]);
    glUniform2f(glGetUniformLocation(textShader, "atlasSize"), 128, 48);
    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(textVAO);

    int cursorPositionX = 0;
    int cursorPositionY = 0;
    for (char const& c : text)
    {
        char chr = toascii(c);


        float xpos = x + (8 * (cursorPositionX * 2));
        float ypos = y + (8 * cursorPositionY);

        float w = 8 * scale;
        float h = 8 * scale;

        float u = 0;
        float v = 0;
        
        // Massive switch satement because I couldn't figure out how to make this work dynamically
        switch (chr)
        {
        case '\n':
            cursorPositionY = cursorPositionY - 1;
            cursorPositionX = -1;
            break;
        case ' ':
            u = 0 * 8; v = 0 * 8;
            break;
        case '!':
            u = 1 * 8; v = 0 * 8;
            break;
        case '"':
            u = 2 * 8; v = 0 * 8;
            break;
        case '#':
            u = 3 * 8; v = 0 * 8;
            break;
        case '$':
            u = 4 * 8; v = 0 * 8;
            break;
        case '%':
            u = 5 * 8; v = 0 * 8;
            break;
        case '&':
            u = 6 * 8; v = 0 * 8;
            break;
        case '\'':
            u = 7 * 8; v = 0 * 8;
            break;
        case '(':
            u = 8 * 8; v = 0 * 8;
            break;
        case ')':
            u = 9 * 8; v = 0 * 8;
            break;
        case '*':
            u = 10 * 8; v = 0 * 8;
            break;
        case '+':
            u = 11 * 8; v = 0 * 8;
            break;
        case ',':
            u = 12 * 8; v = 0 * 8;
            break;
        case '-':
            u = 13 * 8; v = 0 * 8;
            break;
        case '.':
            u = 14 * 8; v = 0 * 8;
            break;
        case '/':
            u = 15 * 8; v = 0 * 8;
            break;
        case '0':
            u = 0 * 8; v = 1 * 8;
            break;
        case '1':
            u = 1 * 8; v = 1 * 8;
            break;
        case '2':
            u = 2 * 8; v = 1 * 8;
            break;
        case '3':
            u = 3 * 8; v = 1 * 8;
            break;
        case '4':
            u = 4 * 8; v = 1 * 8;
            break;
        case '5':
            u = 5 * 8; v = 1 * 8;
            break;
        case '6':
            u = 6 * 8; v = 1 * 8;
            break;
        case '7':
            u = 7 * 8; v = 1 * 8;
            break;
        case '8':
            u = 8 * 8; v = 1 * 8;
            break;
        case '9':
            u = 9 * 8; v = 1 * 8;
            break;
        case ':':
            u = 10 * 8; v = 1 * 8;
            break;
        case ';':
            u = 11 * 8; v = 1 * 8;
            break;
        case '<':
            u = 12 * 8; v = 1 * 8;
            break;
        case '=':
            u = 13 * 8; v = 1 * 8;
            break;
        case '>':
            u = 14 * 8; v = 1 * 8;
            break;
        case '?':
            u = 15 * 8; v = 1 * 8;
            break;
        case (char)64:
            u = 0 * 8; v = 2 * 8;
            break;
        case 'A':
            u = 1 * 8; v = 2 * 8;
            break;
        case 'B':
            u = 2 * 8; v = 2 * 8;
            break;
        case 'C':
            u = 3 * 8; v = 2 * 8;
            break;
        case 'D':
            u = 4 * 8; v = 2 * 8;
            break;
        case 'E':
            u = 5 * 8; v = 2 * 8;
            break;
        case 'F':
            u = 6 * 8; v = 2 * 8;
            break;
        case 'G':
            u = 7 * 8; v = 2 * 8;
            break;
        case 'H':
            u = 8 * 8; v = 2 * 8;
            break;
        case 'I':
            u = 9 * 8; v = 2 * 8;
            break;
        case 'J':
            u = 10 * 8; v = 2 * 8;
            break;
        case 'K':
            u = 11 * 8; v = 2 * 8;
            break;
        case 'L':
            u = 12 * 8; v = 2 * 8;
            break;
        case 'M':
            u = 13 * 8; v = 2 * 8;
            break;
        case 'N':
            u = 14 * 8; v = 2 * 8;
            break;
        case 'O':
            u = 15 * 8; v = 2 * 8;
            break;
        case 'P':
            u = 0 * 8; v = 3 * 8;
            break;
        case 'Q':
            u = 1 * 8; v = 3 * 8;
            break;
        case 'R':
            u = 2 * 8; v = 3 * 8;
            break;
        case 'S':
            u = 3 * 8; v = 3 * 8;
            break;
        case 'T':
            u = 4 * 8; v = 3 * 8;
            break;
        case 'U':
            u = 5 * 8; v = 3 * 8;
            break;
        case 'V':
            u = 6 * 8; v = 3 * 8;
            break;
        case 'W':
            u = 7 * 8; v = 3 * 8;
            break;
        case 'X':
            u = 8 * 8; v = 3 * 8;
            break;
        case 'Y':
            u = 9 * 8; v = 3 * 8;
            break;
        case 'Z':
            u = 10 * 8; v = 3 * 8;
            break;
        case '[':
            u = 11 * 8; v = 3 * 8;
            break;
        case '\\':
            u = 12 * 8; v = 3 * 8;
            break;
        case ']':
            u = 13 * 8; v = 3 * 8;
            break;
        case '^':
            u = 14 * 8; v = 3 * 8;
            break;
        case '_':
            u = 15 * 8; v = 3 * 8;
            break;
        case '`':
            u = 0 * 8; v = 4 * 8;
            break;
        case 'a':
            u = 1 * 8; v = 4 * 8;
            break;
        case 'b':
            u = 2 * 8; v = 4 * 8;
            break;
        case 'c':
            u = 3 * 8; v = 4 * 8;
            break;
        case 'd':
            u = 4 * 8; v = 4 * 8;
            break;
        case 'e':
            u = 5 * 8; v = 4 * 8;
            break;
        case 'f':
            u = 6 * 8; v = 4 * 8;
            break;
        case 'g':
            u = 7 * 8; v = 4 * 8;
            break;
        case 'h':
            u = 8 * 8; v = 4 * 8;
            break;
        case 'i':
            u = 9 * 8; v = 4 * 8;
            break;
        case 'j':
            u = 10 * 8; v = 4 * 8;
            break;
        case 'k':
            u = 11 * 8; v = 4 * 8;
            break;
        case 'l':
            u = 12 * 8; v = 4 * 8;
            break;
        case 'm':
            u = 13 * 8; v = 4 * 8;
            break;
        case 'n':
            u = 14 * 8; v = 4 * 8;
            break;
        case 'o':
            u = 15 * 8; v = 4 * 8;
            break;
        case 'p':
            u = 0 * 8; v = 5 * 8;
            break;
        case 'q':
            u = 1 * 8; v = 5 * 8;
            break;
        case 'r':
            u = 2 * 8; v = 5 * 8;
            break;
        case 's':
            u = 3 * 8; v = 5 * 8;
            break;
        case 't':
            u = 4 * 8; v = 5 * 8;
            break;
        case 'u':
            u = 5 * 8; v = 5 * 8;
            break;
        case 'v':
            u = 6 * 8; v = 5 * 8;
            break;
        case 'w':
            u = 7 * 8; v = 5 * 8;
            break;
        case 'x':
            u = 8 * 8; v = 5 * 8;
            break;
        case 'y':
            u = 9 * 8; v = 5 * 8;
            break;
        case 'z':
            u = 10 * 8; v = 5 * 8;
            break;
        case '{':
            u = 11 * 8; v = 5 * 8;
            break;
        case '|':
            u = 12 * 8; v = 5 * 8;
            break;
        case '}':
            u = 13 * 8; v = 5 * 8;
            break;
        case '~':
            u = 14 * 8; v = 5 * 8;
            break;
        }



        float vertices[6][4] = {
            { xpos,     ypos,       0 + u, 8 + v },
            { xpos + w, ypos + h,   8 + u, 0 + v },
            { xpos + w,     ypos,   8 + u, 8 + v },

            { xpos + w, ypos + h,   8 + u, 0 + v },
            { xpos,     ypos,       0 + u, 8 + v },
            { xpos,     ypos + h,   0 + u, 0 + v }
        };

        // render glyph texture over quad
        font.use(0);

        // update content of VBO memory
        glBindBuffer(GL_ARRAY_BUFFER, textVBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        // render quad
        glDrawArrays(GL_TRIANGLES, 0, 6);
        // now advance cursors for next glyph
        cursorPositionX++;
    }
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);

    glDisable(GL_BLEND);
}

