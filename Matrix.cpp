#include <utility>
#include <cstdlib>
#include "Matrix.h"
#include <vector>

static const double SMALL_NUMBER = 0.0001;

std::ostream &
operator<<(std::ostream &stream, const Matrix &m)
{
    if (m.M.empty())
    {
        stream << std::endl;
        stream << "Empty Matrix" << std::endl;
        stream << std::endl;
    }
    else
    {
        stream << std::endl;
        stream << "Basic:" << std::endl;
        stream << m.M;
    }

    if (!m.P.empty())
    {
        stream << std::endl;
        stream << "Permutation:" << std::endl;
        stream << m.P;
    }

    if (!m.L.empty())
    {
        stream << std::endl;
        stream << "Lower Triangular:" << std::endl;
        stream << m.L;
    }

    if (!m.U.empty())
    {
        stream << std::endl;
        stream << "Upper Triangular:" << std::endl;
        stream << m.U;
    }

    if (!m.R.empty())
    {
        stream << std::endl;
        stream << "rref:" << std::endl;
        stream << m.R;
    }
    return stream;
}

Matrix::Matrix()
    : M(), P(), L(), U(), R()
{
}

Matrix::Matrix(const char *str)
    : M(str), P(), L(), U(), R()
{
}

Matrix::Matrix(const DataBlock &d)
    : M(d), P(), L(), U(), R()
{
}

Matrix::Matrix(DataBlock &&d)
    : M(std::move(d)), P(), L(), U(), R()
{
}

Matrix::Matrix(const Matrix &other)
    : M(other.M), P(other.P), L(other.L), U(other.U), R(other.R)
{
}

Matrix::Matrix(Matrix &&other)
    : M(std::move(other.M)), P(std::move(other.P)), L(std::move(other.L)), U(std::move(other.U)), R(std::move(other.R))
{
}

Matrix &Matrix::operator=(const Matrix &other)
{
    M = other.M;
    P.clear();
    L.clear();
    U.clear();
    R.clear();
    return *this;
}

Matrix &Matrix::operator=(Matrix &&other)
{
    M = std::move(other.M);
    P.clear();
    L.clear();
    U.clear();
    R.clear();
    return *this;
}

Matrix::~Matrix()
{
}

DataBlock &Matrix::t()
{
    return M.t();
}

void Matrix::lu()
{
    unsigned int nrow = M.getNrow();
    unsigned int ncol = M.getNcol();

    if (nrow != ncol)
    {
        std::cout << "(Matrix::lu)Matrix must be square." << std::endl;
        throw 1;
    }

    std::pair<unsigned int, double> rowPivot;

    U = M;
    P = DataBlock::eye(M.getNrow());
    L = DataBlock::eye(M.getNrow());

    for (unsigned int j = 0; j < ncol - 1; j++)
    {
        rowPivot = U.maxPivotRow(j, j);

        if (rowPivot.second < SMALL_NUMBER)
            break;

        if (j != rowPivot.first)
        {
            P.swapCols(j, rowPivot.first);
            U.swapRows(j, rowPivot.first);
            L.swapRows(j, rowPivot.first, j);
        }
        for (unsigned int i = j + 1; i < nrow; i++)
        {
            double e = U.elim(i, j, j);
            L.setData(e, i, j);
        }
    }
}

void Matrix::rref()
{
    R = M;

    unsigned int nrow = R.getNrow();
    unsigned int ncol = R.getNcol();
    unsigned int pivotR = 0, pivotC = 0;

    std::pair<unsigned int, double> rowPivot;

    std::vector<std::pair<unsigned int, unsigned int>> pivotPositions;

    for (unsigned int j = 0; j < nrow; j++)
    {
        rowPivot = R.maxPivotRow(pivotR, j);
        if (rowPivot.second < SMALL_NUMBER)
        {
            continue;
        }

        if (pivotR != rowPivot.first)
        {
            R.swapRows(pivotR, rowPivot.first);
        }
        for (unsigned int i = pivotR + 1; i < nrow; i++)
        {
            double e = R.elim(i, pivotR, j);
        }
        pivotPositions.push_back(std::make_pair(pivotR, j));
        pivotR++;
        pivotC = j;
    }

    // std::cout << R;

    std::pair<unsigned int, unsigned int> currentPosition = pivotPositions.back();
    unsigned int lastJ;
    pivotPositions.pop_back();

    R.pivotU(currentPosition.first, currentPosition.second);
    R.backElim(currentPosition.first, currentPosition.second);
    // std::cout << R;

    while (!pivotPositions.empty())
    {
        lastJ = currentPosition.second;

        currentPosition = pivotPositions.back();
        pivotPositions.pop_back();

        while (currentPosition.second < --lastJ)
        {
            R.pivotU(currentPosition.first, lastJ);
            R.backElim(currentPosition.first, lastJ);
        }

        R.pivotU(currentPosition.first, currentPosition.second);
        R.backElim(currentPosition.first, currentPosition.second);
        // std::cout << R;
    }
}

DataBlock &Matrix::operator+(double d)
{
    return M + d;
}

DataBlock &Matrix::operator-(double d)
{
    return M - d;
}

DataBlock &Matrix::operator*(double d)
{
    return M * d;
}

DataBlock &Matrix::operator/(double d)
{
    return M / d;
}

DataBlock &Matrix::operator+(const Matrix &other)
{
    return M + other.M;
}

DataBlock &Matrix::operator-(const Matrix &other)
{
    return M - other.M;
}

DataBlock &Matrix::operator*(const Matrix &other)
{
    return M * other.M;
}