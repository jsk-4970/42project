*This project has been created as part of the 42 curriculum by jyamada.*

# get_next_line

## Description

ファイルディスクリプタから1行ずつテキストを読み込む関数。`read()`を繰り返し呼び出しても、毎回次の行を正しく返す。標準入力やファイルからの逐次読み込みに使える。

## Instructions

### コンパイル

```bash
cc -Wall -Wextra -Werror -D BUFSIZE=42 get_next_line.c get_next_line_utils.c your_main.c
```

`BUFSIZE`はコンパイル時に指定するバッファサイズ。未指定の場合はデフォルト42。

### 使用例

```c
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Algorithm

静的変数`stash`を使い、読み込み済みだが未返却のデータを保持する。

1. `ft_getfile`: `read()`でファイルを読み込み、`stash`に追記していく。改行が見つかるかEOFになったら終了
2. `ft_extract_line`: `stash`の先頭から改行（含む）までを切り出して返す
3. `ft_clean_stash`: 返却済みの部分を`stash`から削除し、残りを保持

この方式を選んだ理由:
- 静的変数により、関数呼び出し間でバッファの状態を保持できる
- 改行を見つけた時点で読み込みを止めるため、必要以上にメモリを消費しない
- 行の長さに依存せず、動的にメモリを確保するため任意の長さの行に対応可能

## Resources

- [read(2) - Linux manual page](https://man7.org/linux/man-pages/man2/read.2.html)
- [Static Variables in C](https://www.geeksforgeeks.org/static-variables-in-c/)

### AIの使用について

READMEの作成にAIを使用した。コードの実装には使用していない。
