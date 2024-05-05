# 定義する変数
CC=gcc
CFLAGS=-Wall
TARGET=mygrep
SOURCE=mygrep.c

# デフォルトターゲット
all: $(TARGET)

# 実行ファイルのビルド
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)

# 'make clean' で実行ファイルと.oファイルを削除
clean:
	rm -f $(TARGET) *.o

# .PHONYを使用して、実際のファイルではなくコマンド名としてのターゲットを明示
.PHONY: all clean
