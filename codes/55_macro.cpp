#include <iostream>

/*
����Ҫ���ڵ����ã���debug�汾����־��Ϣ��ӡ��release�汾��ȡ����ӡ
*/
#define PR_DEBUG 0 //���ȿ���
#define PR_RELEASE

// #ifdef PR_RELEASE
// #define LOG(x) std::cout << x << std::endl
// #else
// #define LOG(x)
// #endif

//���ȿ���
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


