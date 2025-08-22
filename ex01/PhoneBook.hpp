#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

/**
 * @brief 電話帳管理クラス
 * 最大8件の連絡先を循環バッファで管理
 */
class PhoneBook {
private:
    static const int MAX_CONTACTS = 8;
    Contact contacts[MAX_CONTACTS];
    int contactCount;
    int nextIndex;

    void displayContactsTable() const;
    int getValidIndexFromUser(int contactCount) const;

public:
    /**
     * @brief デフォルトコンストラクタ
     */
    PhoneBook();

    /**
     * @brief 連絡先を追加
     * @param contact 追加する連絡先（const参照で効率化）
     */
    void addContact(const Contact& contact);

    /**
     * @brief 連絡先を検索・表示
     * @throws std::runtime_error 入力ストリームが閉じられた場合
     */
    void searchContacts() const;

    /**
     * @brief 現在の登録件数を取得
     * @return 登録されている連絡先数
     */
    int getContactCount() const;

    /**
     * @brief 電話帳が空かどうかを判定
     * @return 空の場合true
     */
    bool isEmpty() const;
};

#endif
