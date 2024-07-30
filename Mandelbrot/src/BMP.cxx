#include "BMP.hxx"

BMP::BMP(int32_t width, int32_t height, const std::string &name) : width(width), height(height), name(name) {
    file.open(name, std::ios::in | std::ios::out | std::ios::trunc);

    uint8_t padding = (4 - (width % 4)) % 4;
    rowStride = width * 3 + padding;
    data.resize(rowStride * height);
    std::fill(data.begin(), data.end(), 0);

    uint8_t fileHeader[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    uint32_t fileSize = 54 + data.size();
    fileHeader[2] = fileSize;
    fileHeader[3] = fileSize >> 8;
    fileHeader[4] = fileSize >> 16;
    fileHeader[5] = fileSize >> 24;

    uint8_t infoHeader[40] = {40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
    infoHeader[4] = width;
    infoHeader[5] = width >> 8;
    infoHeader[6] = width >> 16;
    infoHeader[7] = width >> 24;

    infoHeader[8] = height;
    infoHeader[9] = height >> 8;
    infoHeader[10] = height >> 16;
    infoHeader[11] = height >> 24;

    infoHeader[20] = data.size();
    infoHeader[21] = data.size() >> 8;
    infoHeader[22] = data.size() >> 16;
    infoHeader[23] = data.size() >> 24;

    file.write(reinterpret_cast<const char *>(fileHeader), 14);
    file.write(reinterpret_cast<const char *>(infoHeader), 40);
    file.write(reinterpret_cast<const char *>(data.data()), data.size());
}

void BMP::SetPixel(int32_t x, int32_t y, uint8_t r, uint8_t g, uint8_t b) {
    uint32_t offset = (rowStride * y) + (x * 3);
    data[offset] = r;
    data[offset + 1] = g;
    data[offset + 2] = b;
}

void BMP::Write() {
    file.seekp(54);
    file.write(reinterpret_cast<const char *>(data.data()), data.size());
}

BMP::~BMP() {
    file.close();
}
