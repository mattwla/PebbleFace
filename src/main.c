#include <pebble.h>
#define HIGHSCORE 0
#define TAUHIGHSCORE 1 
void window_fill(void);
Window *mainmenu;
Window *window;
Window *window2;
TextLayer *text_layer;
TextLayer *text_layer2;
TextLayer *text_layer3;
TextLayer *scorewindow;
TextLayer *highscorewindow;
TextLayer *maintext;
TextLayer *wrong;
TextLayer *correct;
TextLayer *mainhighscorewindow;
TextLayer *tautext;
TextLayer *motivation;
int len;
int pi = 314159;
int piArray [6];
int piArrayTest[6] = {3, 1, 4, 1, 5, 9};
int pinumber = 0;
int correctslot = 0;
int piArray2[15];
int piChunk = 1;
int inGame = 0;
int highscore;
int tauhighscore = 0;
int currentscore;
int currenttauscore;
int taumode = 0;
static char txtcurrentscore[] = "Score\n 000";
static char txtcurrenthighscore[] = "High Score\n 000";
static char txttaucurrenthighscore[] = "High Score \n 000";
void markWrong (int wrongone);
void reviveWindow (void);
char* motivations[] = {"good job", "sweet"};

void storePi(void)
  {
  //this function is called whenever the app needs to load digits of pi or tau into its memory
  
  // pi is too long of a digit to store in one variable, so we have a series of them.
  long long int n = 314159265358979;
  long long int nII = 323846264338327;
  long long int nIII = 950288419716939;
  long long int nIV = 937510582097494;
  long long int nV = 459230781640628;
  long long int nVI = 620899862803482;
  long long int nVII = 534211706798214;
  long long int nVIII = 808651328230664;
  long long int nIX = 709384460955058;
  long long int nX = 223172535940812;
  //same for tau
  long long int t = 628318530717958;
  long long int tII = 647692528676655;
  long long int tIII = 900576839433879;
  long long int tIV = 875021164194988;
  long long int tV = 918461563281257;
  long long int tVI = 241799725606965;
  long long int tVII = 968423413596429; //first digit 9, will be replaced by 0
  long long int tVIII = 617302656461329;
  long long int tIX = 418768921910116;
  long long int tX = 446345071881625;
  
  //detect if we are playing tau mode or pi mode, load corresponding sections,
  if (taumode == 1)
  {
    
    int c = 14;
  if (piChunk == 1)
    {
  while (t != 0)
{
    piArray2[c] = t % 10;
    t /= 10;
    c--;
}
  }
  if (piChunk == 2)
    {
    c = 14;
    while (tII != 0)
{
    piArray2[c] = tII % 10;
    tII /= 10;
    c--;
    }
    }
  if (piChunk == 3)
    {
  while (tIII != 0)
{
    piArray2[c] = tIII % 10;
    tIII /= 10;
    c--;
}
  }
  if (piChunk == 4)
    {
  while (tIV != 0)
{
    piArray2[c] = tIV % 10;
    tIV /= 10;
    c--;
}
  }
  if (piChunk == 5)
    {
  while (tV != 0)
{
    piArray2[c] = tV % 10;
    tV /= 10;
    c--;
}
  }
  
  if (piChunk == 6)
    {
  while (tVI != 0)
{
    piArray2[c] = tVI % 10;
    tVI /= 10;
    c--;
}
  }
  if (piChunk == 7)
    {
  while (tVII != 0)
{
    piArray2[c] = tVII % 10;
    tVII /= 10;
    c--;
}
  piArray2[0] = 0; //this particular chunk starts with 0, which messes with the compiler so I needed to hack it by manually adding a 0
  }
  if (piChunk == 8)
    {
  while (tVIII != 0)
{
    piArray2[c] = tVIII% 10;
    tVIII /= 10;
    c--;
}
  }
  if (piChunk == 9)
    {
  while (tIX != 0)
{
    piArray2[c] = tIX % 10;
    tIX /= 10;
    c--;
}
  }
  if (piChunk == 10)
    {
  while (tX != 0)
{
    piArray2[c] = tX % 10;
    tX /= 10;
    c--;
}
  }
    
  }
  //this is to load pi
  else
  {
    int c = 14;
  if (piChunk == 1)
    {
  while (n != 0)
{
    piArray2[c] = n % 10;
    n /= 10;
    c--;
}
  }
  if (piChunk == 2)
    {
    c = 14;
    while (nII != 0)
{
    piArray2[c] = nII % 10;
    nII /= 10;
    c--;
    }
    }
  if (piChunk == 3)
    {
  while (nIII != 0)
{
    piArray2[c] = nIII % 10;
    nIII /= 10;
    c--;
}
  }
  if (piChunk == 4)
    {
  while (nIV != 0)
{
    piArray2[c] = nIV % 10;
    nIV /= 10;
    c--;
}
  }
  if (piChunk == 5)
    {
  while (nV != 0)
{
    piArray2[c] = nV % 10;
    nV /= 10;
    c--;
}
  }
  
  if (piChunk == 6)
    {
  while (nVI != 0)
{
    piArray2[c] = nVI % 10;
    nVI /= 10;
    c--;
}
  }
  if (piChunk == 7)
    {
  while (nVII != 0)
{
    piArray2[c] = nVII % 10;
    nVII /= 10;
    c--;
}
  }
  if (piChunk == 8)
    {
  while (nVIII != 0)
{
    piArray2[c] = nVIII% 10;
    nVIII /= 10;
    c--;
}
  }
  if (piChunk == 9)
    {
  while (nIX != 0)
{
    piArray2[c] = nIX % 10;
    nIX /= 10;
    c--;
}
  }
  if (piChunk == 10)
    {
  while (nX != 0)
{
    piArray2[c] = nX % 10;
    nX /= 10;
    c--;
}
  }
  }
    
  
  
  }


