#include "pch.h"
#include <iostream>
#include "gtest/gtest.h"
class Class
{
public:
    Class()
    {
        std::cout << "MyClass created" << std::endl;
    }

    ~Class()
    {
        std::cout << "MyClass destroyed" << std::endl;
    }
    int getValue() const {
        return value;
    }

    void setValue(int val) {
        value = val;
    }

private:
    int value;
};
TEST(ObjectCreationTest, StackObjectCreat) {
    Class stackObject;
    ASSERT_TRUE(true);
    stackObject.setValue(24);
    ASSERT_EQ(stackObject.getValue(), 24);
}

TEST(ObjectCreationTest, HeapObjectCreat) {
    Class* heapObject = new Class();
    ASSERT_TRUE(heapObject != nullptr);
    heapObject->setValue(100);
    ASSERT_EQ(heapObject->getValue(), 100);
    delete heapObject;
}
TEST(Test, StackObjectCreat)
{
    Class stackObject;
}

TEST(Test, HeapObjectCreat)
{
    Class* heapObject = new Class();
    delete heapObject;

}