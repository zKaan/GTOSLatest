#pragma once
#include <stdint.h>
#include <sstream>
#include <string>
#include "vector.hpp"

#define C_VAR_SPACE_BYTES 16
class variant_t {
   public:
    enum class vartype_t { TYPE_UNUSED, TYPE_FLOAT, TYPE_STRING, TYPE_VECTOR2, TYPE_VECTOR3, TYPE_UINT32, TYPE_ENTITY, TYPE_COMPONENT, TYPE_RECT, TYPE_INT32 };
    variant_t() { set_defaults(); }
    variant_t(const variant_t& v) {
        set_defaults();
        *this = v;
    }
    variant_t(int32_t var) {
        set_defaults();
        set(var);
    }
    variant_t(uint32_t var) {
        set_defaults();
        set(var);
    }
    variant_t(float var) {
        set_defaults();
        set(var);
    }
    variant_t(float x, float y) {
        set_defaults();
        set(vector2_t(x, y));
    }
    variant_t(float x, float y, float z) {
        set_defaults();
        set(vector3_t(x, y, z));
    }
    variant_t(const vector2_t& v2) {
        set_defaults();
        set(v2);
    }
    variant_t(const vector3_t& v3) {
        set_defaults();
        set(v3);
    }
    variant_t(const rect_t& r) {
        set_defaults();
        set(r);
    }
    variant_t(const std::string& var) {
        set_defaults();
        set(var);
    }

    void reset() { m_type = vartype_t::TYPE_UNUSED; }
    void set(const variant_t& v) {
        switch (v.get_type()) {
            case vartype_t::TYPE_FLOAT: set(v.get_float()); break;
            case vartype_t::TYPE_STRING: set(v.get_string()); break;
            case vartype_t::TYPE_VECTOR2: set(v.get_vector2()); break;
            case vartype_t::TYPE_VECTOR3: set(v.get_vector3()); break;
            case vartype_t::TYPE_UINT32: set(v.get_uint32()); break;
            case vartype_t::TYPE_INT32: set(v.get_int32()); break;
            case vartype_t::TYPE_RECT: set(v.get_rect()); break;
            case vartype_t::TYPE_ENTITY:
            case vartype_t::TYPE_COMPONENT:
            default: break;
        }
    }
    void set(float var) {
        m_type = vartype_t::TYPE_FLOAT;
        *((float*)m_var) = var;
    }
    void set(uint32_t var) {
        m_type = vartype_t::TYPE_UINT32;
        *((uint32_t*)m_var) = var;
    }
    void set(int32_t var) {
        m_type = vartype_t::TYPE_INT32;
        *((int32_t*)m_var) = var;
    }
    void operator=(float var) {
        set(var);
    }
    void operator=(int32_t var) {
        set(var);
    }
    void operator=(uint32_t var) {
        set(var);
    }
    void operator=(std::string const& var) {
        set(var);
	}
    void set(std::string const& var) {
        m_type = vartype_t::TYPE_STRING;
        m_string = var;
    }
    void operator=(vector2_t const& var) {
        set(var);
    }
    void set(vector2_t const& var) {
        m_type = vartype_t::TYPE_VECTOR2;
        *((vector2_t*)m_var) = var;
    }
    void set(float x, float y) { set(vector2_t(x, y)); }
    void operator=(vector3_t const& var) {
        set(var);
    }
    void operator=(rect_t const& var) {
        set(var);
    }
    void set(vector3_t const& var) {
        m_type = vartype_t::TYPE_VECTOR3;
        *((vector3_t*)m_var) = var;
    }
    void set(rect_t const& var) {
        m_type = vartype_t::TYPE_RECT;
        *((rect_t*)m_var) = var;
    }
    void set(float x, float y, float z) { set(vector3_t(x, y, z)); }

    float& get_float() {
        if (m_type == vartype_t::TYPE_UNUSED)
            set(float(0));
        return *((float*)m_var);
    }
    int32_t& get_int32() {
        if (m_type == vartype_t::TYPE_UNUSED)
            set(int32_t(0));
        return *((int32_t*)m_var);
    }
    uint32_t& get_uint32() {
        if (m_type == vartype_t::TYPE_UNUSED)
            set(uint32_t(0));
        return *((uint32_t*)m_var);
    }
    std::string& get_string() { return m_string; }
    vector2_t& get_vector2() {
        if (m_type == vartype_t::TYPE_UNUSED)
            set(vector2_t(0, 0));
        return *((vector2_t*)m_var);
    }
    vector3_t& get_vector3() {
        if (m_type == vartype_t::TYPE_UNUSED)
            set(vector3_t(0, 0, 0));
        return *((vector3_t*)m_var);
    }
    rect_t& get_rect() {
        if (m_type == vartype_t::TYPE_UNUSED)
            set(rect_t(0, 0, 0, 0));
        return *((rect_t*)m_var);
    }

