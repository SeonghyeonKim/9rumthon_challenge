# 문제 9. 폭탄 구현하기 (2)

예상 티어: 브론즈 3
예상 태그: 완전 탐색

<br>

## 문제 설명

N x N 크기의 정사각형 모양의 땅에 1 x 1 크기의 부분에 폭탄이 떨어질때,
그 구역과 구역에 상하좌우로 인접한 땅에 폭탄 값이 변하게 된다.
K개의 모든 폭탄이 떨어졌을때, 모든 땅의 폭탄 값 중에서 가장 높은 값을 출력한다.

위에서 y 번째, 왼쪽에서 x 번째에 위치한 땅을 (y, x)로 나타낸다.
모든 폭탄 값의 초기 값은 0 이다.
땅의 상태가 '#' 이라면 폭탄 값은 0, '0' 이라면 1, '@' 이라면 2 가 증가한다.

1 <= N <= 200
1 <= K <= 500 000
1 <= x, y <= N


<br>

## 문제 해결

N x N 개의 칸의 땅의 상태를 입력받은 후에
K 개의 폭탄의 (y, x) 좌표가 입력될때마다 땅의 상태에 따라 폭탄 값을 증가시키면 된다.


<br>

## 문제 후기

더 쉬운 난이도의 문제가 나왔다.
만약 폭탄이 떨어진 수가 많다면
떨어질 때마다 5칸을 탐색하는 것은 비효율적일지도 모른다.
각 칸마다 떨어진 모든 폭탄의 수를 저장한 후,
마지막에 폭탄 값을 더하는 것이 효율적이다.


<br>