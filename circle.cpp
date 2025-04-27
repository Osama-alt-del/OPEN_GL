#include <GL/glut.h>
#include <math.h>
// It looks like we need to initialise OPEN GL:
void init()
{
    glClearColor(1.0, 1.0, 1.0, .1);          // set the color to white.   (?) (background color?)
    glMatrixMode(GL_PROJECTION);        // set the matrix mode to projection (?) (this projects into clip space apparently)
    glLoadIdentity();                   // load the identity matrix (?)
    gluOrtho2D(-1.0, -1.0, -1.0, -1.0); // set up orthigraphic projection (?)
}

// Actual function to draw the circle:
void drawCircle(float radius, int vCount)
{ // includes the radius and the vertex count, we use triangles to make circles in openGL not actual circle commands
    // glBegin(GL_LINE_LOOP);//Begin drawin gthe line loop (connects verteces with lines ~?) <-- Gl_Line_Loop connected vertexes while...
    glBegin(GL_POLYGON); // begin drawing polygons polygonを渡したら、塗りつぶされた図形が描かれる。
    for (int i = 0; i < vCount; i++)
    {
        float angle = 2 * M_PI * i / vCount; // calculating angle for each vertex (???)
        float x = radius * cos(angle);       // calculate x-coordinate
        float y = radius * sin(angle);       // calculate y-coordinate
        glVertex2f(x, y);                    // specify vertex position (most likely the function to actually state hte vertex is here.
    }
    glEnd(); // end drawing
}

// actual function to render;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // clear the color buffer
    glColor3f(0, 0, 0);           // I'm guessing 3f means 3 floats here, but even integers can be used I think,0.0=0 so ye.
    drawCircle(0.5, 36);          // actually calling the circle function right here
    glFlush();                    // Flush OpenGl buffer (??)
}

// main function (holy crap--this actually creates the window.)
int main(int argc, char **argv)
{
    glutInit(&argc, argv);                       // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
    glutInitWindowSize(500, 500);                // Set window size
    glutInitWindowPosition(100, 100);            // Set window position
    glutCreateWindow("Circle Example");          // Create window with title "Circle Example"
    init();                                      // Initialize OpenGL
    glutDisplayFunc(display);                    // Set display callback function
    glutMainLoop();                              // Enter main event loop
    return 0;
}

// runs with g++ circle.cpp -o circle -lGL -lGLU -lglut apparently (?)
