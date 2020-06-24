#pragma once
#include "DataBlock.h"

class Matrix
{
    friend std::ostream &operator<<(std::ostream &stream, const Matrix &m);

public:
    // constructors and destructor
    Matrix();
    Matrix(const char *str);

    Matrix(const DataBlock &d);
    Matrix(DataBlock &&d);
    Matrix(const Matrix &other);
    Matrix(Matrix &&other);
    ~Matrix();

    // assignment operators
    Matrix &operator=(const Matrix &other);
    Matrix &operator=(Matrix &&other);

    // arithmetic operators
    DataBlock &operator+(const Matrix &other);
    DataBlock &operator-(const Matrix &other);
    DataBlock &operator*(const Matrix &other);

    DataBlock &operator+(double d);
    DataBlock &operator-(double d);
    DataBlock &operator*(double d);
    DataBlock &operator/(double d);

    DataBlock &t();

    // Matrix Functions
    void lu();
    void rref();

private:
    DataBlock M;
    DataBlock P;
    DataBlock L;
    DataBlock U;
    DataBlock R;
};