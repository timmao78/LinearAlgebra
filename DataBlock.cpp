#include <cstdlib>
#include <vector>
#include "DataBlock.h"

std::ostream &operator<<(std::ostream &stream, const DataBlock &d)
{
    if (d.data == nullptr)
    {
        stream << std::endl;
        stream << "Empty Data Block" << std::endl;
        stream << std::endl;
        return stream;
    }

    stream << std::fixed << std::setprecision(4) << std::right << std::endl;
    stream << std::setw(11) << " ";

    for (unsigned int j = 0; j < d.ncol; j++)
        stream << std::setw(5) << "[," << std::setw(4) << j << "]";
    stream << std::endl;

    for (unsigned int i = 0; i < d.nrow; i++)
    {
        stream << std::setw(4) << "[" << std::setw(5) << i << std::setw(2) << std::left << ",]";
        for (unsigned int j = 0; j < d.ncol; j++)
            stream << std::setw(10) << std::right << d.data[i][j];
        if (i == d.nrow - 1)
            stream << std::setw(8) << d.nrow << "x" << d.ncol;
        stream << std::endl;
    }
    stream << std::endl;
    return stream;
}

DataBlock::DataBlock()
    : nrow(0), ncol(0), data(nullptr)
{
#if DEBUG == 1
    // std::cout << "(Default Constructor) No memory allocated, no data copied." << std::endl;
#endif
}

DataBlock::DataBlock(const char *str)
{
    nrow = 0, ncol = 0;
    unsigned int ncolFirst = 0;

    std::vector<double> v;
    std::string eachNumber;

    int it = 0;
    while (str[it] != '\0')
    {
        if (str[it] == ' ' || str[it] == '\t' || str[it] == ';')
        {
            if (!eachNumber.empty())
            {
                v.push_back(std::stod(eachNumber));
                eachNumber.clear();
                ncol++;
            }
            if (str[it] == ';')
            {
                if (nrow == 0)
                    ncolFirst = ncol;
                else if (ncol != ncolFirst)
                {
                    std::cout << "(DataBlock::DataBlock) row " << ++nrow << " has differenct columns!" << std::endl;
                    throw 1;
                }
                nrow++;
                ncol = 0;
            }
        }
        else
        {
            eachNumber.push_back(str[it]);
        }
        it++;
    }
    if (!eachNumber.empty())
    {
        v.push_back(std::stod(eachNumber));
        eachNumber.clear();
        ncol++;
        nrow++;
    }
    else
    {
        nrow++;
    }

    if (nrow != 1 && ncol != ncolFirst)
    {
        std::cout << "(DataBlock::DataBlock) last row has differenct columns!" << std::endl;
        throw 1;
    }

    data = new double *[nrow];
    for (unsigned int i = 0; i < nrow; i++)
        data[i] = new double[ncol];

#if DEBUG == 1
    std::cout << "(Constructor)Allocating " << nrow * ncol * sizeof(double) << " bytes memory @" << data << "... done." << std::endl;
#endif

    for (unsigned int i = 0; i < nrow; i++)
        for (unsigned int j = 0; j < ncol; j++)
            data[i][j] = v[i * ncol + j];
}

DataBlock::DataBlock(const DataBlock &other)
    : nrow(other.nrow), ncol(other.ncol)
{
    if (other.empty())
    {
        data = nullptr;
        std::cout << "(Copy Constructor)Source DataBlock object is empty. No memory allocated, no data copied." << std::endl;
    }
    else
    {
        data = new double *[nrow];
        for (unsigned int i = 0; i < nrow; i++)
            data[i] = new double[ncol];

#if DEBUG == 1
        std::cout << "(Copy Constructor)Allocating " << nrow * ncol * sizeof(double) << " bytes memory @" << data << "... done." << std::endl;
#endif

        for (unsigned int i = 0; i < nrow; i++)
            for (unsigned int j = 0; j < ncol; j++)
                data[i][j] = other.data[i][j];
#if DEBUG == 1
        std::cout << "(Copy Constructor)Copying data... done." << std::endl;
#endif
    }
}

