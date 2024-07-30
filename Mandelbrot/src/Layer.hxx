#pragma once

#include "mppch.hxx"

#include "BMP.hxx"

class Layer : public Automata::Layer {
  private:
    static constexpr int32_t HEIGHT = 1080;
    static constexpr int32_t WIDTH = 1920;

    glm::vec2 xScale = { -2.82, 1.29 };
    glm::vec2 yScale = { -1.12, 1.12 };

    uint32_t maxIteration = 1024;

    BMP file;

  public:
    Layer();
    ~Layer() = default;

    void OnAttach() override;
    void OnDetach() override;
    void OnEvent(Automata::Event &event) override;
    void OnUpdate(double deltaTime) override;
    void OnRender() override;

    static inline int32_t GetWidth() {
        return WIDTH;
    }

    static inline int32_t GetHeight() {
        return HEIGHT;
    }
};