    const float& get_float() const { return *((float*)m_var); }
    const int32_t& get_int32() const { return *((int32_t*)m_var); }
    const uint32_t& get_uint32() const { return *((uint32_t*)m_var); }
    const std::string& get_string() const { return m_string; }
    const vector2_t& get_vector2() const { return *((vector2_t*)m_var); }
    const vector3_t& get_vector3() const { return *((vector3_t*)m_var); }
    const rect_t& get_rect() const { return *((rect_t*)m_var); }

    vartype_t get_type() const { return m_type; }

    std::string print() {
        switch (get_type()) {
            case vartype_t::TYPE_FLOAT: return std::to_string(get_float());
            case vartype_t::TYPE_STRING: return get_string();
            case vartype_t::TYPE_VECTOR2: return "x: " + std::to_string(get_vector2().m_x) + " y: " + std::to_string(get_vector2().m_y);
            case vartype_t::TYPE_VECTOR3:
                return "x: " + std::to_string(get_vector3().m_x) + " y: " + std::to_string(get_vector3().m_y) + " z: " + std::to_string(get_vector3().m_z);
            case vartype_t::TYPE_UINT32: return std::to_string(get_uint32());
            case vartype_t::TYPE_INT32: return std::to_string(get_int32());
            case vartype_t::TYPE_RECT:
                return "x: " + std::to_string(get_rect().m_x) + " y: " + std::to_string(get_rect().m_y) + " w: " + std::to_string(get_rect().m_w) +
                       " h: " + std::to_string(get_rect().m_h);
            case vartype_t::TYPE_ENTITY:
            case vartype_t::TYPE_COMPONENT:
            case vartype_t::TYPE_UNUSED: return "unused"; break;
            default: break;
        }
        return "unknown";
    }
    variant_t& operator=(const variant_t& rhs) {
        m_type = rhs.m_type;
        m_pointer = rhs.m_pointer;
        memcpy(m_var, rhs.m_var, C_VAR_SPACE_BYTES);
        m_string = rhs.m_string;
        return *this;
    }
    variant_t& operator+=(const variant_t& rhs) {
        if (get_type() == rhs.get_type()) {
            switch (get_type()) {
                case vartype_t::TYPE_FLOAT: set(get_float() + rhs.get_float()); break;
                case vartype_t::TYPE_STRING: set(get_string() + rhs.get_string()); break;
                case vartype_t::TYPE_VECTOR2: set(get_vector2() + rhs.get_vector2()); break;
                case vartype_t::TYPE_VECTOR3: set(get_vector3() + rhs.get_vector3()); break;
                case vartype_t::TYPE_UINT32: set(get_uint32() + rhs.get_uint32()); break;
                case vartype_t::TYPE_INT32: set(get_int32() + rhs.get_int32()); break;
                default: break;
            }
        }
        return *this;
    }
    variant_t& operator-=(const variant_t& rhs) {
        if (get_type() == rhs.get_type()) {
            switch (get_type()) {
                case vartype_t::TYPE_FLOAT: set(get_float() - rhs.get_float()); break;
                case vartype_t::TYPE_VECTOR2: set(get_vector2() - rhs.get_vector2()); break;
                case vartype_t::TYPE_VECTOR3: set(get_vector3() - rhs.get_vector3()); break;
                case vartype_t::TYPE_UINT32: set(get_uint32() - rhs.get_uint32()); break;
                case vartype_t::TYPE_INT32: set(get_int32() - rhs.get_int32()); break;
                default: break;
            }
        }
        return *this;
    }
    bool operator==(const variant_t& rhs) const {
        if (get_type() != rhs.get_type())
            return false;
        switch (get_type()) {
            case vartype_t::TYPE_UNUSED: return true;
            case vartype_t::TYPE_FLOAT: return get_float() == rhs.get_float();
            case vartype_t::TYPE_STRING: return get_string() == rhs.get_string();
            case vartype_t::TYPE_VECTOR2: return get_vector2() == rhs.get_vector2();
            case vartype_t::TYPE_VECTOR3: return get_vector3() == rhs.get_vector3();
            case vartype_t::TYPE_UINT32: return get_uint32() == rhs.get_uint32();
            case vartype_t::TYPE_RECT: return get_rect() == rhs.get_rect();
            case vartype_t::TYPE_INT32: return get_int32() == rhs.get_int32();
            case vartype_t::TYPE_ENTITY:
            case vartype_t::TYPE_COMPONENT:
            default: return false;
        }
    }
    bool operator!=(const variant_t& rhs) const { return !operator==(rhs); }
    friend class variantlist_t;

