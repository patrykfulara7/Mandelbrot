#include <Core/main.hxx>

#include "mppch.hxx"

#include "Layer.hxx"

class MandelbrotApplication : public Automata::Application {
  public:
    MandelbrotApplication() : Application(Layer::GetWidth(), Layer::GetHeight(), "Mandelbrot") {
        PushLayer(new Layer());
    }
};

Automata::Application *Automata::CreateApplication() {
    return new MandelbrotApplication();
}
