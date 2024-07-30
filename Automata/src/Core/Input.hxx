#pragma once

#include "ampch.hxx"

#include "Core/KeyCodes.hxx"
#include "Core/Window.hxx"
#include "MouseButtonCodes.hxx"

namespace Automata {
    class Input {
      public:
        static bool IsKeyPressed(Key key);
        static bool IsMouseButtonPressed(MouseButton mouseButton);
        static glm::vec2 GetMousePosition();
    };
} // namespace Automata
