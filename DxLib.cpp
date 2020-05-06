#include "DxLib.h"
#include <Siv3d.hpp>
#include <map>
#include <list>
#include <cstdarg>

using namespace std;

template <typename T>
inline void SafeDestroyObject(T* obj) {
  delete obj;
  obj = nullptr;
}

struct WindowData {
  int width;
  int height;
  bool fullScreen;
  bool resizeAble;
  bool created;

  WindowData() {
    width = 640;
    height = 480;
    fullScreen = false;
    resizeAble = false;
    created = false;
  }
};

struct FontData {
  SDFFont font;
  String name;
  int size;
  int type;
  int thick;
  bool italic;
  int edgeSize;

  FontData() {
    name = U"";
    size = 0;
    type = DX_FONTTYPE_ANTIALIASING;
    thick = 0;
    italic = false;
    font = SDFFont();
  }

  FontData(const char* _name, int _size, int _thick, int _type, int _CharSet, int _EdgeSize, int _Italic) {
    name = Unicode::Widen(_name);
    size = _size;
    thick = _thick;
    type = _type;
    italic = _Italic;
    font = SDFFont(size, FileSystem::SpecialFolderPath(SpecialFolder::SystemFonts) + name, italic ? FontStyle::Italic : FontStyle::Default);
  }
};

class GraphicManager {
private:
  map<int, Texture> data;
  list<int> id;
  int maxNum;

public:
  GraphicManager() {
    maxNum = 65536;
    for (int i = INT_MAX - maxNum - 1; i < INT_MAX; i++)
      id.push_back(i);
  }

  ~GraphicManager() {
    data.clear();
    id.clear();
  }

  int setGraphic(Texture graph) {
    if (id.empty())
      return -1;

    int number = id.front();
    id.pop_front();
    data[number] = graph;

    return number;
  }

  Texture getGraphic(int graphID) {
    map<int, Texture>::iterator it = data.find(graphID);
    if (it == data.end())
      return Texture();
    return it->second;
  }

  int removeGraphic(int graphID) {
    map<int, Texture>::iterator it = data.find(graphID);
    if (it == data.end())
      return -1;

    data.erase(graphID);
    id.push_back(graphID);
    return 0;
  }
};

class AudioManager {
private:
  map<int, pair<Audio, int>> data;
  list<int> id;
  int maxNum;

public:
  AudioManager() {
    maxNum = 4096;
    for (int i = INT16_MAX - maxNum - 1; i < INT16_MAX; i++)
      id.push_back(i);
  }

  ~AudioManager() {
    data.clear();
    id.clear();
  }

  int setAudio(Audio sound) {
    if (id.empty())
      return -1;

    int number = id.front();
    id.pop_front();
    data[number] = make_pair(sound, TRUE);

    return number;
  }

  int setTopPos(int soundID, int flag) {
    map<int, pair<Audio, int>>::iterator it = data.find(soundID);
    if (it == data.end())
      return -1;

    it->second.second = flag;
    return 0;
  }

  pair<Audio, int> getAudio(int soundID) {
    map<int, pair<Audio, int>>::iterator it = data.find(soundID);
    if (it == data.end())
      return make_pair(Audio(), FALSE);

    return it->second;
  }

  int removeAudio(int soundID) {
    map<int, pair<Audio, int>>::iterator it = data.find(soundID);
    if (it == data.end())
      return -1;

    data.erase(soundID);
    id.push_back(soundID);
    return 0;
  }
};

class FontManager {
private:
  map<int, FontData> data;
  list<int> id;
  int maxNum;

public:
  FontManager() {
    maxNum = 32768;
    for (int i = INT32_MAX / 2 - maxNum - 1; i < INT32_MAX / 2; i++)
      id.push_back(i);
  }

  ~FontManager() {
    data.clear();
    id.clear();
  }

  int setFont(FontData font) {
    if (id.empty())
      return -1;

    int number = id.front();
    id.pop_front();
    data[number] = font;

    return number;
  }

  FontData getFont(int fontID) {
    map<int, FontData>::iterator it = data.find(fontID);
    if (it == data.end())
      return FontData();

    return it->second;
  }

