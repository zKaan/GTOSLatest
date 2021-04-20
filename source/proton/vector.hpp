#pragma once
class vector2_t {
   public:
    float m_x;
    float m_y;
    vector2_t() : m_x(0), m_y(0) {}
    vector2_t(float x, float y) : m_x(x), m_y(y) {}
    bool operator==(vector2_t& rhs) { return m_x == rhs.m_x && m_y == rhs.m_y; }
    bool operator==(const vector2_t& rhs) const { return m_x == rhs.m_x && m_y == rhs.m_y; }
    vector2_t operator+(const vector2_t& rhs) { return vector2_t(m_x + rhs.m_x, m_y + rhs.m_y); }
    vector2_t operator-(const vector2_t& rhs) { return vector2_t(m_x - rhs.m_x, m_y - rhs.m_y); }
    float distance(float x, float y) {
        float value_x = this->m_x - x;
        float value_y = this->m_y - y;
        return sqrt(value_x * value_x + value_y * value_y);
    }
};

class vector2i_t {
   public:
    int m_x;
    int m_y;
    vector2i_t() : m_x(0), m_y(0) {}
    vector2i_t(int x, int y) : m_x(x), m_y(y) {}
    vector2i_t(uint32_t x, uint32_t y) : m_x(x), m_y(y) {}
    bool operator==(vector2i_t& rhs) { return m_x == rhs.m_x && m_y == rhs.m_y; }
    bool operator!=(vector2i_t& rhs) {
        return m_x != rhs.m_x || m_y != rhs.m_y;
    }
    bool operator==(const vector2i_t& rhs) const { return m_x == rhs.m_x && m_y == rhs.m_y; }
    vector2i_t operator+(const vector2i_t& rhs) { return vector2i_t(m_x + rhs.m_x, m_y + rhs.m_y); }
    vector2i_t operator-(const vector2i_t& rhs) { return vector2i_t(m_x - rhs.m_x, m_y - rhs.m_y); }
    float distance(int x, int y) {
        float value_x = float(this->m_x) - x;
        float value_y = float(this->m_y) - y;
        return sqrt(value_x * value_x + value_y * value_y);
    }
};

class vector3_t {
   public:
    float m_x;
    float m_y;
    float m_z;
    vector3_t() : m_x(0), m_y(0), m_z(0) {}
    vector3_t(float x, float y, float z) : m_x(x), m_y(y), m_z(z) {}
    bool operator==(vector3_t& rhs) { return m_x == rhs.m_x && m_y == rhs.m_y && m_z == rhs.m_z; }
    bool operator==(const vector3_t& rhs) const { return m_x == rhs.m_x && m_y == rhs.m_y && m_z == rhs.m_z; }
    vector3_t operator+(const vector3_t& rhs) { return vector3_t(m_x + rhs.m_x, m_y + rhs.m_y, m_z + rhs.m_z); }
    vector3_t operator-(const vector3_t& rhs) { return vector3_t(m_x - rhs.m_x, m_y - rhs.m_y, m_z - rhs.m_z); }
};

class rect_t {
   public:
    float m_x;
    float m_y;
    float m_w;
    float m_h;
    rect_t() : m_x(0), m_y(0), m_w(0), m_h(0) {}
    rect_t(float x, float y, float w, float h) : m_x(x), m_y(y), m_w(w), m_h(h) {}
    bool operator==(rect_t& rhs) { return m_x == rhs.m_x && m_y == rhs.m_y && m_w == rhs.m_w && m_h == rhs.m_h; }
    bool operator==(const rect_t& rhs) const { return m_x == rhs.m_x && m_y == rhs.m_y && m_w == rhs.m_w && m_h == rhs.m_h; }
    rect_t operator+(const rect_t& rhs) { return rect_t(m_x + rhs.m_x, m_y + rhs.m_y, m_w + rhs.m_w, m_h + rhs.m_h); }
    rect_t operator-(const rect_t& rhs) { return rect_t(m_x - rhs.m_x, m_y - rhs.m_y, m_w - rhs.m_w, m_h - rhs.m_h); }
};