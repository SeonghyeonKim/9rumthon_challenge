# 문제 6. 문자열 나누기

예상 티어: 실버 4
예상 태그: 문자열, 정렬

<br>

## 문제 설명
길이가 N인 문자열 S가 주어졌을 때, 3개의 부분 문자열로 나눈 최대 점수를 출력한다.
점수는 가능한 모든 부분 문자열을 중복 제거하고 사전순으로 정렬한 배열에서 부분 문자열의 등장 순서를 의미한다.

3 <= N <= 100

<br>

## 문제 해결

문제에서 설명한 그대로 점수를 나타내는 배열을 만들고,
부분 문자열의 최대 점수를 구한다.

반복문을 통해 부분 문자열의 길이를 정한 후,
문자열 S의 부분 문자열은 \<string> 헤더의 substr 함수를 사용한다.

```cpp
vector<string> v;
// 전체 N개의 문자를 i, j, N-i-j개로 나눈다
// 부분 문자열로 나누어 벡터 v에 저장한다
for(int i=1; i<=N-2; i++) {
	for(int j=1; j<=N-i-1; j++) {
		// string.substr(idx, cnt) : idx 자리부터 cnt개의 부분 문자열을 반환. (원본 영향 없음)
		v.push_back(S.substr(0, i));
		v.push_back(S.substr(i, j));
		v.push_back(S.substr(i+j, N-i-j));
	}
}
```

중복되는 문자열을 제거하기 위해
\<algorithm> 헤더의 sort 함수를 사용한 후,
\<algorithm> 헤더의 unique 함수와 \<vector> 헤더의 erase 함수를 사용한다.

```cpp
// 부분 문자열을 오름차순으로 정렬한다
sort(v.begin(), v.end());
// 중복된 부분 문자열을 제거한다
v.erase(unique(v.begin(), v.end()), v.end());
```

배열에서 부분 문자열을 찾기 위해,
배열을 순회하게 된다면 O(n) 시간이 걸린다.
map의 find 함수를 사용한다면 O(log n),
unordered_map의 find 함수를 사용한다면 O(1)이다. 

map을 사용하여 문자열과 점수를 key, value화 했다.

```cpp
int si = v.size();
map<string, int> m;
// 문자열과 점수를 맵 m에 저장한다
for(int i=0; i<si; i++) {
	m.insert({v[i], i+1});
}
```

문자열이 가질 수 있는 최고 점수는
3개의 부분 문자열의 합의 최대값이다.

```cpp
// 부분 문자열의 점수가 제일 높은 분할의 점수를 구한다
int ans = 0;
for(int i=1; i<=N-2; i++) {
	for(int j=1; j<=N-i-1; j++) {
		ans = max(ans, m[S.substr(0, i)] + m[S.substr(i, j)] + m[S.substr(i+j, N-i-j)]);
	}
}
```


<br>

## 문제 후기

나는 단순하게 탐색을 통해 문제를 해결했지만,
더 효율적인 풀이 방식이 있을 것이라고 생각한다...

100자리의 문자열을 3개의 부분 문자열로 나누는 것은 O(n^2).
정렬하는 것은 O(n log n).
최댓값을 구하는 것은 O(n^2).

코드를 실행해도 1초를 넘기지 않는다.


<br>