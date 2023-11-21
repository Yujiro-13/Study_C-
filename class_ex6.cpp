#include <iostream>
#include <string>
#include <memory>

struct HumanData {
    std::string name;
    int maxHP;
    int level;
};

class CHuman {
protected:
    std::string m_szName;
    int m_nHP;
    int m_nMaxHP;
    int m_nLevel;

public:
    CHuman(const HumanData& data);
    virtual ~CHuman();
    virtual int AddHP(int gain);
    virtual int Sleep(float condition);
};

CHuman::CHuman(const HumanData& data)
    : m_szName(data.name), m_nHP(0), m_nMaxHP(data.maxHP), m_nLevel(data.level) {}

CHuman::~CHuman() {}

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

class CFighter : public CHuman {
public:
    CFighter(const std::string& name);
    virtual int Sleep(float condition) override;
};

CFighter::CFighter(const std::string& name) : CHuman({name, 100, 1}) {}

int CFighter::Sleep(float condition) {
    return AddHP(m_nLevel * 10);
}

class CMage : public CHuman {
public:
    CMage(const std::string& name);
    virtual int Sleep(float condition) override;
};

CMage::CMage(const std::string& name) : CHuman({name, 100, 1}) {}

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
