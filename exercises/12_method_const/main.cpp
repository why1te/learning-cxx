#include "../exercise.h"

// READ: 有 cv 限定符的成员函数 <https://zh.cppreference.com/w/cpp/language/member_functions>

struct Fibonacci {
    int numbers[11];
    // TODO: 修改方法签名和实现，使测试通过
    // const 成员函数：隐含函数参数，相当于 get(Fibonacci* this, int i)并承诺不会修改这个对象
    int get(int i) const {
        return numbers[i];
    }
    // 非 const 成员函数：返回的是数组元素本身
    int& get(int i) {
        return numbers[i];
    }
};

int main(int argc, char **argv) {
    // * 编译器计算，常量
    Fibonacci constexpr FIB{{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55}};
    ASSERT(FIB.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << FIB.get(10) << std::endl;
    Fibonacci FIB2{{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55}};
    ASSERT(FIB2.get(10) == 55, "fibonacci(10) should be 55");
    return 0;
}
