#include <cstring>
#include <exception>

#include "stringBasic.h"

StringBasic::StringBasic() :
    m_string(nullptr),
    m_lenght(0),
    m_size(0)
{}


StringBasic::StringBasic(const char* const string) :
    m_string(nullptr),
    m_lenght(strlen(string)),
    m_size(strlen(string))
{
    m_size *= SIZE_SCALE;
    m_string = new char[m_size];
    std::memset(m_string, 0, m_size);
    std::memcpy(m_string, string, m_lenght);
}


StringBasic::~StringBasic() {
    if (m_string != nullptr) {
        try {
            delete[] m_string;
        }
        catch (...) {
        }
        m_string = nullptr;
    }
}


StringBasic::StringBasic(const StringBasic& other) :
    m_size(other.m_size),
    m_lenght(other.m_lenght),
    m_string(nullptr)
{
    m_string = new char[m_size];
    std::memset(m_string, 0, m_size);
    std::memcpy(m_string, other.m_string, m_lenght);
}


StringBasic& StringBasic::operator=(const StringBasic& other) {
    if (m_string != nullptr) {
        try {
            delete[] m_string;
        }
        catch (...) {
        }
    }

    m_string = other.m_string;
    m_size = other.m_size;
    m_lenght = other.m_lenght;

    return *this;
}


StringBasic::StringBasic(StringBasic&& other) noexcept :
    m_size(other.m_size),
    m_lenght(other.m_lenght),
    m_string(other.m_string)
{
    other.m_string = nullptr;
    other.m_lenght = 0;
    other.m_size = 0;
}


StringBasic& StringBasic::operator=(StringBasic&& other) noexcept {
    if (m_string != nullptr) {
        try {
            delete[] m_string;
            m_string = nullptr;
        }
        catch (...) {
        }
    }

    *this = other;
    other.m_string = nullptr;
    return *this;
}


const unsigned long StringBasic::getLenght() const noexcept {
    return m_lenght;
}


const char StringBasic::operator[](std::size_t index) const{
    if (index >= m_lenght) {
        throw std::out_of_range("invalid index exception");
    }

    return m_string[index];
}


char& StringBasic::operator[](std::size_t index) {
    if (index >= m_lenght) {
        throw std::out_of_range("invalid index exception");
    }

    return m_string[index];
}


std::ostream& operator<<(std::ostream& strm, const StringBasic& str) noexcept {
    for (std::size_t i = 0; i < str.m_lenght; i++) {
        strm << str.m_string[i];
    }
    return strm;
}


StringBasic& StringBasic::operator+=(const StringBasic& rhs) {
    add_string(rhs.m_string);
    return *this;
}


StringBasic& StringBasic::operator+=(const char& rhs) {
    add_char(rhs);
    return *this;
}


StringBasic& StringBasic::operator+=(const char* const rhs) {
    add_string(rhs);
    return *this;
}


StringBasic StringBasic::operator+(const StringBasic& rhs) {
    StringBasic string = *this;
    string.add_string(rhs.m_string);
    return string;
}


StringBasic StringBasic::operator+(const char* const rhs) {
    StringBasic string = *this;
    string.add_string(rhs);
    return string;
}


StringBasic StringBasic::operator+(const char& rhs) {
    StringBasic string = *this;
    string.add_char(rhs);
    return string;
}


void StringBasic::add_char(const char chr) {
    if (m_size == 0) {
        m_size = 2;
        m_string = new char[m_size];
        std::memset(m_string, 0, m_size);
        m_string[m_lenght] = chr;
        m_lenght++;;
    }
    else if (m_lenght == (m_size - 1)) {
        increase_size(SIZE_SCALE * m_size);
        m_string[m_lenght] = chr;
        m_lenght++;
    }
    else {
        m_string[m_lenght] = chr;
        m_lenght++;
    }
}


void StringBasic::add_string(const char* const str) {
    for (std::size_t i = 0; str[i]; i++) {
        add_char(str[i]);
    }
}


void StringBasic::insert(const StringBasic& str, std::size_t offset) {
    if (offset > m_lenght) {
        throw std::out_of_range("invalid offset");
    }
    if ((m_lenght + str.m_lenght) > (m_size - 1)) {
        increase_size(SIZE_SCALE + str.m_lenght);
    }

    std::memmove(m_string + offset + str.m_lenght, m_string + offset, m_lenght - offset);
    std::memcpy(m_string + offset, str.m_string, str.m_lenght);
    m_lenght += str.m_lenght;
}


void StringBasic::replace(const StringBasic& substring, const StringBasic& newsubstring) {
    for (std::size_t i = 0; i <= (m_lenght - substring.m_lenght); i++) {
        bool is_substring = true;
        for (std::size_t j = 0; j < substring.m_lenght; j++) {
            if (m_string[i + j] != substring.m_string[j]) {
                is_substring = false;
                break;
            }
        }
        if (is_substring) {
            if ((m_size - 1) < (m_lenght + newsubstring.m_lenght - substring.m_lenght)) {
                increase_size(m_lenght + newsubstring.m_lenght - substring.m_lenght);
            }

            if (newsubstring.m_lenght > substring.m_lenght) {
                std::memmove(m_string + i + newsubstring.m_lenght, m_string + i + substring.m_lenght, m_size - (i + newsubstring.m_lenght + 1));
                std::memcpy(m_string + i, newsubstring.m_string, newsubstring.m_lenght);
                m_lenght += (newsubstring.m_lenght - substring.m_lenght);
                std::memset(m_string + m_lenght, 0, m_size - m_lenght);
            }
            else if (newsubstring.m_lenght < substring.m_lenght) {
                std::memcpy(m_string + i, newsubstring.m_string, newsubstring.m_lenght);
                std::memmove(m_string + i + newsubstring.m_lenght, m_string + i + newsubstring.m_lenght + 1, m_size - (i + newsubstring.m_lenght + 1));
                m_lenght -= (substring.m_lenght - newsubstring.m_lenght);
                std::memset(m_string + m_lenght, 0, m_size - m_lenght);
            }
            else {
                std::memcpy(m_string + i, newsubstring.m_string, newsubstring.m_lenght);
            }
            i += newsubstring.m_lenght - 1;
        }
    }
}


void StringBasic::increase_size(std::size_t increasment) {
    m_size += increasment;
    char* new_string = new char[m_size];
    std::memset(new_string, 0, m_size);
    std::memcpy(new_string, m_string, m_lenght);

    try {
        delete[] m_string;
    }
    catch (...) {
    }

    m_string = new_string;
}