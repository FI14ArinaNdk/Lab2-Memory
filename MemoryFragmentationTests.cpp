#include "pch.h"
#include <iostream>
#include <gtest/gtest.h>
class Memory
{
public:
    static int Memoryy()
    {
        const int chunkSize = 1024 * 1024;
        char* memory[100];

        for (int i = 0; i < 100; ++i) {
            memory[i] = new char[chunkSize];
            std::cout << "Allocated chunk " << i << " of " << chunkSize / 1024 ;
        }

        for (int i = 0; i < 100; i += 2) {
            delete[] memory[i];
            std::cout << "Deallocated chunk " << i << "\n";
        }

        for (int i = 1; i < 100; i += 2) {
            memory[i] = new char[chunkSize];
            std::cout << "Allocated chunk " << i << " of " << chunkSize / 1024;
        }

        return 0;
    }
};


TEST(MemoryTests, ChunkAllocationTest) {
    const int chunkSize = 1024 * 1024;
    const int numChunks = 100;
    char* memory[numChunks];

    for (int i = 0; i < numChunks; ++i) {
        memory[i] = new char[chunkSize];
    }


    for (int i = 0; i < numChunks; i += 2) {
        delete[] memory[i];
        memory[i] = nullptr;

    }


    for (int i = 0; i < numChunks; i += 2) {
        memory[i] = new (std::nothrow) char[chunkSize * chunkSize];
        EXPECT_TRUE(memory[i] == nullptr);
        if (memory[i] == nullptr)
        {
            EXPECT_TRUE(true);
        }
        else {
            EXPECT_TRUE(false);
        }
    }


    for (int i = 0; i < numChunks; i++) {
        delete[] memory[i];
    }
}