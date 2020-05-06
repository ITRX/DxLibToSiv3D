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

#define DX_FONTTYPE_NORMAL 20                   //Siv3Dの不具合でアンチエイリアスをオフにできないらしい
#define DX_FONTTYPE_EDGE 21                     //Siv3Dの不具合でアンチエイリアスをオフにできないらしい
#define DX_FONTTYPE_ANTIALIASING 22
#define DX_FONTTYPE_ANTIALIASING_4X4 22         //サンプリングを変更できないので標準と変わらない
#define DX_FONTTYPE_ANTIALIASING_8X8 22         //サンプリングを変更できないので標準と変わらない
#define DX_FONTTYPE_ANTIALIASING_EDGE 25
#define DX_FONTTYPE_ANTIALIASING_EDGE_4X4 25    //サンプリングを変更できないので標準と変わらない
#define DX_FONTTYPE_ANTIALIASING_EDGE_8X8 25    //サンプリングを変更できないので標準と変わらない

#define KEY_INPUT_BACK 0x0E			    // BackSpaceキー
#define KEY_INPUT_TAB	0x0F			    // Tabキー			
#define KEY_INPUT_RETURN 0x1C		    // Enterキー		
#define KEY_INPUT_LSHIFT 0x2A		    // 左Shiftキー		
#define KEY_INPUT_RSHIFT 0x36	      // 右Shiftキー		
#define KEY_INPUT_LCONTROL 0x1D		  // 左Ctrlキー
#define KEY_INPUT_RCONTROL 0x9D		  // 右Ctrlキー
#define KEY_INPUT_ESCAPE 0x01			  // Escキー
#define KEY_INPUT_SPACE 0x39			  // スペースキー
#define KEY_INPUT_PGUP 0xC9 			  // PageUpキー
#define KEY_INPUT_PGDN 0xD1			    // PageDownキー
#define KEY_INPUT_END	0xCF			    // Endキー
#define KEY_INPUT_HOME 0xC7			    // Homeキー
#define KEY_INPUT_LEFT 0xCB 			  // 左キー
#define KEY_INPUT_UP 0xC8			      // 上キー
#define KEY_INPUT_RIGHT 0xCD			  // 右キー
#define KEY_INPUT_DOWN 0xD0 			  // 下キー
#define KEY_INPUT_INSERT 0xD2			  // Insertキー
#define KEY_INPUT_DELETE 0xD3 		  // Deleteキー

#define KEY_INPUT_MINUS 0x0C			  // －キー			
#define KEY_INPUT_YEN	0x7D			    // ￥キー			
#define KEY_INPUT_PREVTRACK	0x90    // ＾キー			
#define KEY_INPUT_PERIOD 0x34			  // ．キー			
#define KEY_INPUT_SLASH 0x35			  // ／キー			
#define KEY_INPUT_LALT 0x38 			  // 左Altキー		
#define KEY_INPUT_RALT 0xB8 			  // 右Altキー		
//#define KEY_INPUT_SCROLL 0x46			  // ScrollLockキー	
#define KEY_INPUT_SEMICOLON	0x27	  // ；キー			
#define KEY_INPUT_COLON 0x92			  // ：キー			
#define KEY_INPUT_LBRACKET 0x1A		  // ［キー			
#define KEY_INPUT_RBRACKET 0x1B		  // ］キー			
#define KEY_INPUT_AT 0x91			      // ＠キー			
#define KEY_INPUT_BACKSLASH	0x2B	  // ＼キー			
#define KEY_INPUT_COMMA 0x33			  // ，キー			
//#define KEY_INPUT_KANJI 0x94			  // 漢字キー			
//#define KEY_INPUT_CONVERT 0x79	    // 変換キー			
//#define KEY_INPUT_NOCONVERT 0x7B	  // 無変換キー		
//#define KEY_INPUT_KANA 0x70 			  // カナキー			
//#define KEY_INPUT_APPS 0xDD			    // アプリケーションメニューキー		
//#define KEY_INPUT_CAPSLOCK 0x3A	    // CaspLockキー		
#define KEY_INPUT_SYSRQ 0xB7			  // PrintScreenキー	
#define KEY_INPUT_PAUSE 0xC5			  // PauseBreakキー	
//#define KEY_INPUT_LWIN 0xDB 			  // 左Winキー		
//#define KEY_INPUT_RWIN 0xDC 			  // 右Winキー		

#define KEY_INPUT_NUMLOCK	0x45		  // テンキーNumLockキー		
#define KEY_INPUT_NUMPAD0	0x52	    // テンキー０				
#define KEY_INPUT_NUMPAD1	0x4F		  // テンキー１				
#define KEY_INPUT_NUMPAD2	0x50		  // テンキー２				
#define KEY_INPUT_NUMPAD3	0x51	    // テンキー３				
#define KEY_INPUT_NUMPAD4	0x4B	    // テンキー４				
#define KEY_INPUT_NUMPAD5	0x4C		  // テンキー５				
#define KEY_INPUT_NUMPAD6	0x4D		  // テンキー６				
#define KEY_INPUT_NUMPAD7	0x47		  // テンキー７				
#define KEY_INPUT_NUMPAD8	0x48		  // テンキー８				
#define KEY_INPUT_NUMPAD9	0x49		  // テンキー９				
#define KEY_INPUT_MULTIPLY 0x37     // テンキー＊キー			
#define KEY_INPUT_ADD 0x4E			    // テンキー＋キー			
#define KEY_INPUT_SUBTRACT 0x4A		  // テンキー－キー			
#define KEY_INPUT_DECIMAL	0x53		  // テンキー．キー			
#define KEY_INPUT_DIVIDE 0xB5			  // テンキー／キー			
#define KEY_INPUT_NUMPADENTER	0x9C	// テンキーのエンターキー	

