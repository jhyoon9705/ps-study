#include <bits/stdc++.h>

using namespace std;

int main() {
	int storeNum;
	int width, height;
	int securityDirections, securityGap;
	int distanceSum = 0;
	vector<int> v1, v2;
	cin >> width >> height;
	cin >> storeNum;

	for (int i = 0; i < storeNum; i++) {
		int directions, gap;
		cin >> directions >> gap;
		v1.push_back(directions);
		v2.push_back(gap);
	}

	cin >> securityDirections >> securityGap;

	for (int j = 0; j < storeNum; j++) {
		if (securityDirections <= 2) { // 경비원이 북 또는 남에 있는 경우
			if (securityDirections == v1[j]) { // 경비원과 상점이 같은 방향에 있는 경우
				distanceSum += abs(securityGap - v2[j]);
				
			}
			else if(securityDirections + v1[j] == 3){ // 경비원과 상점이 반대 방향에 있는 경우
				if (securityGap + v2[j] <= width) { // 시계방향으로 돌기
					distanceSum += securityGap + v2[j] + height;
				
				}
				else { // 반시계방향으로 돌기
					distanceSum += (2 * width - securityGap - v2[j]) + height;
			
				}
			}
			else { // 경비원과 상점이 전혀 다른 방향에 있는 경우
				if (securityDirections == 1) { // 경비원이 북쪽에 있는 경우
					if(v1[j] == 3) { // 상점이 서쪽에 있는 경우
						distanceSum += v2[j] + securityGap;
					}
					else { // 상점이 동쪽에 있는 경우
						distanceSum += width - securityGap + v2[j];
					}
				}
				else { // 경비원이 남쪽에 있는 경우
					if (v1[j] == 3) { // 상점이 서쪽에 있는 경우
						distanceSum += securityGap + height - v2[j];
					}
					else { // 상점이 동쪽에 있는 경우
						distanceSum += width - securityGap + height - v2[j];
					}
				}
			}
		}
		else { // securityDirections > 2 경비원이 동 또는 서에 있는 경우
			if (securityDirections == v1[j]) { // 경비원과 상점이 같은 방향에 있는 경우
				distanceSum += abs(securityGap - v2[j]);
	
			}
			else if(securityDirections + v1[j] == 7) { // 경비원과 상점이 반대 방향에 있는 경우
				if (securityGap + v2[j] <= height) { // 시계방향으로 돌기
					distanceSum += securityGap + v2[j] + width;
	
				}
				else { // 반시계방향으로 돌기
					distanceSum += (2 * height - securityGap - v2[j]) + width;
		
				}
			}
			else { // 경비원과 상점이 전혀 다른 방향에 있는 경우
				if(securityDirections == 3) { // 경비원이 서쪽에 있는 경우
					if (v1[j] == 1) { // 상점이 북쪽에 있는 경우
						distanceSum += securityGap + v2[j];
					}
					else { // 상점이 남쪽에 있는 경우
						distanceSum += width - securityGap + v2[j];
					}
				}
				else { // 경비원이 동쪽에 있는 경우
					if (v1[j] == 1) { // 상점이 북쪽에 있는 경우
						distanceSum += securityGap + width - v2[j];
					}
					else { // 상점이 남쪽에 있는 경우
						distanceSum += 2* width - securityGap - v2[j];
					}
				}
			}
		}
	}

	cout << distanceSum << endl;

}