char* number_to_text(int num)
  {
  //pebble sdk doesnt let you just print number vars, so we need to convert them to txt chars to show them.
  static char numletters[] = "A";
  snprintf(numletters, sizeof(numletters), "%d", num);
  
  return numletters;
}

void scoreTick(void)
  
{
 //this function is called when we score one right, also is responsible for monitoring and updating highscores
  if (inGame == 1)
    {
    if (taumode == 0)
    {
  currentscore ++;
snprintf(txtcurrentscore, sizeof(txtcurrentscore), "Score\n %d", currentscore);
   snprintf(txtcurrenthighscore, sizeof(txtcurrenthighscore), "High Score\n %d", highscore);
    //strcpy(txtcurrentscore, number_to_text(currentscore))
    }
    else if (taumode == 1)
    {
     currenttauscore ++;
snprintf(txtcurrentscore, sizeof(txtcurrentscore), "Score\n %d", currenttauscore);
   snprintf(txttaucurrenthighscore, sizeof(txttaucurrenthighscore), "High Score\n %d", tauhighscore);
    }
  
if (currentscore > highscore)
  {
  if (taumode == 0)
    {
  persist_write_int(HIGHSCORE, currentscore);
  highscore = persist_read_int(HIGHSCORE);
  snprintf(txtcurrenthighscore, sizeof(txtcurrenthighscore), "High Score\n %d", highscore);
  }
}
if (currenttauscore > tauhighscore)
  {
  if (taumode == 1)
    {
    persist_write_int(TAUHIGHSCORE, currenttauscore);
  tauhighscore = persist_read_int(TAUHIGHSCORE);
  snprintf(txttaucurrenthighscore, sizeof(txttaucurrenthighscore), "High Score\n %d", tauhighscore);
  }
}
  }
}

void increasepi(void)
  {
    pinumber++;
  }

