/**
 * @file Scene.hpp
 * @brief シーン設定関連
 * @author Yoshito Nakaue
 * @date 2020/09/10
 */

#pragma once
#include <cstdint>

namespace ezgp
{
    namespace Scene
    {
        /**
         * @brief 背景色を設定
         * @param color 背景色
         * @return なし
         */
        void SetBackgroundColor(struct Color color);
    }
}