DataBlock::DataBlock(DataBlock &&other)
    : nrow(other.nrow), ncol(other.ncol), data(other.data)
{
#if DEBUG == 1
    std::cout << "(Move Constructor) No memory allocated, no data copied." << std::endl;
#endif
    other.nrow = 0;
    other.ncol = 0;
    other.data = nullptr;
}

DataBlock::DataBlock(DataBlock *pD)
    : nrow(pD->nrow), ncol(pD->ncol), data(pD->data)
{
#if DEBUG == 1
    std::cout << "(Pointer Constructor) No memory allocated, no data copied." << std::endl;
#endif
    pD->nrow = 0;
    pD->ncol = 0;
    pD->data = nullptr;
}

DataBlock &DataBlock::operator=(const DataBlock &other)
{
    if (this != &other)
    {

#if DEBUG == 1
        std::cout << "(Assignment Operator)Freeing " << nrow * ncol * sizeof(double) << " bytes memory @" << data << "... done." << std::endl;
#endif
        for (unsigned int i = 0; i < nrow; i++)
            delete[] data[i];
        delete[] data;

        if (other.empty())
        {
            nrow = 0;
            ncol = 0;
            data = nullptr;
            std::cout << "(Copy Constructor)Source DataBlock object is empty. No memory allocated, no data copied." << std::endl;
        }
        else
        {
            nrow = other.nrow;
            ncol = other.ncol;

            data = new double *[nrow];
            for (unsigned int i = 0; i < nrow; i++)
                data[i] = new double[ncol];

#if DEBUG == 1
            std::cout << "(Assignment Operator)Allocating " << nrow * ncol * sizeof(double) << " bytes memory @" << data << "... done." << std::endl;
#endif

            for (unsigned int i = 0; i < nrow; i++)
                for (unsigned int j = 0; j < ncol; j++)
                    data[i][j] = other.data[i][j];
#if DEBUG == 1
            std::cout << "(Assignment Operator)Copying data... done." << std::endl;
#endif
        }
    }
    return *this;
}

DataBlock &DataBlock::operator=(DataBlock &&other)
{
    if (this != &other)
    {
#if DEBUG == 1
        std::cout << "(Move Assignment Operator)Freeing " << nrow * ncol * sizeof(double) << " bytes memory @" << data << "... done." << std::endl;
#endif
        for (unsigned int i = 0; i < nrow; i++)
            delete[] data[i];
        delete[] data;

        nrow = other.nrow;
        ncol = other.ncol;
        data = other.data;

#if DEBUG == 1
        std::cout << "(Move Assignment Operator) No memory allocated, no data copied." << std::endl;
#endif
        other.nrow = 0;
        other.ncol = 0;
        other.data = nullptr;
    }
    return *this;
}

DataBlock &DataBlock::operator=(DataBlock *pD)
{
    if (this != pD)
    {
#if DEBUG == 1
        std::cout << "(Pointer Assignment Operator)Freeing " << nrow * ncol * sizeof(double) << " bytes memory @" << data << "... done." << std::endl;
#endif
        for (unsigned int i = 0; i < nrow; i++)
            delete[] data[i];
        delete[] data;

        nrow = pD->nrow;
        ncol = pD->ncol;
        data = pD->data;

#if DEBUG == 1
        std::cout << "(Pointer Assignment Operator) No memory allocated, no data copied." << std::endl;
#endif
        pD->nrow = 0;
        pD->ncol = 0;
        pD->data = nullptr;
    }
    return *this;
}

DataBlock::~DataBlock()
{
    if (data != nullptr)
    {
#if DEBUG == 1
        std::cout << "(destructor)Freeing " << nrow * ncol * sizeof(double) << " bytes memory @" << data << "... done." << std::endl;
#endif
        for (unsigned int i = 0; i < nrow; i++)
            delete[] data[i];
        delete[] data;
    }
}

void DataBlock::resetI()
{
    if (data == nullptr)
    {
        std::cout << "(DataBlock::resetI) Can not reset an empty DataBlock." << std::endl;
        throw 1;
    }
    for (unsigned int i = 0; i < nrow; i++)
        for (unsigned int j = 0; j < ncol; j++)
            if (i == j)
                data[i][j] = 1.0;
            else
                data[i][j] = 0.0;
}

