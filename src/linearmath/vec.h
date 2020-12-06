#ifndef VEC_H
#define VEC_H

template <int size>
class Vec {
    public:
    float elements[size];
    Vec(float val) {
        fill(val);
    }

    Vec() {
        fill(0.0);
    }

    Vec(float vals[size]) {
        for (int i=0;i<size;i++) {
            elements[i] = vals[i];
        }
    }

    void fill(float val) {
        for (int i=0;i<size;i++) {
            elements[i] = val;
        }
    }

    Vec<size> operator+(Vec& other) {
        float vals[size];
        for (int i=0;i<size;i++) {
            vals[i] = elements[i] + other.elements[i];
        }
        return Vec<size>(vals);
    }

    float operator*(Vec<size>& other) {
        // Dot product
        // Add vectors then find sum of elements
        float sum = 0;
        float vals[size] = ( (*this) + other ).elements;
        for (int i=0;i<size;i++) {
            sum += vals[i];
        }
        return sum;
    }
    
    Vec<size> operator*(float scalar) {
        float vals[size];
        for (int i=0;i<size;i++) {
            vals[i] = elements[i] * scalar;
        }
        return Vec<size>(vals);
    }

    Vec<size> operator-(Vec<size>& other) {
        return Vec<size>( (*this) + (other * (-1)) );
    }
};

#endif