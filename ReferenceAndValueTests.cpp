#include "pch.h"
#include <iostream>
#include <gtest/gtest.h>

class ValueClass {
public:
    int value;

    ValueClass(int val) : value(val) {}
};

class ReferenceClass {
public:
    int& ref;

    ReferenceClass(int& val) : ref(val) {}
};

TEST(PassByValueReferenceTests, ValueClassPassByValueTest) {
    ValueClass obj1(10);
    ValueClass obj2 = obj1;  

    obj2.value = 20;  

    EXPECT_EQ(obj1.value, 10);
    EXPECT_EQ(obj2.value, 20);
}

TEST(PassByValueReferenceTests, ReferenceClassPassByReferenceTest) {
    int value = 10;
    ReferenceClass obj1(value);
    ReferenceClass obj2 = obj1;  

    obj2.ref = 20;  

    EXPECT_EQ(obj1.ref, 20);
    EXPECT_EQ(obj2.ref, 20);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}