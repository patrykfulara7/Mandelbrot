#pragma once

#include "ampch.hxx"

namespace Automata {
    using MouseButtonCode = int;

    enum MouseButton : MouseButtonCode {
        BUTTON_LEFT = GLFW_MOUSE_BUTTON_1,
        BUTTON_RIGHT = GLFW_MOUSE_BUTTON_2,
        BUTTON_MIDDLE = GLFW_MOUSE_BUTTON_3
    };
} // namespace Automata
