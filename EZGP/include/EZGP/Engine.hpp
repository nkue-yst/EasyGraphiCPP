/**
 * @author Yoshito Nakaue
 * @date 2020/11/02
 */

#pragma once
#include <chrono>
#include <thread>
#include <iostream>

namespace ezgp
{
    // システムを初期化
    void EZGP_Init(int win_width = 1280, int win_height = 720);

    // システムの更新
    bool Update();

    void EndLoop();

    /**
     * @brief 指定時間システムを停止する
     * @param duration 停止時間(秒)
     * @return なし
     */
    template<typename T>
    void Delay(T duration)
    {
        duration *= 1000000;
        std::this_thread::sleep_for(
            std::chrono::microseconds(static_cast<int>(duration))
        );
    }

    // システムを終了
    void EZGP_Quit();
}
