#include <GLFW/glfw3.h>

inline bool PressedW= false;
inline bool PressedS= false;
inline bool PressedA= false;
inline bool PressedD= false;
inline bool PressedUp = false;
inline bool PressedLeft = false;
inline bool PressedRight = false;
inline bool PressedDown = false;

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode); 
