#pragma once

template <typename T>
class Sington {
public:
    static T &get_instance() {
        static T instance;
        return instance;
    }
protected:
    Sington() = default;
    ~Sington() = default;
    Sington(const Sington &) = delete;
    Sington &operator=(const Sington &) = delete;
};