#pragma once

#define PURE =0

#define KEY_CHECK(KEY) (InputManager::GetKeyState(KEY)==eKeyState::PRESSED)
#define KEY_DOWN(KEY) (InputManager::GetKeyState(KEY)==eKeyState::DOWN)
#define KEY_UP(KEY) (InputManager::GetKeyState(KEY)==eKeyState::UP)