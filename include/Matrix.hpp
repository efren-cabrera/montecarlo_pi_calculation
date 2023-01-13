#pragma once
#include <vector>
#include <utility>

namespace MonteCarloSimulation::Internal
{
    template <typename T>
    class Matrix
    {
    public:
        Matrix(const std::vector<std::vector<T>> &matrix);
        const T at(const int &row, const int &column) const;
        const std::vector<std::vector<T>> getData() const;
        const std::vector<T> getNeighbors(const int &row, const int &column) const;
        const std::pair<int, int> getSize() const { return size; }

    private:
        std::vector<std::vector<T>> m_matrix;
        std::pair<int, int> size;
    };
}