#include <iostream>
#include <cstring>

using namespace std;

class Point
{
private:
	int xPos, yPos;
public:
	Point(int x=0, int y=0) : xPos(x), yPos(y)
	{}
	void ShowData() const
	{
		cout << "X��ǥ : " << xPos << " , "
			<< "Y��ǥ : " << yPos << endl;
	}
};

class BoundCheckPointArray
{
private:
	Point *arr;
	int arrLen;
public:
	BoundCheckPointArray(int len) : arrLen(len)
	{
		arr = new Point[len];
	}
	Point &operator[](int idx)
	{
		if (idx < 0 || idx >= arrLen)
		{
			cout << "�ź��� ������ ������ϴ�." << endl;
			exit(1);
		}
		return arr[idx];
	}
};

int main()
{
	/* ��ü�� ������ ���� �迭 Ŭ������ ���� */
	BoundCheckPointArray arr(3);

	arr[0] = Point(3, 4);
	arr[1] = Point(5, 6);
	arr[2] = Point(7, 8);

	for(int i=0; i<3; i++)
		arr[i].ShowData();

	return 0;
}