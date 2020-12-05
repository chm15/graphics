#ifndef MAT_H
#define MAT_H

#include "vec.h"

template<int size>
class Mat {
    // size x size matrix
    Vec<size> columns[size];

    Mat() {
        fill(0.0);
    }

    Mat(float val) {
        fill(val);
    }

    Mat(float vals[size*size]) {
        // First row followed by n other rows
        for (int i=0;i<size;i++) {
            float column[size];
            for (int j=0;j<size;j++) {
                column.push_back(vals[i*size + j]);
            }
            columns.push_back(Vec<size>(column));
        }
    }

    void fill(float val) {
        for (int i=0;i<size;i++) {
            columns.push_back(Vec<size>(val));
        }
    }
};


#endif