  int removeFont(int fontID) {
    map<int, FontData>::iterator it = data.find(fontID);
    if (it == data.end())
      return -1;

    data.erase(fontID);
    id.push_back(fontID);
    return 0;
  }
};

static WindowData* ScreenData = nullptr;
static GraphicManager* GraphicDataBase = nullptr;
static AudioManager* AudioDataBase = nullptr;
static FontManager* FontDataBase = nullptr;
static Array<const Key*> KeyState;
static FontData* defaultFont = nullptr;





int DxLib_Init() {
  ScreenData = new WindowData();
  GraphicDataBase = new GraphicManager();
  AudioDataBase = new AudioManager();
  FontDataBase = new FontManager();
  defaultFont = new FontData("msgothic.ttc", 32, 4, DX_FONTTYPE_ANTIALIASING, -1, -1, 0);

  KeyState.resize(0xff + 1, nullptr);
  KeyState[KEY_INPUT_BACK] = &KeyBackspace;
  KeyState[KEY_INPUT_TAB] = &KeyTab;
  KeyState[KEY_INPUT_RETURN] = &KeyEnter;
  KeyState[KEY_INPUT_LSHIFT] = &KeyLShift;
  KeyState[KEY_INPUT_RSHIFT] = &KeyRShift;
  KeyState[KEY_INPUT_LCONTROL] = &KeyLControl;
  KeyState[KEY_INPUT_RCONTROL] = &KeyRControl;
  KeyState[KEY_INPUT_ESCAPE] = &KeyEscape;
  KeyState[KEY_INPUT_SPACE] = &KeySpace;
  KeyState[KEY_INPUT_PGUP] = &KeyPageUp;
  KeyState[KEY_INPUT_PGDN] = &KeyPageDown;
  KeyState[KEY_INPUT_END] = &KeyEnd;
  KeyState[KEY_INPUT_HOME] = &KeyHome;
  KeyState[KEY_INPUT_LEFT] = &KeyLeft;
  KeyState[KEY_INPUT_UP] = &KeyUp;
  KeyState[KEY_INPUT_RIGHT] = &KeyRight;
  KeyState[KEY_INPUT_DOWN] = &KeyDown;
  KeyState[KEY_INPUT_INSERT] = &KeyInsert;
  KeyState[KEY_INPUT_DELETE] = &KeyDelete;

  KeyState[KEY_INPUT_MINUS] = &KeyMinus;
  KeyState[KEY_INPUT_YEN] = &KeyYen_JIS;
  KeyState[KEY_INPUT_PREVTRACK] = &KeyPreviousTrack;
  KeyState[KEY_INPUT_PERIOD] = &KeyPeriod;
  KeyState[KEY_INPUT_SLASH] = &KeySlash;
  KeyState[KEY_INPUT_LALT] = &KeyLAlt;
  KeyState[KEY_INPUT_RALT] = &KeyRAlt;
  //KeyState[KEY_INPUT_SCROLL] = 
  KeyState[KEY_INPUT_SEMICOLON] = &KeySemicolon_US;
  KeyState[KEY_INPUT_COLON] = &KeyColon_JIS;
  KeyState[KEY_INPUT_LBRACKET] = &KeyLBracket;
  KeyState[KEY_INPUT_RBRACKET] = &KeyRBracket;
  KeyState[KEY_INPUT_AT] = &KeyGraveAccent;
  KeyState[KEY_INPUT_BACKSLASH] = &KeyBackslash_US;
  KeyState[KEY_INPUT_COMMA] = &KeyComma;
  //KeyState[KEY_INPUT_KANJI] = &KeyC
  //KeyState[KEY_INPUT_CONVERT] =
  //KeyState[KEY_INPUT_NOCONVERT] =
  //KeyState[KEY_INPUT_KANA] = 
  //KeyState[KEY_INPUT_APPS] = 
  //KeyState[KEY_INPUT_CAPSLOCK] = Key
  KeyState[KEY_INPUT_SYSRQ] = &KeyPrintScreen;
  KeyState[KEY_INPUT_PAUSE] = &KeyPause;
  //KeyState[KEY_INPUT_LWIN] = &KeyWin
  //KeyState[KEY_INPUT_RWIN] =

  KeyState[KEY_INPUT_NUMLOCK] = &KeyNumLock;
  KeyState[KEY_INPUT_NUMPAD0] = &KeyNum0;
  KeyState[KEY_INPUT_NUMPAD1] = &KeyNum1;
  KeyState[KEY_INPUT_NUMPAD2] = &KeyNum2;
  KeyState[KEY_INPUT_NUMPAD3] = &KeyNum3;
  KeyState[KEY_INPUT_NUMPAD4] = &KeyNum4;
  KeyState[KEY_INPUT_NUMPAD5] = &KeyNum5;
  KeyState[KEY_INPUT_NUMPAD6] = &KeyNum6;
  KeyState[KEY_INPUT_NUMPAD7] = &KeyNum7;
  KeyState[KEY_INPUT_NUMPAD8] = &KeyNum8;
  KeyState[KEY_INPUT_NUMPAD9] = &KeyNum9;
  KeyState[KEY_INPUT_MULTIPLY] = &KeyNumMultiply;
  KeyState[KEY_INPUT_ADD] = &KeyNumAdd;
  KeyState[KEY_INPUT_SUBTRACT] = &KeyNumSubtract;
  KeyState[KEY_INPUT_DECIMAL] = &KeyNumDecimal;
  KeyState[KEY_INPUT_DIVIDE] = &KeyNumDivide;
  KeyState[KEY_INPUT_NUMPADENTER] = &KeyNumEnter;

  KeyState[KEY_INPUT_F1] = &KeyF1;
  KeyState[KEY_INPUT_F2] = &KeyF2;
  KeyState[KEY_INPUT_F3] = &KeyF3;
  KeyState[KEY_INPUT_F4] = &KeyF4;
  KeyState[KEY_INPUT_F5] = &KeyF5;
  KeyState[KEY_INPUT_F6] = &KeyF6;
  KeyState[KEY_INPUT_F7] = &KeyF7;
  KeyState[KEY_INPUT_F8] = &KeyF8;
  KeyState[KEY_INPUT_F9] = &KeyF9;
  KeyState[KEY_INPUT_F10] = &KeyF10;
  KeyState[KEY_INPUT_F11] = &KeyF11;
  KeyState[KEY_INPUT_F12] = &KeyF12;

  KeyState[KEY_INPUT_A] = &KeyA;
  KeyState[KEY_INPUT_B] = &KeyB;
  KeyState[KEY_INPUT_C] = &KeyC;
  KeyState[KEY_INPUT_D] = &KeyD;
  KeyState[KEY_INPUT_E] = &KeyE;
  KeyState[KEY_INPUT_F] = &KeyF;
  KeyState[KEY_INPUT_G] = &KeyG;
  KeyState[KEY_INPUT_H] = &KeyH;
  KeyState[KEY_INPUT_I] = &KeyI;
  KeyState[KEY_INPUT_J] = &KeyJ;
  KeyState[KEY_INPUT_K] = &KeyK;
  KeyState[KEY_INPUT_L] = &KeyL;
  KeyState[KEY_INPUT_M] = &KeyM;
  KeyState[KEY_INPUT_N] = &KeyN;
  KeyState[KEY_INPUT_O] = &KeyO;
  KeyState[KEY_INPUT_P] = &KeyP;
  KeyState[KEY_INPUT_Q] = &KeyQ;
  KeyState[KEY_INPUT_R] = &KeyR;
  KeyState[KEY_INPUT_S] = &KeyS;
  KeyState[KEY_INPUT_T] = &KeyT;
  KeyState[KEY_INPUT_U] = &KeyU;
  KeyState[KEY_INPUT_V] = &KeyV;
  KeyState[KEY_INPUT_W] = &KeyW;
  KeyState[KEY_INPUT_X] = &KeyX;
  KeyState[KEY_INPUT_Y] = &KeyY;
  KeyState[KEY_INPUT_Z] = &KeyZ;

  KeyState[KEY_INPUT_0] = &Key0;
  KeyState[KEY_INPUT_1] = &Key1;
  KeyState[KEY_INPUT_2] = &Key2;
  KeyState[KEY_INPUT_3] = &Key3;
  KeyState[KEY_INPUT_4] = &Key4;
  KeyState[KEY_INPUT_5] = &Key5;
  KeyState[KEY_INPUT_6] = &Key6;
  KeyState[KEY_INPUT_7] = &Key7;
  KeyState[KEY_INPUT_8] = &Key8;
  KeyState[KEY_INPUT_9] = &Key9;
  System::SetTerminationTriggers(UserAction::CloseButtonClicked);
  return 0;
}

