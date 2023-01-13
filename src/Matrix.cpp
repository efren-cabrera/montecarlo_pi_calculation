#include <vector>
#include <Matrix.hpp>

namespace MonteCarloSimulation::Internal
{
    template <typename T>
    Matrix<T>::Matrix(const std::vector<std::vector<T>> &matrix) : m_matrix{matrix}
    {
        size.first = matrix.size();
        size.second = matrix[0].size();
    };

    template <typename T>
    const T Matrix<T>::at(const int &row, const int &column) const
    {
        return m_matrix.at(row).at(column);
    }

    template <typename T>
    const std::vector<std::vector<T>> Matrix<T>::getData() const
    {
        return m_matrix;
    };

    template <typename T>
    const std::vector<T> Matrix<T>::getNeighbors(const int &row, const int &column) const
    {
        std::vector<int> rows{};
        std::vector<int> columns{};
        std::vector<T> out{};

        if (row > 0)
        {
            rows.push_back(row - 1);
        }
        rows.push_back(row);
        if (row < (size.first - 1))
        {
            rows.push_back(row + 1);
        }

        if (column > 0)
        {
            columns.push_back(column - 1);
        }
        columns.push_back(column);
        if (column < (size.second - 1))
        {
            columns.push_back(column + 1);
        }
        for (auto &r : rows)
        {
            for (auto &c : columns)
            {
                if (r == row && c == column)
                {
                    continue;
                }
                out.push_back(this->at(r, c));
            }
        }
        return out;
    }
}