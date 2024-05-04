#include "pch.h"
#include "CppUnitTest.h"
#include "../LB_12.3_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestCreateList)
        {
            // Arrange
            int values[] = { 1, 2, 3 };
            int size = sizeof(values) / sizeof(values[0]);

            // Act
            Node* head = createList(values, size);

            // Assert
            Assert::IsNotNull(head);
            
            deleteList(head); // Звільняємо пам'ять
        }

    };
}