int DxLib_End() {
  SafeDestroyObject(ScreenData);
  SafeDestroyObject(GraphicDataBase);
  SafeDestroyObject(AudioDataBase);
  SafeDestroyObject(FontDataBase);
  SafeDestroyObject(defaultFont);
  KeyState.clear();
  KeyState.shrink_to_fit();

  return 0;
}

int ProcessMessage() {
  return System::Update() ? 0 : -1;
}



int SetGraphMode(int x, int y, int bit) {
  if (ScreenData == nullptr)
    return -1;

  if (ScreenData->created) {
    ScreenData->width = x;
    ScreenData->height = y;
    Window::Resize(Size(ScreenData->width, ScreenData->height));

    delete GraphicDataBase;
    delete FontDataBase;
    GraphicDataBase = new GraphicManager();
    FontDataBase = new FontManager();
  }
  else {
    ScreenData->width = x;
    ScreenData->height = y;
    Window::Resize(Size(ScreenData->width, ScreenData->height));
    ScreenData->created = true;

    if (ScreenData->resizeAble) {
      Window::SetStyle(WindowStyle::Sizable);
      Scene::SetScaleMode(ScaleMode::ResizeFill);
    }
    else
      Window::SetStyle(WindowStyle::Fixed);

    if (ScreenData->fullScreen)
      Window::SetFullscreen(true, unspecified, WindowResizeOption::KeepSceneSize);
  }

  return 0;
}

