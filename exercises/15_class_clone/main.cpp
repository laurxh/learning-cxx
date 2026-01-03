#include "../exercise.h"

class DynFibonacci {
    size_t *cache;
    int capacity; // 💡 必须添加这个成员，否则拷贝构造函数不知道要申请多大的空间
    int cached;

public:
    // 构造函数：初始化 capacity
    DynFibonacci(int capacity) : cache(new size_t[capacity]), capacity(capacity), cached(2) {
        if (capacity > 0) cache[0] = 0;
        if (capacity > 1) cache[1] = 1;
    }

    // 拷贝构造函数：实现深拷贝
    DynFibonacci(DynFibonacci const &other) : 
        cache(new size_t[other.capacity]), // 使用 other 的 capacity
        capacity(other.capacity), 
        cached(other.cached) 
    {
        // 复制数据
        for (int i = 0; i < cached; ++i) {
            cache[i] = other.cache[i];
        }
    }

    // 析构函数：修复 delete[]
    ~DynFibonacci() {
        delete[] cache; // 💡 必须使用 delete[] 释放 new[] 申请的数组
    }

    // 缓存优化计算
    size_t get(int i) {
        for (; cached <= i; ++cached) {
            cache[cached] = cache[cached - 1] + cache[cached - 2];
        }
        return cache[i];
    }

    // Const 版本
    size_t get(int i) const {
        if (i < cached) {
            return cache[i];
        }
        ASSERT(false, "i out of range");
    }
};

int main(int argc, char **argv) {
    DynFibonacci fib(12);
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    DynFibonacci const fib_ = fib;
    ASSERT(fib_.get(10) == fib.get(10), "Object cloned");
    return 0;
}
