#ifndef _DXLIB_H_
#define _DXLIB_H_

#define TRUE 1
#define FALSE 0

#define MOUSE_INPUT_LEFT 1
#define MOUSE_INPUT_RIGHT 2
#define MOUSE_INPUT_MIDDLE 4

#define DX_PLAYTYPE_BACK 10
#define DX_PLAYTYPE_LOOP 11
#define DX_PLAYTYPE_NORMAL 12

#define DX_FONTTYPE_NORMAL 20                   //Siv3D�̕s��ŃA���`�G�C���A�X���I�t�ɂł��Ȃ��炵��
#define DX_FONTTYPE_EDGE 21                     //Siv3D�̕s��ŃA���`�G�C���A�X���I�t�ɂł��Ȃ��炵��
#define DX_FONTTYPE_ANTIALIASING 22
#define DX_FONTTYPE_ANTIALIASING_4X4 22         //�T���v�����O��ύX�ł��Ȃ��̂ŕW���ƕς��Ȃ�
#define DX_FONTTYPE_ANTIALIASING_8X8 22         //�T���v�����O��ύX�ł��Ȃ��̂ŕW���ƕς��Ȃ�
#define DX_FONTTYPE_ANTIALIASING_EDGE 25
#define DX_FONTTYPE_ANTIALIASING_EDGE_4X4 25    //�T���v�����O��ύX�ł��Ȃ��̂ŕW���ƕς��Ȃ�
#define DX_FONTTYPE_ANTIALIASING_EDGE_8X8 25    //�T���v�����O��ύX�ł��Ȃ��̂ŕW���ƕς��Ȃ�

#define KEY_INPUT_BACK 0x0E			    // BackSpace�L�[
#define KEY_INPUT_TAB	0x0F			    // Tab�L�[			
#define KEY_INPUT_RETURN 0x1C		    // Enter�L�[		
#define KEY_INPUT_LSHIFT 0x2A		    // ��Shift�L�[		
#define KEY_INPUT_RSHIFT 0x36	      // �EShift�L�[		
#define KEY_INPUT_LCONTROL 0x1D		  // ��Ctrl�L�[
#define KEY_INPUT_RCONTROL 0x9D		  // �ECtrl�L�[
#define KEY_INPUT_ESCAPE 0x01			  // Esc�L�[
#define KEY_INPUT_SPACE 0x39			  // �X�y�[�X�L�[
#define KEY_INPUT_PGUP 0xC9 			  // PageUp�L�[
#define KEY_INPUT_PGDN 0xD1			    // PageDown�L�[
#define KEY_INPUT_END	0xCF			    // End�L�[
#define KEY_INPUT_HOME 0xC7			    // Home�L�[
#define KEY_INPUT_LEFT 0xCB 			  // ���L�[
#define KEY_INPUT_UP 0xC8			      // ��L�[
#define KEY_INPUT_RIGHT 0xCD			  // �E�L�[
#define KEY_INPUT_DOWN 0xD0 			  // ���L�[
#define KEY_INPUT_INSERT 0xD2			  // Insert�L�[
#define KEY_INPUT_DELETE 0xD3 		  // Delete�L�[

#define KEY_INPUT_MINUS 0x0C			  // �|�L�[			
#define KEY_INPUT_YEN	0x7D			    // ���L�[			
#define KEY_INPUT_PREVTRACK	0x90    // �O�L�[			
#define KEY_INPUT_PERIOD 0x34			  // �D�L�[			
#define KEY_INPUT_SLASH 0x35			  // �^�L�[			
#define KEY_INPUT_LALT 0x38 			  // ��Alt�L�[		
#define KEY_INPUT_RALT 0xB8 			  // �EAlt�L�[		
//#define KEY_INPUT_SCROLL 0x46			  // ScrollLock�L�[	
#define KEY_INPUT_SEMICOLON	0x27	  // �G�L�[			
#define KEY_INPUT_COLON 0x92			  // �F�L�[			
#define KEY_INPUT_LBRACKET 0x1A		  // �m�L�[			
#define KEY_INPUT_RBRACKET 0x1B		  // �n�L�[			
#define KEY_INPUT_AT 0x91			      // ���L�[			
#define KEY_INPUT_BACKSLASH	0x2B	  // �_�L�[			
#define KEY_INPUT_COMMA 0x33			  // �C�L�[			
//#define KEY_INPUT_KANJI 0x94			  // �����L�[			
//#define KEY_INPUT_CONVERT 0x79	    // �ϊ��L�[			
//#define KEY_INPUT_NOCONVERT 0x7B	  // ���ϊ��L�[		
//#define KEY_INPUT_KANA 0x70 			  // �J�i�L�[			
//#define KEY_INPUT_APPS 0xDD			    // �A�v���P�[�V�������j���[�L�[		
//#define KEY_INPUT_CAPSLOCK 0x3A	    // CaspLock�L�[		
#define KEY_INPUT_SYSRQ 0xB7			  // PrintScreen�L�[	
#define KEY_INPUT_PAUSE 0xC5			  // PauseBreak�L�[	
//#define KEY_INPUT_LWIN 0xDB 			  // ��Win�L�[		
//#define KEY_INPUT_RWIN 0xDC 			  // �EWin�L�[		

