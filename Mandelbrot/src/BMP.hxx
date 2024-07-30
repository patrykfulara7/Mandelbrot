#include "mppch.hxx"

class BMP {
  private:
    std::fstream file;

    std::string name;
    int32_t width = 0;
    int32_t rowStride = 0;
    int32_t height = 0;

    std::vector<uint8_t> data;

  public:
    BMP(int32_t width, int32_t height, const std::string &name);
    ~BMP();

    void SetPixel(int32_t x, int32_t y, uint8_t r, uint8_t g, uint8_t b);
    void Write();

    inline int32_t GetWidth() {
        return width;
    }

    inline int32_t GetHeight() {
        return height;
    }

    inline const std::string &GetName() {
        return name;
    }
};