int ChangeWindowMode(int flag) {
  if (ScreenData == nullptr)
    return -1;

  ScreenData->fullScreen = !(flag == TRUE);
  if (ScreenData->created) {
    delete GraphicDataBase;
    delete FontDataBase;
    GraphicDataBase = new GraphicManager();
    FontDataBase = new FontManager();
    Window::SetFullscreen(ScreenData->fullScreen, unspecified, WindowResizeOption::KeepSceneSize);
  }

  return 0;
}

int SetMainWindowText(const char* title) {
  if (title == nullptr)
    return -1;

  Window::SetTitle(Unicode::Widen(title));
  return 0;
}

int SetWindowSizeChangeEnableFlag(int flag) {
  if (flag == TRUE) {
    ScreenData->resizeAble = true;
    Window::SetStyle(WindowStyle::Sizable);
    Scene::SetScaleMode(ScaleMode::ResizeFill);
  }
  else {
    ScreenData->resizeAble = false;
    Window::SetStyle(WindowStyle::Fixed);
  }
  return 0;
}

int CheckHitKey(int key) {
  if (!(0 <= key && key < KeyState.size()))
    return -1;
  if (KeyState[key] == nullptr)
    return -1;

  return KeyState[key]->pressed();
}

int CheckHitKeyAll() {
  for (Array<const Key*>::size_type i = 0; i < KeyState.size(); i++)
    if (KeyState[i] != nullptr)
      if (KeyState[i]->pressed())
        return 1;

  return 0;
}

int GetHitKeyStateAll(char* keyArray) {
  if (keyArray == nullptr)
    return -1;

  for (Array<const Key*>::size_type i = 0; i < KeyState.size(); i++)
    keyArray[i] = KeyState[i]->pressed();

  return 0;
}

int GetMousePoint(int* X, int* Y) {
  *X = Cursor::Pos().x;
  *Y = Cursor::Pos().y;
  return 0;
}

int SetMousePoint(int X, int Y) {
  Cursor::SetPos(X, Y);
  return 0;
}

int GetMouseInput() {
  int state = 0;
  if (MouseL.pressed())
    state |= MOUSE_INPUT_LEFT;
  if (MouseM.pressed())
    state |= MOUSE_INPUT_MIDDLE;
  if (MouseR.pressed())
    state |= MOUSE_INPUT_RIGHT;

  return state;
}

