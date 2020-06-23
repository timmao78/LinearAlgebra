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
    Matrix(DataBlock *pD);

    Matrix(const Matrix &other);
    Matrix(Matrix &&other);

    Matrix &operator=(const Matrix &other);
    Matrix &operator=(Matrix &&other);

    void operator=(DataBlock *pD);

    ~Matrix();

    DataBlock *operator+(const Matrix &other);
    DataBlock *operator-(const Matrix &other);
    DataBlock *operator*(const Matrix &other);

    DataBlock *operator+(double d);
    DataBlock *operator-(double d);
    DataBlock *operator*(double d);
    DataBlock *operator/(double d);

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