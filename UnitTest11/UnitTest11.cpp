#include "pch.h"
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest10
{
    TEST_CLASS(UnitTest10)
    {
    public:

        double g(const double x) {
            if (abs(x) >= 1) {
                return sin(x) / (cos(x) + 2);
            }
            else {
                double S = 1; // Initial term for n=0
                double term = 1; // a0 = 1
                for (int n = 1; n <= 6; n++) {
                    term *= (x * x) / (2 * n * (2 * n - 1));
                    S += term;
                }
                return S;
            }
        }

        TEST_METHOD(TestGFunctionGreaterThanOne)
        {
            double x = 2.0;
            double expected = sin(x) / (cos(x) + 2);
            double result = g(x);
            Assert::AreEqual(expected, result, 0.0001);
        }

        TEST_METHOD(TestGFunctionLessThanOne)
        {
            double x = 0.5;
            double S = 1; // Initial term for n=0
            double term = 1; // a0 = 1
            for (int n = 1; n <= 6; n++) {
                term *= (x * x) / (2 * n * (2 * n - 1));
                S += term;
            }
            double expected = S;
            double result = g(x);
            Assert::AreEqual(expected, result, 0.0001);
        }
    };
}