   private:
    void set_defaults() { m_type = vartype_t::TYPE_UNUSED; }
    vartype_t m_type;
    void* m_pointer;
    union {
        uint8_t m_var[C_VAR_SPACE_BYTES];
        float m_as_floats[4];
        uint32_t m_as_uint32s[4];
        int32_t m_as_int32s[4];
    };
    std::string m_string;
};
inline variant_t operator+(variant_t lhs, const variant_t& rhs) {
    lhs += rhs;
    return lhs;
}
inline variant_t operator-(variant_t lhs, const variant_t& rhs) {
    lhs -= rhs;
    return lhs;
}
#define C_MAX_VARIANT_LIST_PARMS 7
class variantlist_t {
    int size_of_variant(variant_t::vartype_t type) {
        switch (type) {
            case variant_t::vartype_t::TYPE_UNUSED:
            case variant_t::vartype_t::TYPE_COMPONENT:
            case variant_t::vartype_t::TYPE_ENTITY: return 0;
            case variant_t::vartype_t::TYPE_UINT32:
            case variant_t::vartype_t::TYPE_INT32:
            case variant_t::vartype_t::TYPE_FLOAT: return 4;
            case variant_t::vartype_t::TYPE_VECTOR2: return sizeof(vector2_t);
            case variant_t::vartype_t::TYPE_VECTOR3: return sizeof(vector3_t);
            case variant_t::vartype_t::TYPE_RECT: return sizeof(rect_t);
            default: return 0;
        }
    }

