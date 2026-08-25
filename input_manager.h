#pragma once
#include <GLFW/glfw3.h>
#include <unordered_map>

class InputManager {
public:
    static void Update();

    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

    static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

    static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);

    static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);

    static bool GetKeyDown(const int key);

    static bool GetKeyUp(const int key);

    static bool GetKey(const int key);

    static float GetAxis(const char* axis);

    static bool GetMouseButtonDown(const int button);

    static bool GetMouseButton(const int button);

    static bool GetMouseButtonUp(const int button);

    static float GetMouseScroll(const char* axis);

    static Vector2 GetMousePositionDelta();

    enum keyState {
        NOTHING,
        DOWN,
        UP,
        HELD
    };

private:
    static std::unordered_map<int, keyState> keyStates;
    static std::unordered_map<int, keyState> mouseKeyStates;
    static float scrollX;
    static float scrollY;
    static float cursorX;
    static float cursorY;
    static Vector2 mousePositionDelta;
};