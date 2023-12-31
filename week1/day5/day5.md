# 문제 5. 이진수 정렬

예상 티어: 실버 5
예상 태그: 정렬, 비트마스킹

<br>

## 문제 설명

N개의 정수가 주어졌을 때, 각 정수를 2진수로 나타냈을 때, 2진수에 포함된 1의 개수를 기준으로 내림차순 정렬한다.
1의 개수가 같을 경우 원래의 수를 기준으로 내림차순 정렬한다.
이때, K번째에 위치한 수를 출력한다.

<br>

## 문제 해결

비트마스킹을 통해 2진수의 1의 개수를 구했다.
```
for(int i=number; i; i>>=1) count += (i&1);
```
\<algorithm>헤더의 sort 함수를 사용하여 수를 정렬했다.
comp 함수를 사용하여 비교 옵션을 적용했다.

<br>

## 문제 후기

C++의 정렬이 너무 편리하다.
방법만 알면 유사한 문제를 쉽고 빠르게 풀어서,
푼 문제 수를 뻥튀기할 수 있다.

솔직히 비트마스킹 없이
```
for(int i=number; i; i/=2) count += i%2;
```
를 사용해도 상관이 없는데, 
최근에 비트마스킹 문제를 풀어서 이 풀이가 바로 떠올랐다.
습관이 무섭다.

<br>