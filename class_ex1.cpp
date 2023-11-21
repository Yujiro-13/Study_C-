// ポリモーフィズム

#include <iostream>
#include <string>

class CHuman {
protected:
    std::string m_szName;
    int m_nHP;
    int m_nMaxHP;
    int m_nLevel;

public:
    CHuman(const std::string& name, int maxhp = 100);
    virtual ~CHuman();
    virtual int AddHP(int gain);
    virtual int Sleep(float condition);
};

CHuman::CHuman(const std::string& name, int maxhp) : m_szName(name), m_nHP(0), m_nMaxHP(maxhp), m_nLevel(1) {}

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

CFighter::CFighter(const std::string& name) : CHuman(name) {}

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
    CFighter fighter("Fighter");
    CMage mage("Mage");

    CInn inn;
    inn.Stay(&fighter);
    inn.Stay(&mage);

    

    return 0;
}
