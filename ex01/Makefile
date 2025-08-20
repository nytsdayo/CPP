# --- 変数の定義 ---

# C++コンパイラ
CXX = c++

# コンパイルオプション
CXXFLAGS = -std=c++98 -Wall -g

# 実行可能ファイル名
TARGET = phonebook

# すべてのソースファイル (.cpp) を列挙します。
# 自動で .cpp ファイルを探すようにしています。
SRCS = Contact.cpp main.cpp PhoneBook.cpp

# ソースファイル名からオブジェクトファイル名 (.o) を生成します。
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
