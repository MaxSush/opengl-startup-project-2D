#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <memory>

#include "ResourceManager.h"
#include "Utility/VAO.h"
#include "Utility/VBO.h"
#include "Utility/EBO.h"
#include "SpriteRenderer.h"

namespace Breaker
{
    enum class GameState
    {
        GAME_MENU,
        GAME_ACTIVE,
        GAME_WIN,
        GAME_EXIT
    };

    class Game
    {
    public:
        Game();
        ~Game() = default;

        void Init();
        void Update(float dt);
        void Render();

    private:
        GameState state = GameState::GAME_MENU;

        std::unique_ptr<SpriteRenderer> render;
    };
}