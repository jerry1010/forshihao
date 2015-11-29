#include"drawApi.h"

//石豪你在这个cpp文件里面写代码


void drawLines(int x1, int y1, int x2, int y2)
{
	int x, y;
	int temp = 0;
	double d, k;
	bool vers;

	if (x1 > x2 || y1 > y2) {
		temp = x1;
		x1 = x2;
		x2 = temp;
		temp = y1;
		y1 = y2;
		y2 = temp;
	}

	if ((y2 - y1) <= (x2 - x1)) {
		x = x1;
		y = y1;
		d = 1.0*(y2 - y1) / (x2 - x1);
		k = 0.0;
		vers = true;
	}
	else {
		x = x1;
		y = y1;
		d = 1.0*(x2 - x1) / (y2 - y1);
		k = 0.0;
		vers = false;
	}

	while (x != x2 && x1 != x2 && y1 != y2) {
		drawPoint(x, y);
		if ((k += d) <= 0.5)
			vers ? x++ : y++;
		else {
			x++;
			y++;
			k -= 1.0;
		}
	}
	while (x1 = x2 && y != y2){
		drawPoint(x, y);
		y++;
	}
	while (y1 = y2 && x != x2) {
		drawPoint(x, y);
		x++;
	}

}
	

void drawRect(int minx, int miny, int maxx, int maxy)
{
	drawLines(minx, miny, maxx, miny);
	drawLines(maxx, miny, maxx, maxy);
	drawLines(minx, maxy, maxx, maxy);
	drawLines(minx, miny, minx, maxy);
}
void drawCircle(int x0, int y0, int r)
{
	int x = 0;
	int y = r;
	int d = 1 - r;

	while (x <= y) {
		drawPoint(x + x0, y + y0);
		drawPoint(-x + x0, y + y0);
		drawPoint(-x + x0, -y + y0);
		drawPoint(x + x0, -y + y0);
		drawPoint(y + x0, x + y0);
		drawPoint(-y + x0, x + y0);
		drawPoint(-y + x0, -x + y0);
		drawPoint(y + x0, -x + y0);

		if (d < 0)
			d += 2 * x + 3;
		else {
			d += 2 * (x - y) + 5;
			y--;
		}
		x++;
	}
}

//你可以在这个函数里面画东西试试
void onScenceRender()
{
	drawCircle(400, 400, 300);
}