#include "Layer.hxx"

#include "mppch.hxx"

Layer::Layer() : file(WIDTH, HEIGHT, "mandelbrot.bmp") {
}

void Layer::OnAttach() {
}

void Layer::OnDetach() {
}

void Layer::OnEvent(Automata::Event &event) {
    if (event.GetEventType() != Automata::EventType::KeyPressed)
        return;

    auto keyPressedEvent = *dynamic_cast<Automata::KeyPressedEvent *>(&event);
    auto key = keyPressedEvent.GetKeyCode();

    switch (key) {
        case Automata::Key::C: {
            Automata::Application::Close();
        } break;

        case Automata::Key::W: {
            xScale = { (3.0 * xScale.x + xScale.y) / 4.0, (3.0 * xScale.y + xScale.x) / 4.0 };
            yScale = { (3.0 * yScale.x + yScale.y) / 4.0, (3.0 * yScale.y + yScale.x) / 4.0 };
        } break;

        case Automata::Key::S: {
            xScale = { (3.0 * xScale.x - xScale.y) / 4.0, (3.0 * xScale.y - xScale.x) / 2.0 };
            yScale = { (3.0 * yScale.x - yScale.y) / 4.0, (3.0 * yScale.y - yScale.x) / 2.0 };
        } break;
    }
}

void Layer::OnUpdate(double deltaTime) {
    for (int32_t Py = 0; Py < HEIGHT; Py++) {
        for (int32_t Px = 0; Px < WIDTH; Px++) {
            double x0 = Px / (WIDTH / (xScale.y - xScale.x)) + xScale.x;
            double y0 = Py / (HEIGHT / (yScale.y - yScale.x)) + yScale.x;

            double x = 0.0;
            double y = 0.0;

            double x2 = 0.0;
            double y2 = 0.0;
            double w = 0.0;

            uint32_t iteration = 0;
            while (x2 + y2 <= 4.0 and iteration < maxIteration) {
                x = x2 - y2 + x0;
                y = w - x2 - y2 + y0;
                x2 = x * x;
                y2 = y * y;
                w = (x + y) * (x + y);

                iteration++;
            }

            if (iteration == maxIteration) {
                file.SetPixel(Px, Py, 0, 0, 0);
            } else {
                file.SetPixel(Px, Py, (iteration % 256), (iteration * 7 % 256), (iteration % 256));
            }
        }
    }

    file.Write();
}

void Layer::OnRender() {
    Automata::Renderer::Draw(glm::vec2(0, 0), Automata::Texture(file.GetName()));
}