#define KEY_INPUT_NUMLOCK	0x45		  // �e���L�[NumLock�L�[		
#define KEY_INPUT_NUMPAD0	0x52	    // �e���L�[�O				
#define KEY_INPUT_NUMPAD1	0x4F		  // �e���L�[�P				
#define KEY_INPUT_NUMPAD2	0x50		  // �e���L�[�Q				
#define KEY_INPUT_NUMPAD3	0x51	    // �e���L�[�R				
#define KEY_INPUT_NUMPAD4	0x4B	    // �e���L�[�S				
#define KEY_INPUT_NUMPAD5	0x4C		  // �e���L�[�T				
#define KEY_INPUT_NUMPAD6	0x4D		  // �e���L�[�U				
#define KEY_INPUT_NUMPAD7	0x47		  // �e���L�[�V				
#define KEY_INPUT_NUMPAD8	0x48		  // �e���L�[�W				
#define KEY_INPUT_NUMPAD9	0x49		  // �e���L�[�X				
#define KEY_INPUT_MULTIPLY 0x37     // �e���L�[���L�[			
#define KEY_INPUT_ADD 0x4E			    // �e���L�[�{�L�[			
#define KEY_INPUT_SUBTRACT 0x4A		  // �e���L�[�|�L�[			
#define KEY_INPUT_DECIMAL	0x53		  // �e���L�[�D�L�[			
#define KEY_INPUT_DIVIDE 0xB5			  // �e���L�[�^�L�[			
#define KEY_INPUT_NUMPADENTER	0x9C	// �e���L�[�̃G���^�[�L�[	

#define KEY_INPUT_F1 0x3B			      // �e�P�L�[			
#define KEY_INPUT_F2 0x3C			      // �e�Q�L�[			
#define KEY_INPUT_F3 0x3D			      // �e�R�L�[			
#define KEY_INPUT_F4 0x3E			      // �e�S�L�[			
#define KEY_INPUT_F5 0x3F			      // �e�T�L�[			
#define KEY_INPUT_F6 0x40			      // �e�U�L�[			
#define KEY_INPUT_F7 0x41			      // �e�V�L�[			
#define KEY_INPUT_F8 0x42	      		// �e�W�L�[			
#define KEY_INPUT_F9 0x43			      // �e�X�L�[			
#define KEY_INPUT_F10 0x44		    	// �e�P�O�L�[		
#define KEY_INPUT_F11 0x57			    // �e�P�P�L�[		
#define KEY_INPUT_F12 0x58			    // �e�P�Q�L�[		

#define KEY_INPUT_A 0x1E			      // �`�L�[			
#define KEY_INPUT_B	0x30			      // �a�L�[			
#define KEY_INPUT_C	0x2E			      // �b�L�[			
#define KEY_INPUT_D	0x20			      // �c�L�[			
#define KEY_INPUT_E	0x12			      // �d�L�[			
#define KEY_INPUT_F	0x21			      // �e�L�[			
#define KEY_INPUT_G	0x22			      // �f�L�[			
#define KEY_INPUT_H	0x23			      // �g�L�[			
#define KEY_INPUT_I	0x17			      // �h�L�[			
#define KEY_INPUT_J	0x24			      // �i�L�[			
#define KEY_INPUT_K	0x25			      // �j�L�[			
#define KEY_INPUT_L	0x26			      // �k�L�[			
#define KEY_INPUT_M	0x32			      // �l�L�[			
#define KEY_INPUT_N	0x31			      // �m�L�[			
#define KEY_INPUT_O	0x18			      // �n�L�[			
#define KEY_INPUT_P	0x19			      // �o�L�[			
#define KEY_INPUT_Q	0x10			      // �p�L�[			
#define KEY_INPUT_R	0x13			      // �q�L�[			
#define KEY_INPUT_S	0x1F			      // �r�L�[			
#define KEY_INPUT_T	0x14			      // �s�L�[			
#define KEY_INPUT_U	0x16			      // �t�L�[			
#define KEY_INPUT_V	0x2F			      // �u�L�[			
#define KEY_INPUT_W	0x11			      // �v�L�[			
#define KEY_INPUT_X	0x2D			      // �w�L�[			
#define KEY_INPUT_Y	0x15			      // �x�L�[			
#define KEY_INPUT_Z	0x2C			      // �y�L�[			

