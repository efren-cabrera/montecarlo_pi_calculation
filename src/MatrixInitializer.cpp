#include <vector>
#include <Matrix.hpp>
#include <random>
#include <MatrixInitializer.hpp>

namespace MonteCarloSimulation::Utils
{
    MatrixInitializer::MatrixInitializer()
    {
        std::random_device seeder;
        const auto seed{seeder.entropy() ? seeder() : time(nullptr)};
        m_engine = std::mt19937(seed);
    }
    Internal::Matrix<double> MatrixInitializer::createRandomMatrix(int &nRows, int &nColumns)
    {
        std::vector<std::vector<double>> out;
        for (int r{0}; r < nRows; r++)
        {
            out.push_back(std::vector<double>{});
            for (int c{0}; c < nColumns; c++)
            {
                auto number = m_distribution(m_engine);
                out[r].push_back(number);
            }
        }
        return Internal::Matrix<double>(out);
    }
    Internal::Matrix<double> createFillMatrix(int &nRows, int &nColumns, double constant)
    {
        std::vector<std::vector<double>> out;
        for (int c{0}; c < nColumns; c++)
        {
            out.push_back(std::vector<double>(nColumns, constant));
        }
        return Internal::Matrix<double>(out);
    }
}