   public:
    variantlist_t(){};
    variant_t& get(int parmNum) { return m_variant[parmNum]; }
    variant_t& operator[](int num) {
        return m_variant[num];
    }
    variantlist_t(const std::string& string) {
        m_variant[0] = variant_t(string);
	}
    variantlist_t(variant_t v0) { m_variant[0] = v0; }
    variantlist_t(variant_t v0, variant_t v1) {
        m_variant[0] = v0;
        m_variant[1] = v1;
    }
    variantlist_t(variant_t v0, variant_t v1, variant_t v2) {
        m_variant[0] = v0;
        m_variant[1] = v1;
        m_variant[2] = v2;
    }
    variantlist_t(variant_t v0, variant_t v1, variant_t v2, variant_t v3) {
        m_variant[0] = v0;
        m_variant[1] = v1;
        m_variant[2] = v2;
        m_variant[3] = v3;
    }
    variantlist_t(variant_t v0, variant_t v1, variant_t v2, variant_t v3, variant_t v4) {
        m_variant[0] = v0;
        m_variant[1] = v1;
        m_variant[2] = v2;
        m_variant[3] = v3;
        m_variant[4] = v4;
    }
    variantlist_t(variant_t v0, variant_t v1, variant_t v2, variant_t v3, variant_t v4, variant_t v5) {
        m_variant[0] = v0;
        m_variant[1] = v1;
        m_variant[2] = v2;
        m_variant[3] = v3;
        m_variant[4] = v4;
        m_variant[5] = v5;
    }
    void reset() {
        for (int i = 0; i < C_MAX_VARIANT_LIST_PARMS; i++) m_variant[i].reset();
    }
    uint32_t get_mem_needed() {
        int vars_used = 0;
        int mem_needed = 0;
        int var_size;
        for (int i = 0; i < C_MAX_VARIANT_LIST_PARMS; i++) {
            if (m_variant[i].get_type() == variant_t::vartype_t::TYPE_STRING)
                var_size = m_variant[i].get_string().size() + 4;
            else
                var_size = size_of_variant(m_variant[i].get_type());
            if (var_size > 0) {
                vars_used++;
                mem_needed += var_size;
            }
        }
        int total = mem_needed + 1 + (vars_used * 2);
        return total;
	}
    uint8_t* serialize_to_mem(uint32_t* size, uint8_t* data) {
        int vars_used = 0;
        int mem_needed = 0;
        int var_size;
        for (int i = 0; i < C_MAX_VARIANT_LIST_PARMS; i++) {
            if (m_variant[i].get_type() == variant_t::vartype_t::TYPE_STRING)
                var_size = m_variant[i].get_string().size() + 4;
            else
                var_size = size_of_variant(m_variant[i].get_type());
            if (var_size > 0) {
                vars_used++;
                mem_needed += var_size;
            }
        }
        int total = mem_needed + 1 + (vars_used * 2);
        if (!data)
            data = new uint8_t[total];
        uint8_t* p = data;
        *(p++) = uint8_t(vars_used);
        for (int idx = 0; idx < C_MAX_VARIANT_LIST_PARMS; idx++) {
            uint8_t type = uint8_t(m_variant[idx].get_type());
            if (m_variant[idx].get_type() == variant_t::vartype_t::TYPE_STRING) {
                uint32_t len = m_variant[idx].get_string().size();
                memcpy(p++, &idx, 1);
                memcpy(p++, &type, 1);
                memcpy(p, &len, 4);
                p += 4;
                memcpy(p, m_variant[idx].get_string().c_str(), len);
                p += len;
            } else {
                var_size = size_of_variant(m_variant[idx].get_type());
                if (var_size > 0) {
                    memcpy(p++, &idx, 1);
                    memcpy(p++, &type, 1);
                    memcpy(p, m_variant[idx].m_var, var_size);
                    p += var_size;
                }
            }
        }
        if (size)
            *size = total;
        return data;
    }
    bool serialize_from_mem(uint8_t* data, int* read = 0) { //robinson way cuz i dont want to refactor this yet
        uint8_t* p = data;
        uint8_t count = *(p++);
        for (int i = 0; i < count; i++) {
            uint8_t index = *(p++);
            uint8_t type = *(p++);
            switch (variant_t::vartype_t(type)) {
                case variant_t::vartype_t::TYPE_STRING: {
                    uint32_t len;
                    memcpy(&len, p, 4);
                    p += 4;
                    std::string v;
                    v.resize(len);
                    memcpy(&v[0], p, len);
                    p += len;
                    m_variant[index].set(v);
                    break;
                }
                case variant_t::vartype_t::TYPE_UINT32: {
                    uint32_t v;
                    memcpy(&v, p, sizeof(uint32_t));
                    p += sizeof(uint32_t);
                    m_variant[index].set(v);
                    break;
                }
                case variant_t::vartype_t::TYPE_INT32: {
                    int32_t v;
                    memcpy(&v, p, sizeof(int32_t));
                    p += sizeof(int32_t);
                    m_variant[index].set(v);
                    break;
                }
                case variant_t::vartype_t::TYPE_FLOAT: {
                    float v;
                    memcpy(&v, p, sizeof(float));
                    p += sizeof(float);
                    m_variant[index].set(v);
                    break;
                }
                case variant_t::vartype_t::TYPE_VECTOR2: {
                    vector2_t v;
                    memcpy(&v, p, sizeof(vector2_t));
                    p += sizeof(vector2_t);
                    m_variant[index].set(v);
                    break;
                }
                case variant_t::vartype_t::TYPE_VECTOR3: {
                    vector3_t v;
                    memcpy(&v, p, sizeof(vector3_t));
                    p += sizeof(vector3_t);
                    m_variant[index].set(v);
                    break;
                }
                case variant_t::vartype_t::TYPE_RECT: {
                    rect_t v;
                    memcpy(&v, p, sizeof(rect_t));
                    p += sizeof(rect_t);
                    m_variant[index].set(v);
                    break;
                }
                default:
                    if (read)
                        *read = 0;
                    return false;
            }
        }
        if (read)
            *read = int(p - data);
        return true;
    }
    variant_t m_variant[C_MAX_VARIANT_LIST_PARMS];
    std::string print() {
        std::stringstream ss;
        for (int i = 0; i < C_MAX_VARIANT_LIST_PARMS; i++) {
            if (m_variant[i].get_type() == variant_t::vartype_t::TYPE_UNUSED)
                continue;
            ss << "param " << std::to_string(i) << ": " << m_variant[i].print() + "\n";
        }
        if (ss.str().empty())
            ss.str("(none)");
        return ss.str();
    }
};