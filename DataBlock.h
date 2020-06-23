#pragma once
#include <iostream>
#include <string>
#include <iomanip>

#define DEBUG 1

class DataBlock
{
    // friend class Matrix;
    friend std::ostream &operator<<(std::ostream &stream, const DataBlock &d);

public:
    DataBlock();

    DataBlock(const char *str);

    DataBlock(const DataBlock &other);

    DataBlock(DataBlock &&other);

    DataBlock(DataBlock *pD);

    DataBlock &operator=(const DataBlock &other);

    DataBlock &operator=(DataBlock &&other);

    DataBlock &operator=(DataBlock *pD);

    void resetI();

    ~DataBlock();

    bool empty() const;

    static DataBlock *eye(unsigned int n);
    DataBlock *t();

    std::pair<unsigned int, double> maxPivotRow(unsigned int currentRow, unsigned int currentCol);

    double elim(unsigned int i1, unsigned int i2, unsigned int j);

    void backElim(unsigned int i, unsigned int j);
    void pivotU(unsigned int i, unsigned int j);

    void swapRows(unsigned int i, unsigned int j);
    void swapRows(unsigned int i, unsigned int j, unsigned int n);
    void swapCols(unsigned int i, unsigned int j);

    unsigned int getNrow();
    unsigned int getNcol();

    void setData(double d, unsigned int i, unsigned int j);

private:
    DataBlock(unsigned int nrow, unsigned int ncol);

    double **data;
    unsigned int nrow;
    unsigned int ncol;
};