int GetMouseWheelRotVol() {
  return 0;
}


unsigned int GetColor(int r, int g, int b) {
  unsigned int color, alpha = 0xff000000;
  color = alpha | (r << 16) | (g << 8) | b;
  return color;
}

int GetRand(int n) {
  return Random(n);
}

int SetBackgroundColor(int r, int g, int b) {
  Scene::SetBackground(Color(r, g, b));
  return 0;
}


int DrawPixel(int x, int y, unsigned int color) {
  if (ScreenData == nullptr)
    return -1;

  unsigned char* c = (unsigned char*)&color;
  Rect(x, y, 1, 1).draw(Color(c[2], c[1], c[0]));
  return 0;
}

int DrawLine(int x1, int y1, int x2, int y2, unsigned int color, float width) {
  if (ScreenData == nullptr)
    return -1;

  unsigned char* c = (unsigned char*)&color;
  Line(x1, y1, x2, y2).draw(width, Color(c[2], c[1], c[0]));
  return 0;
}

int DrawBox(int x1, int y1, int x2, int y2, unsigned int color, int fill) {
  if (ScreenData == nullptr)
    return -1;

  unsigned char* c = (unsigned char*)&color;
  if (fill == TRUE)
    Rect(x1, y1, x2 - x1, y2 - y1).draw(Color(c[2], c[1], c[0]));
  else
    Rect(x1, y1, x2 - x1, y2 - y1).drawFrame(1, 0, Color(c[2], c[1], c[0]));
  return 0;
}

int DrawCircle(int x, int y, int r, unsigned int color, int fill) {
  if (ScreenData == nullptr)
    return -1;

  unsigned char* c = (unsigned char*)&color;
  if (fill == TRUE)
    Circle(x, y, r).draw(Color(c[2], c[1], c[0]));
  else
    Circle(x, y, r).drawFrame(1, 0, Color(c[2], c[1], c[0]));
  return 0;
}

int DrawOval(int x, int y, int rx, int ry, unsigned int color, int fill) {
  if (ScreenData == nullptr)
    return -1;

  unsigned char* c = (unsigned char*)&color;
  if (fill == TRUE)
    Ellipse(x, y, rx, ry).draw(Color(c[2], c[1], c[0]));
  else
    Ellipse(x, y, rx, ry).drawFrame(1, 0, Color(c[2], c[1], c[0]));
  return 0;
}

int DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, unsigned int color, int fill) {
  if (ScreenData == nullptr)
    return -1;

  unsigned char* c = (unsigned char*)&color;
  if (fill == TRUE)
    Triangle(x1, y1, x2, y2, x3, y3).draw(Color(c[2], c[1], c[0]));
  else
    Triangle(x1, y1, x2, y2, x3, y3).drawFrame(1, 0, Color(c[2], c[1], c[0]));
  return 0;
}


int LoadGraph(const char* name) {
  if (GraphicDataBase == nullptr)
    return -1;

  Texture graph(Unicode::Widen(name));
  if (!graph)
    return -1;

  return GraphicDataBase->setGraphic(graph);
}

int DrawGraph(int x, int y, int graph, int trans) {
  if (GraphicDataBase == nullptr)
    return -1;

  Texture tex = GraphicDataBase->getGraphic(graph);
  if (tex.isEmpty())
    return -1;

  tex.draw(x, y);
  return 0;
}

int DrawTurnGraph(int x, int y, int graph, int trans) {
  if (GraphicDataBase == nullptr)
    return -1;

  Texture tex = GraphicDataBase->getGraphic(graph);
  if (tex.isEmpty())
    return -1;

  tex.mirrored().draw(x, y);
  return 0;
}

int DrawReverseGraph(int x, int y, int graph, int XTurn, int YTurn) {
  if (GraphicDataBase == nullptr)
    return -1;

  Texture tex = GraphicDataBase->getGraphic(graph);
  if (tex.isEmpty())
    return -1;

  if (XTurn == TRUE && YTurn == TRUE)
    tex.mirrored().flipped().draw(x, y);
  else if (XTurn == TRUE)
    tex.mirrored().draw(x, y);
  else if (YTurn == TRUE)
    tex.flipped().draw(x, y);
  else
    tex.draw(x, y);
  return 0;
}

