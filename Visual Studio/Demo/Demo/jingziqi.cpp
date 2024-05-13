// 框架三要素 读取操作 处理数据 绘制画面
#include<graphics.h>

char board[3][3] =
{
	{'-', '-', '-'},
	{'-', '-', '-'},
	{'-', '-', '-'},
};

char current_piece = 'O';

bool checkWin(char ch) // 检测指定棋子玩家是否获胜
{
	if (board[0][0] == ch && board[0][1] == ch && board[0][2] == ch)
		return true;
	if (board[1][0] == ch && board[1][1] == ch && board[1][2] == ch)
		return true;
	if (board[2][0] == ch && board[2][1] == ch && board[2][2] == ch)
		return true;
	if (board[0][0] == ch && board[1][0] == ch && board[2][0] == ch)
		return true;
	if (board[0][1] == ch && board[1][1] == ch && board[2][1] == ch)
		return true;
	if (board[0][2] == ch && board[1][2] == ch && board[2][2] == ch)
		return true;
	if (board[0][0] == ch && board[1][1] == ch && board[2][2] == ch)
		return true;
	if (board[0][2] == ch && board[1][1] == ch && board[2][0] == ch)
		return true;

	return false;
}

bool checkDraw()  // 检测是否平局
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (board[i][j] == '-')
				return false;
		}
	}
	return true;

}

void drawBoard() // 绘制棋盘
{
	line(0, 200, 600, 200);
	line(0, 400, 600, 400);
	line(200, 0, 200, 600);
	line(400, 0, 400, 600);
}

void drawPiece() // 绘制棋子
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			
			switch (board[i][j])
			{
			case 'O':
				circle(200 * j + 100, 200 * i + 100, 100);
				break;
			case 'X':
				line(200 * j, 200 * i, 200 * (j + 1), 200 * (i + 1));
				line(200 * (j + 1), 200 * i, 200 * j, 200 * (i + 1));
				break;
			case '-':
				break;

			}
		}
	}
}

void drawTipText() // 绘制提示信息
{
	static TCHAR str[64];
	_stprintf_s(str, _T("当前棋子类型：%c"), current_piece);
	settextcolor(RGB(225, 175, 45));
	outtextxy(0, 0, str);
}

int main()
{
	initgraph(600, 600); 

	ExMessage msg;

	bool running = true;

	BeginBatchDraw();

	while (running)
	{
		DWORD start_time = GetTickCount();

		while (peekmessage(&msg))
		{
			// 检查鼠标左键按下消息
			if (msg.message == WM_LBUTTONDOWN)
			{
				// 计算点击位置

				int x = msg.x;
				int y = msg.y;

				int index_x = x / 200;
				int index_y = y / 200;

				if (board[index_y][index_x] == '-')
				{
					board[index_y][index_x] = current_piece;

					// 切换棋子类型
					if (current_piece == 'O')
					{
						current_piece = 'X';
					}
					else
					{
						current_piece = 'O';
					}
				}
			}

		}

		cleardevice();
		drawBoard();
		drawPiece();
		drawTipText();
		FlushBatchDraw();

		// 胜负判定
		if (checkWin('X'))
		{
			MessageBox(GetHWnd(), _T("x玩家获胜"), _T("游戏结束"), MB_OK);
			running = false;
		}
		else if (checkWin('O'))
		{
			MessageBox(GetHWnd(), _T("o玩家获胜"), _T("游戏结束"), MB_OK);
			running = false;
		}
		else if (checkDraw())
		{
			MessageBox(GetHWnd(), _T("平局"), _T("游戏结束"), MB_OK);
			running = false;
		}
		
		DWORD end_time = GetTickCount();
		DWORD delta_time = end_time - start_time;
		
		if (delta_time < 1000 / 60)
		{
			Sleep(1000 / 60 - delta_time);
		}
		

	}

	EndBatchDraw();
	return 0;
}