#include"drawApi.h"

//石豪你在这个cpp文件里面写代码


void drawLines(int x1, int y1, int x2, int y2)
{
	int dx, dy, d, x, y;
	bool vers;

	if ((y2 - y1) < (x2 - x1)) {
		x = x1;
		y = y1;
		dx = x2 - x1;
		dy = y2 - y1;
		d = dy * 2 - dx;
		vers = true;
	}
	else {
		x = x1;
		y = y1;
		dx = y2 - y1;
		dy = x2 - x1;
		vers = false;
	}

	d = 2 * dy - dx;

	drawPoint(x1, y1);
	if (vers) {
		++x;
	}
	else {
		++y;
	}

	while (x != x2) {
		if (d <= 0) {
			d += 2 * dy;
			drawPoint(x, y);
		}
		else {
			d += (dy - dx) * 2;
			if (!vers) {
				++x;
			}
			else {
				++y;
			}
			drawPoint(x, y);
		}
		if (vers) {
			++x;
		}
		else {
			++y;
		}
	}

}

void drawRect(int minx, int miny, int maxx, int maxy)
{
	drawLines(minx, miny, maxx, miny);
	drawLines(maxx, miny, maxx, maxy);
	drawLines(maxx, maxy, minx, maxy);
	drawLines(minx, maxy, minx, miny);
}
void drawCircle(int centerx, int centy, int radius)
{

}






//你可以在这个函数里面画东西试试
void onScenceRender()
{
	drawPoint(0, 0);

	drawPoint(400, 300);
	drawPoint(401, 300);
	drawPoint(402, 300);
	drawPoint(403, 300);
	drawPoint(404, 300);

	drawPoint(800, 600);


	drawRect(200, 100, 600, 300);
}