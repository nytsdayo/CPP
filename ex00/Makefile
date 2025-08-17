# --- 変数の定義 ---

# C++コンパイラを指定します。g++ を使います。
CXX = c++

# コンパイルオプションを指定します。
# -std=c++98 : C++98規格でコンパイルします。
# -Wall      : 有用な警告をすべて表示します。
# -g         : デバッグ情報を付加します。
CXXFLAGS = -std=c++98 -Wall -Werror -Wextra -g

# 作成する実行可能ファイルの名前を指定します。
TARGET = megaphone

# コンパイル対象のソースファイル名を指定します。
SRCS = megaphone.cpp


all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $<


clean:
	rm -f $(TARGET)

# .PHONY は、`clean` という名前のファイルが実際に存在していても、
# このルールが正しく動作するようにするためのおまじないです。
.PHONY: all clean