#define KEY_INPUT_0 0x0B			      // �O�L�[			
#define KEY_INPUT_1	0x02			      // �P�L�[			
#define KEY_INPUT_2	0x03			      // �Q�L�[			
#define KEY_INPUT_3 0x04			      // �R�L�[			
#define KEY_INPUT_4	0x05			      // �S�L�[			
#define KEY_INPUT_5	0x06			      // �T�L�[			
#define KEY_INPUT_6	0x07			      // �U�L�[			
#define KEY_INPUT_7	0x08			      // �V�L�[			
#define KEY_INPUT_8	0x09			      // �W�L�[			
#define KEY_INPUT_9	0x0A			      // �X�L�[			

/**�g�p�K�{�֐�**/
int DxLib_Init();
int DxLib_End();
int ProcessMessage();


/**�E�B���h�E����֐�**/
int SetGraphMode(int x, int y, int bit);
int ChangeWindowMode(int flag);
int SetMainWindowText(const char* title);
int SetWindowSizeChangeEnableFlag(int flag);


/**�}�`�`��֐�**/
int DrawPixel(int x, int y, unsigned int color);
int DrawLine(int x1, int y1, int x2, int y2, unsigned int color, float width = 1.0);
int DrawBox(int x1, int y1, int x2, int y2, unsigned int color, int fill);
int DrawCircle(int x, int y, int r, unsigned int color, int fill);
int DrawOval(int x, int y, int rx, int ry, unsigned int color, int fill);
int DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, unsigned int color, int fill);


/**�摜����֐�**/
int LoadGraph(const char* name);
//int LoadDivGraph(char* name, int AllNum, int XNum, int YNum, int XSize, int YSize, int* HandleBuf);
//int MakeGraph(int sizeX, int sizeY);

int DrawGraph(int x, int y, int graph, int trans);
int DrawTurnGraph(int x, int y, int graph, int trans);
int DrawReverseGraph(int x, int y, int graph, int Xturn = FALSE, int Yturn = FALSE);
int DrawExtendGraph(int x1, int y1, int x2, int y2, int graph, int trans);
int DrawRotaGraph(int x, int y, double ExRate, double angle, int graph, int trans, int XTurn = FALSE, int YTurn = FALSE);
int DrawModiGraph(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int graph, int trans);
int DrawRectGraph(int dx, int dy, int sx, int sy, int w, int h, int graph, int trans, int XTurn = FALSE, int YTurn = FALSE);

int InitGraph();
int GetGraphSize(int graph, int* sizeX, int* sizeY);
int DeleteGraph(int graph);
//int SetDrawBlendMode(int mode, int pal);


/**������`�搧��֐�**/
int SetFontSize(int size);
int SetFontThickness(int thick);
int ChangeFont(const char* name);
int ChangeFontType(int type);
int DrawString(int x, int y, const char* str, unsigned int color);
int DrawFormatString(int x, int y, unsigned int color, const char* str, ...);

int InitFontToHandle();
int CreateFontToHandle(const char* name, int size, int thick, int type = -1, int CharSet = -1, int EdgeSize = -1, int Italic = FALSE, int Handle = -1);
int DeleteFontToHandle(int font);
int DrawStringToHandle(int x, int y, const char* str, unsigned int Color, int FontHandle);
int DrawFormatStringToHandle(int x, int y, unsigned int color, int FontHandle, const char* str, ...);


/**�I�[�f�B�I����֐�**/
int LoadSoundMem(const char* name);
int PlaySoundMem(int sound, int type, int topPos = TRUE);
int CheckSoundMem(int sound);
int StopSoundMem(int sound);
int DeleteSoundMem(int sound);
int ChangeVolumeSoundMem(int volume, int sound);
int InitSoundMem();


/**���̓f�o�C�X����֐�**/
int CheckHitKey(int key);
int CheckHitKeyAll();
int GetHitKeyStateAll(char* keyArray);

int GetMousePoint(int* X, int* Y);
int SetMousePoint(int X, int Y);
int GetMouseInput();
int GetMouseWheelRotVol();


/**���̑��֐�**/
unsigned int GetColor(int r, int g, int b);
int GetRand(int n);
int SetBackgroundColor(int r, int g, int b);

#endif
