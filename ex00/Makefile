# --- 変数の定義 ---

CXX = c++

CXXFLAGS = -std=c++98 -Wall -Werror -Wextra

# 作成する実行可能ファイルの名前を指定します。
TARGET = megaphone

# コンパイル対象のソースファイル名を指定します。
SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)


all: $(TARGET)

# 実行可能ファイルを作成するルール
# $(OBJS) (すべての .o ファイル) に依存します。
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# .cpp ファイルから .o ファイルを作成するルール
# %.o: %.cpp という書き方で、すべての .cpp に対応するルールを一度に定義できます。
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<


clean:
	rm -f $(TARGET)

fclean:
	make -s clean
	rm -f $(TARGET)

re:
	make -s fclean
	make

# .PHONY は、同じ名前のファイルが実際に存在していても、
# このルールが正しく動作するようにするためのおまじないです。
.PHONY: all clean fclean re
