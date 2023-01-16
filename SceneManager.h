#pragma once

class SceneManager final {
private:
  //コンストラクタをprivateにする
  SceneManager() = default;
  //デストラクタをprivateにする
  ~SceneManager() = default;
public:
  //コピーコンストラクタを無効にする
  SceneManager(const SceneManager& obj) = delete;
  //代入演算子を無効にする
  SceneManager& operator = (const SceneManager& obj) = delete;

  static SceneManager* GetInstance();
};