int DrawExtendGraph(int x1, int y1, int x2, int y2, int graph, int trans) {
  if (GraphicDataBase == nullptr)
    return -1;

  Texture tex = GraphicDataBase->getGraphic(graph);
  if (tex.isEmpty())
    return -1;

  Rect(x1, y1, x2 - x1, y2 - y1)(tex).draw();
  return 0;
}

int DrawRotaGraph(int x, int y, double ExRate, double angle, int graph, int trans, int XTurn, int YTurn) {
  if (GraphicDataBase == nullptr)
    return -1;

  Texture tex = GraphicDataBase->getGraphic(graph);
  if (tex.isEmpty())
    return -1;

  if (XTurn == TRUE && YTurn == TRUE)
    tex.mirrored().flipped().scaled(ExRate).rotated(angle).drawAt(x, y);
  else if (XTurn == TRUE)
    tex.mirrored().scaled(ExRate).rotated(angle).drawAt(x, y);
  else if (YTurn == TRUE)
    tex.flipped().scaled(ExRate).rotated(angle).drawAt(x, y);
  else
    tex.scaled(ExRate).rotated(angle).drawAt(x, y);
  return 0;
}

int DrawModiGraph(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int graph, int trans) {
  if (GraphicDataBase == nullptr)
    return -1;

  Texture tex = GraphicDataBase->getGraphic(graph);
  if (tex.isEmpty())
    return -1;

  Quad(x1, y1, x2, y2, x3, y3, x4, y4)(tex).draw();
  return 0;
}

int DrawRectGraph(int dx, int dy, int sx, int sy, int w, int h, int graph, int trans, int XTurn, int YTurn) {
  if (GraphicDataBase == nullptr)
    return -1;

  Texture tex = GraphicDataBase->getGraphic(graph);
  if (tex.isEmpty())
    return -1;

  if (XTurn == TRUE && YTurn == TRUE)
    tex(sx, sy, w, h).mirrored().flipped().draw(dx, dy);
  else if (XTurn == TRUE)
    tex(sx, sy, w, h).mirrored().draw(dx, dy);
  else if (YTurn == TRUE)
    tex(sx, sy, w, h).flipped().draw(dx, dy);
  else
    tex(sx, sy, w, h).draw(dx, dy);
  return 0;
}

int InitGraph() {
  if (GraphicDataBase == nullptr)
    return -1;

  delete GraphicDataBase;
  GraphicDataBase = new GraphicManager();
  return 0;
}

int GetGraphSize(int graph, int* sizeX, int* sizeY) {
  if (GraphicDataBase == nullptr)
    return -1;

  Texture tex = GraphicDataBase->getGraphic(graph);
  if (tex.isEmpty())
    return -1;

  *sizeX = tex.width();
  *sizeY = tex.height();
  return 0;
}

int DeleteGraph(int graph) {
  if (GraphicDataBase == nullptr)
    return -1;

  return GraphicDataBase->removeGraphic(graph);
}


int LoadSoundMem(const char* name) {
  if (AudioDataBase == nullptr)
    return -1;

  Audio sound(Unicode::Widen(name));
  if (!sound)
    return -1;

  return AudioDataBase->setAudio(sound);
}

int PlaySoundMem(int sound, int type, int topPos) {
  if (AudioDataBase == nullptr)
    return -1;

  pair<Audio, int> audio = AudioDataBase->getAudio(sound);
  if (!audio.first)
    return -1;

  AudioDataBase->setTopPos(sound, topPos);
  if (audio.first.isPlaying())
    audio.first.stop();

  if (type == DX_PLAYTYPE_BACK)
    audio.first.play();
  else if (type == DX_PLAYTYPE_LOOP) {
    audio.first.setLoop(true);
    audio.first.play();
  }
  else {
    /*Ç¢ÇÁÇÒÇ‚ÇÎÇ±ÇÃèàóù*/
  }

  return 0;
}