void up_click_handler(ClickRecognizerRef recognizer, void *context)
  {
  //this is what happens when we click up, if in game we see if it was right number, if in main menu we start game.  
  if (inGame == 3)
    { }
  else if ((correctslot == 0) || (inGame == 0))
  {
    scoreTick();
    window_fill();
      }
   
  else
  markWrong(1);
}
void down_click_handler(ClickRecognizerRef recognizer, void *context)
  {
  //what happens when we click down, only used in game. 
  if ((inGame == 0) || (inGame == 3))
    {
      
    }
  
  else if (correctslot == 2)
  {
    scoreTick();
    window_fill();
  }
  

  else
    markWrong(3);
  }
void select_click_handler(ClickRecognizerRef recognizer, void *context)
  {
 //what happens when we press select, in game we figure out if it was right, in main menu we swap between tau mode and pi mode
  if (inGame == 0)
    {
    if (taumode == 0)
      {
    text_layer_set_text(tautext, "Tau mode:  On ->");
      
      snprintf(txttaucurrenthighscore, sizeof(txttaucurrenthighscore), "High Score\n %d", tauhighscore);
      text_layer_set_text(mainhighscorewindow, txttaucurrenthighscore);
      taumode = 1;
    }
    else if (taumode == 1)
    {
      text_layer_set_text(tautext, "Tau mode: Off ->");
      snprintf(txtcurrenthighscore, sizeof(txtcurrenthighscore), "High Score\n %d", highscore);
      text_layer_set_text(mainhighscorewindow, txtcurrenthighscore);
      taumode = 0;
    }
  }
  else if (inGame == 3)
    {}
  
  else if (correctslot == 1)
  {
    scoreTick();
    window_fill();
  }
 
  else
    markWrong(2);
  
}

void click_config_provider(void *context)
  {
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
}

void click_config_provider_main(void *context)
  {
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
}

void window_main(Window *mainmenu)
  {
  maintext = text_layer_create(GRect(30, 10, 144, 168));
  window_set_background_color(mainmenu, GColorBlack);
  text_layer_set_background_color(maintext, GColorClear);
  text_layer_set_text_color(maintext, GColorWhite);
  layer_add_child(window_get_root_layer(mainmenu), text_layer_get_layer(maintext));
  text_layer_set_text(maintext, "Start ->");
  text_layer_set_font(maintext, fonts_get_system_font(FONT_KEY_BITHAM_30_BLACK));
  
   tautext = text_layer_create(GRect(20, 60, 144, 168));
  text_layer_set_background_color(tautext, GColorClear);
  text_layer_set_text_color(tautext, GColorWhite);
  layer_add_child(window_get_root_layer(mainmenu), text_layer_get_layer(tautext));
  text_layer_set_text(tautext, "Tau mode: Off ->");
  text_layer_set_font(tautext, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  
  mainhighscorewindow = text_layer_create(GRect(8, 120, 144, 168));
  text_layer_set_background_color(mainhighscorewindow, GColorClear);
  text_layer_set_text_color(mainhighscorewindow, GColorWhite);
  layer_add_child(window_get_root_layer(mainmenu), text_layer_get_layer(mainhighscorewindow));
   text_layer_set_text(mainhighscorewindow, txtcurrenthighscore);
  
  
  
}

void markWrong (int wrongone)
  
  {
  //called when we are wrong, marks an x where wrong and an arrow where the right digit was
  inGame = 3;
  int wherex;
  int wherey;
  if (wrongone == 1)
    wherex = 10;
  if (wrongone == 2)
    wherex = 60;
  if (wrongone == 3)
    wherex = 120;
  if (correctslot == 0)
    wherey = 10;
  if (correctslot == 1)
    wherey = 60;
  if (correctslot == 2)
    wherey = 120;
    
  wrong = text_layer_create(GRect(100, wherex, 144, 168));
  text_layer_set_background_color(wrong, GColorClear);
  text_layer_set_text_color(wrong, GColorWhite);
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(wrong));
  text_layer_set_text(wrong, "X");
  
  correct = text_layer_create(GRect(100, wherey, 144, 168));
  text_layer_set_background_color(correct, GColorClear);
  text_layer_set_text_color(correct, GColorWhite);
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(correct));
  text_layer_set_text(correct, ">");
}

