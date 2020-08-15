/**
 * @file Actor.hpp
 * @brief アクタークラス
 * @author Yoshito Nakaue
 * @date 2020/08/15
 */

#pragma once
#include <EZGS/Math.hpp>
#include <vector>

namespace ezgs
{		
    /**
     * @brief アクターの状態クラス
     */
    enum class State
    {
        EPause,
        EActive,
        EDead,
    };

    /**
     * @brief アクター基底クラス
     */
    class Actor
    {
    public:
        /**
         * @brief システムにアクターを追加
         */
        Actor();

        /**
         * @brief システムからアクターを削除
         */
        virtual ~Actor();

        /**
         * @brief アクター全体の更新
         * @return なし
         */
        void Update(float dt);

        /**
         * @brief アクター自身の更新
         * @return なし
         */
        virtual void UpdateActor(float dt);

        /**
         * @brief 所有コンポーネントの更新
         * @return なし
         */
        void UpdateComponents(float dt);

        /**
         * @brief アクターにコンポーネントを追加
         * @return なし
         */
        void AddComponent(class Component* component);

        /**
         * @brief アクターからコンポーネントを削除
         * @return なし
         */
        void RemoveComponent(class Component* component);

        /**
         * @brief ワールド座標を計算
         * @return なし
         */
        void ComputeWorldTransform();

        /* Setter */
        void SetState(State state) { state_ = state; }
        void SetPosition(const Vec2& pos) { position_ = pos; need_recompute_world_transform_ = true; }
        void SetRotation(const float rot) { rotation_ = rot; need_recompute_world_transform_ = true; }
        void SetScale(const float scl)    { scale_    = scl; need_recompute_world_transform_ = true; }

        /* Getter */
        const State GetState() const { return state_; }
        const Mat4& GetWorldTransform() const { return world_translation_; }
        const Vec2& GetPosition() const { return position_; }
        const float GetRotation() const { return rotation_; }
        const float GetScale() const { return scale_; }

        /**
         * @brief 前方方向を計算
         * @return 前方方向を示すベクトル
         */
        Vec2 GetForward() const { return Vec2(std::cos(rotation_), std::sin(rotation_)); }

    private:
        // アクターの状態
        State state_;

        // ワールド座標
        Mat4 world_translation_;

        // ワールド座標の再計算が必要か否か
        bool need_recompute_world_transform_;

        // 座標
        Vec2 position_;

        // 回転
        float rotation_;

        // 大きさ
        float scale_;

        // 所有しているコンポーネント配列（更新優先度順）
        std::vector<class Component*> components_;
    };
}
