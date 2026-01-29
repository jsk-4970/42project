*This project has been created as part of the 42 curriculum by jyamada.*

# Push_Swap

## Description

Push_Swapは、2つのスタックと限られた操作のみを使用して整数のスタックをソートするアルゴリズムプロジェクトです。目標は、できるだけ少ない操作回数で数値を昇順にソートすることです。

## ファイル構成

```
push_swap/
├── include/
│   └── push_swap.h      # ヘッダファイル（構造体・関数プロトタイプ）
├── src/
│   ├── main.c           # エントリーポイント、引数パース、バリデーション
│   ├── stack.c          # スタック操作（作成、追加）
│   ├── sort.c           # メインソートロジック（基数ソート）
│   ├── sort_small.c     # 小規模ソート（2〜5要素用）
│   ├── operation1.c     # sa, sb, pa, pb
│   ├── operation2.c     # ra, rb, rr
│   ├── operation3.c     # rra, rrb, rrr
│   ├── utils.c          # ユーティリティ関数
│   ├── free.c           # メモリ解放
│   ├── ft_split.c       # 文字列分割
│   ├── ft_strdup.c      # 文字列複製
│   ├── ft_strlen.c      # 文字列長取得
│   └── ft_substr.c      # 部分文字列取得
└── Makefile
```

## データ構造

```c
typedef struct s_stack
{
    int             value;  // 実際の値
    int             index;  // ランク（0〜n-1）
    struct s_stack  *next;  // 次のノード
}   t_stack;
```

スタックは**単方向連結リスト**で実装されています。`index`フィールドはソート時に使用するランク値を保持します。

## アルゴリズム詳細

### 要素数による分岐 (sort.c:71-97)

| 要素数 | アルゴリズム | 関数 |
|--------|-------------|------|
| 1 | 何もしない | - |
| 2 | 必要なら`sa` | `small_sort()` |
| 3 | 専用ロジック | `sort_3()` |
| 4-5 | 最小値をBへ移動→3要素ソート | `sort_5()` |
| 6以上 | 基数ソート | `push_swap()` |

### 基数ソート（Radix Sort）

**ステップ1: ランク付け** (sort.c:15-40)
- 各値に対して、それより小さい値の数をカウント
- 例: `[3, 1, 4]` → ランク `[1, 0, 2]`

**ステップ2: ビット単位の分離** (sort.c:42-52)
```
ビット0から順に処理:
  - ビットが0 → pb（スタックBへ）
  - ビットが1 → ra（スタックA内で回転）
各ビット処理後、全要素をAに戻す
```

**例: 4要素 [3,1,4,2] のソート**
```
初期状態:  A=[3,1,4,2] → ランク=[2,0,3,1]

ビット0処理 (最下位ビット):
  index=2(10) → ビット0は0 → pb
  index=0(00) → ビット0は0 → pb
  index=3(11) → ビット0は1 → ra
  index=1(01) → ビット0は1 → ra
  A=[3,1], B=[4,2]
  kick_back → A=[2,4,3,1]

ビット1処理:
  index=1(01) → ビット1は0 → pb
  index=3(11) → ビット1は1 → ra
  index=2(10) → ビット1は1 → ra
  index=0(00) → ビット1は0 → pb
  A=[4,3], B=[1,2]
  kick_back → A=[2,1,4,3]

結果: ソート完了（ランク順 0,1,2,3）
```

### 小規模ソート（2〜5要素）

**sort_3** (sort_small.c:52-76)
- 3要素のソートを最大2操作で完了
- 最大値の位置で分岐：
  - 先頭 → `ra` + 必要なら`sa`
  - 中央 → `rra` + 必要なら`sa`
  - 末尾 → 必要なら`sa`のみ

**sort_5** (sort_small.c:78-102)
- 最小値を効率的にスタックBへ移動
- 3要素になったら`sort_3`を適用
- Bの要素を戻す

## スタック操作一覧

| 操作 | 説明 | 実装ファイル |
|------|------|-------------|
| `sa` | スタックAの先頭2要素を交換 | operation1.c |
| `sb` | スタックBの先頭2要素を交換 | operation1.c |
| `ss` | `sa`と`sb`を同時実行 | - |
| `pa` | スタックBの先頭をAにプッシュ | operation1.c |
| `pb` | スタックAの先頭をBにプッシュ | operation1.c |
| `ra` | スタックAを回転（先頭→末尾） | operation2.c |
| `rb` | スタックBを回転（先頭→末尾） | operation2.c |
| `rr` | `ra`と`rb`を同時実行 | operation2.c |
| `rra` | スタックAを逆回転（末尾→先頭） | operation3.c |
| `rrb` | スタックBを逆回転（末尾→先頭） | operation3.c |
| `rrr` | `rra`と`rrb`を同時実行 | operation3.c |

## エラーハンドリング (main.c)

以下のケースで`Error\n`を標準エラー出力：

| チェック | 関数 | 行 |
|----------|------|-----|
| 引数なし | main() | 84-85 |
| 整数以外の文字 | is_valid_number() | 60 |
| INT_MIN〜INT_MAX範囲外 | init_stack_a() | 63-64 |
| 重複する値 | is_diff_num() | 69-70 |
| メモリ確保失敗 | init_stack_a() | 65-66 |

## コンパイル

```bash
make        # プログラムをコンパイル
make clean  # オブジェクトファイルを削除
make fclean # オブジェクトファイルと実行ファイルを削除
make re     # クリーンしてから再ビルド
```

## 実行例

```bash
# 複数の引数で実行
./push_swap 4 67 3 87 23

# クォートで囲んだ文字列で実行
./push_swap "4 67 3 87 23"

# 操作回数のカウント
./push_swap 4 67 3 87 23 | wc -l

# checkerで検証
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
```

## 参考資料

- [Push_swap Tutorial](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [基数ソートアルゴリズム](https://www.geeksforgeeks.org/radix-sort/)

## AIの使用について

本プロジェクトでは以下の用途でAI（Claude）を使用しました：
- ソートアルゴリズムのロジックエラー特定のためのデバッグ支援
- メモリ管理とエッジケース処理のコードレビュー
- プロジェクト要件に基づくREADMEドキュメントの生成
