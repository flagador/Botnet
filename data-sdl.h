#define LONG 1080
#define HAUT 720

int mainMenu(SDL_Renderer * pRenderer, SDL_Window * pWindow);
void startNewGame();
int shop(SDL_Renderer * Render, SDL_Window * Window);

void initRect(SDL_Renderer * render ,SDL_Rect * rect, int x, int y , int w, int h,int r,int g,int b);
void initText(SDL_Renderer * render, SDL_Rect rect, SDL_Color color, char * mess, TTF_Font * font);
int isOnButton(SDL_Rect rect);

