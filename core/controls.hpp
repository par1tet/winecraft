#include <GLFW/glfw3.h>
#include <classes/entities/entity.hpp>
#include <vector>
using namespace std;

inline bool PressedUp = false;
inline bool PressedLeft = false;
inline bool PressedRight = false;
inline bool PressedDown = false;
const float moveXY = 0.2f;

void handleMoves(vector<Entity*> entitiesList, int countCubes);
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode); 