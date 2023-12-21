//外部ポインタ構造体変数からクラスのメンバ変数を初期化

#include <iostream>
#include <string>

typedef struct  {
    std::string name;
    int maxHP;
}HumanData;

class CHuman {
protected:
    std::string m_szName;
    int m_nHP;
    int m_nMaxHP;
    int m_nLevel;

public:
    // 外部ポインタ構造体変数からの初期化を行うコンストラクタ
    CHuman(const HumanData* pData);
    virtual ~CHuman();
    virtual int AddHP(int gain);
    virtual int Sleep(float condition);
};

// コンストラクタの実装
CHuman::CHuman(const HumanData* pData) : m_szName(pData->name), m_nHP(0), m_nMaxHP(pData->maxHP), m_nLevel(1) {}

// 他のメンバ関数の実装は省略

int main() {
    // 外部ポインタ構造体変数を用意して初期化
    HumanData data = {"John Doe", 150};

    // CHumanオブジェクトを作成し、外部ポインタ構造体変数からの初期化を行う
    CHuman human(&data);

    // ここでhumanオブジェクトを使用するなどの処理を追加

    return 0;
}
