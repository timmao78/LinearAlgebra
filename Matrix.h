#pragma once
#include "DataBlock.h"

class Matrix
{
    friend std::ostream &operator<<(std::ostream &stream, const Matrix &m);

public:
    Matrix();
    Matrix(const char *str);

    Matrix(const DataBlock &d);
    Matrix(DataBlock &&d);

    Matrix(const Matrix &other);
    Matrix(Matrix &&other);

    Matrix &operator=(const Matrix &other);
    Matrix &operator=(Matrix &&other);

    ~Matrix();

    DataBlock &t();

    void lu();
    void rref();

private:
    DataBlock M;
    DataBlock T;
    DataBlock P;
    DataBlock L;
    DataBlock U;
    DataBlock R;
};