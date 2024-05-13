// �����Ҫ�� ��ȡ���� �������� ���ƻ���
#include<graphics.h>

char board[3][3] =
{
	{'-', '-', '-'},
	{'-', '-', '-'},
	{'-', '-', '-'},
};

char current_piece = 'O';

bool checkWin(char ch) // ���ָ����������Ƿ��ʤ
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

bool checkDraw()  // ����Ƿ�ƽ��
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

void drawBoard() // ��������
{
	line(0, 200, 600, 200);
	line(0, 400, 600, 400);
	line(200, 0, 200, 600);
	line(400, 0, 400, 600);
}

void drawPiece() // ��������
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

void drawTipText() // ������ʾ��Ϣ
{
	static TCHAR str[64];
	_stprintf_s(str, _T("��ǰ�������ͣ�%c"), current_piece);
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
			// ���������������Ϣ
			if (msg.message == WM_LBUTTONDOWN)
			{
				// ������λ��

				int x = msg.x;
				int y = msg.y;

				int index_x = x / 200;
				int index_y = y / 200;

				if (board[index_y][index_x] == '-')
				{
					board[index_y][index_x] = current_piece;

					// �л���������
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

		// ʤ���ж�
		if (checkWin('X'))
		{
			MessageBox(GetHWnd(), _T("x��һ�ʤ"), _T("��Ϸ����"), MB_OK);
			running = false;
		}
		else if (checkWin('O'))
		{
			MessageBox(GetHWnd(), _T("o��һ�ʤ"), _T("��Ϸ����"), MB_OK);
			running = false;
		}
		else if (checkDraw())
		{
			MessageBox(GetHWnd(), _T("ƽ��"), _T("��Ϸ����"), MB_OK);
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