bool DataBlock::empty() const
{
    return data == nullptr;
}

DataBlock::DataBlock(unsigned int nrow, unsigned int ncol)
    : nrow(nrow), ncol(ncol)
{
    data = new double *[nrow];
    for (unsigned int i = 0; i < nrow; i++)
        data[i] = new double[ncol];
#if DEBUG == 1
    std::cout << "(Private Constructor)Allocating " << nrow * ncol * sizeof(double) << " bytes memory @" << data << "... done." << std::endl;
#endif
}

DataBlock *DataBlock::eye(unsigned int n)
{
    DataBlock *rslt = new DataBlock(n, n);

    for (unsigned int i = 0; i < n; i++)
        for (unsigned int j = 0; j < n; j++)
            if (i == j)
                rslt->data[i][j] = 1.0;
            else
                rslt->data[i][j] = 0.0;

    return rslt;
}

DataBlock *DataBlock::t()
{
    DataBlock *rslt = new DataBlock(ncol, nrow);

    for (unsigned int i = 0; i < ncol; i++)
        for (unsigned int j = 0; j < nrow; j++)
            rslt->data[i][j] = data[j][i];

    return rslt;
}

std::pair<unsigned int, double> DataBlock::maxPivotRow(unsigned int currentRow, unsigned int currentCol)
{
    std::pair<unsigned int, double> rslt;

    unsigned int rsltRow = currentRow;

    double maxPivot = std::abs((long)data[currentRow][currentCol]);

    for (unsigned int i = currentRow + 1; i < nrow; i++)
    {
        if (std::abs((long)data[i][currentCol]) > maxPivot)
        {
            maxPivot = abs((long)data[i][currentCol]);
            rsltRow = i;
        }
    }

    rslt = std::make_pair(rsltRow, maxPivot);
    return rslt;
}

double DataBlock::elim(unsigned int r1, unsigned int r2, unsigned int j)
{
    double e = data[r1][j] / data[r2][j];
    for (unsigned int k = 0; k < ncol; k++)
        data[r1][k] -= data[r2][k] * e;
    return e;
}

void DataBlock::backElim(unsigned int i, unsigned int j)
{
    for (int r = i - 1; r >= 0; r--)
    {
        double e = data[r][j];
        for (int k = j; k < ncol; k++)
            data[r][k] -= e * data[i][k];
    }
}

void DataBlock::pivotU(unsigned int i, unsigned int j)
{
    double r = data[i][j];
    for (unsigned int k = j; k < ncol; k++)
        data[i][k] = data[i][k] / r;
}

void DataBlock::swapRows(unsigned int i, unsigned int j)
{
    double tmp[ncol];

    for (int k = 0; k < ncol; k++)
    {
        tmp[k] = data[i][k];
    }
    for (int k = 0; k < ncol; k++)
    {
        data[i][k] = data[j][k];
    }
    for (int k = 0; k < ncol; k++)
    {
        data[j][k] = tmp[k];
    }
}

void DataBlock::swapRows(unsigned int i, unsigned int j, unsigned int n)
{
    double tmp[ncol];

    for (int k = 0; k < n; k++)
    {
        tmp[k] = data[i][k];
    }
    for (int k = 0; k < n; k++)
    {
        data[i][k] = data[j][k];
    }
    for (int k = 0; k < n; k++)
    {
        data[j][k] = tmp[k];
    }
}

void DataBlock::swapCols(unsigned int i, unsigned int j)
{
    double tmp[nrow];

    for (int k = 0; k < nrow; k++)
    {
        tmp[k] = data[k][i];
    }
    for (int k = 0; k < nrow; k++)
    {
        data[k][i] = data[k][j];
    }
    for (int k = 0; k < nrow; k++)
    {
        data[k][j] = tmp[k];
    }
}

unsigned int DataBlock::getNrow()
{
    return nrow;
}
unsigned int DataBlock::getNcol()
{
    return ncol;
}

void DataBlock::setData(double d, unsigned int i, unsigned int j)
{
    data[i][j] = d;
}