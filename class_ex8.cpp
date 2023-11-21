#include <iostream>
#include <string>
#include <vector>
#include <memory>

class CHuman {
public:
    CHuman(int characterType, int maxhp = 100);
    virtual ~CHuman();
    virtual int AddHP(int gain);
    virtual int Sleep(float condition);

protected:
    std::string m_szName;
    int m_nHP;
    int m_nMaxHP;
    int m_nLevel;
    int m_nCharacterType;
};

CHuman::CHuman(int characterType, int maxhp) 
    : m_nHP(0), m_nMaxHP(maxhp), m_nLevel(1), m_nCharacterType(characterType) {
    // キャラクターの名前はサブクラスのコンストラクタで設定する
}

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
    CFighter(int characterType);
    virtual int Sleep(float condition) override;
};

CFighter::CFighter(int characterType) : CHuman(characterType) {
    m_szName = "Fighter";  // キャラクターの名前を設定
}

int CFighter::Sleep(float condition) {
    return AddHP(m_nLevel * 10);
}

class CMage : public CHuman {
public:
    CMage(int characterType);
    virtual int Sleep(float condition) override;
};

CMage::CMage(int characterType) : CHuman(characterType) {
    m_szName = "Mage";  // キャラクターの名前を設定
}

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
    std::cout << "Enter the number of characters: ";
    int numberOfCharacters;
    std::cin >> numberOfCharacters;

    // CFighterとCMageのインスタンスを格納するベクター
    std::vector<std::shared_ptr<CHuman>> characters;

    // キャラクターの数だけループ
    for (int i = 0; i < numberOfCharacters; ++i) {
        int characterType;
        std::cout << "Choose character type for character " << i + 1 << " (1 for Fighter, 2 for Mage): ";
        std::cin >> characterType;

        // 選択されたキャラクタータイプに基づいてCFighterまたはCMageのインスタンスを作成し、charactersベクターに追加
        if (characterType == 1) {
            characters.push_back(std::make_shared<CFighter>(characterType));
        } else if (characterType == 2) {
            characters.push_back(std::make_shared<CMage>(characterType));
        } else {
            std::cout << "Invalid character type." << std::endl;
            return 1;
        }
    }

    // キャラクターの一覧表示
    std::cout << "Character List:" << std::endl;
    for (int i = 0; i < characters.size(); ++i) {
        std::cout << i + 1 << ". " << characters[i]->Sleep(1.0) << std::endl;
    }

    // キャラクターの番号を選択
    std::cout << "Choose a character by entering its number: ";
    int selectedCharacter;
    std::cin >> selectedCharacter;

    // 選択された番号に対応するキャラクターのポインタを呼び出し
    if (selectedCharacter >= 1 && selectedCharacter <= characters.size()) {
        CInn inn;
        inn.Stay(characters[selectedCharacter - 1].get());
    } else {
        std::cout << "Invalid character number." << std::endl;
        return 1;
    }

    return 0;
}
