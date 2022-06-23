# prime_millionaire_tools

## what is this tool
This tool helps you playing prime millionaire  
Mainly, outputs the prime numbers that can be reordered from input  

## example
```
 g++ main.cpp
 ./a.out
 A2345TJQK 
```
output is one of reordered prime 2345ATJQK

## input
- input string consists of `A123456789TJQK`
- too large input sometimes take a lot of time, Numbers of less than 15 digits are recommended.

## 日本語
- 素数大富豪のためのツールです、雑に作ったのでお遊びくらいで使ってください。
- 自分の手札を`A123456789TJQK`の形式で入力として与えることで並び変えてできた素数を一つ出力します。
- 部分集合の手札は計算しません。
- ジョーカーも面倒なので実装していません。
- 素数判定がO(sqrt(N))なので常識的な長さの入力でしか動きません。