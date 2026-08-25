#include "core_headers.h"
#include <imgui_impl_glfw.h>

void InputManager::Update() {
    mousePositionDelta = Vector2(0, 0);
}

void InputManager::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    ImGui_ImplGlfw_KeyCallback(window, key, scancode, action, mods);

    if (action == GLFW_PRESS) {
        keyStates[key] = DOWN;
    }
    else if (action == GLFW_RELEASE) {
        keyStates[key] = UP;
    }
    else if (action == GLFW_REPEAT) {
        keyStates[key] = HELD;
    }
}

void InputManager::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);

    if (action == GLFW_PRESS) {
        mouseKeyStates[button] = DOWN;
    }
    else if (action == GLFW_RELEASE) {
        mouseKeyStates[button] = UP;
    }
}

void InputManager::scrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
    ImGui_ImplGlfw_ScrollCallback(window, xoffset, yoffset);

    scrollX = xoffset;
    scrollY = yoffset;
}

void InputManager::cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
    ImGui_ImplGlfw_CursorPosCallback(window, xpos, ypos);

    mousePositionDelta = Vector2(cursorX - xpos, cursorY - ypos);

    cursorX = xpos;
    cursorY = ypos;
}

bool InputManager::GetKeyDown(const int key) {
    if (keyStates[key] == DOWN) {
        keyStates[key] = HELD;
        return true;
    }
    else {
        return false;
    }
}

bool InputManager::GetKeyUp(const int key) {
    return keyStates[key] == UP;
}

bool InputManager::GetKey(const int key) {
    return keyStates[key] == HELD || keyStates[key] == DOWN;
}

float InputManager::GetAxis(const char* axis) {
    if (axis == "Horizontal") {
        if (keyStates[68] == DOWN || keyStates[68] == HELD)
        {
            return 1;
        }
        else if (keyStates[65] == DOWN || keyStates[65] == HELD) {
            return -1;
        }
    }
    else if (axis == "Vertical") {
        if (keyStates[87] == DOWN || keyStates[87] == HELD)
        {
            return 1;
        }
        else if (keyStates[83] == DOWN || keyStates[83] == HELD) {
            return -1;
        }
    }

    return 0;
}

bool InputManager::GetMouseButtonDown(const int button) {
    if (mouseKeyStates[button] == DOWN) {
        mouseKeyStates[button] = HELD;
        return true;
    }
    else {
        return false;
    }
}

bool InputManager::GetMouseButton(const int button) {
    return mouseKeyStates[button] == HELD || mouseKeyStates[button] == DOWN;
}

bool InputManager::GetMouseButtonUp(const int button) {
    return mouseKeyStates[button] == UP;
}

float InputManager::GetMouseScroll(const char* axis) {
    if (axis == "Horizontal") {
        return scrollX;
    }
    else if (axis == "Vertical") {
        return scrollY;
    }

    scrollX = 0;
    scrollY = 0;

    return 0;
}

Vector2 InputManager::GetMousePositionDelta()
{
    return mousePositionDelta;
}



std::unordered_map<int, InputManager::keyState> InputManager::keyStates = {};

std::unordered_map<int, InputManager::keyState> InputManager::mouseKeyStates = {};

float InputManager::scrollX = 0;
float InputManager::scrollY = 0;

float InputManager::cursorX = 0;
float InputManager::cursorY = 0;

Vector2 InputManager::mousePositionDelta = Vector2(0, 0);