# --- 変数の定義 ---

# C++コンパイラ
CXX = c++

# コンパイルオプション（厳格なエラー検知）
# -pedantic: 標準に厳密に従う
# -std=c++98: C++98標準を使用
# -Wall: すべての警告を有効にする
# -Wextra: 追加の警告を有効にする
# -Werror: 警告をエラーとして扱う
# -g: デバッグ情報を生成する
CXXFLAGS = -std=c++98 \
           -Wall \
           -Wextra \
           -Werror \
           -pedantic \
           -g \

# 実行可能ファイル名
TARGET = phonebook

# ソースファイル
SRCS = Contact.cpp main.cpp PhoneBook.cpp

# オブジェクトファイル
OBJS = $(SRCS:.cpp=.o)

# --- ルールの定義 ---

# デフォルトルール: 実行可能ファイルを作成します。
all: $(TARGET)

# 実行可能ファイルを作成するルール
# $(OBJS) (すべての .o ファイル) に依存します。
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# .cpp ファイルから .o ファイルを作成するルール
# %.o: %.cpp という書き方で、すべての .cpp に対応するルールを一度に定義できます。
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# クリーンルール: 生成されたファイルを削除します。
clean:
	rm -f $(OBJS)

fclean:
	make -s clean
	rm -f $(TARGET)
re:
	make -s fclean
	make
# .PHONY の設定
.PHONY: all clean fclean re