void window_load(Window *window)
  {
   window_set_background_color(window, GColorBlack);
  text_layer = text_layer_create(GRect(120, 5, 144, 168));
  text_layer_set_background_color(text_layer, GColorClear);
  text_layer_set_text_color(text_layer, GColorWhite);
  
  text_layer3 = text_layer_create(GRect(120, 100, 144, 168));
  text_layer_set_background_color(text_layer3, GColorClear);
  text_layer_set_text_color(text_layer3, GColorWhite);
  
  text_layer2 = text_layer_create(GRect(120, 50, 144, 168));
  text_layer_set_background_color(text_layer2, GColorClear);
  text_layer_set_text_color(text_layer2, GColorWhite);
  
  scorewindow = text_layer_create(GRect(10, 0, 144, 168));
  text_layer_set_background_color(scorewindow, GColorClear);
  text_layer_set_text_color(scorewindow, GColorWhite);
  
  highscorewindow = text_layer_create(GRect(8, 120, 144, 168));
  text_layer_set_background_color(highscorewindow, GColorClear);
  text_layer_set_text_color(highscorewindow, GColorWhite);
  
  
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer));
  text_layer_set_text(text_layer, "PRESS");
  text_layer_set_font(text_layer, fonts_get_system_font(FONT_KEY_BITHAM_34_MEDIUM_NUMBERS));
  
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer2));
  text_layer_set_text(text_layer2, "ANY");
  text_layer_set_font(text_layer2, fonts_get_system_font(FONT_KEY_BITHAM_34_MEDIUM_NUMBERS));
  
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer3));
  text_layer_set_text(text_layer3, "KEY");
  text_layer_set_font(text_layer3, fonts_get_system_font(FONT_KEY_BITHAM_34_MEDIUM_NUMBERS));
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(scorewindow));
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(highscorewindow));
  
  /*motivation = text_layer_create(GRect(0, 60, 144, 168));
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(motivation));
  text_layer_set_background_color(motivation, GColorClear);
  text_layer_set_text_color(motivation, GColorWhite);
  text_layer_set_text(motivation, motivations[1]);*/
 
  

}

void window_load2(Window *window2)
  {
  text_layer3 = text_layer_create(GRect(35, 10, 144, 168));
  text_layer_set_background_color(text_layer3, GColorClear);
  text_layer_set_text_color(text_layer3, GColorBlack);
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer3));
  text_layer_set_text(text_layer3, "Chunking Practice");
 }

void window_main_unload(Window *mainmenu)
{
  text_layer_destroy(maintext);
}

void window_unload(Window *window)
{
  text_layer_destroy(text_layer);
  window_destroy(window);
  inGame = 0;
  currentscore = 0;
   text_layer_set_text(mainhighscorewindow, txtcurrenthighscore);
  if (taumode == 1)
    {
    text_layer_set_text(mainhighscorewindow, txttaucurrenthighscore);
  }  
  
  //piChunk = 1;
}

void window_unload2(Window *window2)
{
  text_layer_destroy(text_layer);
}

