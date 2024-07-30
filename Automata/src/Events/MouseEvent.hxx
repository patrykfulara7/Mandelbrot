#pragma once

#include "ampch.hxx"

#include "Core/MouseButtonCodes.hxx"

#include "Events/Event.hxx"

namespace Automata {
    class MouseButtonEvent : public Event {
      protected:
        MouseButtonEvent(MouseButtonCode keycode) : mouseButtonCode(keycode) {
        }

        MouseButtonCode mouseButtonCode;

      public:
        inline MouseButtonCode GetMouseButtonCode(void) const {
            return mouseButtonCode;
        }
    };

    class MouseButtonPressedEvent : public MouseButtonEvent {
      public:
        MouseButtonPressedEvent(MouseButtonCode keycode) : MouseButtonEvent(keycode) {
        }

        EventType GetEventType() const override {
            return EventType::MouseButtonPressed;
        }
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent {
      public:
        MouseButtonReleasedEvent(MouseButtonCode keycode) : MouseButtonEvent(keycode) {
        }

        EventType GetEventType() const override {
            return EventType::MouseButtonReleased;
        }
    };

    class MouseMovedEvent : public Event {
      private:
        glm::vec2 position;

      public:
        MouseMovedEvent(glm::vec2 position) : position(position) {
        }

        inline glm::vec2 GetPosition() {
            return position;
        }

        EventType GetEventType() const override {
            return EventType::MouseMoved;
        }
    };
} // namespace Automata