int CheckSoundMem(int sound) {
  if (AudioDataBase == nullptr)
    return -1;

  pair<Audio, int> audio = AudioDataBase->getAudio(sound);
  if (!audio.first)
    return -1;

  return audio.first.isPlaying();
}

int StopSoundMem(int sound) {
  if (AudioDataBase == nullptr)
    return -1;

  pair<Audio, int> audio = AudioDataBase->getAudio(sound);
  if (!audio.first)
    return -1;

  if (audio.second == TRUE)
    audio.first.stop();
  else
    audio.first.pause();

  return 0;
}

int DeleteSoundMem(int sound) {
  if (AudioDataBase == nullptr)
    return -1;

  return AudioDataBase->removeAudio(sound);
}

int ChangeVolumeSoundMem(int volume, int sound) {
  if (AudioDataBase == nullptr)
    return -1;

  pair<Audio, int> audio = AudioDataBase->getAudio(sound);
  if (!audio.first)
    return -1;

  audio.first.setVolume(volume / 255.0);
  return 0;
}

int InitSoundMem() {
  if (AudioDataBase == nullptr)
    return -1;

  delete AudioDataBase;
  AudioDataBase = new AudioManager();
  return 0;
}


int SetFontSize(int size) {
  if (defaultFont == nullptr)
    return -1;

  defaultFont->size = size;
  if (defaultFont->type == DX_FONTTYPE_NORMAL || defaultFont->type == DX_FONTTYPE_EDGE)
    defaultFont->font = SDFFont(defaultFont->size, FileSystem::SpecialFolderPath(SpecialFolder::SystemFonts) + defaultFont->name, FontStyle::Bitmap);
  else
    defaultFont->font = SDFFont(defaultFont->size, FileSystem::SpecialFolderPath(SpecialFolder::SystemFonts) + defaultFont->name);
  return 0;
}

int SetFontThickness(int thick) {
  if (defaultFont == nullptr)
    return -1;

  defaultFont->thick = 0 <= thick && thick < 10 ? thick : 4;
  return 0;
}

int ChangeFont(const char* name) {
  if (defaultFont == nullptr)
    return -1;

  defaultFont->name = Unicode::Widen(name);
  if (defaultFont->type == DX_FONTTYPE_NORMAL || defaultFont->type == DX_FONTTYPE_EDGE)
    defaultFont->font = SDFFont(defaultFont->size, FileSystem::SpecialFolderPath(SpecialFolder::SystemFonts) + defaultFont->name, FontStyle::Bitmap);
  else
    defaultFont->font = SDFFont(defaultFont->size, FileSystem::SpecialFolderPath(SpecialFolder::SystemFonts) + defaultFont->name);
  return !defaultFont->font ? -1 : 0;
}

int ChangeFontType(int type) {
  if (defaultFont == nullptr)
    return -1;

  defaultFont->type = type;
  if (defaultFont->type == DX_FONTTYPE_NORMAL || defaultFont->type == DX_FONTTYPE_EDGE)
    defaultFont->font = SDFFont(defaultFont->size, FileSystem::SpecialFolderPath(SpecialFolder::SystemFonts) + defaultFont->name, FontStyle::Bitmap);
  else
    defaultFont->font = SDFFont(defaultFont->size, FileSystem::SpecialFolderPath(SpecialFolder::SystemFonts) + defaultFont->name);
  return !defaultFont->font ? -1 : 0;
}

int DrawString(int x, int y, const char* str, unsigned int color) {
  if (defaultFont == nullptr)
    return -1;
  if (!defaultFont->font) 
    return -1;

  unsigned char* c = (unsigned char*)&color;
  if (defaultFont->type == DX_FONTTYPE_EDGE || defaultFont->type == DX_FONTTYPE_ANTIALIASING_EDGE) {
    Graphics2D::SetSDFParameters(defaultFont->font.pixelRange() * 4, 0.05 + (defaultFont->thick - 4) * 0.01);
    defaultFont->font(Unicode::Widen(str)).draw(defaultFont->size, Vec2(x, y), Color(0, 0, 0));
  }

  Graphics2D::SetSDFParameters(defaultFont->font.pixelRange() * 4, (defaultFont->thick - 4) * 0.01);
  defaultFont->font(Unicode::Widen(str)).draw(defaultFont->size, Vec2(x, y), Color(c[2], c[1], c[0]));
  return 0;
}