void window_fill(void)
{
  //called whenever we need to refresh window with new digits (like after a correct press, or when starting game) also determines placement of correct and incorrect digits
  static int piplace = 0;
  if (inGame == 0)
  {reviveWindow();
   window_stack_push(window, true); 
   currentscore = 0;
   currenttauscore = 0;
   piplace = 0;
   piChunk = 1;
   storePi();
   text_layer_set_text(scorewindow, 0);
  snprintf(txtcurrentscore, sizeof(txtcurrentscore), "Score\n %d", currentscore);
  }
  text_layer_set_text(scorewindow, txtcurrentscore);
  text_layer_set_text(highscorewindow, txtcurrenthighscore);
  if (taumode == 1)
    text_layer_set_text(highscorewindow, txttaucurrenthighscore);
  inGame = 1;
  srand(time(NULL));

  
  int wrongone;
  int wrongtwo;
  int oldwrongone = 0;
  int oldwrongtwo = 0;
  static char wrongonec[] = "A";
  static char wrongtwoc[] = "A";
  static char correctc[] = "A";
  
  wrongone = rand() %9;
  wrongtwo = rand() %9;
    
  while ((wrongone == piArray2[piplace]) || (wrongtwo == piArray2[piplace]) || (wrongone == wrongtwo) || (wrongone == oldwrongone) || (wrongtwo == oldwrongtwo) ) 
    {
    wrongone = rand() %9;
    wrongtwo = rand() %9;
  }
  oldwrongone = wrongone;
  oldwrongtwo = wrongtwo;
  
  /* while (wrongone == 0)
     wrongone = rand() %10;
  while (wrongtwo == 0)
    wrongtwo = rand() %10;
  while (wrongone == piArray2[piplace])
     wrongone = rand() %9 + 1;
  while (wrongtwo == piArray2[piplace])
    wrongtwo = rand() %9 + 1;
  while (wrongone == wrongtwo)
    {
     wrongtwo = rand() %9 + 1;
  } */
   
  
  strcpy(wrongonec, number_to_text(wrongone));
  strcpy(wrongtwoc, number_to_text(wrongtwo));
  strcpy(correctc, number_to_text(piArray2[piplace]));
  correctslot = rand() %3;
  if (correctslot == 0) 
    {
    text_layer_set_text(text_layer, correctc);
    text_layer_set_text(text_layer2, wrongonec);
    text_layer_set_text(text_layer3, wrongtwoc);
   }
  if (correctslot == 1)
    {
    text_layer_set_text(text_layer2, correctc);
    text_layer_set_text(text_layer, wrongonec);
    text_layer_set_text(text_layer3, wrongtwoc);
  }
  
  if (correctslot == 2)
    {
    text_layer_set_text(text_layer3, correctc);
    text_layer_set_text(text_layer2, wrongonec);
    text_layer_set_text(text_layer, wrongtwoc);
  }
    piplace ++;
  if (piplace == 15) 
    {
    piChunk ++;
    storePi();
   piplace = 0;
    
  }
    }

void reviveWindow(void)
  {
  window = window_create();
    window_set_window_handlers(window, (WindowHandlers) {
      .load = window_load,
      .unload = window_unload,
    });

  window_set_click_config_provider(window, click_config_provider);
}


void init()
  {
  currentscore = 0;
  currenttauscore = 0;
  if (persist_exists(HIGHSCORE))
    {
    highscore = persist_read_int(HIGHSCORE);
    snprintf(txtcurrenthighscore, sizeof(txtcurrenthighscore), "High Score\n %d", highscore);
  }
  else
    {
    snprintf(txtcurrenthighscore, sizeof(txtcurrenthighscore), "High Score\n 0");
  }
  if (persist_exists(TAUHIGHSCORE))
    {
    tauhighscore = persist_read_int(TAUHIGHSCORE);
    snprintf(txttaucurrenthighscore, sizeof(txttaucurrenthighscore), "High Score\n %d", tauhighscore);
  }
  else
    snprintf(txttaucurrenthighscore, sizeof(txttaucurrenthighscore), "High Score\n 0");
  
  //storePi();
  mainmenu = window_create();
  window_set_window_handlers(mainmenu, (WindowHandlers)
    {
    .load = window_main, 
    .unload = window_main_unload,
  });
  
   window_set_click_config_provider(mainmenu, click_config_provider_main);
  window_stack_push(mainmenu, true);

  
  /*window = window_create();
    window_set_window_handlers(window, (WindowHandlers) {
      .load = window_load,
      .unload = window_unload,
    });

  window_set_click_config_provider(window, click_config_provider);
  //window_stack_push(window, true); */

}

void deinit()
    {
    //window_destroy(window);
 
  window_destroy(mainmenu);
  }
  
  
  int main(void) 
  {
  init();
  app_event_loop();
  deinit();
}


