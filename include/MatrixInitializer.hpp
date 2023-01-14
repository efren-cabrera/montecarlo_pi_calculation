#pragma once
#include <Matrix.hpp>
#include <random>

namespace MonteCarloSimulation::Utils
{
    class MatrixInitializer
    {
    public:
        MatrixInitializer();
        Internal::Matrix<double> createRandomMatrix(int &nRows, int &nColumns);
        Internal::Matrix<double> createFillMatrix(int &nRows, int &nColumns, double constant);
    private:
        std::mt19937 m_engine;
        std::uniform_int_distribution<int> m_distribution{1, 100};
    };
}