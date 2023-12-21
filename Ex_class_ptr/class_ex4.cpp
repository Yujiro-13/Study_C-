// 動的メモリの確保をスマートポインタで行うように

#include <iostream>
#include <string>
#include <memory>

class CHuman {
protected:  //  メンバ変数
    std::string m_szName;
    int m_nHP;
    int m_nMaxHP;
    int m_nLevel;

public: //  メンバ関数
    CHuman(const std::string& name, int maxhp = 100);   //  コンストラクタ
    virtual ~CHuman();  //  デストラクタ
    virtual int AddHP(int gain);    //  仮想関数
    virtual int Sleep(float condition);
};

CHuman::CHuman(const std::string& name, int maxhp) : m_szName(name), m_nHP(0), m_nMaxHP(maxhp), m_nLevel(1) {}  //  コンストラクタの実装、メンバ変数の初期化

CHuman::~CHuman() {}    //  デストラクタの実装

int CHuman::AddHP(int gain) {
    m_nHP += gain;
    if (m_nHP > m_nMaxHP) {
        m_nHP = m_nMaxHP;
    }
    std::cout << m_nHP << std::endl;
    return m_nHP;
}

int CHuman::Sleep(float condition) {
    return AddHP(static_cast<int>(m_nLevel * 10 * condition));
}

class CFighter : public CHuman {    //  CHumanの派生クラス CFighter
public:
    CFighter(const std::string& name);  //  CFighterのコンストラクタ
    virtual int Sleep(float condition) override;    //  CHumanの仮想関数Sleepをオーバーライド
};

CFighter::CFighter(const std::string& name) : CHuman(name) {}   //  CFighterのコンストラクタ 基底クラスCHumanのコンストラクタを呼び出している

int CFighter::Sleep(float condition) {
    return AddHP(m_nLevel * 10);
}

class CMage : public CHuman {
public:
    CMage(const std::string& name);
    virtual int Sleep(float condition) override;
};

CMage::CMage(const std::string& name) : CHuman(name) {}

int CMage::Sleep(float condition) {
    return AddHP(static_cast<int>(m_nLevel * 10 * (condition * 1.2)));
}

class CInn {
public:
    int Stay(CHuman* man);
};

int CInn::Stay(CHuman* man) {
    return man->Sleep(1.5);
}

int main() {
    std::string characterType;
    std::cout << "Choose character type (Fighter or Mage): ";
    std::cin >> characterType;

    std::shared_ptr<CHuman> character;

    if (characterType == "Fighter") {
        character = std::make_shared<CFighter>("Fighter");
    } else if (characterType == "Mage") {
        character = std::make_shared<CMage>("Mage");
    } else {
        std::cout << "Invalid character type." << std::endl;
        return 1;
    }

    CInn inn;
    inn.Stay(character.get());

    return 0;
}
