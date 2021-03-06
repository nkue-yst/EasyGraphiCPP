/**
 * @file Circle.hpp
 * @brief 円関連
 * @author Yoshito Nakaue
 * @date 2020/10/31
 */

#pragma once
#include <EZGP/Color.hpp>

namespace ezgp
{
    class Circle
    {
    public:
        // 正円
        Circle(int x, int y, int rad);

        /**
         * @brief サイズ・座標を指定して円を描画する
         * @param x x座標
         * @param y y座標
         * @param rad 半径
         * @param color 塗りつぶす色
         * @return なし
         */
        static void draw(int x, int y, int rad, Color color = Color(0, 0, 0))
        {
            draw(x, y, rad, rad, color);
        }

        /**
         * @brief サイズ・座標を指定して円の枠を描画する
         * @param x x座標
         * @param y y座標
         * @param rad 半径
         * @param color 色
         * @return なし
         */
        static void drawFrame(int x, int y, int rad, Color color = Color(0, 0, 0))
        {
            drawFrame(x, y, rad, rad, color);
        }


        // 楕円
        Circle(int x, int y, int rad_x, int rad_y);

        /**
         * @brief サイズ・座標を指定して楕円を描画する
         * @param x x座標
         * @param y y座標
         * @param rad_x x方向の半径
         * @param rad_y y方向の半径
         * @param color 塗りつぶす色
         * @return なし
         */
        static void draw(int x, int y, int rad_x, int rad_y, Color color = Color(0, 0, 0));

        /**
         * @brief サイズ・座標を指定して楕円の枠を描画する
         * @param x x座標
         * @param y y座標
         * @param rad_x x方向の半径
         * @param rad_y y方向の半径
         * @param color 色
         * @return なし
         */
        static void drawFrame(int x, int y, int rad_x, int rad_y, Color color = Color(0, 0, 0));


        /* 正円・楕円共通関数 */

        /**
         * @brief 座標を指定して円を描画する
         * @param x x座標
         * @param y y座標
         * @param color 塗りつぶす色
         * @return なし
         */
        void draw(Color color = Color(0, 0, 0))
        {
            draw(x_, y_, rad_x_, rad_y_, color);
        }

        /**
         * @brief 座標を指定して楕円の枠を描画する
         * @param x x座標
         * @param y y座標
         * @param color 塗りつぶす色
         * @return なし
         */
        void drawFrame(Color color = Color(0, 0, 0))
        {
            drawFrame(x_, y_, rad_x_, rad_y_, color);
        }

        /**
         * @brief マウスが重なっているかを判定
         * @return 重なっていればtrue, 重なっていなければfalse
         */
        bool mouseOver();
        
    private:
        int x_;
        int y_;
        int rad_x_;
        int rad_y_;
    };
}