int DrawFormatString(int x, int y, unsigned int color, const char* str, ...) {
  if (defaultFont == nullptr)
    return -1;
  if (!defaultFont->font)
    return -1;

  va_list ArgPoint;
  char result[512];

  va_start(ArgPoint, str);
  vsprintf_s(result, str, ArgPoint);
  va_end(ArgPoint);

  unsigned char* c = (unsigned char*)&color;
  if (defaultFont->type == DX_FONTTYPE_EDGE || defaultFont->type == DX_FONTTYPE_ANTIALIASING_EDGE) {
    Graphics2D::SetSDFParameters(defaultFont->font.pixelRange() * 4, 0.05 + (defaultFont->thick - 4) * 0.01);
    defaultFont->font(Unicode::Widen(result)).draw(defaultFont->size, Vec2(x, y), Color(0, 0, 0));
  }

  Graphics2D::SetSDFParameters(defaultFont->font.pixelRange() * 4, (defaultFont->thick - 4) * 0.01);
  defaultFont->font(Unicode::Widen(result)).draw(defaultFont->size, Vec2(x, y), Color(c[2], c[1], c[0]));
  return 0;
}


int CreateFontToHandle(const char* name, int size, int thick, int type, int CharSet, int EdgeSize, int Italic, int Handle) {
  if (FontDataBase == nullptr)
    return -1;

  FontData font(name, size, thick, type, CharSet, EdgeSize, Italic);
  if (!font.font)
    return -1;

  return FontDataBase->setFont(font);
}

int DeleteFontToHandle(int font) {
  if (FontDataBase == nullptr)
    return -1;

  return FontDataBase->removeFont(font);
}

int DrawStringToHandle(int x, int y, const char* str, unsigned int color, int FontHandle) {
  if (FontDataBase == nullptr)
    return -1;

  FontData fontData = FontDataBase->getFont(FontHandle);
  if (!fontData.font)
    return -1;

  unsigned char* c = (unsigned char*)&color;
  if (fontData.type == DX_FONTTYPE_EDGE || fontData.type == DX_FONTTYPE_ANTIALIASING_EDGE) {
    Graphics2D::SetSDFParameters(fontData.font.pixelRange() * 4, 0.05 + (fontData.thick - 4) * 0.01);
    fontData.font(Unicode::Widen(str)).draw(fontData.size, Vec2(x, y), Color(0, 0, 0));
  }

  Graphics2D::SetSDFParameters(fontData.font.pixelRange() * 4, (fontData.thick - 4) * 0.01);
  fontData.font(Unicode::Widen(str)).draw(fontData.size, Vec2(x, y), Color(c[2], c[1], c[0]));

  return 0;
}

int DrawFormatStringToHandle(int x, int y, unsigned int color, int FontHandle, const char* str, ...) {
  if (FontDataBase == nullptr)
    return -1;

  FontData fontData = FontDataBase->getFont(FontHandle);
  if (!fontData.font)
    return -1;

  va_list ArgPoint;
  char result[512];

  va_start(ArgPoint, str);
  vsprintf_s(result, str, ArgPoint);
  va_end(ArgPoint);

  unsigned char* c = (unsigned char*)&color;
  if (fontData.type == DX_FONTTYPE_EDGE || fontData.type == DX_FONTTYPE_ANTIALIASING_EDGE) {
    Graphics2D::SetSDFParameters(fontData.font.pixelRange() * 4, 0.05 + (fontData.thick - 4) * 0.01);
    fontData.font(Unicode::Widen(result)).draw(fontData.size, Vec2(x, y), Color(0, 0, 0));
  }

  Graphics2D::SetSDFParameters(fontData.font.pixelRange() * 4, (fontData.thick - 4) * 0.01);
  fontData.font(Unicode::Widen(result)).draw(fontData.size, Vec2(x, y), Color(c[2], c[1], c[0]));

  return 0;
}

int InitFontToHandle() {
  if (FontDataBase == nullptr)
    return -1;

  delete FontDataBase;
  FontDataBase = new FontManager();
  return 0;
}