#define KEY_INPUT_F1 0x3B			      // Ｆ１キー			
#define KEY_INPUT_F2 0x3C			      // Ｆ２キー			
#define KEY_INPUT_F3 0x3D			      // Ｆ３キー			
#define KEY_INPUT_F4 0x3E			      // Ｆ４キー			
#define KEY_INPUT_F5 0x3F			      // Ｆ５キー			
#define KEY_INPUT_F6 0x40			      // Ｆ６キー			
#define KEY_INPUT_F7 0x41			      // Ｆ７キー			
#define KEY_INPUT_F8 0x42	      		// Ｆ８キー			
#define KEY_INPUT_F9 0x43			      // Ｆ９キー			
#define KEY_INPUT_F10 0x44		    	// Ｆ１０キー		
#define KEY_INPUT_F11 0x57			    // Ｆ１１キー		
#define KEY_INPUT_F12 0x58			    // Ｆ１２キー		

#define KEY_INPUT_A 0x1E			      // Ａキー			
#define KEY_INPUT_B	0x30			      // Ｂキー			
#define KEY_INPUT_C	0x2E			      // Ｃキー			
#define KEY_INPUT_D	0x20			      // Ｄキー			
#define KEY_INPUT_E	0x12			      // Ｅキー			
#define KEY_INPUT_F	0x21			      // Ｆキー			
#define KEY_INPUT_G	0x22			      // Ｇキー			
#define KEY_INPUT_H	0x23			      // Ｈキー			
#define KEY_INPUT_I	0x17			      // Ｉキー			
#define KEY_INPUT_J	0x24			      // Ｊキー			
#define KEY_INPUT_K	0x25			      // Ｋキー			
#define KEY_INPUT_L	0x26			      // Ｌキー			
#define KEY_INPUT_M	0x32			      // Ｍキー			
#define KEY_INPUT_N	0x31			      // Ｎキー			
#define KEY_INPUT_O	0x18			      // Ｏキー			
#define KEY_INPUT_P	0x19			      // Ｐキー			
#define KEY_INPUT_Q	0x10			      // Ｑキー			
#define KEY_INPUT_R	0x13			      // Ｒキー			
#define KEY_INPUT_S	0x1F			      // Ｓキー			
#define KEY_INPUT_T	0x14			      // Ｔキー			
#define KEY_INPUT_U	0x16			      // Ｕキー			
#define KEY_INPUT_V	0x2F			      // Ｖキー			
#define KEY_INPUT_W	0x11			      // Ｗキー			
#define KEY_INPUT_X	0x2D			      // Ｘキー			
#define KEY_INPUT_Y	0x15			      // Ｙキー			
#define KEY_INPUT_Z	0x2C			      // Ｚキー			

#define KEY_INPUT_0 0x0B			      // ０キー			
#define KEY_INPUT_1	0x02			      // １キー			
#define KEY_INPUT_2	0x03			      // ２キー			
#define KEY_INPUT_3 0x04			      // ３キー			
#define KEY_INPUT_4	0x05			      // ４キー			
#define KEY_INPUT_5	0x06			      // ５キー			
#define KEY_INPUT_6	0x07			      // ６キー			
#define KEY_INPUT_7	0x08			      // ７キー			
#define KEY_INPUT_8	0x09			      // ８キー			
#define KEY_INPUT_9	0x0A			      // ９キー			

/**使用必須関数**/
int DxLib_Init();
int DxLib_End();
int ProcessMessage();


/**ウィンドウ制御関数**/
int SetGraphMode(int x, int y, int bit);
int ChangeWindowMode(int flag);
int SetMainWindowText(const char* title);
int SetWindowSizeChangeEnableFlag(int flag);


/**図形描画関数**/
int DrawPixel(int x, int y, unsigned int color);
int DrawLine(int x1, int y1, int x2, int y2, unsigned int color, float width = 1.0);
int DrawBox(int x1, int y1, int x2, int y2, unsigned int color, int fill);
int DrawCircle(int x, int y, int r, unsigned int color, int fill);
int DrawOval(int x, int y, int rx, int ry, unsigned int color, int fill);
int DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, unsigned int color, int fill);


/**画像制御関数**/
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


/**文字列描画制御関数**/
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


/**オーディオ制御関数**/
int LoadSoundMem(const char* name);
int PlaySoundMem(int sound, int type, int topPos = TRUE);
int CheckSoundMem(int sound);
int StopSoundMem(int sound);
int DeleteSoundMem(int sound);
int ChangeVolumeSoundMem(int volume, int sound);
int InitSoundMem();


/**入力デバイス制御関数**/
int CheckHitKey(int key);
int CheckHitKeyAll();
int GetHitKeyStateAll(char* keyArray);

int GetMousePoint(int* X, int* Y);
int SetMousePoint(int X, int Y);
int GetMouseInput();
int GetMouseWheelRotVol();


/**その他関数**/
unsigned int GetColor(int r, int g, int b);
int GetRand(int n);
int SetBackgroundColor(int r, int g, int b);

#endif
