#!/bin/bash

# 色の定義
GREEN="\033[32m"
RED="\033[31m"
YELLOW="\033[33m"
RESET="\033[0m"

# チェッカーの場所（優先順位: checker_linux -> checker -> ./checker）
if [ -f ./checker_linux ]; then
    CHECKER="./checker_linux"
elif [ -f ./checker ]; then
    CHECKER="./checker"
else
    echo -e "${RED}Error: checker program not found!${RESET}"
    exit 1
fi

echo -e "Using checker: ${YELLOW}$CHECKER${RESET}"

# テスト関数
run_test() {
    COUNT=$1
    LIMIT=$2
    ITERATIONS=$3
    
    echo -e "\n${YELLOW}=== Testing $COUNT numbers ($ITERATIONS runs) ===${RESET}"
    echo -e "Target Limit: ${GREEN}$LIMIT${RESET} operations"
    
    TOTAL_OPS=0
    MAX_OPS=0
    MIN_OPS=1000000
    FAILED=0

    for ((i=1; i<=ITERATIONS; i++))
    do
        # ランダムな数字を生成 (Rubyを使用)
        ARG=$(ruby -e "puts (1..$COUNT).to_a.shuffle.join(' ')")
        
        # push_swapを実行して行数をカウント
        OPS=$(./push_swap $ARG | wc -l)
        
        # チェッカーで正しくソートされたか確認
        RESULT=$(./push_swap $ARG | $CHECKER $ARG)
        
        # 統計の更新
        TOTAL_OPS=$((TOTAL_OPS + OPS))
        if [ $OPS -gt $MAX_OPS ]; then MAX_OPS=$OPS; fi
        if [ $OPS -lt $MIN_OPS ]; then MIN_OPS=$OPS; fi

        # 結果の表示 (1行ずつ)
        if [ "$RESULT" == "OK" ] && [ $OPS -le $LIMIT ]; then
            echo -e "Run $i: ${GREEN}OK${RESET} ($OPS ops)"
        elif [ "$RESULT" == "OK" ] && [ $OPS -gt $LIMIT ]; then
            echo -e "Run $i: ${YELLOW}OK (Over limit)${RESET} ($OPS ops)"
            FAILED=$((FAILED + 1))
        else
            echo -e "Run $i: ${RED}KO${RESET} ($OPS ops)"
            FAILED=$((FAILED + 1))
        fi
    done

    AVG=$((TOTAL_OPS / ITERATIONS))

    echo -e "---------------------------------"
    echo -e "Results for $COUNT numbers:"
    echo -e "Average: $AVG"
    echo -e "Min:     $MIN_OPS"
    if [ $MAX_OPS -le $LIMIT ]; then
        echo -e "Max:     ${GREEN}$MAX_OPS${RESET} (<= $LIMIT)"
    else
        echo -e "Max:     ${RED}$MAX_OPS${RESET} (> $LIMIT)"
    fi
    echo -e "---------------------------------"
}

# --- 実行セクション ---

# 100個のテスト (目標: 700未満)
# 20回実行してみる
run_test 100 700 20

# 500個のテスト (目標: 5500未満)
# 20回実行してみる
run_test 500 5500 20
