/**
 * @author Yoshito Nakaue
 * @date 2020/08/27
 */

#include <EZGS.hpp>

int ezgs_main()
{
    if (System::CreateWindow())
        return 1;

    while (System::Update())
    {

    }

    System::EZGS_Quit();
    return 0;
}
