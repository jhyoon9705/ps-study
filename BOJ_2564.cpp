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
		if (securityDirections <= 2) { // ������ �� �Ǵ� ���� �ִ� ���
			if (securityDirections == v1[j]) { // ������ ������ ���� ���⿡ �ִ� ���
				distanceSum += abs(securityGap - v2[j]);
				
			}
			else if(securityDirections + v1[j] == 3){ // ������ ������ �ݴ� ���⿡ �ִ� ���
				if (securityGap + v2[j] <= width) { // �ð�������� ����
					distanceSum += securityGap + v2[j] + height;
				
				}
				else { // �ݽð�������� ����
					distanceSum += (2 * width - securityGap - v2[j]) + height;
			
				}
			}
			else { // ������ ������ ���� �ٸ� ���⿡ �ִ� ���
				if (securityDirections == 1) { // ������ ���ʿ� �ִ� ���
					if(v1[j] == 3) { // ������ ���ʿ� �ִ� ���
						distanceSum += v2[j] + securityGap;
					}
					else { // ������ ���ʿ� �ִ� ���
						distanceSum += width - securityGap + v2[j];
					}
				}
				else { // ������ ���ʿ� �ִ� ���
					if (v1[j] == 3) { // ������ ���ʿ� �ִ� ���
						distanceSum += securityGap + height - v2[j];
					}
					else { // ������ ���ʿ� �ִ� ���
						distanceSum += width - securityGap + height - v2[j];
					}
				}
			}
		}
		else { // securityDirections > 2 ������ �� �Ǵ� ���� �ִ� ���
			if (securityDirections == v1[j]) { // ������ ������ ���� ���⿡ �ִ� ���
				distanceSum += abs(securityGap - v2[j]);
	
			}
			else if(securityDirections + v1[j] == 7) { // ������ ������ �ݴ� ���⿡ �ִ� ���
				if (securityGap + v2[j] <= height) { // �ð�������� ����
					distanceSum += securityGap + v2[j] + width;
	
				}
				else { // �ݽð�������� ����
					distanceSum += (2 * height - securityGap - v2[j]) + width;
		
				}
			}
			else { // ������ ������ ���� �ٸ� ���⿡ �ִ� ���
				if(securityDirections == 3) { // ������ ���ʿ� �ִ� ���
					if (v1[j] == 1) { // ������ ���ʿ� �ִ� ���
						distanceSum += securityGap + v2[j];
					}
					else { // ������ ���ʿ� �ִ� ���
						distanceSum += width - securityGap + v2[j];
					}
				}
				else { // ������ ���ʿ� �ִ� ���
					if (v1[j] == 1) { // ������ ���ʿ� �ִ� ���
						distanceSum += securityGap + width - v2[j];
					}
					else { // ������ ���ʿ� �ִ� ���
						distanceSum += 2* width - securityGap - v2[j];
					}
				}
			}
		}
	}

	cout << distanceSum << endl;

}