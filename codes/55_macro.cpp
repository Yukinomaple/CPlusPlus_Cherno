#include <iostream>

/*
宏主要用于调试用，如debug版本的日志消息打印，release版本中取消打印
*/
#define PR_DEBUG 0 //优先考虑
#define PR_RELEASE

// #ifdef PR_RELEASE
// #define LOG(x) std::cout << x << std::endl
// #else
// #define LOG(x)
// #endif

//优先考虑
#if PR_DEBUG == 1
#define LOG(x) std::cout << x << std::endl
#elif defined(PR_RELEASE)
#define LOG(x) std::cout << "Defined:PR_RELEASE" << std::endl
#endif





int main()
{
    LOG("hello");
    LOG(111);


}


