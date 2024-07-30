#include "Core/Input.hxx"
#include "Core/Application.hxx"

namespace Automata {
    bool Input::IsKeyPressed(Key key) {
        auto windowHandle = Application::GetWindow().GetWindowHandle();
        auto state = glfwGetKey(windowHandle, static_cast<int>(key));
        return state == GLFW_PRESS or state == GLFW_REPEAT;
    }

    bool Input::IsMouseButtonPressed(MouseButton mouseButton) {
        auto windowHandle = Application::GetWindow().GetWindowHandle();
        auto state = glfwGetMouseButton(windowHandle, mouseButton);
        return state == GLFW_PRESS;
    }

    glm::vec2 Input::GetMousePosition() {
        auto windowHandle = Application::GetWindow().GetWindowHandle();
        double x, y;
        glfwGetCursorPos(windowHandle, &x, &y);
        return { x, y };
    }
} // namespace Automata
